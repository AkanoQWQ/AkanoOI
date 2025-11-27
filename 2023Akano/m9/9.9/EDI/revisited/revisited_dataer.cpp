#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXVAL = 1e6;
Rander rd;
int n,cnt;
inline void Make(){
	cnt++;
	if(cnt <= 5){
		n = 300;
		cout<<n<<endl;
		for(int i = 1;i <= n;i++){
			cout<<rd(1,MAXVAL)<<" ";
		}
		cout<<endl;
	}else if(cnt <= 10){
		n = 1000;
		cout<<n<<endl;
		for(int i = 1;i <= n;i++){
			cout<<rd(1,MAXVAL)<<" ";
		}
		cout<<endl;
	}else if(cnt <= 15){
		n = 1000;
		cout<<n<<endl;
		vector<int> otp;
		for(int i = 1;i <= n;i++){
			otp.push_back(rd(1,MAXVAL));
		}
		sort(otp.begin(),otp.end());
		for(auto i : otp)cout<<i<<" ";
		cout<<endl;
	}
	
	return ;
}
inline void Solve(){
	system("Solve.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("revisited",1,15,Make,Solve);
	return not(Akano loves pure__Elysia);
}

