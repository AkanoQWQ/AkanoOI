#pragma once
#include<bits/stdc++.h>
using namespace std;

//基础函数 
int _TIME_BASE; 
inline int GetTime(){//获取毫秒级时间戳 并多次使用会返回不同的值 
	_TIME_BASE = (_TIME_BASE + 27);
    auto c_time=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    return c_time.count() + _TIME_BASE;
}
inline int GetLength(auto _in[]){//获取数组长度 貌似有问题?考虑string数组 
	return sizeof(_in) / sizeof(_in[0]);
}
inline string TransToString(int _in){//统一转换至string类型 
	return to_string(_in);
}
inline string TransToString(string _in){//统一转换至string类型 
	return _in;
}
inline void FilterateEnd(string& str){//过滤行末空格和换行 
	while(str.back() == '\n' || str.back() == ' ')str.pop_back();
	return  ;
}
