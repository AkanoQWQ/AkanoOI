#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
#include "basic.h"//基本函数库
#include "IO.h"//IO库 
using namespace std;
//常值参数 
const string pre_file = ".\\__MAIN__\\";//文件执行目录,执行完自动删除
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
inline long long Execute(const string& name){//执行某一程序,返回它的返回值 
	long long result = system(name.c_str());
	if(result == 0){
		//the code runs correctly
	}else if(result == 1){
		cout<<name<<" didnt runs correctly.Return with value 1"<<endl; 
	}else if(result == -1073741819){
		result = 3221225477ll;
		cout<<name<<" access illegal memory.Return with value 3221225477"<<endl;
	}else if(result == -1073741571){
		result = 3221225725ll;
		cout<<name<<" leads to stack overflow.Return with value 3221225725"<<endl;
	}else if(result == -1073741676){
		result = 3221225620ll;
		cout<<name<<" try to divide zero.Return with value 3221225620"<<endl;
	}else{
		cout<<name<<" Return with undefined value "<<result<<endl;
	}
	return result;
}
inline long long Run(){//执行data,std,code三个exe 
	long long result = 0;
	IO::Write(pre_file + in_name);
	result |= Execute(pre_file + data_name);//data
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + out_name);
	result |= Execute(pre_file + code_name);//main
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + ans_name);
	result |= Execute(pre_file + std_name);//std
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
	for(int i = l;i <= r;i++){
		IO::Open(".\\" + name + ".\\" + name + to_string(i) + in_suffix);
		IO::Write(pre_file + name + to_string(i) + out_suffix);
		int startTime = clock();
		Execute(pre_file + code_name);
		int endTime = clock();
		if(endTime - startTime > TimeLimit){
			result.tle++;
			string ret = "Point " + to_string(i) + " : ";
			ret += "Use time " + to_string(endTime - startTime) + " ";
			ret += "Out of " + to_string(TimeLimit) + " ";
			ret += "Time Limit Exceeded";
			result.returnList.push_back(ret);
		}else{
			//ChangeIO
			const string out_file = pre_file + name + to_string(i) + out_suffix;
			const string ans_file = ".\\" + name + ".\\" + name + to_string(i) + ans_suffix;
			bool same = CompareFile(out_file,ans_file);
			if(!same){
				result.wa++;
				string ret = "Point " + to_string(i) + " : ";
				ret += "Use time " + to_string(endTime - startTime) + " ";
				ret += "Wrong Answer";
				result.returnList.push_back(ret);
			}else{
				result.ac++;
				string ret = "Point " + to_string(i) + " : ";
				ret += "Use time " + to_string(endTime - startTime) + " ";
				ret += "Accepted";
				result.returnList.push_back(ret);
			}
		}
	}
	IO::Open("CON");
	IO::Write("CON");
	return result;
}
