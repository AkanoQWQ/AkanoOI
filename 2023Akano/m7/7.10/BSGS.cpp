#include<bits/stdc++.h>
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
inline ll BSGS(ll a,ll b,ll mod){
	a %= mod,b %= mod;
	const int up = sqrt(mod);
	unordered_map<ll,ll> hs;
	ll insertVal = b;
	hs[insertVal] = 0;
	for(int i = 1;i <= up;i++){
		insertVal = (insertVal * a) % mod;
		hs[insertVal] = i;
	}
	for(int i = 1;i <= up;i++){
		const int OBJ = KSM(a,i * up,mod);
		if(hs.find(OBJ) != hs.end()){
			return i * up - hs[OBJ];
		}
	}
	return -1;
}
ll p,b,n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>p>>b>>n;
	const ll ans = BSGS(b,n,p);
	if(ans == -1){
		cout<<"no solution";
	}else{
		cout<<ans;
	}
	return 0;
}

