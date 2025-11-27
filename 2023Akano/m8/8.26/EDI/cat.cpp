#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,h[MAXN],father[MAXN],fa[MAXN][22],dep[MAXN];
ll f[MAXN],ans;
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
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i],y = fa[y][i];
		}
	}
	return fa[x][0];
}
int GetFa(int x){
	if(father[x] == x)return x;
	return father[x] = GetFa(father[x]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("cat/cat4.in","r",stdin);
//	freopen("cat.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		father[i] = i;
		cin>>h[i];
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(h[u],h[v]),AddEdge(h[v],h[u]);//在高度上进行DP,建边也建在高度上 
	}
	dfs(1);
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			const int pos = GetFa(v);
			if(pos < u){//不能走到比自己高的地方 
				father[pos] = u;
				f[u] = max(f[u],f[pos] + dep[u] + dep[pos] - dep[LCA(u,pos)] * 2);
			}
		}
		ans = max(ans,f[u]);
	}
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
