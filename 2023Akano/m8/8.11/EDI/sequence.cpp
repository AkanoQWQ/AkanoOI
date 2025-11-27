#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
ll n,p,f[MAXN],sum;
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	cin>>n>>p;
	for(int i = 1;i <= n;i++){
		cin>>f[i];
		sum = (sum + f[i]) % p;
	}
	for(int i = 1;i <= n;i++){
		if(f[i] == 1)continue;
		ll s = KSM(f[i],n) - 1;
		if(s == ((f[i]-1) * sum) % p){
			cout<<f[i]<<endl;
			return 0;
		}
	}
	return 0;
}
