#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e7 + 1018 + 1108;
const int MOD = 998244353;
bool _ST_;
int n,m;
int stp[MAXN],inv[MAXN],sum[MAXN];
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline void Pre(){
	stp[0] = 1,sum[0] = 1,inv[0] = 1;
	for(int i = 1;i <= n;i++){
		stp[i] = (1ll * stp[i-1] * i) % MOD;
		sum[i] = (1ll * sum[i-1] * stp[i]) % MOD;
	}
	inv[n] = KSM(sum[n],MOD-2);
	for(int i = n-1;i >= 1;i--){
		inv[i] = (1ll * inv[i+1] * stp[i+1]) % MOD;
	}
	for(int i = 1;i <= n;i++){
		inv[i] = (1ll * inv[i] * sum[i-1]) % MOD;
	}
	return ;
}
inline ll C(ll x,ll y){
	if(y > x)return 0;
	return (((1ll * stp[x] * inv[x-y]) % MOD) * inv[y]) % MOD;
}
inline ll Step(ll x,ll y){
	y = abs(y);
	if((x - y) % 2 != 0)return 0;//impossible
	return C(x,y+(x-y)/2);
}
bool _ED_;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	n = 2 * n - 2;
	Pre();
	ll ans = Step(n,0);	
	for(int i = 0;i < n/2;i += m){
		ll delta = 0;
		//对于过程中走到 -1 的方案，将它第一次走到 -1 之后的括号取反，那么恰好一一对应了以结尾走到 -2 的方案数。
		delta -= Step(n,-2*(i+1));//正负一样的
		//同理，把走到 m-1 的方案取反就是走到 2*m-2 的方案
		delta -= Step(n,2*(i+m-1));
		//把走到 -2 又走到 2*m-2 的重复减去(加回来)，就是 走到 -1 再走到 m-1 的方案 以及 走到 m-1 再走到 -1 的方案
		//两者是相等的,所以直接乘以2就行。它们都等于 走到 2*m 的方案数
		delta += 2*Step(n,2*(i+m));
		ans = (((ans + delta) % MOD) + MOD) % MOD;
		//因为要计算在 -1 和 m-1 之间来回横跳的情况，所以用 i 枚举以 m 为周期的情况进行容斥
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
