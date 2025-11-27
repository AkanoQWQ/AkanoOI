#include<bits/stdc++.h>
using namespace std;
using ll = __int128;
const int MOD = 19940417;
ostream& operator<<(ostream& cout,ll& _x){
	long long _in = _x;
	cout<<_in % MOD;
	return cout;
}
istream& operator>>(istream& cin,ll& _x){
	long long _in;
	cin>>_in;
	_x = _in;
	return cin;
}
inline ll Sum(ll l,ll r){
	return (r - l + 1) * (l + r) / 2;
}
ll PowSum(ll x){
	return (x * (x + 1) * (2 * x + 1) / 6) % MOD;
}
ll S0lve(ll x){//x
	ll l = 1,r = 0,ret = 0;
	while(l <= x){
		r = x / (x / l);
		ret = (ret + x * (r - l + 1) -  Sum(l,r) * (x / l)) % MOD;
		l = r + 1;
	}
	return ret;
}
ll Solve(ll a,ll b){
	ll l = 1,r = 0,ret = 0,up = min(a,b);
	while(l <= up){
		r = min(a / (a / l),b / (b / l));
		const ll A = a / l;
		const ll B = b / l;
		ret += (((a * b * (r-l+1))%MOD) - ((Sum(l,r) * (((A*b + B*a)) % MOD))%MOD) + (((((A * B) % MOD) * (PowSum(r)-PowSum(l-1)))) % MOD));
		ret %= MOD;
		l = r + 1;
	}
	return ret;
}
ll n,m;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll ans = (S0lve(n) * S0lve(m)) % MOD;
	ll dec = Solve(n,m);
	ans = (((ans - dec) % MOD) + MOD) % MOD;
	cout<<ans;
	return 0;
}
