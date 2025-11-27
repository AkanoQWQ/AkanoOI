#include<bits/stdc++.h>
#include<conio.h>
#include "refresh.h"
#include "basic.h"
#include "error.h"
using namespace std;

//显示部分
inline int ReadInt(){
	int ret = 0;
	char ch = getch();
	while(!isdigit(ch))ch = getch();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getch();
	}
	return ret;
}
struct Image{
	int sizeX,sizeY;
	char** content;
	inline char NoEndlChar(istream& _istream){
		char ch = _istream.get();
		while(ch == '\n' && ch != EOF)ch = _istream.get();
		return ch;
	}
	inline void Delete(){
		for(int i = 0;i <= sizeX;i++)delete[] content[i];
		delete[] content;
		return ;
	}
	inline void Reverse(int _x,int _y){
		Delete();
		sizeX = _x,sizeY = _y;
		content = new char*[sizeX+1];
		for(int i = 1;i <= sizeX;i++){
			content[i] = new char[sizeY+1];
			memset(content[i],0,sizeof(char) * (sizeY+1));
		}
		return ;
	}
	inline void LoadFile(const string& name){
		ifstream fin(name.c_str());
		int _x = 0,_y = 0;//不初始化,没读进来就会出问题! 
		fin>>_x>>_y;
		Reverse(_x,_y);
		for(int i = 1;i <= sizeX;i++){
			for(int j = 1;j <= sizeY;j++){
				content[i][j] = NoEndlChar(fin);
			}
		}
		return ; 
	}
	inline void LoadString(int _x,int _y,const string& str){
		istringstream iss(str);
		Reverse(_x,_y);
		for(int i = 1;i <= sizeX;i++){
			for(int j = 1;j <= sizeY;j++){
				content[i][j] = NoEndlChar(iss);
			}
		}
		return ; 
	}
	inline void Show(){
		for(int i = 1;i <= sizeX;i++){
			for(int j = 1;j <= sizeY;j++){
				cout<<content[i][j];
			}
			cout<<endl;
		}
		return ;
	}
	char* operator[](int x){
		return content[x];
	}
	const char* operator[](int x)const {
		return content[x];
	}
	Image(){
		sizeX = sizeY = -1;
		content = nullptr;
		return ;
	}
};
class Canvas{
	private:
		char** content;
		inline void Delete(){
			for(int i = 0;i <= sizeX;i++)delete[] content[i];
			delete[] content;
			return ;
		}
		inline void BR(){
			for(int i = 1;i <= showY+2;i++)cout<<"-";
			cout<<'\n';
			return ;
		}
		inline bool IsASCII(char ch){
			return (int(ch) >= 0);//可以吗? 
		}
		inline void Output(char ch){
			if(int(ch) == 0){
				cout<<' ';
			}else{
				cout<<ch;
			}
			return ;
		}
		inline void Move(int& x,int& y){
			y++;
			if(y > sizeY){
				y = 1;
				x++;
			}
			return ;
		}
	public:
		int sizeX,sizeY;
		int showX,showY;
		int camX,camY;
		inline void Reverse(int _x,int _y){
			Delete();
			sizeX = _x,sizeY = _y;
			content = new char*[sizeX+1];
			for(int i = 1;i <= sizeX;i++){
				content[i] = new char[sizeY+1];
				memset(content[i],0,sizeof(char) * (sizeY+1));
			}
			return ;
		}
		inline void Resize(int _x,int _y){
			if(_x > sizeX || _y > sizeY)Reverse(_x,_y);
			showX = _x,showY = _y;
			return ;
		}
		inline void Show(){
			BR();
			for(int i = 1;i <= showX;i++){
				cout<<'|';
				int doubleCnt = 0;
				for(int j = showY;j >= 1;j--){
					if(IsASCII(content[i+camX-1][j+camY-1]))break;
					doubleCnt++;
				}
				for(int j = 1;j <= showY;j++){
					if(j == showY){//特判最后一个字符,只输出ASCII字符或者全角字符的后半部分 
						if(doubleCnt % 2 == 0){
							Output(content[i+camX-1][j+camY-1]);
						}else{//不完整的泉角字符 
							cout<<' ';
						}
					}else{
						Output(content[i+camX-1][j+camY-1]);
					}
				}
				cout<<'|'<<'\n';
			}
			BR();
			cout<<flush;
			return ;
		}
		inline bool SetCameraPosition(int x,int y){
			int edX = x + showX - 1,edY = y + showY - 1;
			if(edX > sizeX || edY > sizeY || x < 1 || x < 1)return false;
			camX = x,camY = y;
			return true;
		}
		inline bool DrawImage(const Image& img,int stX,int stY){
			int edX = camX + stX + img.sizeX - 2,edY = camY + stY + img.sizeY - 2;
			if(edX > sizeX || edY > sizeY || stX < 1 || stY < 1)return false;
			for(int x = 1;x <= img.sizeX;x++){
				for(int y = 1;y <= img.sizeY;y++){
					content[stX+x-1][stY+y-1] = img[x][y];
				}
			}
			return true;
		}
		inline bool DrawImageCentral(const Image& img,int x,int y){
			return DrawImage(img,x - img.sizeX / 2,y - img.sizeY / 2);
		}
		inline bool WriteBasic(const string& str,int x,int y){//基础写字,没有任何特判,写在一行中,如果写出去就换行至第一个字,可能会导致泉角错位 
			for(auto i : str){//极其不推荐使用 
				if(x > sizeX)return false;
				content[x][y] = i;
				Move(x,y);
			}
		}
		inline bool WriteInline(const string& str,int x,int y,int len){//在一定长度内写字,自行控制长度,越界返回false,每过len长度换行至原y长度 
			bool nowDouble = false;
			int nowlen = 0;
			for(auto i : str){
				nowlen++;
				if(nowlen > len){
					nowlen = 1,x++;
				}
				if(nowlen == len && IsASCII(i) == false && nowDouble == false){
					nowlen = 1,x++;
				}
				if(IsASCII(i) == false)nowDouble = !nowDouble;
				if(y + nowlen - 1 > sizeY)return false;
				content[x][y + nowlen - 1] = i;
			}
			return true;
		}
		inline bool DrawHorizontalLine(int x,int l,int r){//附近有泉角符号可能导致错位哦,暂时懒得解决 
			if(l < 0 || r > sizeY)return false;
			for(int i = l;i <= r;i++){
				content[x][i] = '-';
			}
			return true;
		}
		inline void Clear(){
			for(int x = 1;x <= sizeX;x++){
				for(int y = 1;y <= sizeY;y++){
					content[x][y] = 0;
				}
			}
			return ;
		}
		char* operator[](int x){
			return content[x];
		}
		const char* operator[](int x)const {
			return content[x];
		}
		Canvas(){
			sizeX = sizeY = -1;
			showX = 0,showY = 0;
			camX = camY = 1;
			content = nullptr;
			return ;
		}
};
class Screen{
	private:
		inline void ScreenShowEvent(int ticks = 8){
			const int waitingTime = 1000 / ticks;
			while(true){
				canvas.Show();
				Refresh();//先输出再Refresh!
				Sleep(waitingTime);
			}
			return ;
		}
		inline void PushThread(){
			thread screenShowThread(ScreenShowEvent,this,32);
			screenShowThread.detach();
			return ;
		}
	public:
		Canvas canvas;
		inline void Init(){
			RefreshInit();
			PushThread();//初始时启动线程
			return ;
		}
		Screen(){
			
			return ;
		}
};


