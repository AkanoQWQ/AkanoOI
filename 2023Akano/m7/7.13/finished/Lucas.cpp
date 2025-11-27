#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXP = 1e5 + 6;
ll ink[MAXP];
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
inline ll C(ll n,ll m,ll mod){
	if(m > n)return 0;
	return Div(ink[n],(ink[m] * ink[n-m]) % mod,mod); 
}
ll Lucas(ll n,ll m,ll mod){
	if(m > n)return 0;
	if(n == 0 || m == 0)return 1;
	return (C(n % mod,m % mod,mod) * Lucas(n / mod,m / mod,mod)) % mod;
}
inline void Pre(int mod){
	for(int i = 1;i <= mod;i++){
		ink[i] = (ink[i-1] * i) % mod;
	}
	return ;
}
ll T,inn,inm,p,pw[MAXP];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ink[0] = 1;
	cin>>T;
	while(T--){
		cin>>inn>>inm>>p;
		Pre(p);
		cout<<Lucas(inn + inm,inn,p)<<'\n';
	}
	return 0;
}

