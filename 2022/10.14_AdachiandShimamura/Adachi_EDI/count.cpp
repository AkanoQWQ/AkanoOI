#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3006;
const int MOD = 10086;
int n,v[MAXN],st,dis[MAXN][MAXN],ans;
vector<int> e[MAXN];
void dfs(int u,int fa,int val){
	val = (val * v[u]) % MOD; 
	dis[u][st] = (val) % MOD;
	dis[st][u] = dis[u][st];
	for(int i = 0;i < e[u].size();i++){
		const int v = e[u][i];
		if(v == fa)continue;
		dfs(v,u,val);
	}
	return ;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		long long llin;
		scanf("%lld",&llin);
		v[i] = int((llin%MOD));
	}
	for(int i = 1;i < n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		st = i;
		dfs(i,-114514,1);
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			ans = (ans+dis[i][j])%MOD;
		}
	}
	printf("%d",ans);
	return 0;
}
