#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline void Make(){
	int n = 500,k = 500;
	cout<<n<<" "<<k<<endl;
	for(int i = 1;i <= k;i++){
		auto mp = RandTree(n);
		for(auto j : mp){
			cout<<j.first<<" "<<j.second<<endl;
		}
	}
	return ;
}
inline void Solve(){}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("trees",1,1,Make,Solve);
	return not(Akano loves pure__Elysia);
}
