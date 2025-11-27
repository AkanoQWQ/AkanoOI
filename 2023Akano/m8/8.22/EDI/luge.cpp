#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018 + 1108 + 1822;
const int MOD = 998244353;
const int div2 = (MOD+1) / 2;
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
ll n,k,arr[MAXN],f[MAXN][MAXN];
void dfs(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		for(int j = 0;j + arr[v] <= k;j++){//IMP ±³°üÏÂ´« 
			f[v][j + arr[v]] = (f[u][j] * div2) % MOD;
		}
		dfs(v,u);
		for(int j = 0;j <= k;j++){
			f[u][j] = (((f[u][j] * div2) % MOD) + (f[v][j])) % MOD;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("luge/luge2.in","r",stdin);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	f[1][arr[1]] = 1;
	dfs(1,1);
	cout<<f[1][k]<<endl;
	return 0;
}
