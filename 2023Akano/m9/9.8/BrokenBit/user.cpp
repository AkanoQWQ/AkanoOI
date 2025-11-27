#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Interactor<4096> inter;
int n,m,ans;
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	inter.ConnectTwoWay("BrokenBit");
	inter<<"Ask"<<Flush;
	inter>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i & (1<<(j-1))){
				inter<<"Add "<<j<<" "<<i<<Flush;
			}
		}
	}
	inter<<"Query"<<Flush;
	inter>>str;
	int cnt = 0;
	for(auto i : str){
		ans += (!(i - '0')) * (1<<cnt);
		cnt++;
	}
	inter<<ans<<Flush;
	return not(Akano loves pure__Elysia);
}
