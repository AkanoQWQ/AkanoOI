#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int n;
ll ans,deltaval;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>deltaval;
	for(int i = 1;i <= n;i++){
		ans ^= (KSM(i,i) + deltaval) % MOD;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
