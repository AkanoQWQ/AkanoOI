#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXM = 8e5 + 1018 + 1108;
const int MOD = 1e9 + 7;
inline ll P(ll inx){
	inx %= MOD;
	return (inx * inx) % MOD;
}
struct Edge{
	int nxt,to;
	ll val;
}e[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
ll dis1[MAXN],dis2[MAXN],f1[MAXN],f2[MAXN];
ll n,m,s,t,maindis;
bool vis[MAXN];
inline ll Dij(int st,int ed,ll* dis,ll* f){
	priority_queue<pair<ll,int> > q;
	for(int i = 1;i <= n;i++){
		dis[i] = INF;
		vis[i] = false;
	}
	dis[st] = 0;
	f[st] = 1;
	q.push(make_pair(-dis[st],st));
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] == dis[u] + e[i].val){
				f[v] = (f[v] + f[u]) % MOD;
			}else if(dis[v] > dis[u] + e[i].val){
				f[v] = f[u];
				dis[v] = dis[u] + e[i].val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return dis[ed];
}
ll Solve1(int st,int ed){
	ll ret = P(f1[ed]);
	ll dec = 0;
	for(int i = 1;i <= n;i++){
		if(dis1[i] == dis2[i] && dis1[i] + dis2[i] == maindis){
			dec = (dec + P(f1[i] * f2[i])) % MOD;
		}
	}
	for(int i = 2;i <= cnt;i++){
		const int u = e[i^1].to,v = e[i].to;
		const bool cand = dis1[u] - e[i].val < dis2[v] && dis2[v] < dis1[u] + e[i].val;
		if(dis1[u] + e[i].val + dis2[v] == maindis && cand){
			dec = (dec + P(f1[u] * f2[v])) % MOD;
		}
	}
	ret = (((ret - dec) % MOD) + MOD) % MOD;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("ARC090C.in","r",stdin);
	cin>>n>>m>>s>>t;
	for(int i = 1;i <= m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	maindis = Dij(s,t,dis1,f1);
	maindis = Dij(t,s,dis2,f2);
	cout<<Solve1(s,t)<<endl;
	return 0;
}
