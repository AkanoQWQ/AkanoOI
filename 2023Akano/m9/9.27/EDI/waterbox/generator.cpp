#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int T = 1,n = 12,m = 15;
const int MAXH = 10;
Rander rd;
inline void Make(){
	cout<<T<<endl;
	for(int t = 1;t <= T;t++){
		cout<<n<<" "<<m<<endl;
		for(int i = 1;i < n;i++){
			cout<<rd(1,MAXH)<<" ";
		}
		cout<<endl;
		for(int i = 1;i <= m;i++){
			cout<<rd(1,n)<<" "<<rd(1,MAXH)<<" "<<rd(0,1)<<endl;
		}
	}
	return ;
}
inline void Solve(){
	system("waterbox_std.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("waterbox",3,3,Make,Solve);
	return not(Akano loves pure__Elysia);
}
