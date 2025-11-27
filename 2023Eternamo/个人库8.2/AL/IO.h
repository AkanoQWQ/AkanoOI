#pragma once
#include<bits/stdc++.h>
#include<io.h> 
using namespace std;

//IO
namespace IO{
	const int oldstdout = dup(1);
	inline void Open(const string& name){
		freopen(name.c_str(),"r",stdin);
		cin.clear();
		return ;
	}
	inline void BackCon(){
		dup2(oldstdout,1);
		return ;
	}
	inline void Write(const string& name){
		freopen(name.c_str(),"w",stdout);
		if(name == "CON")BackCon();
		cout.clear();
		return ;
	}
}
