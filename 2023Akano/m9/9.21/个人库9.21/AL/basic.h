#pragma once
#include<chrono>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
#include<windows.h>
using namespace std;

//基础函数 
int _TIME_BASE; 
inline int GetTime(){//获取毫秒级时间戳 并多次使用会返回不同的值 
	_TIME_BASE = (_TIME_BASE + 27);
    auto c_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    return c_time.count() + _TIME_BASE;
}
inline string GetClock(){//返回世界时间,年月日时分秒的格式,字符串类型 
	auto timeStamp = chrono::system_clock::now().time_since_epoch();
	long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeStamp).count();
	std::time_t current_time = milliseconds / 1000;
    std::tm* local_time = std::localtime(&current_time);
	string ret;
	ret += to_string(local_time->tm_year + 1900) + "-"; 
	ret += to_string(local_time->tm_mon + 1) + "-";
	ret += to_string(local_time->tm_mday) + " ";
	ret += to_string(local_time->tm_hour) + ":";
	ret += to_string(local_time->tm_min) + ":";
	ret += to_string(local_time->tm_sec);
	return ret;
}
//获取数组长度 貌似有问题?考虑string数组.已被废弃 
//inline int GetLength(auto _in[]){
//	return sizeof(_in) / sizeof(_in[0]);
//}
inline string TransToString(int _in){//统一转换至string类型 
	return to_string(_in);
}
inline string TransToString(string _in){//统一转换至string类型 
	return _in;
}
inline void FilterateEnd(string& str){//过滤行末空格和换行 
	while(str.back() == '\n' || str.back() == ' ')str.pop_back();
	return  ;
}
inline vector<int> GetPermutation(int n){//获得长度为n的由1~n的排列 
	vector<int> ret;
	for(int i = 1;i <= n;i++)ret.push_back(i);
	return ret;
}
inline string Depath(string str){//消除相对路径 
	reverse(str.begin(),str.end());
	string ret;
	for(auto i : str){
		if(i == '\\' || i == '/'){
			break;
		}
		ret += i;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
inline void Kill(const string& name,int killTime){//在一段时间后杀死程序 
	const string command = "taskkill /f /im "+name+" 1>nul 2>nul";
	Sleep(killTime);
	system(command.c_str());
	return ;
}
inline string MakeCPP(string preinclude,string pre,string inmain){//返回一个cpp格式的字符串,传参include,main前 
	string ret = "#include<bits/stdc++.h>\n";
	ret += preinclude;
	ret += "using namespace std;\n";
	ret += pre;
	ret += "int main(){\n";
	ret += inmain;
	ret += "	return 0;\n";
	ret += "}";
	return ret;
}
inline char ToLower(char ch){
	if('A' <= ch && ch <= 'Z'){
		ch = ch - ('A' - 'a');
	}
	return ch;
}
inline string ToLower(string str){
	string ret;
	for(auto i : str)ret += ToLower(i);
	return ret;
}
inline void SetColor(string color){
	color = ToLower(color);
	if(color == "black")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	if(color == "darkblue")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	if(color == "green")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	if(color == "lakeblue")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	if(color == "red")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	if(color == "purple")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	if(color == "yellow")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	if(color == "white")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	if(color == "gray")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
	if(color == "blue")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	if(color == "lightgreen")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	if(color == "lightblue")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	if(color == "lightred")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	if(color == "lightpurple")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	if(color == "lightyellow")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(color == "lightwhite")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	return ; 
}
inline string Bit(int x){
	string ret;
	while(x){
		ret += char('0' + (x&1));
		x >>= 1;
	}
	return ret;
}
inline string Bit(int x,int len){
	string ret;
	for(int i = 1;i <= len;i++){
		ret += char('0' + (x&1));
		x >>= 1;
	}
	return ret;
}
void SetFontConsolas(int inSize){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = inSize;//设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//字体粗细 FW_BOLD
	wcscpy(cfi.FaceName,L"Consolas"); //设置字体,必须是控制台已有的
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	return ;
}
void SetFontDefault(int inSize){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = inSize;//设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//字体粗细 FW_BOLD
	wcscpy(cfi.FaceName,L""); //设置字体,必须是控制台已有的
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	return ;
}
inline void BR(){
	cout<<"---------------------------------------------------------"<<endl;
	return ;
}
inline int GetMemory(bool* st,bool* ed){
	return (st - ed) / 1024 / 1024;
}
//字符串处理 
struct VectorReader{
	typedef vector<string>::iterator Itor;
	Itor it,ed;
	inline void Reset(vector<string>& vec){
		it = vec.begin(),ed = vec.end();
		return ;
	}
	inline string GetNext(){
		if(it == ed)return "";
		return *(it++); 
	}
	inline bool End(){
		return (it == ed);
	}
};
inline string IgnoreSpace(const string& str){
	string ret;
	for(auto i : str){
		if(i != ' ')ret += i;
	}
	return ret;
}
inline vector<string> Split(const string& str){
	string now;
	vector<string> ret;
	for(auto i : str){
		if(i == ' ' || i == '	'){
			if(!now.empty())ret.push_back(now);
			now = "";
		}else{
			now += i;
		}
	}
	if(!now.empty())ret.push_back(now);
	return ret;
}
inline int str2int(const string& str){
	int ret = 0;
	for(auto i : str){
		ret = ret * 10 + i - '0';
	}
	return ret;
}
inline bool AllSpace(const string& str){
	for(auto i : str)if(i != ' ')return false;
	return true;
}
inline vector<string> Recognize(const string& str,char st,char ed){
	vector<string> ret;
	stack<string,vector<string> > stk;
	for(auto i : str){
		if(i == st){
			stk.push("");
		}else if(i == ed){
			if(!stk.empty()){//防止反括号过多 
				ret.push_back(stk.top());
				stk.pop();
			}
		}else{
			if(!stk.empty()){
				stk.top() += i;
			}
		}
	}
	return ret;
}
inline string DeletePair(const string& str,char st,char ed){
	int cnt = 0;
	string ret;
	for(auto i : str){
		if(i == st){
			cnt++;
		}else if(i == ed){
			cnt--;
			cnt = max(cnt,0);
		}else{
			if(cnt == 0){
				ret += i;
			}
		}
	}
	return ret;
}
