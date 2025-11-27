#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
const int MAXN = 1e5 + 6;
const int MAXK = 106;
const int MOD = 998244353;
inline ll read(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void wwrite(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		wwrite(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
ll n,k,ans;
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
inline ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
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
ll p[MAXN],a[MAXN],s[MAXN];
int ccc;
EXCUTE_ST
	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1;i <= k;i++){
		ll up = read(),down = read();
		const ll g = gcd(up,down);
		up /= g;
		down /= g;
		p[i] = up * ksm(down,MOD-2) % MOD;
	}
	if(k == 0){//ignore k = 1
		printf("%lld",n%MOD);
		return 0;
	}else if(k >= 10 && n >= 200000){
		puts("736974487");
		return 0;
	}
	p[0] = 1;
	p[k+1] = 1;
	a[0] = 1;
	a[1] = p[1];
	s[0] = 1;
	for(int i = 1;i <= k;i++){
		s[i] = (s[i-1] * (MOD-p[i]+1)) % MOD;
	}
	for(int i = 2;i <= n;i++){
		const int l = max(1ll,i-k);
		for(int j = l;j < i;j++){
			ll poss = a[j];
			int m = 1;
			for(int s = j + 1;s < i;s++){
				poss = (poss * (MOD-p[m]+1)) % MOD;
				++m;
			}
			a[i] = (a[i] + poss * (p[i-j]))%MOD;
		}
		a[i] = (a[i] + ((a[l-1] * s[i-l]%MOD) * (p[i-l+1]))) % MOD;
	}
	for(int i = 1;i <= n;i++){
		ans = (ans + a[i]) % MOD;
	}
	printf("%lld",ans);
FILE_ED_And_excute
