#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
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
bool fail;
ll f[MAXN][2];
int n,k,kol[MAXN],fa[MAXN],dep[MAXN],no[MAXN];
vector<int> points[MAXN];
void FindFa(int u){
	dep[u] = dep[fa[u]] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u])continue;
		fa[v] = u;
		FindFa(v);
	}
	return ;
}
void GetKolor(int u,int v){
	while(u != v){
		if(dep[u] < dep[v])swap(u,v);//dep_u > dep_v
		u = fa[u];
		if(kol[u] == 0){
			kol[u] = kol[v];
		}else if(kol[v] == kol[u]){
			return ;
		}else{
			fail = true;
			return ;
		}
	}
	return ;
}
inline void Remake(){
	set<pii> edges;
	int nnt = k;
	for(int i = 1;i <= n;i++){
		if(kol[i] == 0){
			no[i] = ++nnt;
		}else{
			no[i] = kol[i];
		}
		cerr<<i<<" -> "<<no[i]<<endl;
	}
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(no[u] != no[v])edges.insert({no[u],no[v]});
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : edges){
		AddEdge(i.first,i.second);
	}
	return ;
}
void dfs(int u,int father){
	if(u <= k){
		f[u][0] = 0,f[u][1] = 1;
	}else{
		f[u][0] = 1,f[u][1] = 0;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs(v,u);
		//下方为0
		if(f[v][0] != 0){
			f[u][0] *= f[v][0];
			f[u][1] *= f[v][0];
		}
		if(f[v][1] != 0){
			ll org1 = f[u][1];
			f[u][1] *= f[v][1];//下方为1且剪掉
			f[u][1] += f[u][0] * f[v][1];//下方为1且不剪掉
			f[u][0] *= f[v][1];//下方为1且剪掉
		}
	}
	cerr<<u<<" f "<<f[u][0]<<","<<f[u][1]<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>kol[i];
		points[kol[i]].push_back(i);
	}
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	FindFa(1);
	for(int i = 1;i <= k;i++){
		for(auto u : points[i]){
			if(u == points[i][0])continue;
			GetKolor(points[i][0],u);
		}
	}
	if(fail){
		cout<<not(Akano loves pure__Elysia)<<endl;
		return not(Akano loves pure__Elysia);
	}
	Remake();
	dfs(1,-10181108);
	cout<<f[1][1]<<endl;
	return not(Akano loves pure__Elysia);
}
