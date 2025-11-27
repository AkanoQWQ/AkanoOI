#include<bits/stdc++.h>
const int MAXN = 100006;
const int MAXM = MAXN * 3;
using namespace std;
int n,m,q;//题目变量 
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
int fa[MAXN];//并查集模块 
int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
int lfa[MAXN][22],w[MAXN][22];//LCA预处理模块 
int dep[MAXN];//DFS模块 
void dfs(int u,int father){
	lfa[u][0] = father;
	for(int i = 1;i <= 20;i++){
		lfa[u][i] = lfa[lfa[u][i-1]][i-1];
		w[u][i] = max(w[u][i-1],w[lfa[u][i-1]][i-1]);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			w[v][0] = e[i].v;
			dep[v] = dep[u] + 1;
			dfs(v,u);
		}
	}
	return ;
}
int lca(int x,int y){//LCA正篇模块 
	int ret = 0;
	if(dep[x] < dep[y])swap(x,y);
	//cout<<x<<" in "<<dep[x]<<" and "<<y<<" in "<<dep[y]<<endl;
	for(int i = 20;i >= 0;i--){
		if(dep[lfa[x][i]] >= dep[y]){
			//cout<<x<<" goto ";
			ret = max(ret,w[x][i]);
			x = lfa[x][i];
			//cout<<x<<"with ret "<<ret<<endl;
		}
	}
	if(x == y)return ret;
	for(int i = 20;i >= 0;i--){
		if(lfa[x][i] != lfa[y][i]){
			ret = max(ret,max(w[x][i],w[y][i]));
			//cout<<x<<","<<y<<" goto ";
			x = lfa[x][i],y = lfa[y][i];
			//cout<<x<<","<<y<<" with ret "<<ret<<endl;
		}
	}
	ret = max(ret,max(w[x][0],w[y][0]));
	return ret;
}
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f=-1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
inline void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar(x % 10 + '0');
	return ;
}
int main(){
	//freopen("par.in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(),m = read(),q = read();
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		for(int j = 2;(m - i + 1) * j <= n;j++){
			int a = m - i + 1,b = a * j,w = i;
			if(find(a) != find(b)){
				//cout<<a<<" "<<b<<" connect in "<<w<<endl;
				AddEdge(a,b,w);
				AddEdge(b,a,w);
				fa[find(a)] = b;
				if(tot == n*2){
					goto lets_go;
				}
			}
		}
	}
	lets_go:
	dep[1] = 1;
	dfs(1,1);
	while(q--){
		int a = read(),b = read();
		write(lca(a,b)),putchar('\n');
	}
	return 0;
}
