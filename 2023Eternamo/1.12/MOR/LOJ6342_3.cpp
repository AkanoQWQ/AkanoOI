#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 7;
inline int ksm(int aa,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * aa) % MOD;
		aa = (1ll * aa * aa) % MOD;
		b >>= 1;
	}
	return ret;
}
inline int divv(int aa,int b){
	return (1ll * aa * ksm(b,MOD-2)) % MOD;
}
int n,f;
int main(){
	cin>>n;
	for(int i = n-1;i >= 2;i--)f = (f + divv(f + n - i + 1,n - i)) % MOD;
	cout<<divv(f + n - 1 + 1,n - 1);
	return 0;
}
