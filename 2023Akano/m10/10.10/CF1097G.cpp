#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXK = 206;
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
int n,k,siz[MAXN];
ll stirling[MAXK][MAXK],f[MAXN][MAXK],cache[MAXK],ans[MAXK];//stalin(误
//f_u_i 在u子树内使用了 i 条边
void dfs(int u,int fa){
	siz[u] = 1,f[u][0] = 1 + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		siz[u] += siz[v];
		memset(cache,0,sizeof(cache));
		//把边分配给u "之前的子树" 和 "当前子树v"
		for(int x = 0;x <= min(k,siz[u]);x++){
			for(int y = 0;y <= min(k-x,siz[v]);y++){
				cache[x+y] += f[u][x] * f[v][y];
				cache[x+y] %= MOD;
			}
		}
		memcpy(f[u],cache,sizeof(cache));
		
		//不能不经过u
		for(int j = 0;j <= k;j++){
			ans[j] = (ans[j] + MOD - f[v][j]) % MOD;
		}
	}
	for(int j = 0;j <= k;j++){
		ans[j] = (ans[j] + f[u][j]) % MOD;
	}
	for(int j = k;j >= 1;j--){//加入u上面的边
		f[u][j] = (f[u][j] + f[u][j-1]) % MOD;
	}
	f[u][1] = ((f[u][1] + MOD - 1) % MOD);//不看题解根本想不到,完泉不选子树但是选了上面一条边,并不合法
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	stirling[1][1] = 1;
	for(int i = 2;i <= k;i++){
		for(int j = 1;j <= k;j++){
			stirling[i][j] = (stirling[i-1][j-1] + stirling[i-1][j] * j) % MOD;
		}
	}
	dfs(1,0);
	ll totans = 0;
	ll fac = 1;
	for(int nowk = 1;nowk <= k;nowk++){
		fac = (fac * nowk) % MOD;
		totans = (totans + ((fac * ans[nowk]) % MOD) * stirling[k][nowk]) % MOD;
	}
	cout<<totans<<endl;
	return not(Akano loves pure__Elysia);
}
