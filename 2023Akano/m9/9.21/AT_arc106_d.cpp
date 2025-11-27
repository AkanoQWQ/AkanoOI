#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXK = 306;
const int MOD = 998244353;
const int div2 = (MOD+1) / 2;
ll n,k,arr[MAXN],sump[MAXN][MAXK],p[MAXN][MAXK],C[MAXK][MAXK],p2[MAXK];
inline void Pre(){
	for(int i = 0;i <= k;i++){
		C[i][0] = 1;
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= k;j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
	return ;
}
ll f[MAXK][MAXK];//f_i_j = C_i_j * sump_1_i-j
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	Pre();
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = n;i >= 1;i--){
		p[i][0] = 1,sump[i][0] = sump[i+1][0] + p[i][0];
	}
	p2[0] = 1;
	for(int i = 1;i <= k;i++){
		p2[i] = (p2[i-1] * 2) % MOD;
		for(int j = n;j >= 1;j--){
			p[j][i] = (p[j][i-1] * arr[j]) % MOD;
			sump[j][i] = (sump[j+1][i] + p[j][i]) % MOD;
		}
	}
	for(int power = 1;power <= k;power++){
		ll ans = 0;
		for(int j = 0;j <= power;j++){
			ans += (((C[power][j] * sump[1][power-j]) % MOD) * sump[1][j]) % MOD;
			ans %= MOD;
		}
		ans -= (p2[power] * sump[1][power]);
		ans = ((ans % MOD) + MOD) % MOD;
		ans = (ans * div2) % MOD;
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
