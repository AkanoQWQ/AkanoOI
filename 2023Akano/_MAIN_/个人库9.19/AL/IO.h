#pragma once
#include<bits/stdc++.h>
#include<io.h> 
using namespace std;

//IO
namespace IO{
	const int oldstdout = dup(1);
	inline void Open(const string& name){//读取文件内容 
		cout<<flush;
		freopen(name.c_str(),"r",stdin);
		cin.clear();
		return ;
	}
	inline void BackCon(){//返回控制台时恢复stdout句柄防止出错 
		dup2(oldstdout,1);
		return ;
	}
	inline void Write(const string& name){//写入文件内容 
		cout<<flush;
		freopen(name.c_str(),"w",stdout);
		if(name == "CON")BackCon();
		cout.clear();
		return ;
	}
}
