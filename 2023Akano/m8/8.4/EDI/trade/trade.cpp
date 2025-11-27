#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = (1<<18) + 1018 + 1108;
const int MAXM = MAXN * 4;
const int MAXDEP = 21;
const int MOD = 998244353;
const ll INF = 1e14;
struct Edge{
	int nxt,to;
	ll val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,maxdep,dep[MAXN];
ll upper[MAXN],sz[MAXN],dis[MAXDEP][MAXN],f[MAXN][2],ans;
vector<int> son[MAXN];
bool vis[MAXN];
inline void Dij(int ST,ll nowdis[],ll predis[],ll nowupper,const vector<int>& inv){
	priority_queue<pair<ll,int> > q;
	for(auto i : inv){
		nowdis[i] = predis[i] + nowupper;
		vis[i] = false;
	}
	nowdis[ST] = 0;
	q.push(make_pair(-nowdis[ST],ST));
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(nowdis[v] > nowdis[u] + e[i].val){
				nowdis[v] = nowdis[u] + e[i].val;
				q.push(make_pair(-nowdis[v],v));
			}
		}
	}
	return ;
}
void predfs(int u){
	dep[u] = dep[u/2] + 1;
	sz[u] = 1;
	son[u].push_back(u);
	if(u*2+1 <= n){
		predfs(u*2),predfs(u*2+1);
		sz[u] += sz[u*2] + sz[u*2+1];
		f[u][1] = sz[u*2] * upper[u*2] + f[u*2][0] + f[u*2][1];
		f[u][0] = sz[u*2+1] * upper[u*2+1] + f[u*2+1][0] + f[u*2+1][1];
		for(auto i : son[u*2]){
			son[u].push_back(i);
		}
		for(auto i : son[u*2+1]){
			son[u].push_back(i);
		}
	}
	ans = (ans + ll(upper[u]) * (dep[u] - 1) * sz[u]) % MOD;
	return ;
}
void dfs(int u){
	Dij(u,dis[dep[u]],dis[dep[u]-1],upper[u],son[u]);
	bool nowl = (u == (u/2) * 2);
	for(int i = (u >> 1);i >= 1;i >>= 1){
		ll nowsize = sz[i*2] + 1;
		if(dis[dep[i]][u] >= INF)break;
		ans += (f[i][!nowl] + nowsize * dis[dep[i]][u]) % MOD;
		if(ans >= MOD)ans -= MOD;
		nowl = (i == ((i/2) * 2));
	}
	if(u*2+1 <= n){
		dfs(u*2),dfs(u*2+1);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("trade/data.in","r",stdin);
//	freopen("trade/trade1.out","w",stdout);
	cin>>n>>m;
	maxdep = n,n = (1<<n) - 1;
	for(int i = 2;i <= n;i++){
		cin>>upper[i];
		AddEdge(i,i/2,upper[i]);
	}
	for(int i = 1;i <= n;i++)dis[0][i] = INF;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w);
	}
	dep[1] = 1;
	predfs(1);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
