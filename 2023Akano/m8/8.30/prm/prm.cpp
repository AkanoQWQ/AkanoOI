#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXVAL = 1e8;
const int MAXV = 1e7;
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
bitset<MAXVAL> otp;
inline void BSGS(ll a,ll b,ll mod,ll inup){
	a %= mod,b %= mod;
	const int up = sqrt(mod);
	unordered_map<ll,ll> hs;
	ll insertVal = b;
	hs[insertVal] = 0;
	for(int i = 1;i <= up;i++){
		insertVal = (insertVal * a) % mod;
		hs[insertVal] = i;
	}
	for(int i = 1;i <= inup;i++){
		if(i*up - mod > inup)break;
		const int OBJ = KSM(a,i * up,mod);
		if(hs.find(OBJ) != hs.end()){
			if(i * up - hs[OBJ] > inup)continue;
			if(otp[i * up - hs[OBJ]])continue;
			otp[i * up - hs[OBJ]] = true;
			cout<<i * up - hs[OBJ]<<'\n';
		}
	}
	cout<<flush;
	return ;
}
ll p,b,n,up;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("prm/prm7.in","r",stdin);
	cin>>b>>n>>p>>up;
	BSGS(b,n,p,up);
	return not(Akano loves pure__Elysia);
}
