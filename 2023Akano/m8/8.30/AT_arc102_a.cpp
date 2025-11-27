#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll n,k,ans;
inline ll P(ll x){
	return x * x;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll a = 1;a <= n;a++){
		ll lessB = k - (a % k);
		if((2*(k-a)) % k == 0){
			ans += P(ceil(1.0f * (n - lessB + 1) / k));
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
