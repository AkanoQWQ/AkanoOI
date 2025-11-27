#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e6 + 1018 + 1108;
ll n,p,k,nowk[MAXN],ans,a[MAXN],suma[MAXN];
ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline int Read(){
	int ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n = Read(),p = Read(),k = Read();
	nowk[0] = 1;
	for(int i = 1;i <= n;i++){
		a[i] = Read();
		nowk[i] = (nowk[i-1] * k) % p;
		suma = (suma * a[i]) % p;
	}
	cout<<ans;
	return 0;
}

