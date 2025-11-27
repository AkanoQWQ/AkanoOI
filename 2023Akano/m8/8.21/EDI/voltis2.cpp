#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 5006;
const int cont[2] = {1,-1};
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
int n;
int con[MAXN][MAXN];
ll f[MAXN][MAXN][4],stp[MAXN],g[MAXN],ans,cache[MAXN][4],sz[MAXN],sum[MAXN],realg[MAXN],sumg;
void dfs(int u,int fa){
	f[u][0][0] = 1;
	sz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		for(int j = 0;j <= sz[u] + sz[v];j++)memset(cache[j],0,sizeof(cache[j]));
		for(int j = 0;j < sz[v];j++){
			sum[j] = (f[v][j][0] + f[v][j][1] + f[v][j][2] + f[v][j][3]) % MOD;
		}
		for(int j = 0;j < sz[u];j++){
			for(int k = 0;k < sz[v];k++){
				for(int s1 = 0;s1 <= 3;s1++){
					cache[j+k][s1] = (cache[j+k][s1] + f[u][j][s1] * sum[k]) % MOD;
				}
				for(int s1 = 0;s1 <= 3;s1++){
					if((s1 & con[u][v]) != 0)continue;
					for(int s2 = 0;s2 <= 3;s2++){
						if((s2 & con[v][u]) != 0)continue;
						cache[j+k+1][s1|con[u][v]] += f[u][j][s1] * f[v][k][s2];//+? *?
						cache[j+k+1][s1|con[u][v]] %= MOD;
					}
				}
			}
		}
		sz[u] += sz[v];
		for(int j = 0;j < sz[u];j++){
			for(int s = 0;s <= 3;s++){
				f[u][j][s] = cache[j][s];
			}
		}
	}
	return ;
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
inline ll Div(ll a,ll b){
	return (a * KSM(b,MOD-2)) % MOD;
}
inline ll C(ll nown,ll nowm){
	if(nown < nowm)return 0;
	return Div(stp[nown],(stp[nowm] * stp[nown - nowm]) % MOD);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("voltis/voltis2.in","r",stdin);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		con[u][v] = 1,con[v][u] = 2;
		AddEdge(u,v),AddEdge(v,u);
	}
	stp[0] = 1;
	for(int i = 1;i <= n;i++){
		stp[i] = (stp[i-1] * i) % MOD;
	}
	dfs(1,1);
	ans = stp[n];
	for(int i = 1;i <= n;i++){
		for(int s = 0;s <= 3;s++){
			g[i] += f[1][i][s];
		}
		g[i] *= stp[n-i];
	}
	for(int i = n;i >= 1;i--){
		realg[i] = g[i];
		for(int j = i+1;j <= n;j++){
			realg[i] -= (realg[j] * C(j,i)) % MOD;
			realg[i] = (realg[i] + MOD) % MOD;
		}
		ans -= realg[i];
		ans = (ans + MOD) % MOD;
	}
	cout<<ans;
	return 0;
}
