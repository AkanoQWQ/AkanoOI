#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 10;
Rander rd;
inline void Make(){
	cout<<n<<endl;
	cout<<rd.RandStr(rd(6,8),"01")<<endl;
	cout<<rd.RandStr(rd(8,10),"01")<<endl;
	for(int i = 1;i <= n;i++){
		int k = rd(1,i);
		cout<<k<<" ";
		for(int j = 1;j <= k;j++){
			cout<<rd(0,i-1)<<" ";
		}
		cout<<rd.RandStr(rd(5,10),"01")<<endl;
	}
	return ;
}
inline void Solve(){
	system("string_std.exe");
	return ;
}
int main(){
	MakeData("string",1,200,Make,Solve);
	return not(Akano loves pure__Elysia);
}
