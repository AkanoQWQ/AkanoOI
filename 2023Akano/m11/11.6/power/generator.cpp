#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int t = 1e2;
inline void Make(){
	cout<<t<<endl;
	for(int i = 1;i <= t;i++){
		cout<<rd(1e3,1e4)<<" "<<rd(1e3,1e4)<<endl;
	}
	return ;
}
inline void Solve(){
	system("power_BF.exe");
	return ;
}
int main(){
	MakeData("power",1,10,Make,Solve);
	return not(Akano loves pure__Elysia);
}
