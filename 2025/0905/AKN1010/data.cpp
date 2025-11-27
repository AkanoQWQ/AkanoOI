#include<bits/stdc++.h>
#include<AL/datamaker.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e6 + 1018 + 1108;
int fa[MAXN];
inline void Make(){
	int treesize = 5e6;
	auto treemap = RandTree(treesize);
	for(auto e : treemap){
		int smaller = min(e.first,e.second),bigger = max(e.first,e.second);
		fa[bigger] = smaller;
	}
	for(int i = 2;i <= treesize;i++){
		cout<<fa[i]<<'\n';
	}
	cout<<flush;
	return ;
}
inline void Solve(){
	system("sol.exe");
	return ;
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("chuangeroot",1,10,Make,Solve);
	return not(Akano loves pure__Elysia);
}
