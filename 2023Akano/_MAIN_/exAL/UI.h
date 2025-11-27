#pragma once
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

/////////////////////////
//常量声明区
////////////////////////

const int CANVAS_INF = 32768;

/////////////////////////
//类声明区
////////////////////////

class UIbasic;
using UIp = UIbasic*;
class Text;
using Textp = Text*;
class Inputbox;
using Inputboxp = Inputbox*;
class Button;
using Buttonp = Button*;
class UIptr;
using UIptrp = UIptr*;//为什么UIptr需要有指针呢?如果想要用更高层的管理器托管的话,就要创建为指针方便管理
struct Position;
using POS = Position;
using Rect = Position;//矩形,内核和Position一致,只是它表示的是一个范围

/////////////////////////
//函数声明区
////////////////////////

Rect GetFontSize();//获取当前字体的大小
Rect StringRect(const string& str,Rect rect);//rect:范围   获取字符串输出后的长宽
string ShiftString(const string& str,Rect rect,int line);//计算字符串向下位移 line 行后的字符串

/////////////////////////
//类实现区
////////////////////////

struct Position{
	int x,y;
	Position() = default;
	Position(int _x,int _y){
		x = _x,y = _y;
		return ;
	}
};

class UIbasic{
private:
	
protected:
	inline bool IsClicked(){
		//可能不需要这一条了?已经在侦测的入口加了 is_down()
		if(not(keystate(key_mouse_l)))return false;
		int mouseX,mouseY;
		mousepos(&mouseX,&mouseY);
		return (pos.x <= mouseX && mouseX <= pos.x + sizeX) && (pos.y <= mouseY && mouseY <= pos.y + sizeY);
	}
public:
	//是否被激活(互动),是否可见
	bool active,display;
	//坐标及大小(大小的类型是否可以换成Rect?)
	Position pos;
	int sizeX,sizeY;
	//优先级 默认为100,越小越优先,直接在这里设置没用
	int priority;
	//虚函数接口,分别为绘画函数和点击函数
	virtual void Draw(){}
	virtual void Onclick(){}
	//检查是否点击,这个是通用的所以不用声明为虚函数了
	void CheckOnclick(){
		if(IsClicked())Onclick();
		return ;
	}
	UIbasic() = default;
	UIbasic(Position _pos,int _sizeX,int _sizeY){
		pos = _pos,sizeX = _sizeX,sizeY = _sizeY;
		active = display = true;
		priority = 100;
		return ;
	}
	//虚解析函数,不加报错
	virtual ~UIbasic(){}
};

//"可持久化绘画函数",在使用UI托管的情况下如果简单地使用一次绘画函数,它很快会被覆盖掉
//为了使绘画的内容可以持续出现在画布上,把这个函数封装为一个UI类以便在每一帧都调用这个函数
class DrawFunction : public UIbasic{
	//提供的接口 : 一个返回值为 void ,参数为一个 Position 和 一个 Rect 的函数/仿函数
	//参数含义为当前位置和画图范围
	using funcT = function<void(POS,Rect)>;
public:
	funcT drawFunc;
	void Draw(){
		drawFunc(pos,Rect(sizeX,sizeY));
		return ;
	}
	DrawFunction(POS _pos,int _sizeX,int _sizeY,funcT _func) : UIbasic(_pos,_sizeX,_sizeY){
		drawFunc = _func;
		return ;
	}
};

//当前被选中的text
Textp selectedText;

