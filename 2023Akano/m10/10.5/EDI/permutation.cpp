#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 106;
int mod,T,n,k;
ll stp[MAXN],stpInv[MAXN],f[MAXN][MAXN][MAXN];
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & a)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline void Prepare(){
	stp[0] = 1,stpInv[0] = 1;
	for(int i = 1;i < MAXN;i++){
		stp[i] = (stp[i-1] * i) % mod;
		stpInv[i] = KSM(stp[i],mod-2);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>mod>>T;
	Prepare();
	while(T--){
		cin>>n>>k;
		
	}
	return not(Akano loves pure__Elysia);
}
