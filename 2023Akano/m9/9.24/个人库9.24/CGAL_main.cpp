//残缺无法使用的版本
#include<bits/stdc++.h>
#include<conio.h>
#include "AL/CGAL.h"
#include "AL/ExWindows.h"
#include "AL/error.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

bool endFlag = false;
Screen screen;
Canvas& canvas = screen.canvas;//引用出来,懒
vector<string> text = {"......","~CGAL ENGINE~"};
vector<string> nowdecisions;

Position canvasSize;
inline void GetCanvasSize(){
	canvasSize = GetWindowSize();
	canvasSize.x -= 4;//边框
	canvasSize.y -= 2;
	return ;
}

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
		
		GetCanvasSize();
		canvas.Resize(canvasSize.x - 1,canvasSize.y - 1);
		const int ShowSize = canvasSize.x * 2 / 3;
		
		canvas.Clear();
		canvas.DrawHorizontalLine(ShowSize-1,1,canvasSize.y);
		
		vector<string> cmds = Recognize(text[page],'[',']');
		if(!cmds.empty()){//应当只有一个参数 
			canvas.DrawImageCentral(vp.GetImage(cmds[0]),ShowSize / 2,canvasSize.y / 2);
		}
		
		canvas.WriteInline(DeletePair(text[page],'[',']'),ShowSize,1,canvasSize.y - 2);

		//for debug
		
		CONSOLE_SCREEN_BUFFER_INFOEX info1,info2;
		info1.cbSize = sizeof(info1);
		info2.cbSize = sizeof(info2);
		
		GetConsoleScreenBufferInfoEx(hOutBuf, &info1);
		GetConsoleScreenBufferInfoEx(hOutBuf, &info2);
		
		aerr<<info1.dwSize.X<<" and1 "<<info1.dwSize.Y<<enderr;
		aerr<<info2.dwSize.X<<" and2 "<<info2.dwSize.Y<<enderr;
		
		canvas.WriteInline(to_string(page) + " / " + to_string(int(text.size())-1),ShowSize-2,1,canvasSize.y - 2);
		canvas.WriteInline(to_string(decision) + " / " + to_string(maxdecision),ShowSize-3,1,canvasSize.y - 2);
		canvas.WriteInline(to_string(canvasSize.x) + " " + to_string(canvasSize.y),ShowSize-4,1,canvasSize.y - 2);
		
		if(mode == "decision"){
			int avg_dis = canvasSize.y / maxdecision;
			for(int i = 1;i <= maxdecision;i++){
				canvas.WriteInline(nowdecisions[i] + ((i == decision) ? "←" : ""),ShowSize / 2,avg_dis * (i-1) + 2,avg_dis-2);
			}
		}
		Sleep(waitingTime);
	}
	return ;
}
inline void Init(){
	Maximize();
	GetCanvasSize();
	canvas.Reverse(canvasSize.x * 2,canvasSize.y * 2);
	canvas.Resize(canvasSize.x - 1,canvasSize.y - 1);
	screen.Init();
	vp.OutputFunc = OutputOnScreen;
	vp.DecisionFunc = DecisionOnScreen;
	vp.ReadCMD("algirlthm/main.cgal");
	vp.Run();
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
