#include<bits/stdc++.h>
#include<AL/colorout.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using Bigint = __int128;
ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	a %= mod;
	while(b){
		if(b & 1)ret = (Bigint(ret) * a) % mod;
		a = (Bigint(a) * a) % mod;
		b >>= 1;
	}
	return ret;
}
ll POW(ll a,ll b,ll mod){
	ll ret = 1;
	for(ll i = 1;i <= b;i++)ret = (ret * a) % mod;
	return ret;
}
const ll pr = 1e9 + 9;
mt19937_64 rng(time(0));
inline bool JudgeP(ll x){
	const static int testTime = 32;
	if(x <= 3)return (x == 2);
	for(int i = 1;i <= testTime;i++){
		ll num = rng() % x;
		if(num == 0 || num == 1)continue;
		if(KSM(num,x-1,x) != 1){
			return false;
		}
	}
	return true;
}
inline bool JudgePStrict(ll x){
	const static int testTime = 1e5 + 2077 + 2006 + 1018 + 1108;
	if(x <= 3)return (x == 2);
	for(int i = 1;i <= testTime;i++){
		ll num = rng() % x;
		if(num == 0 || num == 1)continue;
		if(KSM(num,x-1,x) != 1){
			return false;
		}
	}
	return true;
}
inline bool ISP(ll x){
	for(ll i = 2;i*i <= x;i++){
		if(x % i == 0)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(ll i = pr;i <= pr+1e8;i++){
		if((i & 1) == 0)continue;
		if(JudgeP(i)){
			if(JudgePStrict(i) == false){
				kout<<i<<" is a [red]false prime[/red]"<<kend;
			}else{
				kout<<i<<" is a [blue]prime[/blue]"<<kend;
				break;
			}
		}
	}
	return not(Akano loves pure__Elysia);
}
