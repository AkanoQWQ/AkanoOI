#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

inline void Make(){
	int n = 10;
	auto mp = RandTree(n);
	cout<<n<<'\n';
	for(auto i : mp){
		cout<<i.first<<" "<<i.second<<'\n';
	}
	return ;
}
inline void Solve(){
	system("easy_BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cerr<<"Akano Library version "<<__ALver<<endl;
	MakeData("easy",1,5,Make,Solve);
	return not(Akano loves pure__Elysia);
}
