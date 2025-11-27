#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXA = 1e5;
int n = 20,k = 7,q = 10;
Rander rd;
inline void Make(){
	cout<<n<<" "<<k<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,MAXA)<<" ";
	}
	cout<<endl;
	cout<<q<<endl;
	for(int i = 1;i <= q;i++){
		int l = rd(1,n),r = rd(1,n);
		if(l > r)swap(l,r);
		cout<<rd(1,n-1)<<" "<<l<<" "<<r<<endl;
	}
	return ;
}
inline void Solve(){
	system("B8463_std.exe");
	return ;
}
int main(){
	MakeData("B8463",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
