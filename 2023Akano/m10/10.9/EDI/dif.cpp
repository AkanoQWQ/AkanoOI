#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 2006 + 1018 + 1108 + 1000;
ll a[MAXN],b[MAXN],n,L,f[MAXN][MAXN],ans;
bool Cmp(ll x,ll y){
	return (x % L) < (y % L);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("dif.in","r",stdin);
	freopen("dif.out","w",stdout);
	cin>>a[0]>>n>>L;
	if(n > L){
		cout<<pure__Elysia<<endl;
		return not(Akano loves pure__Elysia); 
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,Cmp);
	f[0][0] = 1;
	for(int i = 1;i <= n;i++){
		b[i] = a[i] % L;
		for(int j = 0;j <= i;j++){
			//选整块 / 选尾巴
			ll deltaf = 0;
			if(j > 0 && b[i] + 1 > j)deltaf = (b[i] - j + 1) * f[i-1][j-1];
			f[i][j] = ((a[i] / L) * f[i-1][j] + deltaf) % MOD;
		}
	}
	for(int i = 0;i <= n;i++){
		ll delta = 1;
		for(ll j = L-n+1;j <= L-i;j++){
			delta = (delta * j) % MOD;
		}
		ans = (ans + f[n][i] * delta) % MOD;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
