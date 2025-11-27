#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
string compileOption = "-lm -O2 -std=c++14 -Wl,--stack=998244353 -Wall";
inline int GetTime(){
    auto c_time=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    return c_time.count();
}
inline int Open(string name,auto _in[]){
	int tail = 0;
	cin.clear();
	freopen(name.c_str(),"r",stdin);
	while(cin>>_in[++tail]);
	return tail-1;
}
inline int GetLength(auto _in[]){
	return sizeof(_in) / sizeof(_in[0]);
}
inline string TransToString(int _in){
	return to_string(_in);
}
inline string TransToString(string _in){
	return _in;
}
inline pair<int,vector<string> > Compare(auto _ouf[],auto _ans[],int comp_length){
	pair<int,vector<string> > ret;
	int len = min(GetLength(_ouf),GetLength(_ans));
	if(len < comp_length){
		cout<<"WARNING : Your compArray is too short!"<<endl;
	}
	comp_length = min(comp_length,len);
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
inline int Execute(string name){
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
inline void Compile(string Fname,string EXEname){
	const string str = "g++ "+Fname+".cpp -o __MAIN__/"+EXEname+".exe "+compileOption;
	system(str.c_str());
	return ;
}
inline void PreCompile(const string name){
	CreateDirectory("__MAIN__",NULL);
	Compile(name,"code");
	Compile(name+"_std","std");
	Compile(name+"_data","data");
	return ;
}
inline long long Execute(){
	long long result = 0;
	result |= Execute(".\\__MAIN__\\data.exe");//data
	result |= Execute(".\\__MAIN__\\code.exe");//main
	result |= Execute(".\\__MAIN__\\std.exe");//std
	return result;
}
inline void EXIT(){
//	RemoveDirectory("__MAIN__");
	return ;
}
inline int randint(int l,int r,mt19937& _mt){
	if(l > r)return 0;
	return (_mt() % (r - l + 1)) + l;
}
inline int randint(mt19937& _mt){
	return _mt() % INT_MAX;
}
struct Rander{
	mt19937 rng;
	int l,r;
	Rander(){
		mt19937 newrng(GetTime());
		rng = newrng;
		l = 0,r = INT_MAX;
	}
	Rander(unsigned int _inseed){//_seed is a key word
		mt19937 newrng(_inseed);
		rng = newrng;
		l = 0,r = INT_MAX;
	}
	Rander(int _l,int _r){
		mt19937 newrng(GetTime());
		rng = newrng;
		l = _l,r = _r;
	}
	Rander(unsigned int _inseed,int _l,int _r){
		mt19937 newrng(_inseed);
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
};
