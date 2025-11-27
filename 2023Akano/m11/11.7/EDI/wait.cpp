#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1e5 + 1018 + 1108;

bool _ST_;

int n,m,f[MAXN],g[MAXN];
bool vis[MAXN];
bool Sub1 = true,Sub2 = true;
inline bool BF(int u,int v,int lim){
	while(u != v && lim--){
		if(f[u] == u && g[v] == v)break;
		u = f[u],v = g[v];
	}
	return (u == v);
}
namespace Subtask1{
	int nxt[MAXN][62];
	inline void Solve(){
		for(int i = 1;i <= n;i++){
			nxt[i][0] = f[i];
		}
		for(int j = 1;j <= 60;j++){
			for(int i = 1;i <= n;i++){
				nxt[i][j] = nxt[nxt[i][j-1]][j-1];
			}
		}
		for(int nowt = 1,u,v;nowt <= m;nowt++){
			cin>>u>>v;
			if(nxt[u][60] == nxt[v][60]){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
		return ;
	}
}
namespace Subtask2{
	int vis1[MAXN],vis2[MAXN];
	inline bool Judge(int tid,int u,int v){
		int lim = n + 1;
		while(u != v && lim--){
			if(vis1[u] == tid && vis2[v] == tid)break;
			vis1[u] = tid,vis2[v] = tid;
			u = f[u],v = g[v];
		}
		return (u == v);
	}
	inline void Solve(){
		for(int nowt = 1,u,v;nowt <= m;nowt++){
			cin>>u>>v;
			if(Judge(nowt,u,v)){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
		return ;
	}
}
namespace Subtask3{
	inline void Solve(){
		for(int nowt = 1,u,v;nowt <= m;nowt++){
			cin>>u>>v;
			if(BF(u,v,n*n + 2)){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
		return ;
	}
}

bool _ED_;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("wait.in","r",stdin);
	freopen("wait.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>f[i];
		if(vis[f[i]])Sub2 = false;
		vis[f[i]] = true;
	}
	for(int i = 1;i <= n;i++)vis[i] = false;
	for(int i = 1;i <= n;i++){
		cin>>g[i];
		if(vis[g[i]])Sub2 = false;
		vis[g[i]] = true;
		if(f[i] != g[i])Sub1 = false;
	}
	if(Sub1){
		Subtask1::Solve();
	}else if(Sub2){
		Subtask2::Solve();
	}else{
		Subtask3::Solve();
	}
	return not(Akano loves pure__Elysia);
}
