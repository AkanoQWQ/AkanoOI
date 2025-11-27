#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int n = 2000,w = 5000,val = 1e9;
int cnt = 0;
inline void Make(){
	cout<<n<<" "<<w<<" "<<val<<endl;
	cnt++;
	if(cnt <= 20){
		for(int i = 1;i <= n;i++){
			cout<<rd(1,n)<<" "<<rd(1,val)<<endl;
		}
	}else if(cnt <= 50){
		for(int i = 1;i <= n;i++){
			cout<<rd(1,10)<<" "<<rd(1,val/10)<<endl;
		}
	}else if(cnt <= 90){
		for(int i = 1;i <= n;i++){
			cout<<rd(1,30)<<" "<<rd(1,val/5)<<endl;
		}
	}else{
		for(int i = 1;i <= n;i++){
			cout<<n/10<<" "<<rd(1,val/15)<<endl;
		}
	}
	
	return ;
}
inline void Solve(){
	system("cactus_BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("cactus",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
