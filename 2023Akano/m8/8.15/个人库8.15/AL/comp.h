#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
#include "basic.h"//基本函数库
#include "IO.h"//IO库 
#include "error.h"//报错库 
using namespace std;
//常值参数 
const string pre_file = ".\\__MAIN__\\";//文件执行目录,执行完自动删除
const string pre_file_instr = ".\\\\__MAIN__\\\\";
const string in_name = "data.in";
const string out_name = "code.out"; 
const string ans_name = "std.ans";
const string code_name = "code.exe";
const string std_name = "std.exe";
const string data_name = "data.exe";
const string out_suffix = ".out";
const string ans_suffix = ".ans";
const string in_suffix = ".in";
//可变参数 
string compileOption = "-lm -O2 -std=c++14 -Wl,--stack=998244353 -Wall";
//主要函数
//用于对拍的函数 
inline void Compile(string Fname,string EXEname){//编译文件 
	const string str = "g++ "+Fname+" -o "+EXEname+" "+compileOption;
	system(str.c_str());
	return ;
}
inline void PreCompile(const string name){//预先编译data,std,code三个exe 
	CreateDirectory(pre_file.c_str(),NULL);
	Compile(name+".cpp",pre_file + code_name);
	Compile(name+"_std.cpp",pre_file + std_name);
	Compile(name+"_data.cpp",pre_file + data_name);
	return ;
}
inline pair<long long,int> Execute(const string& name){//执行某一程序,返回它的返回值和用时的pair 
	int stc = clock();
	long long result = system(name.c_str());
	int edc = clock();
	if(result == 0){
		//the code runs correctly
	}else if(result == 1){
		string ret = name + " 未正确运行.Return with value 1.";
		ret += "注意,这可能是由于程序TLE被杀死导致的.";
		Error::PE("comp.h",ret);
	}else if(result == -1073741819){
		result = 3221225477ll;
		Error::PE("comp.h",name + " 访问非法内存.Return with value 3221225477");
	}else if(result == -1073741571){
		result = 3221225725ll;
		Error::PE("comp.h",name + " 导致栈溢出.Return with value 3221225725");
	}else if(result == -1073741676){
		result = 3221225620ll;
		Error::PE("comp.h",name + " 尝试除以0.Return with value 3221225620");
	}else{
		Error::PE("comp.h",name + " Return with undefined value " + to_string(result));
	}
	return make_pair(result,edc - stc);
}
string now_killname = "";
int now_killtime = -1;
inline void PreExecute(const string& name,int killtime){
	CreateDirectory(pre_file.c_str(),NULL);
	string exename = Depath(name);
	string command = "Kill(\""+exename+"\","+to_string(killtime)+");\n";
	string now = MakeCPP("#include<AL/main.h>\n","",command);
	IO::Write(pre_file+"kill.cpp");
	cout<<now<<endl;
	IO::Write("CON");
	Compile(pre_file+"kill.cpp",pre_file+"kill.exe");
	return ;
}
inline pair<long long,int> Execute(const string& name,int killtime){//执行某一程序,并超时终止
	if(now_killname != name || now_killtime != killtime){//返回它的返回值和用时的pair 
		now_killtime = killtime,now_killname = name;
		PreExecute(name,killtime);
		//因为新版本运行时间单独计算不会受kill影响,此段代码废弃 
//		string errinf = "在运行 "+name+" 的时候没有创建kill程序,";
//		errinf += "可能导致程序被识别为 TLE"; 
//		Error::PE("comp.h",errinf);
	}
	WinExec((pre_file+"kill.exe").c_str(),0);
	pair<long long,int> ret = Execute(name);
	system("taskkill /f /im kill.exe 1>nul 2>nul");
	return ret;
}
inline long long Run(){//执行data,std,code三个exe 
	long long result = 0;
	IO::Write(pre_file + in_name);
	result |= Execute(pre_file + data_name).first;//data
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + out_name);
	result |= Execute(pre_file + code_name).first;//main
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + ans_name);
	result |= Execute(pre_file + std_name).first;//std
	IO::Open("CON");
	IO::Write("CON");
	return result;
}
inline int FileIntoArray(string name,auto _in[]){//将文件内的内容写入数组中 
	int tail = 0;
	cin.clear();
	IO::Open(name);
	while(cin>>_in[++tail]);
	IO::Open("CON");
	return tail-1;
}
inline pair<int,vector<string> > Compare(auto _ouf[],auto _ans[],int comp_length){//比较两数组内容 
	pair<int,vector<string> > ret;
	//注:GetLength函数貌似有误,详情见basic.h
	//该段代码已废弃 
//	int len = min(GetLength(_ouf),GetLength(_ans));
//	if(len < comp_length){
//		cout<<"WARNING : Your compArray is too short!"<<endl;
//	}
//	comp_length = min(comp_length,len);
	for(int i = 0;i <= comp_length;i++){
		if(_ouf[i] != _ans[i]){
			++ret.first;
			string errInf = "In the "+TransToString(i);
			errInf += " element,read " + TransToString(_ouf[i]);
			errInf += " but expected "+ TransToString(_ans[i]);
			ret.second.push_back(errInf);
		}
	}
	return ret;
}
inline void Delete(){//删除data,std,code三个文件 
	DeleteFile((pre_file + code_name).c_str());
	DeleteFile((pre_file + std_name).c_str());
	DeleteFile((pre_file + data_name).c_str());
	DeleteFile((pre_file + in_name).c_str());
	DeleteFile((pre_file + out_name).c_str());
	DeleteFile((pre_file + ans_name).c_str());
	RemoveDirectory(pre_file.c_str());
	return ;
}

