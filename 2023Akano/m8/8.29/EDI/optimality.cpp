#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll t,n,m,k;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("optimality.in","r",stdin);
	freopen("optimality.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		ll ans = 1e9;
		for(ll x = 0;(1ll<<x) * n + ((1ll<<x)-1) * k <= m;x++){
			ll cnt = x;
			ll res = m - ((1ll<<x) * n + ((1ll<<x)-1) * k);
			for(int i = x;i >= 0;i--){
				if(res >= (1<<i)){
					cnt += res / (1<<i);
					res %= (1<<i);
				}
			}
			ans = min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
