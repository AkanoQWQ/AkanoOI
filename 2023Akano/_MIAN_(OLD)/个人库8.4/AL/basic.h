#pragma once
#include<bits/stdc++.h>
using namespace std;

//基础函数 
inline int GetTime(){//获取毫秒级时间戳 
    auto c_time=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    return c_time.count();
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

