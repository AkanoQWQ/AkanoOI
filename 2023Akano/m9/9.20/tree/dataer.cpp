#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 50,k = 2000,q = n*k;
Rander rd;
inline void Make(){
	cout<<n<<" "<<k<<" "<<q<<endl;
	auto mp = RandTree(n);
	for(auto i : mp)cout<<i.first<<" "<<i.second<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,k)<<" "<<rd(1,k)<<endl;
	}
	for(int i = 1;i <= q;i++){
		cout<<rd(1,n)<<" "<<rd(1,k)<<endl;	
	} 
	return ;
}
inline void Solve(){

	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("tree",1,1,Make,Solve);
	return not(Akano loves pure__Elysia);
}