//"文字UI",简单地把文字显示在屏幕上
class Text : public UIbasic{
private:
	
public:
	//文字的内容
	string content;
	//背景颜色和字体颜色
	COLORREF bgcolor = WHITE,maincolor = BLACK;
	//是否水平居中,默认为否
	bool center;
	//滚轮的位移,用于shift显示信息
	int wheel;
	//滚轮固定,不会因为滚轮而移动文字,是默认设置
	bool wheelFixed;
	//滚轮一次的最小单位,是不是在不同环境下不一样?
	constexpr static int wheelUnit = 120;
	void Onclick(){
		selectedText = this;
		return ;
	}
	inline void AddWheel(int delta){
		wheel -= delta;//这个地方是反过来的,因为输入就和上下反过来
		wheel = max(wheel,0);
		Rect rect = StringRect(content,Rect(sizeX,sizeY));
		wheel = min(wheel,wheelUnit * rect.y);
		return ;
	}
	void Draw(){
		setfontbkcolor(bgcolor),setcolor(maincolor);
		string realContent = ShiftString(content,Rect(sizeX,sizeY),wheel / wheelUnit);
		if(center == false){
			outtextrect(pos.x,pos.y,sizeX,sizeY,realContent.c_str());
		}else{
			int realX = StringRect(realContent,Rect(sizeX,sizeY)).x;
			int spaceX = (sizeX - realX) / 2;
			outtextrect(pos.x + spaceX,pos.y,sizeX - spaceX,sizeY,realContent.c_str());
		}
		return ;
	}
	Text() = default;
	Text(POS _pos,int _sizeX,int _sizeY,string _content = "") : UIbasic(_pos,_sizeX,_sizeY){
		content = _content,center = false,wheelFixed = true;
		return ;
	}
};

//当前被选中的inputbox
Inputboxp selectedInputbox;

//"输入框UI",用于提供给用户输入信息
class Inputbox : public UIbasic{
private:
	//提供的接口 : 一个返回值为 void ,参数为一个 string& 的函数/仿函数
	//参数含义为输入框里的内容,为引用形式(方便你可以进行清空等操作,设置提交后的输入框该有什么内容)
	using funcT = function<void(string&)>;
	//默认的Submit函数(含义见下),什么也不做
	class EmptyFunc{
	public:
		void operator()(string& str){
			str.length();//防止讨厌的警告......
			return ;
		}
	};
	//在按钮被销毁时是否提交(比如提前关闭了界面,是否进行Submit操作)
	bool lastSubmit;
public:
	//inputbox里的内容,一开始为预定,后面为用户输入的内容
	string content;
	//提交事件,在用户输入回车后被调用的事件,类型如上
	//被一个按钮类绑定以后,在按钮按下的时候也会调用submitFunc事件
	funcT submitFunc;
	void Draw(){
		const static int charSpace = 3;//字体间隙
		Rect contentRect = StringRect(content,Rect(sizeX - charSpace * 2,sizeY - charSpace * 2));
		setcolor(BLACK),setfillcolor(WHITE);
		rectangle(pos.x,pos.y,pos.x + sizeX,pos.y + sizeY);
		if(contentRect.y > sizeY){//溢出了,倒序输出
			string realOutput = "";
			Rect fontSize = GetFontSize();
			int contentMax = (sizeY / fontSize.y) * (sizeX / fontSize.x);
			int charcnt = 0,fullCnt = 0;//泉角字符统计
			for(auto it = --content.end();it != content.begin()-1;--it){
				realOutput += *it;
				if(int(*it) < 0)fullCnt++;
				if(++charcnt >= contentMax)break;
			}
			if(fullCnt & 1)realOutput.pop_back();
			reverse(realOutput.begin(),realOutput.end());
			outtextrect(pos.x + charSpace,pos.y + charSpace,sizeX - charSpace,sizeY - charSpace,realOutput.c_str());
		}else{
			setfontbkcolor(WHITE),setcolor(BLACK);
			outtextrect(pos.x + charSpace,pos.y + charSpace,sizeX - charSpace,sizeY - charSpace,content.c_str());
		}
		return ;
	}
	inline void Push(char ch){
		if(int(ch) == 8){
			if(!content.empty()){
				if(int(content.back()) < 0 && int(content.length()) >= 2){
					content.pop_back();//额外退格,全角字符
				}
				content.pop_back();
			}
		}else if(int(ch) == 13){
			submitFunc(content);
		}else if(int(ch) == -27){
			//输入中文带来的奇怪字符
		}else{
			content += ch;
		}
		return ;
	}
	void Onclick(){
		selectedInputbox = this;
		return ;
	}
	Inputbox() = default;
	Inputbox(POS _pos,int _sizeX,int _sizeY,funcT _func = funcT(EmptyFunc()),string _default_content = "",bool _lastSubmit = false) : UIbasic(_pos,_sizeX,_sizeY){
		content = _default_content,submitFunc = _func,lastSubmit = _lastSubmit;
		return ;
	}
	~Inputbox(){
		if(lastSubmit)submitFunc(content);//最后会进行提交
		return ;
	}
};

