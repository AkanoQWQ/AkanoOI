#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int cnt,n,m;
inline void Make(){
	++cnt;
	if(cnt <= 1){
		n = rd(5,10),m = n;
	}else if(cnt <= 3){
		n = rd(10,20),m = n / 2;
	}else if(cnt <= 6){
		n = rd(512,1018),m = ceil(log2(n));
	}else if(cnt <= 10){
		n = rd(50000,92006),m = ceil(log2(n));
	}
	cout<<n<<" "<<m<<endl;
	return ;
}
inline void Solve(){
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("brokenbit",1,10,Make,Solve);
	return not(Akano loves pure__Elysia);
}
