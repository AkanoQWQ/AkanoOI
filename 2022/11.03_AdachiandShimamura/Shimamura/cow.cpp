#include<bits/stdc++.h>
using namespace std;
const int MAXN = 606;
const int MAXM = 2*MAXN*MAXN + MAXN*6;
const int INF = 0x7fffffff;
int t,n,m,st,ed,ans;
int tot = 1,head[MAXN];
struct Edge{
	int to,nxt,v;
}e[MAXM];
void AddEdge(int from,int to,int v){
	e[++tot].to = to;
	e[tot].v = v;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
void awa(int from,int to,int v){
	AddEdge(from,to,v);
	AddEdge(to,from,0);
	return ;
}
queue<int> q;
int dep[MAXN],cur[MAXN];
bool bfs(){
	memset(dep,0,sizeof(dep));
	dep[st] = 1;
	while(!q.empty())q.pop();
	q.push(st);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dep[v] || e[i].v <= 0)continue;
			dep[v] =  dep[u] + 1;
			q.push(v);
		}
	}
	return dep[ed];
}
int dfs(int u,int val){
	if(u == ed || val == 0)return val;
	int ret = 0;
	int st_edge = cur[u];
	/*if(st_edge == 0)*/st_edge = head[u];
	for(int i = st_edge;i;i = e[i].nxt){
		cur[u] = i;
		const int v = e[i].to;
		if(e[i].v <= 0 || dep[v] != dep[u] + 1)continue;
		int addret = dfs(v,min(val,e[i].v));
		e[i].v -= addret;
		e[i^1].v += addret;
		ret += addret;
		val -= addret;
	}
	return ret;
}
int maxflow;
int main(){
	cin>>n>>m>>st>>ed;
	for(int i = 1;i <= n;i++){
		if(i != st && i != ed){
			awa(i,i+n,1);
		}else{
			awa(i,i+n,INF);
		}
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		awa(a+n,b,INF);
		awa(b+n,a,INF);
	}
	while(bfs()){
		memset(cur,0,sizeof(cur));
		maxflow += dfs(st,INF);
	}
	cout<<maxflow;//
	return 0;
}