class Button : public UIbasic{
private:
	//提供的接口 : 一个返回值为 void ,无参数的函数/仿函数
	//如果想要在按钮里存储内容,请使用仿函数储存信息
	using funcT = function<void(void)>;
	//链接的inputbox集合,当按下按钮时连接的inputbox会调用submit函数
	vector<Inputboxp> linkBoxs;
	//默认的监听函数,什么也不做
	class VoidListener{
	private:
		constexpr static bool DEBUG_VOIDLISTENER_ONCLICK = false;
	public:
		void operator()(){
			if(DEBUG_VOIDLISTENER_ONCLICK)cerr<<"click on void Listener"<<endl;
			return ;
		}
	};
public:
	//监听函数,在按钮被按下后调用
	funcT listener;
	//按钮上显示的文字
	string content;
	
	//一定不要把UIptrp放进来......
	template<typename T>
	inline void Link(T inputbox){//泉部自动解释为inputboxp,当然转换要求是指针
		linkBoxs.push_back(Inputboxp(inputbox));
		return ;
	}
	void Draw(){
		constexpr static double radiusAlpha = 0.2;
		Rect contentRect = StringRect(content,Rect(sizeX,sizeY));
		const int spaceX = (sizeX - contentRect.x) / 2,spaceY = (sizeY - contentRect.y) / 2;
		setcolor(BLACK),setfillcolor(WHITE);
		roundrect(pos.x,pos.y,pos.x + sizeX,pos.y + sizeY,sizeX * radiusAlpha,sizeY * radiusAlpha);
		setfontbkcolor(WHITE),setcolor(BLACK);
		//-2是因为实际体验中,字体要稍微偏右
		outtextrect(pos.x + spaceX,pos.y + spaceY,sizeX - spaceX,sizeY - spaceY,content.c_str());
		return ;
	}
	void Onclick(){
		for(auto i : linkBoxs){
			i->submitFunc(i->content);
		}
		listener();
		return ;
	}
	Button() = default;
	Button(POS _pos,int _sizeX,int _sizeY,funcT _func = VoidListener(),string _content = "") : UIbasic(_pos,_sizeX,_sizeY){
		content = _content,listener = _func;
		return ;
	}
};

