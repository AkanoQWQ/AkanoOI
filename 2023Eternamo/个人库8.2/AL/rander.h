#pragma once
#include<bits/stdc++.h>
#include "basic.h"
using namespace std;
mt19937 __DEFAULT__MT19937;
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
	Rander(){
		mt19937 newrng(GetTime());
		rng = newrng;
		l = 0,r = INT_MAX;
	}
	Rander(int _l,int _r){
		mt19937 newrng(GetTime());
		rng = newrng;
		l = _l,r = _r;
	}
	int rd(){
		return (rng() % (r - l + 1)) + l;
	}
	int rd(int _l,int _r){
		return (rng() % (_r - _l + 1)) + _l;
	}
	int operator()(){
		return rd();
	}
	int operator()(int _l,int _r){
		return rd(_l,_r);
	}
	inline void SetSeed(unsigned int __IN__SEED){
		mt19937 newrng(__IN__SEED);
		rng = newrng;
		return ;
	}
};
