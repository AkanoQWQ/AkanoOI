#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXK = 106;
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
int n,k;
ll f[MAXN][MAXK],fac[MAXN],stirling[MAXK][MAXK],cache[MAXK],ans;
void dfs(int u){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		dfs(v);
		ll now = 0;
		for(int ks = 0;ks <= k;ks++){
			now += ((f[v][ks] * stirling[k][ks]) % MOD) * fac[ks];
			now %= MOD;
		}
		memset(cache,0,sizeof(cache));
		for(int j = 0;j <= k;j++){
			for(int ks = 0;ks + j <= k;ks++){
				cache[ks + j] += f[u][j] * f[v][ks];
				cache[ks + j] %= MOD;
			}
		}
		for(int j = 0;j <= k;j++){
			f[u][j] = (cache[j] + f[u][j] * now) % MOD;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>n>>k;
	fac[0] = 1;
	for(int i = 1;i <= n;i++){
		fac[i] = (fac[i-1] * i) % MOD;
		f[i][0] = f[i][1] = 1;
	}
	for(int i = 2;i <= n;i++){
		int fa;
		cin>>fa;
		AddEdge(fa,i);
	}
	stirling[0][0] = 1;
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= k;j++){
			stirling[i][j] = (stirling[i-1][j-1] + stirling[i-1][j] * j) % MOD;
		}
	}
	dfs(1);
	for(int i = 0;i <= k;i++){
		ans += ((f[1][i] * stirling[k][i]) % MOD) * fac[i];
		ans %= MOD;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