//UIptr 类,智能管理 UI
//位置置于下方,此时应该完成所有 UI 的实现
class CmpUIp{
public:
	bool operator()(UIp p1,UIp p2){
		if(p1->priority != p2->priority){
			return p1->priority > p2->priority;
		}
		return p1 < p2;
	}
};
set<UIp,CmpUIp> UIpool;
vector<UIp> UIdeletePool;//延迟删除,否则RE
vector<UIptrp> UIptrActivePool;//延迟激活,防止奇怪的问题
class UIptr{
private:
	UIp ptr;
	inline void DeleteElement(UIp _ptr){
		_ptr->active = _ptr->display = false;
		UIdeletePool.push_back(_ptr);//很重要......
		return ;
	}
	inline void InsertElement(UIp _ptr){
		if(_ptr == nullptr)return ;
		UIpool.insert(_ptr);
		return ;
	}
public:
	bool operator<(const UIptr& oth)const{
		return ptr < oth.ptr;
	}
	inline void SetPriority(int _val){//不在这里设置的话没有用
		UIpool.erase(ptr);
		ptr->priority = _val;
		UIpool.insert(ptr);
		return ;
	}
	inline void Display(bool _val){
		ptr->display = _val;
		return ;
	}
	inline void Active(bool _val){
		ptr->active = _val;
		return ;
	}
	inline bool Display(){
		return ptr->display;
	}
	inline bool Active(){
		return ptr->active;
	}
	inline UIp Ptr(){//防止UIptrp需要不停转换
		return ptr;
	}
	UIbasic& operator*(){
		return *ptr;
	}
	operator UIp(){
		return ptr;
	}
	//提供快速转换为对应UI指针的转换符的函数,而不是转换符
	//常见的错误是对UIptrp进行转换,相当于把一个UIptr对象看做了UI对象,显然会导致RE
	//一定不要对UIptrp直接进行类型转换!请使用 uiptr->TextP
	inline Textp TextP(){
		return Textp(ptr);
	}
	inline Inputboxp InputboxP(){
		return Inputboxp(ptr);
	}
	inline Buttonp ButtonP(){
		return Buttonp(ptr);
	}
	UIptr(){
		ptr = nullptr;
		return ;
	}
	UIptr(UIp _ptr){
		ptr = _ptr;
		InsertElement(ptr);
		return ;
	}
	UIptr& operator=(UIp _ptr){
		DeleteElement(ptr);
		ptr = _ptr;
		InsertElement(ptr);
		return *this;
	}
	~UIptr(){
		DeleteElement(ptr);
		return ;
	}
};

//UIptrManager类,智能管理UIptr
//冷笑话,"我认为除了使用 UIptrManagerFactoryUnion 产生的 UIptrManagerFactory 构造的 UIptrManager 管理的 UIptr 托管的 UI* 以外的任何写法,都是不规范的"
class UIptrManager{
private:
	set<UIptrp> uiptrs;
public:
	inline int Size(){
		return uiptrs.size();
	}
	inline void Bind(UIptrp ptr){
		uiptrs.insert(ptr);
		return ;
	}
	inline void Delete(UIptrp ptr){
		uiptrs.erase(ptr);
		delete ptr;
		return ;
	}
	inline void Debind(UIptrp ptr){
		uiptrs.erase(ptr);
		return ;
	}
	inline void Display(bool _val){//设置所有管理元素的display
		for(auto i : uiptrs)i->Display(_val);
		return ;
	}
	inline void Active(bool _val){//设置所有管理元素的active
		for(auto i : uiptrs)i->Active(_val);
		return ;
	}
	UIptrManager& operator+=(UIptrp ptr){
		Bind(ptr);
		return *this;
	}
	UIptrManager& operator-=(UIptrp ptr){
		Delete(ptr);//是删除不是解绑
		return *this;
	}
	UIptrManager& operator+=(UIp ptr){//后果:无法手动选择性删除(已经无法追踪到UI了)
		UIptrp newptr = new UIptr(ptr);
		Bind(newptr);
		return *this;
	}
	inline void Clear(){
		for(auto i : uiptrs)delete i;
		uiptrs.clear();
		return ;
	}
	UIptrManager() = default;
	~UIptrManager(){
		Clear();
		return ;
	}
};


/////////////////////////
//函数实现区
////////////////////////

//用于创建一个y轴为y,左右界为 [l,r] 的内容为content的文字类,返回指针(UIp)
UIp NewText(int y,int l,int r,const string& content){
	return new Text(POS(l,y),r-l,CANVAS_INF,content);
}
//功能同上,返回的是UIptr指针版
UIptrp NewTextP(int y,int l,int r,const string& content){
	return new UIptr(NewText(y,l,r,content));
}

