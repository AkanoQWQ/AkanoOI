#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 80,m = 800,a = 5e3,b = 3;
const int MAXVAL = 10;
Rander rd;
void Make(){
	cout<<n<<" "<<m<<" "<<a<<" "<<b<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<rd(-MAXVAL,MAXVAL)<<" ";
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
	MakeData("matrix",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
