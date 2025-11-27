#pragma once
#include<bits/stdc++.h>
#include "IO.h"
#include "basic.h"
#include "DB.h"
using namespace std;
namespace Error{
	string outputName = "AL_error";
	struct AkanoErrorStream{
		string content;
	}aerr;
	struct AkanoErrorStreamEndFlag{
		
	}enderr;
	struct Data{
		string position,inf,worldTime;
		int runningTime;
	};
	vector<Data> data;
	inline void PushError(const string& pos,const string& inf){
		Data newdata;
		newdata.position = pos,newdata.inf = inf;
		newdata.runningTime = clock(),newdata.worldTime = GetClock();
		data.push_back(newdata);
		return ;
	}
	inline void PE(const string& pos,const string& inf){//简写别名 
		PushError(pos,inf);
	}
	inline bool Empty(){
		return data.empty();
	}
	inline void Clear(){
		data.clear();
		return ;
	}
	inline void Output(ostream& os){
		if(!aerr.content.empty()){
			PushError("AkanoErrorStream",aerr.content);
			aerr.content = "";
		}
		os<<"一共有 "<<data.size()<<" 个错误"<<endl;
		for(auto err : data){
			os<<"在 "<<err.position<<" 中,发生了如下错误:"<<endl;
			os<<err.inf<<endl;
			os<<"时间 : 世界时间 "<<err.worldTime<<" ,程序时间 "<<err.runningTime<<endl;
			os<<"---------------------------------------------------------------"<<endl;
		}
		return ;
	}
	inline void Output(){//默认cout
		Output(cout);
		return ;
	}
	//注意改变IO(旧版本提示)
	//新版本,使用 ofstream 是否可行?
	inline void OutputFile(const string& name){
		if(Empty())return ;
		ofstream ofs((name + ".err").c_str());
		Output(ofs);
		ofs.close();
		return ;
	}
	inline void OutputFile(){
		OutputFile(outputName);
		return ;
	}
	
	AkanoErrorStream& operator<<(AkanoErrorStream& aes,AkanoErrorStreamEndFlag _flag){
		PushError("AkanoErrorStream",aes.content);
		aes.content = "";
		return aes;
	}
	AkanoErrorStream& operator<<(AkanoErrorStream& aes,string content){
		aes.content += content;
		return aes;
	}
	AkanoErrorStream& operator<<(AkanoErrorStream& aes,const char* content){
		aes.content += content;
		return aes;
	}
	template<typename T>
	AkanoErrorStream& operator<<(AkanoErrorStream& aes,T content){
		aes.content += to_string(content);
		return aes;
	}
	
	void OutputFileAfterClose(){
		Error::OutputFile();
		return ;
	}
	
	inline int InitEventForError(){
		atexit(OutputFileAfterClose);
		return 10181108;
	}
	int __init__event__val = InitEventForError();
	
}
using Error::aerr;
using Error::enderr;
