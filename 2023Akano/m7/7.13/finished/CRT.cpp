#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 6;
ll n,a[MAXN],mod[MAXN],m[MAXN],c[MAXN];
ll Exgcd(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	ll ret = Exgcd(b,a % b,x,y);
	ll nowx2 = x;
	x = y;
	y = nowx2 - (a / b) * y;
	return ret;
}
ll CE(ll a,ll mod){//x*a + k*mod = 1,ret x,AKA ax === 1 (%mod) 
	ll x = 0,k = 0;
	ll amgcd = Exgcd(a,mod,x,k);
	a /= amgcd,mod /= amgcd;
	ll delta_x = ll(ceil(double(1-x) / mod)) * mod;
	x += delta_x;
	return x / amgcd;
}
inline ll CRT(){
	ll MOD = 1,ret = 0;
	for(int i = 1;i <= n;i++)MOD *= mod[i];
	for(int i = 1;i <= n;i++){
		m[i] = MOD / mod[i];
		c[i] = m[i] * (CE(m[i],mod[i]));
		ret = (ret + a[i] * c[i]) % MOD;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>mod[i]>>a[i];
	}
	cout<<CRT()<<flush;
	return 0;
}
