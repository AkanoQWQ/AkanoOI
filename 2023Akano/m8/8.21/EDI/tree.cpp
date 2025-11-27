#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e5 + 1018 + 1108;
inline KSM(ll a,ll b){
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
bool est[MAXN];
int n,m,c;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i < n;i++){
		cin>>c>>c;
	}
	for(int i = 1;i <= m;i++){
		cin>>c;
		est[c] = true;
	}
	for(int i = 1;i <= n;i++){
		if(est[i]){
			cout<<0<<'\n';
		}else{
			cout<<Div(n,m)<<'\n';
		}
	}
	return 0;
}

