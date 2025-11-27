#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 14;
int n;
ll a[MAXN],mod[MAXN];
ll ExGcd(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	ll gcd = ExGcd(b,a % b,x,y);
	ll oldX = x;
	x = y;
	y = oldX - (a / b) * y;
	return gcd;
}
inline ll GetInv(ll a,ll m){
	ll x = 0,y = 0;
	ll gcd = ExGcd(a,m,x,y);
	ll delta = ceil(double(1 - x) / double(m));
	return x + delta * m;
}
inline ll CRT(){
	ll ret = 0,M = 1;
	for(int i = 1;i <= n;i++)M *= mod[i];
	for(int i = 1;i <= n;i++){
		ll mi = M / mod[i];
		ll inv = GetInv(mi,mod[i]);
		ret = (ret + ((a[i] * mi) % M) * inv) % M; 
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>mod[i]>>a[i];
	} 
	cout<<CRT()<<endl;
	return not(Akano loves pure__Elysia);
}
