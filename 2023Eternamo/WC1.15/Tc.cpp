#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 3221225473;
inline ll read(){
	ll ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
ll ksm(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline int divv(ll a,ll b){
	return (a * ksm(b,MOD-2)) % MOD;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
//	puts("2684354563");
//	return 0;
	cout<<(divv(1,2) + )MOD;
	ll n = read();
	for(int i = 1;i <= n;i++){
		
	}
	return 0;
}

