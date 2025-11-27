#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int MOD = 1e9 + 7;
using ll = long long;
using pii = pair<int,int>;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
pii edges[MAXN];
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int t,n,del[MAXN],farpos[MAXN][2],setFa[MAXN];
int GetFa(int x){
	if(setFa[x] == x)return x;
	return setFa[x] = GetFa(setFa[x]);
}
ll ans = 1;
int dep[MAXN],fa[MAXN][26];
ll dis[MAXN],anses[MAXN],val[MAXN];
void dfs(int u,int father){
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dep[v] = dep[u] + 1;
		dis[v] = dis[u] + val[v];
		fa[v][0] = u;
		dfs(v,u);
	}
	return ;
}
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
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
inline ll GetDis(int x,int y){
	int lca = LCA(x,y);
	return dis[x] + dis[y] - dis[lca] - dis[fa[lca][0]];
}
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll _val,ll _divn){
	_val %= MOD,_divn %= MOD;
	return (_val * KSM(_divn,MOD-2)) % MOD;
}
ll Solve(int x,int y){
	x = GetFa(x),y = GetFa(y);
	int poss[4] = {farpos[x][0],farpos[x][1],farpos[y][0],farpos[y][1]};
	ll nowval = 0;
	int p1 = -1,p2 = -1;
	for(int i = 0;i < 4;i++){
		for(int j = i + 1;j < 4;j++){
			const ll newdis = GetDis(poss[i],poss[j]);
			if(newdis > nowval){
				nowval = newdis;
				p1 = poss[i],p2 = poss[j];
			}
		}
	}
	ans = Div(ans,val[x] * val[y]);
	setFa[y] = x;
	farpos[x][0] = p2,farpos[x][1] = p1;
	val[x] = nowval;
	ans = (ans * val[x]) % MOD;
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B5125.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>val[i];
		farpos[i][0] = farpos[i][1] = i;
		ans = (ans * val[i]) % MOD;
		setFa[i] = i;
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		edges[i] = make_pair(u,v);
		AddEdge(u,v),AddEdge(v,u);
	}
	dis[1] = val[1],dep[1] = 1;
	dfs(1,1);
	for(int i = 1;i <= n-1;i++){
		cin>>del[i];
	}
	anses[n] = ans;
	for(int i = n-1;i >= 1;i--){
		anses[i] = Solve(edges[del[i]].first,edges[del[i]].second);
	}
	for(int i = 1;i <= n;i++){
		cout<<anses[i]<<'\n';
	}
	cout<<flush;
	return 0;
}
