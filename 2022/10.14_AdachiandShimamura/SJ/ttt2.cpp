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
	char c[CANVAS_MAX_Y][CANVAS_MAX_X],cache[CANVAS_MAX_Y][CANVAS_MAX_X];
	int CanvasX,CanvasY;
	int showX,showY;
	void DrawImg(int id,int x,int y){
		for(int i = 0;i < pic[id].size();i++){
			for(int j = 0;j < pic[id][i].length();j++){
				if(pic[id][i][j] == '~'){
					if(this->c[y+i][x+j] == 0){
						this->c[y+i][x+j] = ' ';
					}
					continue;
				}
				this->c[y+i][x+j] = pic[id][i][j];
			}
		}
		return ;
	}
	void DrawImg(string name,int x,int y){
		for(int i = 1;i <= pictail;i++){
			if(picName[i] == name){
				DrawImg(i,x,y);
				return ;
			}
		}
		return ;
	}
	void DrawImgC(int id,int x,int y){
		for(int i = 0;i < pic[id].size();i++){
			for(int j = 0;j < pic[id][i].length();j++){
				if(pic[id][i][j] == '~'){
					if(this->cache[y+i][x+j] == 0){
						this->cache[y+i][x+j] = ' ';
					}
					continue;
				}
				this->cache[y+i][x+j] = pic[id][i][j];
			}
		}
		return ;
	}
	void DrawImgC(string name,int x,int y){
		for(int i = 1;i <= pictail;i++){
			if(picName[i] == name){
				DrawImgC(i,x,y);
				return ;
			}
		}
		return ;
	}
	void _INIT(){
		
		return ;
	}
	void Show(){
		system("cls");
		for(int i = 1;i <= min(CanvasY,showY);i++){
			string output = "";
			for(int j = 1;j <= min(CanvasX,showX);j++){
				if(cache[i][j] != 0){
					output += this->cache[i][j];
				}else if(c[i][j] != 0){
					output += this->c[i][j];
				}else{
					output += ' ';
				}
			}
			cout<<output;
			if(i != min(CanvasY,showY))putchar('\n');
		}
		memset(cache,0,sizeof(cache));
		return ;
	}
}canvas,background;
void modeset(short w,short h){
	const short short4 = 4;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {short(w+short4), short(h+short4)};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	return;
}
int WindowsX = 510,WindowsY = 160,FontX = 3,FontY = 5;
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
	modeset(WindowsX,WindowsY-1);
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
			}else if(ins == "SetName"){
				cin>>ins;
				picName[pictail] = ins;
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
	canvas.showX = WindowsX,canvas.showY = WindowsY-1;
	canvas._INIT();
	return ;
}

const int MX = 520;
const int MY = 180;
HANDLE hOutput, hOutBuf;
COORD coord = { 2519,1279 };
DWORD bytes = 0;
char data[MY][MX];

void WriteAntiFlash(){
	//system("pause");
    int i, j;
    for(int i = 0;i < MY;i++){
    	for(int j = 0;j < MX;j++){
    		data[i][j] = canvas.cache[i][j];
		}
	}
	data[1][1] = 'T';
    for (i = 0; i < MY; i++){
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutBuf, data[i], MX, coord, &bytes);
    }
    //WindowsINIT();
    SMALL_RECT rc = {1,1, MX, MY};
	SetConsoleWindowInfo(hOutBuf ,true ,&rc);
    SetConsoleActiveScreenBuffer(hOutBuf);
    Sleep(200);
    memset(data,0,sizeof(data));
    data[1][1] = 'V';
    for (i = 0; i < MY; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutput, data[i], MX, coord, &bytes);
    }
    SetConsoleActiveScreenBuffer(hOutput);
    Sleep(500);
}


int main(){//163
	hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);


	CanvasINIT();
	WindowsINIT();


	



	
	Files_read.push("main.cie");
	while(!Files_read.empty()){
		ReadFiles(Files_read.front());
		Files_read.pop();
	}
	cin.clear();
	
	freopen("CON","r",stdin);
	for(int i = 1;i <= 6;i++){
		
		canvas.DrawImgC("title1",0,0);
		canvas.DrawImgC("star"+to_string(7-i),400,30);
		//canvas.Show();
		WriteAntiFlash();
		Sleep(600);
	}
	return 0;
	while(1){
		n = getch();
		if(n >= '0' && n <= '9')canvas.DrawImgC(n-'0',0,0);
		canvas.Show();
	}
	return 0;
}
