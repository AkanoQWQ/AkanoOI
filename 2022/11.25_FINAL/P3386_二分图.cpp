#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2006;
const int MAXM = 2e5 + 6;
const int INF = 0x7fffffff;
const int VST = 0;
const int VED = 2000; 
struct Edge{
	int nxt,to,cap;
}e[MAXM];
int head[MAXN],ent = 1,en;
inline void AddEdge(int from,int to,int cap){
	e[++ent].to = to;
	e[ent].cap = cap;
	e[ent].nxt = head[from];
	head[from]= ent;
	return ;
}
inline void awa(int u,int v,int c){
	AddEdge(u,v,c);
	AddEdge(v,u,0);
	return ;
}
int n,m,stp,edp,dep[MAXN],cur[MAXN];
queue<int> q;
inline bool bfs(int st,int ed){
	while(!q.empty())q.pop();
	for(int i = 0;i <= n;i++){
		dep[i] = 0;
	}
	for(int i = 1;i <= m;i++){
		dep[i+n] = 0;
	}
	dep[ed] = 0;
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
		int actual_push = dfs(v,min(e[i].cap,val));
		val -= actual_push;
		ret += actual_push;
		e[i].cap -= actual_push;
		e[i^1].cap += actual_push;
		if(actual_push == 0)dep[v] = -1;
		if(val == 0)break;
	}
	return ret;
} 
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
inline int Dinic(int st,int ed){
	dfs_ed = ed;
	int ret = 0;
	while(bfs(st,ed)){
		ret += dfs(st,INF);
	}
	return ret;
}
void write(int x){
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
signed main(){
	n = read(),m = read(),en = read();
	for(int i = 1;i <= n;i++){
		awa(VST,i,1);
	}
	for(int i = 1;i <= m;i++){
		awa(i+n,VED,1);
	}
	for(int i = 1;i <= en;i++){
		int u = read(),v = read();
		awa(u,v+n,1); 
	}
	write(Dinic(VST,VED));
	return 0;
}