//用于评测的函数
struct JudgeResult{
	int ac,wa,tle;
	vector<string> returnList;
	inline int Sum(){
		return ac + wa + tle;
	}
	JudgeResult(){ac = wa = tle = 0;}
};
inline void JudgePreExecute(const string& name){
	CreateDirectory(pre_file.c_str(),NULL);
	Compile(name+".cpp",pre_file + code_name);
	return ;
}
inline bool CompareFile(const string& file1,const string& file2){//注意会改变IO 
	string content1,content2,cache;
	IO::Open(file1);
	while(getline(cin,cache)){
		content1 += cache + "\n"; 
	}
	FilterateEnd(content1);//过滤行末空格和换行 
	IO::Open(file2);
	while(getline(cin,cache)){
		content2 += cache + "\n"; 
	}
	FilterateEnd(content2);
	return content1 == content2;
}
inline JudgeResult Judge(const string& name,int l,int r,int TimeLimit){
	JudgeResult result;
	JudgePreExecute(name);
	PreExecute(pre_file + code_name,TimeLimit * 1.1);
	IO::Write(pre_file + name + to_string(l) + out_suffix);
	Execute(pre_file + code_name,TimeLimit * 1.1);//第一次执行会慢一点,提前执行一次 
	for(int i = l;i <= r;i++){
		IO::Open(".\\" + name + ".\\" + name + to_string(i) + in_suffix);
		IO::Write(pre_file + name + to_string(i) + out_suffix);
		int useTime = Execute(pre_file + code_name,TimeLimit * 1.1).second;
		if(useTime > TimeLimit){
			result.tle++;
			string ret = "Point " + to_string(i) + " : ";
			ret += "Use time " + to_string(useTime) + " ";
			ret += "Out of " + to_string(TimeLimit) + " ";
			ret += "Time Limit Exceeded";
			if(useTime >= TimeLimit * 1.1){
				ret += "(Killed)";
			}
			result.returnList.push_back(ret);
		}else{
			//ChangeIO
			const string out_file = pre_file + name + to_string(i) + out_suffix;
			const string ans_file = ".\\" + name + ".\\" + name + to_string(i) + ans_suffix;
			bool same = CompareFile(out_file,ans_file);
			if(!same){
				result.wa++;
				string ret = "Point " + to_string(i) + " : ";
				ret += "Use time " + to_string(useTime) + " ";
				ret += "Wrong Answer";
				result.returnList.push_back(ret);
			}else{
				result.ac++;
				string ret = "Point " + to_string(i) + " : ";
				ret += "Use time " + to_string(useTime) + " ";
				ret += "Accepted";
				result.returnList.push_back(ret);
			}
		}
	}
	IO::Open("CON");
	IO::Write("CON");
	return result;
}
