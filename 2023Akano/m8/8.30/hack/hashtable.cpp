#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline void BSGS(ll a,ll b,ll mod){
	a %= mod,b %= mod;
	const int up = sqrt(mod);
	unordered_map<ll,ll> hs;
	ll insertVal = b;
	hs[insertVal] = 0;
	for(int i = 1;i <= up;i++){
		insertVal = (insertVal * a) % mod;
		hs[insertVal] = i;
	}
	for(int i = 1;i <= up * 10;i++){
		const int OBJ = KSM(a,i * up,mod);
		if(hs.find(OBJ) != hs.end()){
			cout<<i * up - hs[OBJ]<<"?"<<endl;
		}
	}
	return ;
}
inline int Phi(int x){
	int ret = 1;
	for(int i = 1;i <= x;i++){
		if(__gcd(x,i) == 1)ret++;
	}
	return ret;
}
ll p,b,n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	b = 3,n = 1,p = 35;
	BSGS(b,n,p);
	BF(b,n,p);
	cout<<p<<" phi "<<Phi(p)<<endl;
	return not(Akano loves pure__Elysia);
}
