#pragma once
#include<bits/stdc++.h>
#include "basic.h"
using namespace std;
mt19937 __DEFAULT__MT19937(GetTime());
inline int randint(int l,int r){
	if(l > r)return 0;
	return (__DEFAULT__MT19937() % (r - l + 1)) + l;
}
inline int randint(){
	return __DEFAULT__MT19937() % INT_MAX;
}
struct Rander{
	mt19937 rng;
	int l,r;
	Rander(){//默认随机范围 0~INT_MAX 
		mt19937 newrng(GetTime());
		rng = newrng;
		l = 0,r = INT_MAX;
	}
	Rander(int _l,int _r){//传入数据范围 
		mt19937 newrng(GetTime());
		rng = newrng;
		l = _l,r = _r;
	}
	inline int Rand(){//获取该对象内部的数据范围内的一个随机数 
		return (rng() % (r - l + 1)) + l;
	}
	inline int Rand(int _l,int _r){//获取传参的数据范围内的一个随机数 
		return (rng() % (_r - _l + 1)) + _l;
	}
	inline char RandChar(char st,char ed){//获取st~ed范围内的随机字符 
		if(st > ed)swap(st,ed);
		return char((rng() % (ed - st + 1)) + st);
	}
	inline char RandChar(const string& charset){//获取charset字符集内的随机字符 
		const int now = charset.size();
		return charset[rng()%now];
	}
	inline string RandStr(int len,char st,char ed){//获取st~ed范围内的随机字符构成的字符串 
		if(st > ed)swap(st,ed);
		string ret = "";
		for(int i = 1;i <= len;i++){
			ret += RandChar(st,ed);
		}
		return ret;
	}
	inline string RandStr(int len,const string& charset){//获取charset字符集内的随机字符构成的字符串 
		string ret = "";
		for(int i = 1;i <= len;i++){
			ret += RandChar(charset);
		}
		return ret;
	}
	int operator()(){
		return Rand();
	}
	int operator()(int _l,int _r){
		return Rand(_l,_r);
	}
	inline void SetSeed(unsigned int __IN__SEED){//设置种子,注意_seed是关键词 
		mt19937 newrng(__IN__SEED);
		rng = newrng;
		return ;
	}
	inline void SetLR(int _l,int _r){
		l = _l,r = _r;
		return ;
	}
};
