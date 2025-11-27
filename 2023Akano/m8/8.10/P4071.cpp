#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 2006 + 1018 + 1108;
const int MOD = 1e9 + 7;
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
ll t,n,m,stp[MAXN],c[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	stp[0] = 1;
	c[0] = 1,c[1] = 0,c[2] = 1;
	for(int i = 3;i <= 1e6;i++){
		c[i] = ((i-1) * (c[i-1] + c[i-2])) % MOD;
	}
	for(int i = 1;i <= 1e6;i++)stp[i] = (stp[i-1] * i) % MOD;
	while(t--){
		cin>>n>>m;
		if(m > n){
			cout<<0<<endl;
			continue;
		}
		ll ans = Div(stp[n],(stp[m] * stp[n-m]) % MOD);
		ans = (ans * c[n-m]) % MOD;
		cout<<ans<<endl;
	}
	return 0;
}
