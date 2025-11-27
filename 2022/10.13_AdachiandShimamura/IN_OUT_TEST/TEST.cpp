#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
const int INF = 0x7fffffff;
const int CANVAS_MAX_X = 600;
const int CANVAS_MAX_Y = 200;
const bool AUTO_END_FILE_WHILE_READ_EMPTY = 1;//防止cie文件错误带来的卡死.警告:可能使得文件读入不全
string s;
int pictail = 0,nx = 0,Lpictail,Rpictail;
char n;
int status = 0;
int waitingTime = 1000;
vector<string> pic[1006];
string picName[1006];
class Canvas{
public:
	string c[CANVAS_MAX_Y];
	int CanvasX,CanvasY;
	int showX,showY;
	void DrawImg(int id,int x,int y){
		for(int i = 0;i < pic[id].size();i++){
			for(int j = 0;j < pic[id][i].length();j++){
				this->c[y+i][x+j] = pic[id][i][j];
				//cout<<y+i<<","<<x+j<<" "<<id<<" "<<i<<" "<<j<<endl;
			}
		}
		return ;
	}
	void _INIT(){
		for(int i = 1;i < CANVAS_MAX_Y-1;i++){
			for(int j = 1;j <= 100;j++)c[i] += "          ";
		}
		return ;
	}
	void Show(){
		system("cls");
		for(int i = 1;i <= CanvasY;i++){
			for(int j = 1;j <= CanvasX;j++){
				//printf("%c",this->c[i][j]);
				putchar(this->c[i][j]);
			}
			//printf("\n");
			putchar('\n');
		}
		return ;
	}
}canvas,background;
void modeset(short w,short h){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	return;
}
int WindowsX = 512,WindowsY = 161,FontX = 3,FontY = 5;
void WindowsINIT(){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi; //hello imX2G
	cfi.nFont = 0;
	cfi.dwFontSize.X = FontX;
	cfi.dwFontSize.Y = FontY;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consoleCurrentFont;
	GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
	HWND hwnd=GetForegroundWindow();
	MoveWindow(hwnd,1,1,WindowsX*FontX,WindowsY*FontY,TRUE); 
	modeset(WindowsX,WindowsY);
	return ;
}
queue<string> Files_read;
void ReadFiles(string FileName){
	cin.clear();
	string InputStatus = "Read";
	int zeronum = 0;
	freopen(FileName.c_str(),"r",stdin);
	while(1){
		string opt = "",ins = "";
		if(InputStatus == "Read")cin>>opt;
		if(InputStatus == "AddingPic"){
			getline(cin,ins);
			if(ins == "EndAddPic"){
				InputStatus = "Read";
				continue;
			}
			pic[pictail].push_back(ins);
		}//以上:输入区 
		if(opt == "AddPic"){
			InputStatus = "AddingPic";
			pictail++;
		}else if(opt == "EndAddPic"){
			InputStatus = "Read";
		}else if(opt == "End"){
			return ;
		}else if(opt == "OpenFile"){
			cin>>ins;
			Files_read.push(ins);
			InputStatus = "Read";
		}
		if(opt == "" && ins == ""){
			if(AUTO_END_FILE_WHILE_READ_EMPTY)zeronum++;
		}else{
			zeronum = 0;
		}
		if(zeronum >= 100 && AUTO_END_FILE_WHILE_READ_EMPTY){
			return ;
		}
	}
	return ;
}
void CanvasINIT(){
	canvas.CanvasX = 520,canvas.CanvasY = 180;
	canvas.showX = 510,canvas.showY = 160;
	canvas._INIT();
	return ;
}
int main(){//163
	CanvasINIT();
	WindowsINIT();
	Files_read.push("main.cie");
	while(!Files_read.empty()){
		ReadFiles(Files_read.front());
		Files_read.pop();
	}
	cin.clear();
	freopen("CON","r",stdin);
	while(1){
		n = getch();
		canvas.DrawImg(n-'0',0,0);
		canvas.Show();
	}
	return 0;
}
