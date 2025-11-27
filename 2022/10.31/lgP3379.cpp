#include<bits/stdc++.h>
const int MAXN = 500006;
const int MAXM = MAXN * 2.5;
using namespace std;
int n,m,s;//题目变量 
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
int lfa[MAXN][22];//LCA预处理模块 
int dep[MAXN];//DFS模块 
void dfs(int u,int father){
	lfa[u][0] = father;
	for(int i = 1;i <= 20;i++){
		lfa[u][i] = lfa[lfa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			dep[v] = dep[u] + 1;
			dfs(v,u);
		}
	}
	return ;
}
int lca(int x,int y){//LCA正篇模块 
	int ret = 0;
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0;i--){
		if(dep[lfa[x][i]] >= dep[y]){
			x = lfa[x][i];
		}
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(lfa[x][i] != lfa[y][i]){
			x = lfa[x][i],y = lfa[y][i];
		}
	}
	return lfa[x][0];
}
int main(){
	//freopen("par.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 1;i < n;i++){
		int a,b;
		cin>>a>>b;
		AddEdge(a,b,1);
		AddEdge(b,a,1);
	}
	dfs(s,s);
	while(m--){
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<endl;
	}
	return 0;
}
