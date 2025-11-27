#pragma once
#include<bits/stdc++.h>
#include "IO.h"
#include "basic.h"
using namespace std;
namespace Error{
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
	inline void Output(){
		cout<<"一共有 "<<data.size()<<" 个错误"<<endl;
		for(auto err : data){
			cout<<"在 "<<err.position<<" 中,发生了如下错误:"<<endl;
			cout<<err.inf<<endl;
			cout<<"时间 : 世界时间 "<<err.worldTime<<" ,程序时间 "<<err.runningTime<<endl;
			cout<<"---------------------------------------------------------------"<<endl;
		}
		return ;
	}
	inline void OutputFile(const string& name){//注意改变IO 
		if(Empty())return ;
		IO::Write(name+".err");
		Output();
		IO::Write("CON");
		return ;
	}
	inline void OutputFile(){
		OutputFile("AL_error");
		return ;
	}
}
