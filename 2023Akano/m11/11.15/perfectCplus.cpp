#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 3e5 + 1018 + 1108;
constexpr int VAL = 306;
constexpr int MOD = 998244353;
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
ll n,f[MAXN][VAL],mx,a[MAXN],sum = 1,ans;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum = (sum * a[i]) % MOD;
		mx = max(mx,a[i]);
	}
	f[1][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= mx;j++){
			//选
			if(j == 0){
				f[i+1][a[i]] += f[i][j];
			}else{
				f[i+1][__gcd(ll(j),a[i])] += f[i][j];
			}
			//不选
			f[i+1][j] += f[i][j];
		}
	}
	ans = f[n+1][0] * 1;
	cerr<<f[n+1][0]<<" expected "<<1<<endl;
	for(int i = 1;i <= mx;i++){
		cerr<<i<<" app "<<f[n+1][i]<<" val "<<Div(sum,i)<<endl;
		ans += f[n+1][i] * Div(sum,i);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
