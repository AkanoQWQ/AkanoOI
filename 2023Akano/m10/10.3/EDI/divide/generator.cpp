#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 8,kol = 6;
Rander rd;
inline void Make(){
	cout<<1<<endl;
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,kol)<<" ";
	}
	cout<<endl;
	
	auto tr = RandTree(n);
	for(auto i : tr){
		cout<<i.first<<" "<<i.second<<endl;
	}
	
	return ;
}
inline void Solve(){
	system("divide.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("divide",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
