#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline void Make(){
	int n = 1e5,x = 1;
	cout<<n<<" "<<x<<endl;
	auto tr = RandTree(n);
	for(auto i : tr){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return ;
}
inline void Solve(){
	
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("CF1481F",1,10,Make,Solve);
	return not(Akano loves pure__Elysia);
}
