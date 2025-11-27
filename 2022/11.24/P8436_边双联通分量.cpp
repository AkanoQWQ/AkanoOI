#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 6;
const int MAXM = 4e6 + 6;
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,from;
	bool est;
}e[MAXM];
int head[MAXN],ent = 1;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].est = 0;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,m,dfn[MAXN],low[MAXN],dnt,ans;
bool GD[MAXN];
void tarjan(int u,int fa){
	int child = 0;
	dfn[u] = low[u] = ++dnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			child++;
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u]){
				e[i].est = 1;
				e[i^1].est = 1;
			}
		}else if(v != fa){
			low[u] = min(low[u],dfn[v]);
		}
	}
	return ;
}
bool vis[MAXN];
int SC;
vector<int> SCC[MAXN];
void dfs(int u){
	vis[u] = 1;
	SCC[SC].push_back(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(e[i].est || vis[v])continue;
		dfs(v);
	}
	return ;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= m;i++){
		int u = read(),v = read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])tarjan(i,-1);
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == 0){
			++SC;
			dfs(i);
		}
	}
	write(SC),putchar('\n');
	for(int i = 1;i <= SC;i++){
		write(SCC[i].size()),putchar(' ');
		for(int j = 0;j < SCC[i].size();j++){
			write(SCC[i][j]),putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
