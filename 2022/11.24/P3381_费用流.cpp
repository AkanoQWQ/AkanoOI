#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4 + 6;
const int MAXM = 2e5 + 6;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to,cap,cost;
}e[MAXM];
int head[MAXN],ent = 1;
void AddEdge(int from,int to,int cap,int cost){
	e[++ent].to = to;
	e[ent].cost = cost;
	e[ent].cap = cap;
	e[ent].nxt = head[from];
	head[from]= ent;
	return ;
}
void awa(int u,int v,int c,int c2){
	AddEdge(u,v,c,c2);
	AddEdge(v,u,0,-c2);
	return ;
}
int n,m,stp,edp,dis[MAXN],lst[MAXN],incf[MAXN];
queue<int> q;
bool inq[MAXN];
bool SPFA(int st,int ed){
	for(int i = 1;i <= n;i++){
		dis[i] = INF;
		incf[MAXN] = 0;
		lst[i] = 0;
	}
	dis[st] = 0,inq[st] = 1,incf[st] = INF;
	q.push(st);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(e[i].cap <= 0)continue;
			if(dis[v] > dis[u] + e[i].cost){
				dis[v] = dis[u] + e[i].cost;
				lst[v] = i^1;
				incf[v] = min(incf[u],e[i].cap);
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return (dis[ed] != INF);
}
pair<int,int> Dinic(int st,int ed){
	int ret_maxflow = 0,ret_mincost = 0;
	while(SPFA(st,ed)){
		ret_maxflow += incf[ed],ret_mincost += dis[ed] * incf[ed];
		int pos = ed;
		while(pos != st){
			e[lst[pos]].cap += incf[ed];
			e[lst[pos]^1].cap -= incf[ed];
			pos = e[lst[pos]].to;
		}
	}
	return make_pair(ret_maxflow,ret_mincost);
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&stp,&edp);
	for(int i = 1;i <= m;i++){
		int u,v,cap,cost;
		scanf("%lld%lld%lld%lld",&u,&v,&cap,&cost);
		awa(u,v,cap,cost); 
	}
	pair<int,int> maxflow_mincost = Dinic(stp,edp);
	printf("%lld %lld",maxflow_mincost.first,maxflow_mincost.second);
	return 0;
}
