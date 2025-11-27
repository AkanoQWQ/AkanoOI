#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
ll n,inm,ina,nowa,nowm;
ll Exgcd(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	ll ret = Exgcd(b,a % b,x,y);
	ll nowx2 = x;
	x = y;
	y = nowx2 - (a / b) * y;
	return ret;
}
inline ll Mul(ll a,ll b,ll mod){
	ll ret = 0;
	while(b){
		if(b & 1)ret = (ret + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ret;
}
inline void EXCRT(ll mod,ll a){
	if(nowa == 0 && nowm == 0){
		nowa = a,nowm = mod;
		return ;
	}
	const ll delta = (((a - nowa) % mod) + mod) % mod;
	//m*p - nowm*q = nowa - a
	//if((nowa - a) % mmgcd != 0)NO SOLUTION;
	ll p = 0,q = 0;
	ll mmgcd = Exgcd(nowm,mod,p,q);//m*p + nowm * q = mmgcd
	p = Mul(p,delta / mmgcd,mod / mmgcd);
	nowa += p * nowm;
	nowm = mod / mmgcd * nowm;
	nowa = ((nowa % nowm) + nowm) % nowm;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("EXCRT.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>inm>>ina;
		EXCRT(inm,ina);
	}
	if(nowa < 0){
		nowa %= nowm;
		nowa = (nowa + nowm) % nowm;
	}
	cout<<nowa % nowm<<flush;
	return 0;
}
