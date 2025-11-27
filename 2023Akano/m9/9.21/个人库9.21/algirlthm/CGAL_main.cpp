#include<bits/stdc++.h>
#include<conio.h>
#include "AL/CGAL.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

bool endFlag = false;
Screen screen;
Canvas& canvas = screen.canvas;//引用出来,懒
vector<string> text = {"......","~CGAL ENGINE~"};
vector<string> nowdecisions;

int page = 1;
int decision = 1,maxdecision;
bool decided;

VirtualProgram vp;
string mode = "page";
inline void OutputOnScreen(string str){
	while(page != int(text.size())-1)Sleep(100);//等待至最后一个被读取 
	text.push_back(str);
	return ;
}
inline int DecisionOnScreen(vector<string> vec){
	while(page != int(text.size())-1)Sleep(100);//等待至最后一个被读取 
	decision = 1,decided = false,maxdecision = int(vec.size())-1;
	nowdecisions = vec;
	mode = "decision";
	while(decided == false){
		Sleep(100);
	}
	mode = "page";
	return decision;
}
inline void ControlEvent(){
	while(true){
		char ch = getch();
		if(ch == 'q'){
			endFlag = true;
		}
		if(mode == "page"){
			if(ch == 'a'){
				page--;
				page = max(page,1);
			}
			if(ch == 'd'){
				page++;
				page = min(page,int(text.size())-1);
			}
		}else if(mode == "decision"){
			if(ch == 'a'){
				decision--;
				decision = max(decision,1);
			}
			if(ch == 'd'){
				decision++;
				decision = min(decision,maxdecision);
			}
			if(int(ch) == 13){//回车 
				decided = true;
			}
		}
	}
	return ;
}
inline void ShowEvent(int ticks = 8){
	const int waitingTime = 1000 / ticks;
	while(true){
		canvas.Clear();
		canvas.DrawHorizontalLine(12,1,100);
		vector<string> cmds = Recognize(text[page],'[',']');
		if(!cmds.empty()){//应当只有一个参数 
			canvas.DrawImageCentral(vp.GetImage(cmds[0]),6,34);
		}
		
		canvas.WriteInline(DeletePair(text[page],'[',']'),13,1,68);
		canvas.WriteInline(to_string(page) + " / " + to_string(int(text.size())-1),11,1,68);
		canvas.WriteInline(to_string(decision) + " / " + to_string(maxdecision),10,1,68);
		if(mode == "decision"){
			int avg_dis = 60 / maxdecision;
			for(int i = 1;i <= maxdecision;i++){
				canvas.WriteInline(nowdecisions[i] + ((i == decision) ? "←" : ""),6,avg_dis * (i-1) + 2,avg_dis-2);
			}
		}
		Sleep(waitingTime);
	}
	return ;
}
inline void Init(){
	screen.Init();
	vp.OutputFunc = OutputOnScreen;
	vp.DecisionFunc = DecisionOnScreen;
	vp.ReadCMD("algirlthm/main.cgal");
	vp.Run();
	canvas.Reverse(50,200);
	canvas.Resize(20,70);
	thread Controller(ControlEvent);
	Controller.detach();
	thread Shower(ShowEvent,8);
	Shower.detach();
	
	return ;
}
int main(){
	Init();
	while(!endFlag){//阻挡程序 
		rand();//不加这个 rand 煞笔 O2 会把这个优化掉...... 
	}
	Error::OutputFile("CGAL");
	return not(Akano loves pure__Elysia);
}
