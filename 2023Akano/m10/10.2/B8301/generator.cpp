#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int n = 10,val = 20;
inline void Make(){
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,val)<<" ";
	}
	cout<<endl;
	return ;
}
inline void Solve(){
	system("BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("B8301",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
