#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
const int subtask1Limit = 626;
int t,mod,k,q;
int belong[MAXN],nnt;
vector<int> e[MAXN];
bool vis[MAXN];
inline void BFS(int* dis,int ST){
	queue<int> que;
	que.push(ST),vis[ST] = true;
	while(!que.empty()){
		const int u = que.front();
		que.pop();
		for(auto v : e[u]){
			if(vis[v])continue;
			dis[v] = dis[u] + 1;
			que.push(v),vis[v] = true;
		}
	}
	return ;
}
namespace Subtask1{
	const int MAXB = 626;
	int maindis[MAXB][MAXB];
	inline void Solve(){
		for(int i = 1;i <= nnt;i++){
			e[i].clear();
		}
		for(int i = 0;i < mod;i++){
			if(belong[i] != belong[(i+1) % mod]){
				e[belong[i]].push_back(belong[(i+1) % mod]);
			}
		}
		for(int i = 1;i <= nnt;i++){
			memset(maindis[i],0,sizeof(maindis[i]));
			for(int j = 1;j <= nnt;j++){
				vis[j] = false;
			}
			BFS(maindis[i],i);
		}
		for(int i = 1;i <= q;i++){
			int u,v;
			cin>>u>>v;
			cout<<maindis[belong[u]][belong[v]]<<'\n';
		}
		return ;
	}
}
namespace Subtask2{
	int totdis[MAXN];
	inline void Solve(){
		for(int i = 1;i <= nnt;i++){
			e[i].clear();
		}
		for(int i = 0;i < mod;i++){
			e[belong[i]].push_back(belong[(i+1) % mod]);
		}
		memset(totdis,0,sizeof(totdis));
		for(int j = 1;j <= nnt;j++){
			vis[j] = false;
		}
		BFS(totdis,belong[0]);
		for(int i = 1;i <= q;i++){
			int u,v;
			cin>>u>>v;
			int ans = 1e9,pos = u;
			do{
				ans = min(ans,totdis[belong[(v - pos + mod) % mod]]);
				pos = (ll(pos) * k) % mod;
			}while(pos != u);
			cout<<ans<<'\n';
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>mod>>k>>q;
		if(k == 1){
			for(int i = 1;i <= q;i++){
				int u,v;
				cin>>u>>v;
				cout<<(u == v) - 1<<'\n';
			}
			continue;
		}
		nnt = 0;
		for(int u = 0;u < mod;u++){
			if(belong[u])continue;
			int pos = u;
			belong[u] = ++nnt;
			do{
				belong[pos] = belong[u];
				pos = (ll(pos) * k) % mod;
			}while(belong[pos] == 0);
		}
		if(nnt <= subtask1Limit){
			Subtask1::Solve();
		}else{
			Subtask2::Solve();
		}
	}
	return not(Akano loves pure__Elysia);
}
