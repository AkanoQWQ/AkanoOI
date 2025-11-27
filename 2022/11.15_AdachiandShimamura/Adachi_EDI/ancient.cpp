#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
ll n,g;
const ll MAXJ = 40006;
const ll MOD = 999911659;
const ll pr[14] = {0,2,3,4679,35617};
ll jc[MAXJ],a[14],ans;
void build(ll p){
	jc[0] = 1,jc[1] = 1;
	for(int i = 2;i <= p;i++)jc[i] = (jc[i-1] * i) % p;
	return ;
}
ll ksm(ll a,ll b,ll p){
	ll ret = 1;
	a %= p;
	while(b){
		if(b & 1 == 1)ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ret;
}
ll C(ll x,ll y,ll p){
	if(x < y)return 0;
	return jc[x] * ksm((jc[y] * jc[x-y])%p,p-2,p) % p;
}
ll lucas(ll x,ll y,ll p){
	if(x < y)return 0;
	if(x == 0)return 1;
	return lucas(x/p,y/p,p) * C(x%p,y%p,p) % p;
}
void crt(){
	for(int i = 1;i <= 4;i++){
		const int m = (MOD-1) / pr[i];
		ans += ((a[i] * m)%(MOD-1)) * ksm(m,pr[i]-2,pr[i]) % (MOD-1);
	}
	return ;
}
EXCUTE_ST
	freopen("ancient.in","r",stdin);
	freopen("ancient.out","w",stdout);
	cin>>n>>g;
	for(int i = 1;i <= 4;i++){
		build(pr[i]);
		for(ll j = 1;j * j <= n;j++){
			if(n % j != 0)continue;
			a[i] = (a[i] + lucas(n,j,pr[i])) % pr[i];
			if(j*j != n){
				a[i] = (a[i] + lucas(n,n/j,pr[i])) % pr[i];
			}
		}
	}
	crt();
	cout<<ksm(g,ans,MOD);
FILE_ED_And_excute
