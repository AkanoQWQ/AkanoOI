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
set<ll> otp;
inline void BSGS(ll a,ll b,ll mod,ll inup){
	a %= mod,b %= mod;
	const int up = sqrt(inup);
	unordered_map<ll,ll> hs;
	ll insertVal = b;
	hs[insertVal] = 0;
	for(ll i = 1;i <= up;i++){
		insertVal = (insertVal * a) % mod;
		hs[insertVal] = i;
	}
	for(ll i = 1;i <= inup;i++){
		if(i*up - mod > inup)break;
		const int OBJ = KSM(a,i * up,mod);
		if(hs.find(OBJ) != hs.end()){
			if(i * up - hs[OBJ] > inup)continue;
			otp.insert(i * up - hs[OBJ]);
		}
	}
	return ;
}
ll x,maxval,base,mod;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>x>>maxval>>base>>mod;
	const ll OBJ = KSM(base,x,mod);
	BSGS(base,OBJ,mod,maxval);
	cout<<otp.size()<<endl;
	for(auto i : otp)cout<<i<<" ";
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
