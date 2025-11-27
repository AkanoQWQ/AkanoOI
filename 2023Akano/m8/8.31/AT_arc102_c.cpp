#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1018 + 1108;
const int MOD = 998244353;
ll k,n,f[MAXN][MAXN],fs[MAXN][MAXN],g[MAXN][MAXN],gs[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>k>>n;
	f[0][0] = g[0][0] = fs[0][0] = gs[0][0] = 1;
	for(int i = 1;i <= n;i++){
		fs[0][i] = (fs[0][i-1] + f[0][i]) % MOD;
		gs[0][i] = (gs[0][i-1] + g[0][i]) % MOD;
	}
	for(int i = 1;i <= k;i++){
		f[i][0] = f[i-1][0],fs[i][0] = f[i][0];
		g[i][0] = gs[i-1][0],gs[i][0] = g[i][0];
		for(int j = 1;j <= n;j++){
			f[i][j] = (f[i-1][j] + 2 * fs[i-1][j-1]) % MOD;
			fs[i][j] = (fs[i][j-1] + f[i][j]) % MOD;
			g[i][j] = gs[i-1][j];
			gs[i][j] = (gs[i][j-1] + g[i][j]) % MOD;
		}
	}
	for(int x = 2;x <= 2*k;x++){
		ll ans = 0;
		int freePoint = 0,fixedPoint = k,pairPoint = 0;
		for(int i = 1;i <= k;i++){
			if(x - i < 1 || x - i > k){
				freePoint++;
			}
		}
		fixedPoint -= freePoint;
		pairPoint = (fixedPoint - (x % 2 == 0)) / 2;
		for(int i = 0;i <= n;i++){
			ans = (ans + f[pairPoint][i] * g[freePoint][n-i]) % MOD;
		}
		if(x % 2 == 0){// x/2 与 x/2 配对 并选择它,不选择它已经包含在上面了 
			for(int i = 0;i < n;i++){
				ans = (ans + f[pairPoint][i] * g[freePoint][n-i-1]) % MOD;
			}
		}
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}

