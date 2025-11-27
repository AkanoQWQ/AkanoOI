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
class VoidListener;
class Button;
using Buttonp = Button*;
class UIptr;
using UIptrp = UIptr*;//为什么UIptr需要有指针呢?如果想要用更高层的管理器托管的话,就要创建为指针方便管理
struct Position;
using POS = Position;
using Rect = Position;//矩形,内核和Position一致

/////////////////////////
//函数声明区
////////////////////////

Rect StringRect(const string& str,Rect rect);//rect:范围   获取字符串输出后的长宽

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
	bool active,display;
	Position pos;
	int sizeX,sizeY;
	int priority;//优先级默认为100,越小越优先,直接在这里设置没用
	virtual void Draw(){}
	virtual void Onclick(){}
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
	virtual ~UIbasic(){}
};

class DrawFunction : public UIbasic{
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

class Text : public UIbasic{
private:
	
public:
	string content;
	COLORREF bgcolor = WHITE,maincolor = RED;
	void Draw(){
		setfontbkcolor(WHITE),setcolor(BLACK);
		outtextrect(pos.x,pos.y,sizeX,sizeY,content.c_str());
		return ;
	}
	Text() = default;
	Text(POS _pos,int _sizeX,int _sizeY,string _content = "") : UIbasic(_pos,_sizeX,_sizeY){
		content = _content;
		return ;
	}
};

Inputboxp selectedInputbox;//当前被选中的inputbox
class Inputbox : public UIbasic{
private:
	using funcT = function<void(string&)>;
	class EmptyFunc{
	public:
		void operator()(string& str){
			str.length();//防止讨厌的警告......
			return ;
		}
	};
	bool lastSubmit;//最后是否提交
public:
	string content;
	funcT submitFunc;//提交事件
	void Draw(){
		const static int charSpace = 3;//字体间隙
		Rect contentRect = StringRect(content,Rect(sizeX - charSpace * 2,sizeY - charSpace * 2));
		setcolor(BLACK),setfillcolor(WHITE);
		rectangle(pos.x,pos.y,pos.x + sizeX,pos.y + sizeY);
		if(contentRect.y > sizeY){//溢出了,倒序输出
			string realOutput = "";
			LOGFONTA info;
			getfont(&info);
			assert(info.lfWidth != 0);//原因见StringRect
			int contentMax = (sizeY / info.lfHeight) * (sizeX / info.lfWidth);
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

class VoidListener{
private:
	constexpr static bool DEBUG_VOIDLISTENER_ONCLICK = false;
public:
	void operator()(){
		if(DEBUG_VOIDLISTENER_ONCLICK)cerr<<"on click on void Listener"<<endl;
		return ;
	}
};

class Button : public UIbasic{
private:
	using funcT = function<void(void)>;
	vector<Inputboxp> linkBoxs;
public:
	funcT listener;
	string content;
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
		outtextrect(max(pos.x,pos.x + spaceX - 2),pos.y + spaceY,sizeX - spaceX,sizeY - spaceY,content.c_str());
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
	UIbasic& operator*(){
		return *ptr;
	}
	operator UIp(){
		return ptr;
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
	UIptrManager& operator+=(UIp ptr){//后果:无法手动删除
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

UIp NewText(int y,int l,int r,const string& content){
	return new Text(POS(l,y),r-l,CANVAS_INF,content);
}
UIptrp NewTextP(int y,int l,int r,const string& content){//返回的是UIptr指针版
	return new UIptr(NewText(y,l,r,content));
}

inline Rect StringRect(const string& str,Rect rect){
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
	int realX = rect.x - (rect.x % info.lfWidth);//把余下的部分丢掉
	int len = str.length() * info.lfWidth;
	return Rect(len % realX,int(ceil(1.0f * len / realX) * info.lfHeight));
}

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
	}
	return ;
}

inline void KeyboardCheck(){
	while(kbhit()){
		char ch = getch();
		if(selectedInputbox != nullptr){
			selectedInputbox->Push(ch);
		}
	}
	return ;
}

inline void UIevent(){
	for(auto ptr : UIdeletePool){
		UIpool.erase(ptr);
		if(selectedInputbox == ptr)selectedInputbox = nullptr;//否则RE
		delete ptr;
	}
	UIdeletePool.clear();
	for(auto uiptr : UIptrActivePool){
		uiptr->Active(true);
	}
	UIptrActivePool.clear();
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
