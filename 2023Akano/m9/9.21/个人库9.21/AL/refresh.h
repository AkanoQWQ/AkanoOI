#pragma once
#include<Windows.h>
const int OPD_SIZE = 8000;
HANDLE hOutput,hOutBuf;
COORD coord={0,0};
char outPutData[OPD_SIZE];
DWORD bytes=0;

inline void RefreshInit(){
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//获取默认标准显示缓冲区句柄
	hOutBuf = CreateConsoleScreenBuffer(//创建新的缓冲区
        GENERIC_READ | GENERIC_WRITE, 
        FILE_SHARE_READ | FILE_SHARE_WRITE, 
        NULL, 
        CONSOLE_TEXTMODE_BUFFER, 
        NULL
    );
    //设置新的缓冲区为活动显示缓冲
    SetConsoleActiveScreenBuffer(hOutBuf);
    //隐藏两个缓冲区的光标
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible=0;
    cci.dwSize=1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
	return ;
}
inline void Refresh(){
	ReadConsoleOutputCharacterA(hOutput, outPutData, OPD_SIZE, coord, &bytes);
    WriteConsoleOutputCharacterA(hOutBuf, outPutData, OPD_SIZE, coord, &bytes);
    system("cls");
	return ;
}
