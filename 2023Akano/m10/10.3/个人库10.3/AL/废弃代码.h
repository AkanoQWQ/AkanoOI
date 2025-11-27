/*
comp.h
inline void PreCompile(const string name){//预先编译data,std,code三个exe 
	CreateDirectory(pre_file.c_str(),NULL);
	Compile(name+".cpp",pre_file + code_name);
	Compile(name+"_std.cpp",pre_file + std_name);
	Compile(name+"_data.cpp",pre_file + data_name);
	return ;
}

comp.h
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

comp.h
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

comp.h
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

原 AOJ.cpp
//Akano Offline Judge Version 2023.8.15
//BASIC ON AL ver2023.8.15
//需要AL ver2023.8.15及以上 
//2023.8.15后放弃维护 
#include<bits/stdc++.h>
#include<AL/comp.h>//需要使用install.cmd安装AL 
using namespace std;
using pivs = pair<int,vector<string> >;
const int ArraySize = 6e6 + 6;//注意比较数组的大小,应该和答案输出的元素个数一致 
int T = 1000;
string ouf[ArraySize],ans[ArraySize];//默认使用string 
string main_name;
bool KEEP_FILE = false;
int main(){
	cin>>main_name>>T;
	PreCompile(main_name);
	for(int turn = 1;turn <= T;turn++){
		cout<<turn<<" CHECK"<<'\n';
		long long result = Run();
		if(result != 0){//Error
			KEEP_FILE = true;
			break;
		}
		int n1 = FileIntoArray(pre_file + out_name,ouf);
		int n2 = FileIntoArray(pre_file + ans_name,ans);
		if(n1 < n2){
			KEEP_FILE = true;
			cout<<"Answer too short"<<'\n';break;
		}
		if(n1 > n2){
			KEEP_FILE = true;
			cout<<"Answer too long"<<'\n';break;
		}
		pivs ret = Compare(ouf,ans,min(n1,n2));
		if(ret.first != 0 || !ret.second.empty()){
			KEEP_FILE = true;
			cout<<ret.first<<" WA in "<<min(n1,n2)<<endl;
			for(auto warn : ret.second){
				cout<<warn<<'\n';
			}
			break;
		}
	}
	if(KEEP_FILE == false)Delete();
	Error::OutputFile("AOJ_err");
	return 0;
}
//可能的BUG
//1.cmd提示你无法正确打开某个exe
//在任务管理器中检查该exe是否正常关闭,是否有一个不明所以的cmd.exe
//发现以上异常,结束对应进程 
//2.__MAIN__文件没有正常删除
//在任务管理器中检查code.exe , std.exe , data.exe 是否正常关闭,是否有一个不明所以的cmd.exe
//发现以上异常,结束对应进程 

原output.h
#pragma once
#include<bits/stdc++.h>
using namespace std;
struct MyOutput{
	
}out;
template<typename T>
MyOutput& operator<<(MyOutput& out,const vector<T>& vec){
	for(auto i : vec){
		cout<<i<<" ";
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,const set<T>& st){
	for(auto i : st){
		cout<<i<<" ";
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,priority_queue<T> q){
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,queue<T> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,stack<T> stk){
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return out;
}
template<typename T1,typename T2>
MyOutput& operator<<(MyOutput& out,const pair<T1,T2>& pr){
	cout<<pr.first<<" "<<pr.second;
	return out;
}
template<typename T>
MyOutput& operator<<(MyOutput& out,const T& content){
	cout<<content;
	return out;
}
*/
