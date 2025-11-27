#include<bits/stdc++.h>
const int MAXN = 300006;
const int MAXM = MAXN * 2.2;
const int MAXD = 32;
using namespace std;
int n,m,s,aa[MAXN],ans[MAXN];//题目变量 
int head[MAXN],tot;//前向星模块 
struct Edge{
	int nxt,to,v;
}e[MAXM];
void AddEdge(int from,int to,int val){
	e[++tot].to = to;
	e[tot].v = val;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int lfa[MAXN][MAXD+5];//LCA预处理模块 
int dep[MAXN];//DFS模块 
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	lfa[u][0] = father;
	for(int i = 1;i <= MAXD;i++){
		lfa[u][i] = lfa[lfa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			dfs(v,u);
		}
	}
	return ;
}
int lca(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = MAXD;i >= 0;i--){
		if(dep[lfa[x][i]] >= dep[y])x = lfa[x][i];
	}
	if(x == y)return x;
	for(int i = MAXD;i >= 0;i--){
		if(lfa[x][i] != lfa[y][i]){
			x = lfa[x][i],y = lfa[y][i];
		}
	}
	return lfa[x][0];
}
void dfs2(int u,int father){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs2(v,u);
		ans[u] += ans[v];
	}
	return ;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>aa[i];
	} 
	for(int i = 1;i < n;i++){
		int a,b;
		cin>>a>>b;
		AddEdge(a,b,1);
		AddEdge(b,a,1);
	}
	dfs(1,0);
	for(int i = 1;i < n;i++){
		const int a = aa[i];
		const int b = aa[i+1];
		const int l = lca(a,b);
		ans[a]++;
		ans[b]++;
		ans[l]--;
		ans[lfa[l][0]]--;
	}
	dfs2(1,0);
	for(int i = 2;i <= n;i++){
		ans[aa[i]]--;
	}
	for(int i = 1;i <= n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
