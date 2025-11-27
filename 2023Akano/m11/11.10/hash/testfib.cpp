#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

namespace SegmentfaultCatcher{
	jmp_buf jumpPos;
	int jumpTime,checkPoint;
	int RegisterSignal(int);
	inline void ExecuteAfterSegfault(int x){
		RegisterSignal(x);//需要重新注册一遍
		cerr<<"Oops!Segment fault,last checkpoint is "<<checkPoint<<endl;
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
#define UpdateLine SegmentfaultCatcher::checkPoint = __LINE__
using SegmentfaultCatcher::Segfault;
int a,b;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	srand(time(0));
	int cnt = SaveLoad();
	if(rand() % 2 == 0){Segfault();}UpdateLine;
	if(rand() % 2 == 0){Segfault();}UpdateLine;
	if(rand() % 2 == 0){Segfault();}UpdateLine;
	if(rand() % 3 == 0){Segfault();}UpdateLine;
	if(rand() % 3 == 0){Segfault();}UpdateLine;
	if(rand() % 3 == 0){Segfault();}UpdateLine;
	if(rand() % 4 == 0){Segfault();}UpdateLine;
	cin>>a>>b;
	cout<<a+b<<endl;
	cerr<<"achieve after"<<cnt<<endl;
	return not(Akano loves pure__Elysia);
}
