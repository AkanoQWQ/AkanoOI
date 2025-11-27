#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
int cnt = 0;
Rander rd;
const int TOT = 200;
const int SUB1 = 160;
const int SUB2 = 180;
const int SUB3 = 200;
inline void Make(){
	++cnt;
	if(cnt <= SUB1){
		int t = 1,n = rd(60,80),m = rd(4,10);
		cout<<t<<endl;
		for(int turn = 1;turn <= t;turn++){
			cout<<n<<" "<<m<<endl;
			for(int i = 1;i <= m;i++){
				int l = rd(1,n),r = min(n,l + rd(2,5)),x = rd(1,3);
				cout<<l<<" "<<r<<" "<<x<<endl;
			}
		}
	}else if(cnt <= SUB2){
		int t = 10,n = 200,m = rd(5,20);
		cout<<t<<endl;
		for(int turn = 1;turn <= t;turn++){
			cout<<n<<" "<<m<<endl;
			for(int i = 1;i <= m;i++){
				int l = rd(1,n),r = rd(l,n),x = rd(1,3);
				cout<<l<<" "<<r<<" "<<x<<endl;
			}
		}
	}else{
		int t = 10,n = 200,m = 1e5;
		cout<<t<<endl;
		for(int turn = 1;turn <= t;turn++){
			cout<<n<<" "<<m<<endl;
			for(int i = 1;i <= m;i++){
				int l = rd(1,n),r = rd(l,n),x = rd(1,3);
				cout<<l<<" "<<r<<" "<<x<<endl;
			}
		}
	}
	return ;
}
inline void Solve(){
	if(cnt <= SUB1){
		system("solve2.exe");
	}else if(cnt <= SUB2){
		system("solve1.exe");
	}else{
		system("solve1.exe");
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("string",1,TOT,Make,Solve);
	return (Akano loves pure__Elysia);
}
