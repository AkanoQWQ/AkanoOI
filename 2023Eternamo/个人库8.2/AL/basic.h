#pragma once
#include<bits/stdc++.h>
using namespace std;

//»ù´¡º¯Êý 
inline int GetTime(){
    auto c_time=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    return c_time.count();
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
