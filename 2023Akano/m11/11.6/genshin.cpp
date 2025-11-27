#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1018 + 1108;
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
bool banned[MAXN];
int dep[MAXN],father[MAXN],f[MAXN][2];
vector<int> element[MAXN],vis[MAXN],mypath[MAXN];
int n,m,mainans,cntans;
void dfs(int u,int fa){
	f[u][0] = f[u][1] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		f[u][0] += max(f[v][0],f[v][1]);
	}
	for(auto id : element[u]){
		bool OK = true;
		for(auto v : mypath[id]){
			if(banned[v]){
				OK = false;
				break;
			}
		}
		if(OK == false)continue;
		int upd = 1;
		for(auto v : vis[id]){
			upd += max(f[v][0],f[v][1]);
		}
		f[u][1] = max(f[u][1],upd);
	}
	return ;
}
inline int Solve(int u,int v){
	for(int i = 1;i <= n;i++){
		banned[i] = false;
	}
	while(u){
		if(dep[u] < dep[v])swap(u,v);
		banned[u] = true;
		if(u == v)break;
		u = father[u];
	}
	dfs(1,1);
	return max(f[1][0],f[1][1]);
}
void Pre(int u,int fa){
	dep[u] = dep[fa] + 1,father[u] = fa;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		Pre(v,u);
	}
	return ;
}
inline void AddElement(int id,int u,int v){
	for(int i = 1;i <= n;i++){
		banned[i] = false;
	}
	banned[u] = banned[v] = true;
	while(u){
		if(dep[u] < dep[v])swap(u,v);
		for(int i = head[u];i;i = e[i].nxt){
			const int nxtV = e[i].to;
			if(nxtV == father[u] || banned[nxtV])continue;
			vis[id].push_back(nxtV);
		}
		mypath[id].push_back(u);
		if(u == v)break;
		banned[u] = true;
		u = father[u];
		banned[u] = true;
	}
	element[u].push_back(id);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	cin>>n>>m;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	Pre(1,1);
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		if(dep[u] > dep[v])swap(u,v);
		AddElement(i,u,v);
	}
	mainans = Solve(0,0);
	for(int u = 1;u <= n;u++){
		for(int v = 1;v <= n;v++){
			if(Solve(u,v) == mainans)cntans++;
		}
	}
	cout<<cntans<<endl;
	return not(Akano loves pure__Elysia);
}
