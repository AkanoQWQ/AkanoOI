#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 106;
const int MAXM = MAXN;
const int MAXPN = MAXN * MAXN;
int T;
ll pow2[MAXPN],step[MAXPN],g[MAXN],c[MAXN][MAXN],f[MAXN][MAXN],h[MAXN][MAXN];
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
//契约 : 黑点为 1 ~ n-m , 白点为 n-m+1 ~ n
inline void Prepare(){
	pow2[0] = step[0] = 1;
	for(int i = 1;i < MAXPN;i++){
		pow2[i] = (pow2[i-1] * 2) % MOD;
		step[i] = (step[i-1] * i) % MOD;
	}
	for(int i = 0;i < MAXN;i++){
		c[i][0] = 1;
	}
	for(int i = 1;i < MAXN;i++){
		for(int j = 1;j < MAXN;j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
		}
	}
	//先求出 n 个节点连通子图的数量 g
	for(int n = 1;n < MAXN;n++){
		g[n] = pow2[n * (n-1) / 2];
		for(int i = 1;i < n;i++){
			g[n] -= ((g[i] * pow2[(n - i) * (n - i - 1) / 2]) % MOD) * c[n-1][i-1];
			g[n] = ((g[n] % MOD) + MOD) % MOD;
		}
	}
	//h_n_m 表示 : 选 n 个白点, m 个黑点他们之间的连边方案(点已经选出)
	//首先黑点必须连通,带来 g[m] 的贡献
	//其次 KSM(pow2[m] - 1,n)  表示每个白点都必须和一个黑点相连
	//每个黑点都可以选择连或者不连,但是至少要有一个点往外边连,并且 n 个白点可以随便选一个(这个解释好像有误?)
	//最后白点内部随便连,带来 pow2[n * (n-1) / 2] 的贡献
	for(int n = 1;n < MAXN;n++){
		for(int m = 0;m < MAXN;m++){
			h[n][m] = (((g[m] * KSM(pow2[m] - 1,n)) % MOD) * pow2[n * (n-1) / 2]) % MOD;
		}
	}
	return ;
}

inline void Solve(){
	f[0][0] = 1;
	for(int n = 0;n < MAXN;n++){
		f[n][0] = pow2[n * (n-1) / 2];
		for(int m = 1;m <= n;m++){
			for(int i = 1;i <= m;i++){
				//加入了独立的白色连通块,大小为 i
				//为了防止去重,我们令最后一个白点n所在的连通块在最后
				//于是除了点n,其他的点从剩下的 m-1 个白点里选出 i-1 个作为新加入的点
				f[n][m] += f[n-i][m-i] * c[m-1][i-1];
				f[n][m] %= MOD;
			}
			for(int i = 1;i <= m;i++){
				for(int j = 1;j <= n-m;j++){
					//表示选择了i个白点,m个黑点
					ll delta = f[n-i-j][m-i];
					//同样选出白点
					delta = (delta * c[m-1][i-1]) % MOD;
					//在 n-m 个黑点中选出新加入的 m 个黑点
					delta = (delta * c[n-m][j]) % MOD;
					//含义见 h 可知
					delta = (delta * h[i][j]) % MOD;
					f[n][m] += delta;
					f[n][m] %= MOD;
				}
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	Prepare();
	Solve();
	while(T--){
		int n,m;
		cin>>n>>m;
		cout<<f[n][m]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
