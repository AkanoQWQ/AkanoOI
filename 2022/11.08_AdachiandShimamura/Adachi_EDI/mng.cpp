#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int MAXM = MAXN * 2;
struct Edge{
	int nxt,to;
}e[MAXM];
int ent = 1;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,sz[MAXN],child[MAXN],fa[MAXN],dep[MAXN];
void dfs1(int u,int father){
	sz[u] = 1,fa[u] = father,dep[u] = dep[father] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[child[u]]){
			child[u] = v;
		}
	}
	return ;
}
int dfn[MAXN],dnt;
void dfs2(int u,int tp){
	dfn[u] = ++dnt;
	if(child[u] != 0){
		dfs2(child[u],tp);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u] || v == child[u])continue;
		dfs2(v,v)
	}
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i = 2;i <= n;i++){
		int x;
		scanf("%d",&x);
		AddEdge(x+1,i);
		AddEdge(i,x+1);
	}
	dfs1(1,0);
	dfs2(1,0);
	return 0;
}
