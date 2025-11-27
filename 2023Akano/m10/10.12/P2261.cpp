#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll n,k;
ll Sum(ll l,ll r){
	return (r - l + 1) * (l + r) / 2;
}
inline ll Solve(){
	ll l = 1,ret = 0;
	while(l <= min(k,n)){
		ll r = min((k / (k / l)),min(k,n));
		ret += (k / l) * Sum(l,r);
		l = r + 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(n <= k){
		cout<<n*k - Solve()<<endl;
	}else{
		ll org = n * k;
		n = k;
		cout<<org - Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
