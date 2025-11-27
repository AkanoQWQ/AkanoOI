#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500006;
struct Edge{
	int to,nxt;
}e[MAXN*2];
int head[MAXN],ent = 1;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int dep[MAXN],fa[MAXN][22];
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i = 1;i <= 19;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs(v,u);
	}
	return ;
}
int lca(int x,int y){
	while(dep[x] != dep[y]){
		if(dep[x] < dep[y])swap(x,y);
		for(int i = 19;i >= 0;i--){
			if(dep[fa[x][i]] >= dep[y]){
				x = fa[x][i];
			}
		}
	}
	if(x == y)return x;
	for(int i = 19;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int n,m,s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i < n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	dfs(s,s);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
