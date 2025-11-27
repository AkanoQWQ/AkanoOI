#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
inline void Make(){
	int T = 10,n = 1e4;
	cout<<T<<endl;
	for(int t = 1;t <= T;t++){
		cout<<n<<endl;
		for(int i = 1;i <= n;i++){
			cout<<rd(1,n)<<" ";
		}
		cout<<endl;
	}
	return ;
}
inline void Solve(){
	system("std.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("langue",1,5,Make,Solve);
	return not(Akano loves pure__Elysia);
}
