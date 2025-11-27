#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 6;
struct Edge{
	int nxt,to;
} e[MAXN*2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int fa[MAXN][21],dep[MAXN];
void dfs(int u){
	dep[u] = dep[fa[u][0]] + 1;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		fa[v][0] = u;
		dfs(v);
	}
	return ;
}
int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n,q;
int main(){
	n = read();
	for(int i = 1;i < n;i++){
		int u = read(),v = read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	dfs(1);
	q = read();
	while(q--){
		int x = read(),y = read();
		const int l = LCA(x,y);
		write(dep[x] + dep[y] - 2 * dep[l] + 1),putchar('\n');
	}
	return 0;
}
