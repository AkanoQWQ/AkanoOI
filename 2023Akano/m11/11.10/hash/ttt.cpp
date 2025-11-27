#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

namespace SegmentfaultCatcher{
	jmp_buf jumpPos;
	int jumpTime;
	int RegisterSignal(int);
	inline void ExecuteAfterSegfault(int x){
		RegisterSignal(x);//需要重新注册一遍
		longjmp(jumpPos,++jumpTime);
		return ;
	}
	inline int RegisterSignal(int x){//为了不要讨厌的警告整这个x
		signal(SIGSEGV,ExecuteAfterSegfault);
		return x;
	}
	int regInt = RegisterSignal(0);
	inline void Segfault(){
		static char failch = 0;
		char* chp = nullptr;
		failch = failch + *chp;
		return ;
	}
};
#define SaveLoad() setjmp(SegmentfaultCatcher::jumpPos)
using SegmentfaultCatcher::Segfault;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	try{
		Segfault();
	}catch(char* v){
		cout<<v<<endl;
	}
	return not(Akano loves pure__Elysia);
}
