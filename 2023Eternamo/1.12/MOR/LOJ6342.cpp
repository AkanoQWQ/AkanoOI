#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 7;
int f[MAXN],p[MAXN],sum[MAXN],sump[MAXN];
int ksm(int aa,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * aa) % MOD;
		aa = (1ll * aa * aa) % MOD;
		b >>= 1;
	}
	return ret;
}
int divv(int aa,int b){
	return (1ll * aa * ksm(b,MOD-2)) % MOD;
}
int n;
int main(){
	cin>>n;
	p[1] = 1,f[1] = 0,sum[1] = divv(p[1],n),sump[1] = divv(1,n);
	for(int i = 2;i <= n;i++){
		f[i] = sum[i-1];
		p[i] = sump[i-1];
		sum[i] = (1ll*sum[i-1] + divv(((1ll*f[i]*p[i]) % MOD) + p[i],i+1)) % MOD;
		sump[i] = (sump[i-1] + divv(p[i],i+1)) % MOD;
	}
	cout<<f[n];
	return 0;
}
