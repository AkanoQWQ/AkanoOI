#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
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
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<(499122177ll * 19261337ll) % MOD;
	return not(Akano loves pure__Elysia);
}
