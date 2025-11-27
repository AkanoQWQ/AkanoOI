#include<bits/stdc++.h>
#include "AL/datamaker.h"
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXA = 1e9;
int t = 0,n,q,m;
Rander rd;
inline void Make(){
	t++;
	if(1 <= t && t <= 1){
		n = 1018,q = 1108,m = 14;
	}else{
		n = 2e5 - rd(10,100),q = 2e5 - rd(10,100),m = rd(15,20);
	}
	cout<<n<<" "<<m<<'\n';
	for(int i = 1;i <= n;i++){
		cout<<rd(1,MAXA)<<" ";
	}
	cout<<'\n';
	cout<<q<<'\n';
	for(int i = 1;i <= q;i++){
		int poss = rd(1,10000),l,r;
		if(poss <= 5000){
			l = rd(1,n),r = rd(1,n);
		}else{
			l = rd(100,500),r = n - rd(5,200);
		}
		if(l > r)swap(l,r);
		cout<<l<<" "<<r<<'\n';
	}
	cout<<flush;
	return ;
}
inline void Solve(){
	system("std.exe");
	return ;
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("help",1,5,Make,Solve);
	return not(Akano loves pure__Elysia);
}
