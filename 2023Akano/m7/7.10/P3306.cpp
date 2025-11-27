#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline void Execute(ll& x,const ll& mod){
	x = ((x % mod) + mod) % mod;
	return ;
}
ll Div(ll a,ll b,ll mod){
	Execute(a,mod),Execute(b,mod);
	return (a * KSM(b,mod-2,mod) + mod) % mod;
}
inline ll BSGS(ll a,ll b,ll mod){
	a %= mod,b %= mod;
	const ll up = sqrt(mod)+1;
	unordered_map<ll,ll> hs;
	ll insertVal = b;
	hs[insertVal] = 0;
	for(int i = 1;i <= up;i++){
		insertVal = (insertVal * a) % mod;
		hs[insertVal] = i;
	}
	for(int i = 1;i <= up;i++){
		const int OBJ = KSM(a,i*up,mod);
		if(hs.find(OBJ) != hs.end()){
			return i * up - hs[OBJ];
		}
	}
	return -2;
}
ll T,p,a,b,x,t;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>p>>a>>b>>x>>t;
		if(x == t){
			cout<<1<<endl;
			continue;
		}
		if(a == 0){
			if(b == t){
				cout<<2<<endl;
			}else{
				cout<<-1<<endl;
			}
			continue;
		}
		if(a == 1){
			ll newt = t - x;
			Execute(newt,p);
			if(b == 0){
				cout<<-1<<endl;
				continue;
			}
			const ll ans = ((newt * KSM(b,p-2,p)) % p) + 1;
			cout<<ans<<endl;
			continue;
		}
		const ll OBJ = Div(t - Div(b,1-a,p),x + Div(b,a-1,p),p);
		const ll ans = BSGS(a,OBJ,p) + 1;
		cout<<ans<<endl; 
	}
	return 0;
}
