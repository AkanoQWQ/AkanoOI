#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 1018 + 1108;
ll n,pow2[MAXN],fac[MAXN],ans = 1;
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
int main(){//就是线性姬计数吧,但是咱不会qwq   ~~~    然而并不是~
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	pow2[0] = fac[0] = 1;
	for(int i = 1;i <= n;i++){
		pow2[i] = (pow2[i-1] * 2) % MOD;
		fac[i] = (fac[i-1] * i) % MOD;
	}
	for(int i = 1;i <= n;i++){
		ans *= (pow2[n] - pow2[i-1]);
		ans %= MOD;
	}
	ans = Div(ans,fac[n]);
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}

