#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e4;
const int MAXVAL = 1e3;
Rander rd;
inline void Make(){
	cout<<MAXN<<'\n';
	for(int i = 1;i <= MAXN;i++){
		cout<<rd(1,MAXVAL)<<" ";
	}
	cout<<'\n';
	cout<<MAXN<<'\n';
	for(int i = 1;i <= MAXN;i++){
		int l = rd(1,MAXN),r = rd(1,MAXN);
		if(l > r)swap(l,r);
		cout<<l<<" "<<r<<'\n';
	}
	cout<<flush;
	return ;
}
inline void Solve(){
	
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("frog",1,3,Make,Solve);
	return not(Akano loves pure__Elysia);
}
