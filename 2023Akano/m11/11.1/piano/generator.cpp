#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 30,m = 6,k = 10;
Rander rd;
inline void Make(){
	cout<<n<<" "<<m<<" "<<k<<" "<<10181108<<endl;
	cout<<rd.RandStr(n,"abc")<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(10,100)<<" ";
	}
	cout<<endl;
	for(int i = 1;i <= m;i++){
		cout<<rd.RandStr(4,"abc")<<" "<<rd(10,100)<<" "<<rd(1,m)<<endl;
	}
	return ;
}
inline void Solve(){
	system("piano.exe");
	return ;
}
int main(){
	MakeData("piano",1,50,Make,Solve);
	return not(Akano loves pure__Elysia);
}
