#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
namespace Subtask2{
	int n = 8;
	inline void Make(){
		auto tr = RandTree(n);
		cout<<n<<" "<<n-1<<endl;
		for(auto i : tr){
			cout<<i.first<<" "<<i.second<<endl;
		}
		for(int i = 1;i <= n;i++){
			cout<<rd(1,n/2)<<" "<<rd(1,100)<<endl;
		}
		return ;
	}
}
inline void Solve(){
	system("travel_std.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("travel",1,20,Subtask2::Make,Solve);
	return not(Akano loves pure__Elysia);
}
