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
