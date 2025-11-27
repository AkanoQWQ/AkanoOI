#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
using Structure = bitset<MAXN>;
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
int T,n,kol[MAXN],tp[MAXN];
vector<int> point[MAXN],control[MAXN];
int f[MAXN],dep[MAXN],father[MAXN][22],contribute[MAXN];
bool needCont[MAXN];
inline int LCA(int x,int y){
	if(dep[x] < dep[y]){
		swap(x,y);
	}
	for(int i = 20;i >= 0;i--){
		if(dep[father[x][i]] >= dep[y])x = father[x][i];
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(father[x][i] != father[y][i]){
			x = father[x][i],y = father[y][i];
		}
	}
	return father[x][0];
}
void dfs(int u,int fa){
	father[u][0] = fa;
	for(int i = 1;i <= 20;i++){
		father[u][i] = father[father[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dep[v] = dep[u] + 1;
		dfs(v,u);
	}
	return ;
}
Structure DP(int u,int fa){
	Structure now;
	now[kol[u]] = true;
	vector<pair<int,Structure> > childs;
	f[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		childs.emplace_back(v,DP(v,u));
		now |= childs.back().second;
		f[u] += f[v];
	}
	for(auto child : childs){
		const int v = child.first;
		for(int vKol = now._Find_first();vKol < MAXN;vKol = now._Find_next(vKol)){
			if(child.second[vKol] == false){
				contribute[vKol] += f[v];
			}
		}
	}
	for(auto nowKol : control[u]){
		int tot = contribute[nowKol];
		f[u] = max(f[u],tot + 1);
	}
	
	return now;
}
inline int Solve(){
	for(int i = 1;i <= n;i++){
		point[i].clear();
		control[i].clear();
		head[i] = 0;
		needCont[i] = false;
		contribute[i] = 0;
	}
	cnt = 0;
	for(int i = 1;i <= n;i++){
		cin>>kol[i];
		point[kol[i]].push_back(i);
		tp[kol[i]] = i;
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dep[1] = 1;
	dfs(1,0);
	for(int i = 1;i <= n;i++){
		if(point[i].empty())continue;
		for(auto u : point[i]){
			tp[i] = LCA(tp[i],u);
		}
		control[tp[i]].push_back(i);
	}
	DP(1,0);
	return f[1];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
