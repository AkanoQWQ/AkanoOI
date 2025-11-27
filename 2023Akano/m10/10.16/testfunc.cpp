#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int (*pluss)(int,int);

int MyPlus(int a,int b){
	a += b;
	return a;
}
using vFp = void(*)();
using viFp = void(*)(int);
using iFp = int(*)();
using iiFp = int(*)(int);
using iiiFp = int(*)(int,int);
viFp test;
inline void Output(int x){
	cerr<<"TEST "<<x<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	test = Output;
	test(23);
	return not(Akano loves pure__Elysia);
}
