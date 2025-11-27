#include<bits/stdc++.h>
#include "UI.h"
#include<AL/comp.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

constexpr int screenX = 800;
constexpr int screenY = 640;
constexpr char* caption = (char*)"PEOJ UIversion!";

template<typename T>
inline string ToString(T firArg){
	ostringstream oss;
	oss<<firArg;
	return oss.str();
}
template<typename T,typename... Args>
string ToString(T firArg,const Args... args){
	ostringstream oss;
	oss<<firArg;
	return oss.str() + ToString(args...);
}

inline void ClearScreen(){
	setcolor(WHITE),setfillcolor(WHITE);
	bar(0,0,screenX,screenY);
	return ;
}
inline void ReDraw(){
	ClearScreen();
	for(auto ui : UIpool){
		if(ui->display)ui->Draw();
	}
	delay_ms(0);
	return ;
}
UIptrManager mainUI;

string judgeName;
int judgeTimes;

struct WaitingList{
	string name;
	int maxTurn,maxScore,maxTime,tid;
	WaitingList() = default;
	WaitingList(string _name,int _t,int _mx,int _mt,int _tid){
		name = _name,maxTurn = _t,maxScore = _mx,maxTime = _mt;
		tid = _tid;
		return ;
	}
};
vector<WaitingList> waiting;
namespace InputTestSpace{
	void AddTest(const string&,int,int,int);
}
inline void Prepare(){
	SetDefaultGCC();
	if(CheckGCC() == false){
		cout<<"GCC没有找到默认路径!请手动输入GCC路径(./.../g++.exe):"<<endl;
		string path = "DEF";
		do{
			if(path != "DEF")cout<<"GCC路径错误!请重新输入:"<<endl;
			getline(cin,path);
			SetGCC("\"" + path + "\"");
		}while(CheckGCC() == false);
	}
	if(_access("config.txt",00) == 0){
		cout<<"文件读入了以下题目:"<<endl;
		ifstream fin("config.txt");
		WaitingList nowList;
		while(fin>>nowList.name>>nowList.maxTurn>>nowList.maxTime>>nowList.maxScore){
			cout<<"题目 : "<<nowList.name<<" ; 数据点数 : "<<nowList.maxTurn<<" ; ";
			cout<<"时限 : "<<nowList.maxTime<<" ; 最大分数 : "<<nowList.maxScore<<endl;
			InputTestSpace::AddTest(nowList.name,nowList.maxScore,nowList.maxTime,nowList.maxScore);
		}
	}
	return ;
}
inline void SubmitName(string& str){
	if(str.empty())return ;
	judgeName = str;
	str = "";
	return ;
}
inline void SubmitTimes(string& str){
	if(str.empty())return ;
	istringstream iss(str);
	iss>>judgeTimes;
	str = "";
	return ;
}
struct Test{
	UIptrp info;//题目相关的信息对应的UIptr
	string name;
	int maxTurn,nowScore,maxScore;
	inline void Update(int _score){
		nowScore = _score;
		auto text = info->TextP();
		text->content = ToString(name,"  数据点数:",maxTurn," 分数:",nowScore,"/",maxScore);
		if(nowScore == maxScore){
			text->maincolor = GREEN;
		}else{
			text->maincolor = RED;
		}
		return ;
	}
	Test(UIptrp _info,string _name,int _maxTurn,int _score,int _maxscore){
		info = _info,nowScore = _score,maxScore = _maxscore;
		name = _name,maxTurn = _maxTurn;
		return ;
	}
	//看上去很诡异很不合理,原因是煞笔vector会调用析构函数......吗?
	//感觉这个地方好像有错耶
	~Test(){
		//info = nullptr;//不要删,调用后自行处理
		return ;
	}
};
//题目的id计数器,修改题目总数后记得清空,因为它和在testsInfo里的位置有关!
int tidCnt;
vector<Test> testsInfo;
namespace InputTestSpace{
	const int TestSpace = 50;
	UIptrManager InputTestUI;
	UIptrp inputButton,OKbutton,deleteButton;
	int useLessCnt;
	void StartJudge(){
		UIptr background = new DrawFunction({340,15},120,50,drawrect);
		UIptr showinfo = NewText(20,350,450,"正在评测中");
		auto text = Textp(UIp(showinfo));
		background.SetPriority(150);
		text->center = true;
		//延迟删除UI,现在不能删,不然调用过程中会释放函数的内存  UIevent();
		ReDraw();//但是删除的UI都被设置为了非激活隐藏模式,可以刷新一下
		int totMaxScore = 0,totScore = 0;
		for(auto now : waiting){
			JudgeResult result = Judge(now.name,1,now.maxTurn,now.maxTime);
			cout<<"现在正在评测 "<<now.name<<",数据点数"<<now.maxTurn<<",时限"<<now.maxTime<<endl;
			assert(result.Sum() != 0);
			int score = result.ac * now.maxScore / result.Sum();
			totMaxScore += now.maxScore,totScore += score;
			testsInfo[now.tid-1].Update(score);
		}
		return ;
	}
	inline void AddTest(const string& name,int maxTurn,int maxTime,int maxScore){
		WaitingList nowList;
		nowList.name = name,nowList.maxTurn = maxTurn;
		nowList.maxTime = maxTime,nowList.maxScore = maxScore;
		nowList.tid = ++tidCnt;
		waiting.push_back(nowList);
		cout<<"添加了题目 : \""<<nowList.name<<"\",数据点数 : \""<<nowList.maxTurn<<"\""<<endl;
		UIptrp newINFO = NewTextP(40 + TestSpace * waiting.size(),200,600,"等待填充");
		(Textp(UIp(*newINFO)))->center = true;
		newINFO->SetPriority(200);//优先级很低
		mainUI += newINFO;
		testsInfo.emplace_back(newINFO,nowList.name,nowList.maxTurn,0,nowList.maxScore);
		testsInfo.back().Update(0);
		return ;
	}
	void SubmitTest(){
		if(judgeTimes == 0)return ;
		AddTest(judgeName,judgeTimes,1000,100);
		judgeName = "",judgeTimes = 0;
		InputTestUI.Clear();
		inputButton->Display(true);
		OKbutton->Display(true);
		deleteButton->Display(true);
		UIptrActivePool.push_back(inputButton),UIptrActivePool.push_back(OKbutton),UIptrActivePool.push_back(deleteButton);
		return ;
	}
	inline void InputTest(){
		inputButton->Display(false),inputButton->Active(false);
		OKbutton->Display(false),OKbutton->Active(false);
		deleteButton->Display(false),deleteButton->Active(false);
		UIptrp background = new UIptr(new DrawFunction({10,5},320,395,drawrect));
		UIptrp pass1 = new UIptr(NewText(20,15,300,"请在下面分别输入题号和评测次数"));
		UIptrp inputbox_name = new UIptr(new Inputbox({20,110},300,35,SubmitName,"请输入名字",false));
		UIptrp inputbox_times = new UIptr(new Inputbox({20,210},300,35,SubmitTimes,"请输入评测次数",false));
		UIptrp AddTestbutton = new UIptr(new Button({20,310},80,60,SubmitTest,"确认添加题目"));
		InputTestUI += pass1,InputTestUI += inputbox_name,InputTestUI += inputbox_times,InputTestUI += AddTestbutton,InputTestUI += background;
		auto BPtestButton = (Buttonp)(UIp(*AddTestbutton));
		background->SetPriority(120);
		//使用Link以后不需要Lastsubmit了
		BPtestButton->Link(UIp(*inputbox_name)),BPtestButton->Link(UIp(*inputbox_times));
		return ;
	}
	inline void DeleteTests(){
		for(auto i : testsInfo){
			delete i.info;
		}
		testsInfo.clear();
		waiting.clear();
		tidCnt = 0;
		return ;
	}
	inline void InitButton(){
		inputButton = new UIptr(new Button({20,310},100,80,InputTest,"添加题目"));
		OKbutton = new UIptr(new Button({20,410},100,80,StartJudge,"开始评测"));
		deleteButton = new UIptr(new Button({20,510},100,80,DeleteTests,"删除题目"));
		mainUI += OKbutton,mainUI += inputButton;
		return ;
	}
}

int main(){
	initgraph(screenX,screenY,INIT_RENDERMANUAL);
	setcaption(caption);
	setfont(24,9,"微软雅黑");
	Error::outputName = "PEOJ";//设置ERR流的默认名字
	SetErrorMode(SEM_NOGPFAULTERRORBOX);//不显示错误对话框,否则RE识别为TLE且有弹窗 
	Prepare();
	InputTestSpace::InitButton();
	
	for(;is_run();delay_fps(60)){
		ReDraw();
		UIUpdate();
	}
	return not(Akano loves pure__Elysia);
}
