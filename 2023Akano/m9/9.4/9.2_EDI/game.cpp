#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN*2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,t,m,oth[MAXN],f[MAXN],g[MAXN],mx[MAXN][2],dep[MAXN],sumOth[MAXN];
bool inp[MAXN];
inline void ReadIn(){
	cin>>n>>t>>m;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	return ;
}
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		oth[u]++;
	}
	sumOth[u] = sumOth[fa] + oth[u] - 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		if(f[v] > mx[u][0]){
			mx[u][0] = f[v];
		}else if(f[v] > mx[u][1]){
			mx[u][1] = f[v];
		}
		oth[u]++;
	}
	f[u] = mx[u][1] + oth[u];
	g[u] = f[u] + (sumOth[fa] + 1) - (fa == m);
//	cerr<<u<<" g "<<g[u]<<" sumOth "<<sumOth[u]+1<<endl;
	return ;
}
vector<int> p;
void GetPath(int u){
	inp[u] = true;
	p.push_back(u);
	if(u == t)return ;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(dep[v] > dep[u])continue;
		GetPath(v);
	}
	return ;
}
inline bool Judge(int step){
//	cerr<<"Judge "<<step<<endl;
	int used = 0,up = 0;
	for(auto u : p){
		up++;
		int now = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(inp[v])continue;
			if(g[v] <= step)continue;
			now++;
		}
		used += now;
//		cerr<<"in "<<u<<" use "<<used<<endl;
		if(used > up)return false;
	}
	return (used <= step);
}
inline int Solve(){
	int l = 0,r = n+1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(Judge(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	cerr<<"now readin"<<endl;
	ReadIn();
	cerr<<"now dfs"<<endl;
	dfs(t,0);
	cerr<<"now getpath"<<endl;
	GetPath(m);
	cerr<<"now solve"<<endl;
	cout<<Solve()<<endl;
	return not(Akano loves pure__Elysia);
}