//获取字体大小
inline Rect GetFontSize(){
	LOGFONTA info;
	getfont(&info);
	try{
		if(info.lfWidth == 0){
			throw "当前字体使用自适应宽度,请设置宽度!";
		}
	}catch(const char* errInfo){
		closegraph();
		cerr<<endl<<"-----------------------------------------------------------------"<<endl;
		cerr<<errInfo;
		cerr<<endl<<"-----------------------------------------------------------------"<<endl;
	}
	return Rect(info.lfWidth,info.lfHeight);
}
//用于计算一段文字在某个矩形中会占用多大的空间,返回一个矩阵
inline Rect StringRect(const string& str,Rect rect){
	Rect fontSize = GetFontSize();
	int realX = rect.x - (rect.x % fontSize.x);//把余下的部分丢掉
	int len = str.length() * fontSize.y;
	return Rect(len % realX,int(ceil(1.0f * len / realX) * fontSize.y));
}
//计算字符向下位移多少行以后如何显示
inline string ShiftString(const string& str,Rect rect,int line){
	if(line < 0)return str;
	string ret = str;
	reverse(ret.begin(),ret.end());
	Rect fontSize = GetFontSize();
	int delchars = line * (rect.x / fontSize.x);//注意优先级,默认向下取整
	cerr<<"line one is "<<(rect.x / fontSize.x)<<" becuase "<<rect.x<<" and "<<fontSize.x<<endl;
	while(delchars > 0 && !ret.empty()){
		if(int(ret.back()) < 0){
			ret.pop_back(),delchars--;//泉角字符,连续删除
		}
		ret.pop_back(),delchars--;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
//检查鼠标和UI的互动,请每一帧调用(或调用UIupdate,最好不要重复调用)
inline void MouseCheck(){
	while(mousemsg()){
		auto mouseMessage = getmouse();
		if(mouseMessage.is_down()){
			selectedInputbox = nullptr;//取消选中输入栏
			for(auto ui : UIpool){
				if(UIpool.find(ui) == UIpool.end()){
					continue;//可能出现在过程中被删掉的情况
				}
				if(ui->active)ui->CheckOnclick();
			}
		}
		if(mouseMessage.is_wheel() && selectedText != nullptr){
			if(selectedText->wheelFixed == false){
				selectedText->AddWheel(mouseMessage.wheel);
			}
		}
	}
	return ;
}
//检查键盘和UI的互动,请每一帧调用(或调用UIupdate,最好不要重复调用)
inline void KeyboardCheck(){
	while(kbhit()){
		char ch = getch();
		if(selectedInputbox != nullptr){
			selectedInputbox->Push(ch);
		}
	}
	return ;
}
//进行一些UI相关的逻辑计算(如延迟删除),请每一帧调用(或调用UIupdate,最好不要重复调用)
inline void UIevent(){
	for(auto ptr : UIdeletePool){
		UIpool.erase(ptr);
		if(selectedInputbox == ptr)selectedInputbox = nullptr;//否则RE
		if(selectedText == ptr)selectedInputbox = nullptr;//否则RE
		delete ptr;
	}
	UIdeletePool.clear();
	for(auto uiptr : UIptrActivePool){
		uiptr->Active(true);
	}
	UIptrActivePool.clear();
	return ;
}
//一键调用所有UI相关的逻辑事件,每帧调用,参数表示是否包含绘画
//由于常常需要手动实现ReDraw函数,故默认不包含绘画
inline void UIUpdate(bool needDraw = false){
	if(needDraw){//没有清屏
		for(auto ui : UIpool){
			if(ui->display)ui->Draw();
		}
		delay_ms(0);
	}
	MouseCheck();
	KeyboardCheck();
	UIevent();
	return ;
}

/////////////////////////
//特化实现区
////////////////////////

struct DrawRect{
	COLORREF bgcolor = WHITE,rectcolor = BLACK;
	void operator()(POS pos,Rect rect){
		setcolor(rectcolor),setfillcolor(bgcolor);
		bar(pos.x,pos.y,pos.x+rect.x,pos.y+rect.y);
		rectangle(pos.x,pos.y,pos.x+rect.x,pos.y+rect.y);
		return ;
	}
}drawrect;
