#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 206;
const int MAXM = 2e4 + 6;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to,cap;
}e[MAXM];
int head[MAXN],ent = 1;
void AddEdge(int from,int to,int cap){
	e[++ent].to = to;
	e[ent].cap = cap;
	e[ent].nxt = head[from];
	head[from]= ent;
	return ;
}
void awa(int u,int v,int c){
	AddEdge(u,v,c);
	AddEdge(v,u,0);
	return ;
}
int n,m,stp,edp,dep[MAXN],cur[MAXN];
queue<int> q;
bool bfs(int st,int ed){
	while(!q.empty())q.pop();
	for(int i = 1;i <= n;i++){
		dep[i] = 0;
	}
	dep[st] = 1;
	q.push(st);
	while(!q.empty()){
		const int u = q.front();
		cur[u] = head[u];
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dep[v] == 0 && e[i].cap > 0){
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return (dep[ed] > 0);	
}
int dfs_ed;
int dfs(int u,int val){
	if(u == dfs_ed || val == 0)return val;
	int ret = 0;
	for(int i = cur[u];i;i = e[i].nxt){
		cur[u] = i;
		const int v = e[i].to;
		if(e[i].cap <= 0 || dep[v] != dep[u] + 1)continue;
		const int push_to = min(e[i].cap,val);
		int actual_push = dfs(v,push_to);
		val -= actual_push;
		ret += actual_push;
		e[i].cap -= actual_push;
		e[i^1].cap += actual_push;
		if(actual_push == 0)dep[v] = -1;
		if(val == 0)break; 
	}
	return ret;
} 
int Dinic(int st,int ed){
	dfs_ed = ed;
	int ret = 0;
	while(bfs(st,ed)){
		ret += dfs(st,INF);
	}
	return ret;
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&stp,&edp);
	for(int i = 1;i <= m;i++){
		int u,v,cap;
		scanf("%lld%lld%lld",&u,&v,&cap);
		awa(u,v,cap); 
	}
	int maxflow = Dinic(stp,edp);
	printf("%lld",maxflow);
	return 0;
}
