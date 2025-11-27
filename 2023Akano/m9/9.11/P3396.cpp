#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 150000 + 2006 + 1018 + 1108;
const int MAXSQRT = 404;
int n,q,blk,arr[MAXN],ans[MAXSQRT][MAXSQRT];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	blk = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		for(int j = 1;j <= blk;j++){
			ans[j][i % j] += arr[i]; 
		}
	}
	while(q--){
		char cmd;
		int x,y;
		cin>>cmd>>x>>y;
		if(cmd == 'A'){
			if(x <= blk){
				cout<<ans[x][y]<<'\n';
			}else{
				int now = 0;
				for(int i = y;i <= n;i += x){
					now += arr[i];
				}
				cout<<now<<'\n';
			}
		}else{
			for(int i = 1;i <= blk;i++){
				ans[i][x % i] += y - arr[x]; 
			}
			arr[x] = y;
		}
	}
	return not(Akano loves pure__Elysia);
}
