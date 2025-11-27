#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 999911659;
const ll MAXMOD = 62006 + 1018 + 1108;
const ll mods[12] = {2,3,4679,35617};
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll a,ll b,ll mod){
	return (a * KSM(b,mod-2,mod)) % mod;
}
ll stp[MAXMOD];
namespace CRT{
	ll a[12],c[12];
	inline ll CRT(){
		ll M = 1,ret = 0;
		for(int i = 0;i < 4;i++)M *= mods[i];
		for(int i = 0;i < 4;i++){
			const ll m = M / mods[i];
			const ll invm = Div(1,m,mods[i]);
			ret = (ret + a[i] * ((m * invm) % M)) % M;
		}
		return ret;
	}
}
inline ll C(ll n,ll m,ll mod){
	if(n < m)return 0;
	ll upper = stp[n];
	ll lower = (stp[m] * stp[n-m]) % mod;
	return Div(upper,lower,mod);
}
ll Lucas(ll n,ll m,ll mod){
	if(n == 0)return 1;
	if(n < m)return 0;
	return (Lucas(n/mod,m/mod,mod) * C(n%mod,m%mod,mod)) % mod;	
}
inline ll Calc(ll n,ll mod){
	stp[0] = 1ll;
	for(ll i = 1;i <= mod+3;i++)stp[i] = (stp[i-1] * i) % mod;
	ll ret = 0;
	for(int i = 1;i * i <= n;i++){
		if(i * i == n){
			ret = (ret + Lucas(n,i,mod)) % mod;
			break;
		}
		if(n % i == 0){
			ret = (ret + Lucas(n,n/i,mod)) % mod;
			ret = (ret + Lucas(n,i,mod)) % mod;
		}
	}
	return ret;
}
inline ll Solve(ll n){
	for(int p = 0;p < 4;p++){
		CRT::a[p] = Calc(n,mods[p]);
	}
	return CRT::CRT();
}
ll inn,g;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>inn>>g;
	if(g == MOD){
		cout<<0<<endl;
		return 0;
	}
	cout<<KSM(g,Solve(inn),MOD)<<endl;
	return 0;
}
