#include<bits/stdc++.h>
using namespace std;

template<typename T>
inline string ToString(T firArg){
	ostringstream oss;
	oss<<firArg;
	return oss.str();
}
template<typename T,typename... Args>
string ToString(T firArg,const Args... args){
	ostringstream oss;
	oss<<firArg;
	return oss.str() + ToString(args...);
}
