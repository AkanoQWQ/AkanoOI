#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006*4;
const int st = 0;
const int ed = 8000;
const int INF = 0x7fffffff;
int n;
struct Edge{
	int nxt,v,to;
}e[MAXN*6];
int head[MAXN],tot = 1;
void AddEdge(int from,int to,int val){
	e[++tot].to = to;
	e[tot].v = val;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
void awa(int from,int to,int val){
	AddEdge(from,to,val);
	AddEdge(to,from,0);
	return ;
}
queue<int> q;
int dep[MAXN],cur[MAXN];
bool bfs(){
	while(!q.empty())q.pop();
	memset(dep,0,sizeof(dep));
	q.push(st);
	dep[st] = 1;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dep[v] || e[i].v <= 0)continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
	return dep[ed];
}
int dfs(int u,int val){
	if(u == ed || val == 0)return val;
	int ret = 0;
	int sta = cur[u];
	if(!sta)sta = head[u];
	for(int i = sta;i;i = e[i].nxt){
		cur[u] = i;
		const int v = e[i].to;
		if(e[i].v <= 0 || val <= 0 || dep[v] != dep[u]+1)continue;
		int push_push_uwu = min(val,e[i].v);
		int actually_push_awa = dfs(v,push_push_uwu); 
		if(actually_push_awa <= 0)continue;
		val -= actually_push_awa;
		e[i].v -= actually_push_awa;
		e[i^1].v += actually_push_awa;
		ret += actually_push_awa;
	}
	return ret;
}
int Dinic(){
	int maxflow = 0;
	while(bfs()){
		memset(cur,0,sizeof(cur));
		maxflow += dfs(st,INF);
	}
	return maxflow;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n*2;i++){
		int a,b;
		cin>>a>>b;
		awa(st,i,1);
		awa(i,a+2*n,1);
		awa(i,b+2*n,1);
	}
	for(int i = 1;i <= n;i++){
		awa(i+2*n,ed,2);
	}
	cout<<Dinic();
	return 0;
}
