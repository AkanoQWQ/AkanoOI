#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 5e14;//¹»ÁËÂð? 
const int MAXN = 2e5 + 1018 + 1108;
const int MAXM = 1e6 + 1018 + 1108;
struct Edge{
	int nxt,to;
	ll val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,ll inval){
	e[++cnt].to = to;
	e[cnt].val = inval;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
ll maindis[2][MAXN];
bool vis[MAXN];
int n,m,q,l,r;
inline void Dij(int ST,ll* dis){
	priority_queue<pair<ll,int> > q;
	for(int i = 1;i <= n;i++){
		dis[i] = INF;
		vis[i] = false;
	}
	dis[ST] = 0;
	q.push(make_pair(-dis[ST],ST));
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("monogatari.in","r",stdin);
	freopen("monogatari.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1;i < m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	cin>>l>>r;
	Dij(1,maindis[0]);
	Dij(n,maindis[1]);
	while(q--){
		ll len;
		cin>>len;
		ll ans = min(maindis[0][n],min(maindis[0][l] + maindis[1][r],maindis[0][r] + maindis[1][l])+len);
		if(ans >= INF){
			cout<<"+Inf"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
4 3 1
1 2 7
1 3 4
2 3
9
*/
