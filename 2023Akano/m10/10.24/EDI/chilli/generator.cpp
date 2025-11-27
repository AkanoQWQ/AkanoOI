#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
int n = 2e5;
inline void Make(){
	auto mp = RandTree(n);
	cout<<n<<endl;
	for(auto i : mp){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return ;
}
inline void Solve(){
	system("chilli_BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("chilli",1,1,Make,Solve);
	return not(Akano loves pure__Elysia);
}
