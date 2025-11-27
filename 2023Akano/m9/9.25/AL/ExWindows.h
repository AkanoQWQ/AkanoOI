#pragma once
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
/*
你猜猜咱为什么要写这个头文件?
因为Windows自带的API是真的难用啊......
有时候还有BUG
所以手写二次封装了一下
*/
struct Position{//对应COORD 写起来好像还更难一点，但是易懂
	//x为行,y为列 对应一般的 arr[x][y]
	int x,y;
	Position() = default;
	Position(int _x,int _y){
		x = _x,y = _y;
		return ;
	}
	/*与 COORD 的转换*/
	Position(COORD _coord){
		x = _coord.Y,y = _coord.X;
		return ;
	}
	Position& operator=(COORD _coord){//对,它的X与Y是反过来的!X是列Y是行......
		x = _coord.Y,y = _coord.X;
		return *this;
	}
};
Position operator/(Position pos1,Position pos2){
	pos1.x /= pos2.x,pos1.y /= pos2.y;
	return pos1;
}
ostream& operator<<(ostream& os,Position pos){
	os<<"("<<pos.x<<","<<pos.y<<")";
	return os;
}
//以下为底层封装
//都是很基础的封装,没法直接用,还得二次封装
inline CONSOLE_SCREEN_BUFFER_INFOEX _GetScreenInfo(){
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX screenInfo;
	screenInfo.cbSize = sizeof(screenInfo);//就是说,为什么这么煞笔的东西不能写在Windows底层
	GetConsoleScreenBufferInfoEx(outputHandle,&screenInfo);
	return screenInfo;
}
//以下为高级封装,可以直接使用
inline Position GetBufferSize(){
	Position ret;
	auto screenInfo = _GetScreenInfo();
	ret = screenInfo.dwSize;
	return ret;
}
inline Position GetWindowSize(){
	Position ret;
	auto screenInfo = _GetScreenInfo();
	//这里的x,y其实也反过来了,不过体现的不是很明显
	ret.x = screenInfo.srWindow.Bottom - screenInfo.srWindow.Top + 1;//对,他这里少了1
	ret.y = screenInfo.srWindow.Right -screenInfo.srWindow.Left + 1;//也不知道是为什么
	return ret;
}
inline void SetBufferSize(int x,int y){//不被建议使用,可能在某些环境下失效
	COORD newSize = {short(y),short(x)};//反过来
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(outputHandle,newSize);
	return ;
}
inline void SetBufferSize(Position pos){
	SetBufferSize(pos.x,pos.y);
	return ;
}
inline void SetWindowSize(int x,int y){
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT newSize = {0,0};
	newSize.Right = y - 1;//反过来
	newSize.Bottom = x - 1;
	SetConsoleWindowInfo(outputHandle,1,&newSize);
	return ;
}
inline void SetWindowSize(Position pos){
	SetWindowSize(pos);
	return ;
}
inline void SetScreenSize(int x,int y){
	SetBufferSize(x,y);
	SetWindowSize(x,y);
	return ;
}
inline void SetScreenSize(Position pos){
	SetScreenSize(pos.x,pos.y);
	return ;
}
inline Position GetResolution(){//获得分辨率
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA,0,&rect,0);
	return Position(rect.bottom - rect.top,rect.right - rect.left);
}
inline Position GetFontSize(){
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO fontInfo;
	GetCurrentConsoleFont(outputHandle,true,&fontInfo);//第二个参数有点没看懂,可能要改
	COORD fontSize = GetConsoleFontSize(outputHandle,fontInfo.nFont);
	return Position(fontSize);
}
inline void Maximize(){//并不准确地最大化窗口
	Position pos = GetResolution() / GetFontSize();
	pos.x -= 3,pos.y -= 3;//留出边框空间,因此并不准确
	SetScreenSize(pos);
	return ;
}
