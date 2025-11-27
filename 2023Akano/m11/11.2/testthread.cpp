#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline void func(){
	system("testfunc.exe");
	return ;
}
int a;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	thread thr(func);
	thr.detach();
	while(cin>>a){
		if(a == 0){
			_endthreadex(5);
		}else if(a == -1){
			break;
		}
	}
	return not(Akano loves pure__Elysia);
}
