#pragma once
#include<bits/stdc++.h>
#include "IO.h"
#include "rander.h"
using namespace std;
const string fin = ".in";
const string fout = ".out";
inline void ShuffleEdge(vector<pair<int,int> >& edge,int n){//建立随机映射打乱点的编号,输入边集和点集大小 
	mt19937 newrng(randint());
	vector<int> vec;
	for(int i = 1;i <= n;i++){
		vec.push_back(i);
	}
	shuffle(vec.begin(),vec.end(),newrng);
	for(auto& e : edge){
		e.first = vec[e.first-1],e.second = vec[e.second-1];
	}
	return ;
}
inline vector<pair<int,int> > RandTree(int size){//获得随机树,输入树大小 
	vector<pair<int,int> > ret;
	Rander rd;
	for(int i = 2;i <= size;i++){
		ret.push_back(make_pair(i,rd(1,i-1)));
	}
	ShuffleEdge(ret,size);
	return ret;
}
inline vector<pair<int,int> > RandUndirectMap(int n,int m){//获得随机无向图,输入点集大小和边集大小 
	vector<pair<int,int> > ret;
	if(m > n * (n-1) / 2){
		cout<<"边的数量溢出!"<<endl;
		return ret;
	}
	if(m < n-1){
		cout<<"边的数量不足!"<<endl;
		return ret;
	}
	Rander rd;
	set<pair<int,int> > edge;
	for(int i = 2;i <= n;i++){
		edge.insert(make_pair(i-1,i));
		ret.push_back(make_pair(i-1,i));
	}
	m -= n-1;
	for(int i = 1;i <= m;i++){
		int x = rd(1,n),y = rd(1,n);
		if(x > y)swap(x,y);//x < y
		while(x == y || edge.find(make_pair(x,y)) != edge.end()){
			x = rd(1,n),y = rd(1,n);
		}
		edge.insert(make_pair(x,y));
		ret.push_back(make_pair(x,y));
	}
	ShuffleEdge(ret,n);
	return ret;
}
inline vector<pair<int,int> > RandDirectMap(int n,int m){//获得随机有向图,输入点集大小和边集大小 
	vector<pair<int,int> > ret;
	if(m > n * (n-1)){
		cout<<"边的数量溢出!"<<endl;
		return ret;
	}
	if(m < n-1){
		cout<<"边的数量不足!"<<endl;
		return ret;
	}
	Rander rd;
	set<pair<int,int> > edge;
	for(int i = 2;i <= n;i++){
		edge.insert(make_pair(i-1,i));
		ret.push_back(make_pair(i-1,i));
	}
	m -= n-1;
	for(int i = 1;i <= m;i++){
		int x = rd(1,n),y = rd(1,n);
		while(x == y || edge.find(make_pair(x,y)) != edge.end()){
			x = rd(1,n),y = rd(1,n);
		}
		edge.insert(make_pair(x,y));
		ret.push_back(make_pair(x,y));
	}
	ShuffleEdge(ret,n);
	return ret;
}
inline string RandString(int len){//获得由小写字母组成的随机字符串 
	Rander rd;
	return rd.RandStr(len,'a','z');
}
inline void MakeData(string name,int stRound,int edRound,void (*DataFunc)(),void (*StdFunc)()){//默认的生成数据的方式
    for(int i = stRound;i <= edRound;i++){
        IO::Write(name+to_string(i)+fin);
        DataFunc();
        IO::Open(name+to_string(i)+fin);
        IO::Write(name+to_string(i)+fout);
        StdFunc();
    }
    IO::Open("CON"),IO::Write("CON");
    return ;
}
