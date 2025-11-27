#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 206;
ll d,n,dp[MAXN][MAXN];
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
const int bs = MAXN*2;
ll cat[MAXN*2][bs + MAXN*2],ins[MAXN*2][MAXN*2];
inline void Pre(){
	cat[0][bs] = 1;
	for(int i = 1;i <= 2*n;i++){
		for(int j = bs - 2*n;j <= bs + 2*n;j++){
			cat[i][j] += cat[i-1][j-1];
			cat[i][j] += cat[i-1][j+1];
			cat[i][j] %= MOD;
		}
	}
	for(int i = 0;i <= 2*n;i++){
		ins[0][i] = 1;
	}
	for(int i = 1;i <= 2*n;i++){
		for(int j = 0;j <= 2*n;j++){
			for(int k = 0;k <= j;k++){
				ins[i][j] = (ins[i][j] + ins[i-1][j-k]) % MOD;
			}
		}
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("shiawase.in","r",stdin);
	freopen("shiawase.out","w",stdout);
	cin>>d>>n;
	dp[0][0] = 1;
	Pre();
	for(int i = 1;i <= d;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= j;k++){
				dp[i][j] += (((dp[i-1][j-k] * cat[2*k][bs]) % MOD) * ins[2*(j-k)][2*k]) % MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	cout<<dp[d][n] % MOD;
	return 0;
}

