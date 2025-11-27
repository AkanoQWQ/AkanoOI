#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 100006;
const int MAXM = 2000006;
struct Edge{
	int nxt,to,v;
}e[MAXM];
int ent = 1,head[MAXN];
void AddEdge(int from,int to,int v){
	e[++ent].to = to;
	e[ent].v = v;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,m,h[MAXN];
priority_queue<pair<int,int> > q;
int dis[MAXN],reachable = 0;
ll cost = 0;
bool vis[MAXN];
void Solve(){
	for(int i = 1;i <= n;i++)dis[i] = INF;
	dis[1] = 0;
	q.push(mp(0,1));
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		reachable++;
		cost += dis[u];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > e[i].v){
				dis[v] = e[i].v;
				q.push(mp(-dis[v],v));
			}
		}
	}
	return ;
}
int main(){
	freopen("ski.in","r",stdin);
	freopen("ski.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&h[i]);
	}
	while(m--){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		if(h[u] >= h[v]){
			AddEdge(u,v,k);
		}
		if(h[v] >= h[u]){
			AddEdge(v,u,k);
		}
	}
	Solve();
	printf("%d %lld",reachable,cost);
	return 0;
}