//逻辑部分

class VirtualProgram{
	private:
		map<string,int> intPool;
		map<string,vector<string> > plot;
		map<string,vector<string> > code;
		map<string,Image> img;
		
		inline static void DefaultOutput(string str){
			cout<<str<<endl;
			return ;
		}
		inline static int DefaultInput(vector<string> strs){
			for(int i = 1;i <= int(strs.size());i++){
				cout<<i<<" : "<<strs[i-1]<<endl;
			}
			int ret = 0;
			cin>>ret;
			return ret;
		}
		inline void OutputPlot(const string& plotName){
			if(OutputFunc == nullptr){
				Error::PE("CGAL.h","没有输出函数,默认使用cout");
				OutputFunc = DefaultOutput; 
			}
			vector<string>& vec = plot[plotName];
			for(auto i : vec){
				OutputFunc(i);
			}
			return ;
		}
		void ExecuteCMD(const string& codeName){
			VectorReader reader;
			reader.Reset(code[codeName]);
			while(!reader.End()){
				string cmd = reader.GetNext();
				if(cmd == "SetInt"){
					string name = reader.GetNext();
					int val = str2int(reader.GetNext());
					intPool[name] = val;
				}else if(cmd == "PlusInt"){
					string name = reader.GetNext();
					int val = str2int(reader.GetNext());
					intPool[name] += val;
				}else if(cmd == "SetVar"){
					string name = reader.GetNext(),var = reader.GetNext();
					intPool[name] = intPool[var];
				}else if(cmd == "PlusVar"){
					string name = reader.GetNext(),var = reader.GetNext();
					intPool[name] += intPool[var];
				}else if(cmd == "./"){
					string name = reader.GetNext();
					ExecuteCMD(name);
				}else if(cmd == ".:"){
					string name = reader.GetNext();
					OutputPlot(name);
				}else if(cmd == "Decision"){ 
					int number = str2int(reader.GetNext());
					vector<string> vec;
					vec.push_back("NO_DATA");
					for(int i = 1;i <= number;i++){//传入的是plot名字,是为了可以直接使用getline
						string nowName = reader.GetNext(),now = "";
						for(auto content : plot[nowName])now += content + " ";
						vec.push_back(now);
					}
					vector<string> nextCMD(number+1);
					for(int i = 1;i <= number;i++){
						nextCMD[i] = reader.GetNext();
					}
					if(DecisionFunc == nullptr){
						Error::PE("CGAL.h","没有设置决策函数,默认使用cin");
						DecisionFunc = DefaultInput;
						continue;
					}
					int nextNum = DecisionFunc(vec);
					if(nextNum != 0)ExecuteCMD(nextCMD[nextNum]);
				}else if(cmd == "End"){
					break;
				}else{
					Error::PE("CGAL.h","读到了未识别的命令: "+cmd);
				}
			}
			return ;
		}
		inline void ReadImage(const string& name,const string& fname){
			img[name].LoadFile(fname);
			return ;
		}
	public:
		void (*OutputFunc)(string str);//输出函数 
		int (*DecisionFunc)(vector<string> content);//选择函数 
		inline void ReadCMD(const string& fname){
			ifstream fin(fname.c_str());
			string str;
			string now = "__uninitialized__";
			string mode = "__DEFAULT__";
			while(getline(fin,str)){
				if(str.empty())continue;
				//先判断模式的改变 
				string name = "";
				if(str[0] == ':'){
					for(int i = 1;i < int(str.length());i++){
						if(str[i] == ' ')break;
						name += str[i];
					}
					now = name;
					mode = "plot";
					continue;
				}
				if(str[0] == '/'){
					for(int i = 1;i < int(str.length());i++){
						if(str[i] == ' ')break;
						name += str[i];
					}
					now = name;
					mode = "cmd";
					continue; 
				}
				if(str[0] == '+'){//请注意这里的路劲是相对于主程序来说的相对路径! 
					for(int i = 1;i < int(str.length());i++){
						if(str[i] == ' ')break;
						name += str[i];
					}
					ReadCMD(name);
					continue;
				}
				if(IgnoreSpace(str) == "AddPic"){
					string nowfname;
					fin>>name>>nowfname;
					ReadImage(name,nowfname);
					continue;
				}
				if(mode == "plot"){
					if(!AllSpace(str))plot[now].push_back(str);	
				}
				if(mode == "cmd"){
					vector<string> ins = Split(str);
					for(auto i : ins)code[now].push_back(i);
				}
			}
			return ;
		}
		inline void Run(){
			thread runThread(ExecuteCMD,this,"main");
			runThread.detach();
			return ;
		}
		inline Image& GetImage(const string& name){
			return img[name];
		}
		inline vector<string> Debug_GetPlot(const string& str){
			return plot[str];
		}
		inline vector<string> Debug_GetPlotList(){
			vector<string> vec;
			for(auto i : plot)vec.push_back(i.first);
			return vec;
		}
}; 
