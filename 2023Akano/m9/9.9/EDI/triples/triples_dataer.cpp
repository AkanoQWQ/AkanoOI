#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 5000;
Rander rd;
inline void Make(){
	if(true){
		cout<<n<<endl;
		for(int i = 2;i <= n;i++){
			cout<<1<<" "<<i<<endl;
		}
	}else{
		auto mp = RandTree(n);
		cout<<n<<endl;
		for(auto i : mp){
			cout<<i.first<<" "<<i.second<<endl;
		}
	}
	return ;
}
inline void Solve(){
//	system("Solve.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("triples",1,20,Make,Solve);	
	return not(Akano loves pure__Elysia);
}

