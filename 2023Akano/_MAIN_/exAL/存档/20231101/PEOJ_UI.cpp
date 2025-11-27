#include<bits/stdc++.h>
#include "UI.h"
#include "other.h"
#include<AL/comp.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

constexpr int screenX = 800;
constexpr int screenY = 640;
constexpr char* caption = (char*)"PEOJ UIversion!";

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
	int maxTurn,maxScore,maxTime;
	WaitingList() = default;
	WaitingList(string _name,int _t,int _mx,int _mt){
		name = _name,maxTurn = _t,maxScore = _mx,maxTime = _mt;
	}
};
vector<WaitingList> waiting;

struct SubmitName{
	void operator()(string& str){
		if(str.empty())return ;
		judgeName = str;
		str = "";
		return ;
	}
};
class SubmitTimes{
public:
	void operator()(string& str){
		if(str.empty())return ;
		istringstream iss(str);
		iss>>judgeTimes;
		str = "";
		return ;
	}
};
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
			waiting.push_back(nowList);
		}
	}
	return ;
}
namespace InputTestSpace{
	const int TestSpace = 50;
	UIptrManager InputTestUI;
	UIptrp inputButton;
	UIptrp OKbutton;
	int useLessCnt;
	void StartJudge(){
		mainUI.Clear();
		UIptr showinfo = NewText(20,10,300,"正在评测中");
		//延迟删除UI,现在不能删,不然调用过程中会释放函数的内存  UIevent();
		ReDraw();//但是删除的UI都被设置为了非激活隐藏模式,可以刷新一下
		int totMaxScore = 0,totScore = 0;
		ostringstream oss;
		for(auto now : waiting){
			JudgeResult result = Judge(now.name,1,now.maxTurn,now.maxTime);
			assert(result.Sum() != 0);
			int score = result.ac * now.maxScore / result.Sum();
			totMaxScore += now.maxScore,totScore += score;
			oss<<now.name<<" : "<<score<<"pts / "<<now.maxScore<<"pts"<<endl;
		}
		oss<<"总分数 : "<<totScore<<"pts / "<<totMaxScore<<"pts"<<endl;
		mainUI += NewTextP(20,10,300,oss.str());
		return ;
	}
	void SubmitTest(){
		if(judgeTimes == 0)return ;
		WaitingList nowList;
		nowList.name = judgeName,nowList.maxTurn = judgeTimes;
		nowList.maxTime = 1000,nowList.maxScore = 100;
		waiting.push_back(nowList);
		cout<<"添加了题目 : \""<<judgeName<<"\",数据点数 : \""<<judgeTimes<<"\""<<endl;
		judgeName = "",judgeTimes = 0;
		InputTestUI.Clear();
		inputButton->Display(true);
		OKbutton->Display(true);
		UIptrActivePool.push_back(inputButton),UIptrActivePool.push_back(OKbutton);
		mainUI += NewTextP(20 + TestSpace * waiting.size(),350,600,ToString(nowList.name,"  数据点数:",nowList.maxTurn));
		return ;
	}
	inline void InputTest(){
		inputButton->Display(false),inputButton->Active(false);
		OKbutton->Display(false),OKbutton->Active(false);
		UIptrp background = new UIptr(new DrawFunction({10,5},320,395,drawrect));
		UIptrp pass1 = new UIptr(NewText(20,15,300,"请在下面分别输入题号和评测次数"));
		UIptrp inputbox_name = new UIptr(new Inputbox({20,110},300,35,SubmitName(),"请输入名字",false));
		UIptrp inputbox_times = new UIptr(new Inputbox({20,210},300,35,SubmitTimes(),"请输入评测次数",false));
		UIptrp AddTestbutton = new UIptr(new Button({20,310},80,60,SubmitTest,"确认添加题目"));
		InputTestUI += pass1,InputTestUI += inputbox_name,InputTestUI += inputbox_times,InputTestUI += AddTestbutton,InputTestUI += background;
		auto BPtestButton = (Buttonp)(UIp(*AddTestbutton));
		background->SetPriority(120);
		//使用Link以后不需要Lastsubmit了
		BPtestButton->Link(UIp(*inputbox_name)),BPtestButton->Link(UIp(*inputbox_times));
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
	
	InputTestSpace::inputButton = new UIptr(new Button({20,310},80,60,InputTestSpace::InputTest,"添加题目"));
	InputTestSpace::OKbutton = new UIptr(new Button({20,410},80,60,InputTestSpace::StartJudge,"开始评测"));
	mainUI += InputTestSpace::OKbutton,mainUI += InputTestSpace::inputButton;
	
	for(;is_run();delay_fps(60)){
		ReDraw();
		MouseCheck();
		KeyboardCheck();
		UIevent();
	}
	return not(Akano loves pure__Elysia);
}
