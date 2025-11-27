#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 3e5 + 1018 + 1108;
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
int n,m,dfn[MAXN],dnt,dep[MAXN],fa[MAXN][22],sz[MAXN],f[MAXN];
vector<pii> arc,line[MAXN];
void dfs(int u){
	sz[u] = 1;
	dep[u] = dep[fa[u][0]] + 1;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	dfn[u] = ++dnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(dfn[v])continue;
		fa[v][0] = u;
		dfs(v);
		sz[u] += sz[v];
	}
	return ;
}
inline int GOTO(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] > dep[y])x = fa[x][i];
	}
	return x;
}
void DP(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		DP(v,u);
		f[u] += f[v];
	}
	for(auto l : line[u]){
		f[u] = max(f[u],f[l.second] + 1);
	}
	return ;
}
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 2;i <= n;i++){
		int fa;
		cin>>fa;
		AddEdge(fa,i),AddEdge(i,fa);
	}
	return ;
}
inline void Solve(){
	dfs(1);
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		if(dep[u] > dep[v])swap(u,v);//u在上方
		if(fa[v][0] == u){
			cout<<-1<<endl;
			exit(0);
		}
		int lcaSon = GOTO(v,u);
		if(fa[lcaSon][0] == u){
			line[lcaSon].emplace_back(u,v);
		}else{
			arc.emplace_back(u,v);
		}
	}
	DP(1,1);
	return ;
}
inline void Output(){
	int ans = f[1];
	for(auto l : line[1]){
		ans = max(ans,f[l.second] + 1);
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	Output();
	return not(Akano loves pure__Elysia);
}
