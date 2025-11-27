#include<bits/stdc++.h>
#include<graphics.h>
#include "UI.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using Pos = Position;
inline void Event(string str){
	setfontbkcolor(RGB(255,255,255));
	setcolor(RGB(0,0,0));
	xyprintf(40,140,"Event %s",str.c_str());
	return ;
}
inline void CLS(){
	setcolor(RGB(255,255,255));
	setfillcolor(RGB(255,255,255));
	bar(0,0,600,480);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	initgraph(600,480);
	inputboxPool.insert(new Inputbox(Pos(50,40),Pos(100,70),Event));
	for(;is_run();delay_fps(60)){
		CLS();
		UIExecute();
		setfontbkcolor(RGB(255,255,255));
		setcolor(RGB(0,0,0));
	}
	return not(Akano loves pure__Elysia);
}
