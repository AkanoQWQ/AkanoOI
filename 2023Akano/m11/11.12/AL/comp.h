#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
#include "basic.h"//基本函数库
#include "IO.h"//IO库 
#include "error.h"//报错库 
#include "DB.h"//数据库 
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
string compileOption = "-lm -O2 -std=c++14 -Wl,--stack=998244353";
string gcc;
//主要函数
//用于对拍的函数
inline bool TryGCC(const string& path){//尝试GCC是否可用
	const string command = path + " --help 1>nul 2>nul";
	int res = system(command.c_str());
	return (res == 0);
}
inline string FindGCC(){//尝试使用DB库里的GCC程序
	for(auto i : ADB::GCC_PATH){
		if(TryGCC(i))return i;
	}
	return "";
}
inline void SetGCC(const string& name){//设置默认的GCC程序
	gcc = name;
	return ;
}
inline void SetDefaultGCC(){//使用DB库里的GCC
	string res = FindGCC();
	if(res != "")gcc = res;
	return ;
}
inline bool CheckGCC(){//检查当前GCC是否可用
	return TryGCC(gcc);
}
inline bool Compile(string Fname,string EXEname){//编译文件,忽略错误信息 
	const string str = gcc + " "+Fname+" -o "+EXEname+" "+compileOption+" 1>nul 2>nul";
	int res = system(str.c_str());
	return (res == 0);
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
	cout<<flush;
	return make_pair(result,edc - stc);
}
inline void ExecuteThread(const string& name,pair<long long,int>& ret){
	ret = Execute(name);
	return ;
}
inline pair<long long,int> Execute(const string& name,int killtime){//执行某一程序,并超时终止
	constexpr pair<long long,int> defaultret = {20061018,20061108};
	pair<long long,int> ret = defaultret;
	thread exeThread(ExecuteThread,name,ref(ret));
	exeThread.detach();
	int stc = clock();
	while(ret == defaultret){
		if(clock() - stc > killtime){//记住,最后的程序名为 Depath 后的结果
			const string command = "taskkill /f /im \"" + Depath(name) + "\"" + " 1>nul 2>nul";
			system(command.c_str());
		}
	}
	return ret;
}
template<typename T>
inline int FileIntoArray(string name,T _in[]){//将文件内的内容写入数组中 
	int tail = 0;
	ifstream fin(name);
	while(fin>>_in[++tail]);
	return tail-1;
}
//用于评测的函数
struct JudgeResult{
	int ac,wa,tle,ce,re;
	vector<string> returnList;
	inline int Sum(){
		return ac + wa + tle + ce + re;
	}
	JudgeResult(){ac = wa = tle = ce = re = 0;}
};
inline bool JudgePreExecute(const string& name){//返回有没有编译成功 
	CreateDirectory(pre_file.c_str(),NULL);
	const string dir = pre_file + code_name;
	bool ret = Compile(name+".cpp",dir);
	return ret;
}
inline bool CompareFile(const string& file1,const string& file2){
	string content1,content2,cache;
	ifstream fin1(file1);//新版本使用ifstream
	while(getline(fin1,cache)){
		FilterateEnd(cache);//20231108 UPD : 过滤行末空格 
		content1 += cache + "\n"; 
	}
	FilterateEnd(content1);//过滤行末空格和换行 
	ifstream fin2(file2);
	while(getline(fin2,cache)){
		FilterateEnd(cache);//20231108 UPD : 过滤行末空格 
		content2 += cache + "\n"; 
	}
	FilterateEnd(content2);
	return content1 == content2;
}
inline JudgeResult Judge(const string& name,int l,int r,int TimeLimit){
	JudgeResult result;
	bool CompileResult = JudgePreExecute(name);
	if(CompileResult == false){
		if(r - l + 1 >= 0)result.ce = (r - l + 1);
		return result;
	}
	for(int i = l;i <= r;i++){
		const string in_path = ".\\" + name + "\\" + name + to_string(i) + in_suffix;
		if(_access(in_path.c_str(),00) == -1){
			Error::PE("comp.h","尝试访问 "+in_path+" 但是没有找到这个文件.是否数据根本没有此文件?");
			continue;
		}
		IO::Open(in_path);
		IO::Write(pre_file + name + to_string(i) + out_suffix);
		pair<long long,int> nowResult = Execute(pre_file + code_name,TimeLimit * 1.1);
		long long returnValue = nowResult.first;
		int useTime = nowResult.second;
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
		}else if(returnValue != 0){
			result.re++;
			string ret = "Point " + to_string(i) + " : ";
			ret += "Use time " + to_string(useTime) + " ";
			ret += "Out of " + to_string(TimeLimit) + " ";
			ret += "Runtime Error";
			result.returnList.push_back(ret);
		}else{
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
