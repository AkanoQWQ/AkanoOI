#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 152;
constexpr int MAXLG = 56;
constexpr ll INF = 1e16 + 10181108;
ll n,t,Tk[MAXN],Ty[MAXN],h[MAXN][MAXN],g[MAXN][MAXN],maxw,ans;
ll trans[MAXN][MAXN],f[MAXN],nxt[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("kawaii/kawaii3.in","r",stdin);
	cin>>n>>t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			trans[i][j] = INF;
		}
		cin>>Tk[i]>>Ty[i];
		for(int j = 1;j <= Tk[i];j++){
			cin>>g[i][j];
		}
		for(int j = 1;j <= Tk[i];j++){
			cin>>h[i][j];
			trans[i][g[i][j]] = min(trans[i][g[i][j]],h[i][j] + Ty[i]);
		}
	}
	{
		for(int u = 1;u <= n;u++){
			for(int v = 1;v <= n;v++){
				cerr<<trans[u][v]<<" ";
			}
			cerr<<endl;
		}
	}
	for(int i = 0;i <= 3;i++){
		bool OK = false;
		if(i+1 >= 2 && __builtin_popcount(i+1) == 1){
			cerr<<i+1<<":";
		}
		for(int j = 1;j <= n;j++){
			f[j] = nxt[j];
			if(i+1 >= 2 && __builtin_popcount(i+1) == 1){
				cerr<<f[j]<<",";
			}
			
			if(f[j] <= t)OK = true;
			nxt[j] = INF;
		}
		if(i+1 >= 2 && __builtin_popcount(i+1) == 1){
			cerr<<endl;
		}
		if(OK == false){
			cout<<i-1<<endl;
			break;
		}
		for(int u = 1;u <= n;u++){
			for(int v = 1;v <= n;v++){
				nxt[v] = min(nxt[v],f[u] + trans[u][v]);
			}
		}
	}
	return not(Akano loves pure__Elysia);
}
//25805423172969
//
