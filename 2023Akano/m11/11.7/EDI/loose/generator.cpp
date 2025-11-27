#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int n = 1e6,m = 2;
inline void Make(){
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		if(rd(1,100) <= 5){
			cout<<rd(-1e8,-1e7)<<" ";
		}else{
			cout<<rd(-9e3,1e4)<<" ";
		}
	}
	cout<<endl;
	for(int i = 1;i <= m;i++){
		int k = rd(1018,1108);
		cout<<k<<endl;
		for(int j = 1;j <= k;j++){
			cout<<rd(1,n)<<" "<<rd(1,n)<<endl;
		}
	}
	return ;
}
inline void Solve(){
//	system("loose_BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("loose",5,7,Make,Solve);
	return not(Akano loves pure__Elysia);
}
