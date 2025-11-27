#include<bits/stdc++.h>
#include<graphics.h>
#include "UI.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline void ClearScreen(){
	setcolor(WHITE),setfillcolor(WHITE);
	bar(0,0,640,400);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	initgraph(640,400,INIT_RENDERMANUAL);
	setfont(24,9,"Console");
	UIptr text1 = new Text({20,5},100,100," ----");
	UIptr text2 = new Text({20,20},100,100,"  ----");
	text1.TextP()->wheelFixed = false;
	for(;is_run();delay_fps(60)){
		ClearScreen();
		UIUpdate(true);
		setcolor(BLACK),setfillcolor(BLACK);
		bar(10,21,20 + 17,60);
	}
	return not(Akano loves pure__Elysia);
}
