#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
inline void Make(){
	int n = 400;
	auto mp = RandTree(n);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,1e9)<<" ";
	}
	cout<<endl;
	for(auto i : mp){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return ;
}
inline void Solve(){
	
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("light",1,1,Make,Solve);
	return not(Akano loves pure__Elysia);
}
