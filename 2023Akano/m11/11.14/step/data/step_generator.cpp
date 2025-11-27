#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int cnt = 0;
inline void Make(){
	cnt++;
	int delta = rd(1,50),n,k;
	if(cnt <= 2){
		n = 2e4 - delta;
		k = rd(1018,1108);
	}else if(cnt <= 5){
		n = 1e6 - delta;
		k = rd(1018000,1108000);
	}else{
		n = 2e7 - delta;
		k = rd(1e5,1e9);
	}
	cout<<n<<" "<<k<<endl;
	return ;
}
inline void Solve(){
	system("step_BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("step",1,20,Make,Solve);
	return not(Akano loves pure__Elysia);
}
