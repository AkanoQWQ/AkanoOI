#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline void Debug(const char* format,...){
	va_list argList;
	va_start(argList,format);
	for(;*format;format++){
		if(*format == '%'){
			format++;
			if(*format == 'd'){
				cout<<va_arg(argList,int);
			}else if(*format == 's'){
				cout<<va_arg(argList,char*);
			}
		}else{
			cout<<*format;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Debug("这是我的个人 format,它可以输出一个整数 : %d ,当然还有字符串 : %s",10181108,"\"this is a string\"");
	return not(Akano loves pure__Elysia);
}
