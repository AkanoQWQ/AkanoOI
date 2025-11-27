#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
const int SZ = 141;
const int MAXN = 141;
const int MAXS = (1<<9) + 14;
ll pcnt[SZ],pr[SZ],pnt,CRTA[SZ];
inline int Cnt1(int val){
	int ret = 0;
	while(val){
		ret += (val & 1);
		val >>= 1;
	}
	return ret;
}
inline string Bit(int val){
	string ret;
	while(val){
		ret += (val & 1) + '0';
		val >>= 1;
	}
	return ret;
}
bool Cmp4Stat(int val1,int val2){
	return Cnt1(val1) > Cnt1(val2);
}
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
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
inline ll Div(ll a,ll b,ll mod){
	ll B_INV = 0,y = 0;
	ll gcd = Exgcd(b,mod,B_INV,y);
	B_INV /= gcd;
	a %= mod,B_INV %= mod;
	lll ret = lll(a) * lll(B_INV) % mod;
	ret = (ret + mod) % mod;
	return ret;
}
ll GetNumOfP(ll x,ll p){//NEED PK?
	if(x == 0)return 0;
	return GetNumOfP(x / p,p) + (x / p);
}
inline ll GNOP(ll x,ll p){return GetNumOfP(x,p);}//DEFINE
ll sumPKINV;//share
inline ll GetInvWithoutP(ll x,ll p,ll pk){
	ll ret = 1;
	if(x == 0)return 1;
	ret *= GetInvWithoutP(x / p,p,pk);ret %= pk;
	ret *= KSM(sumPKINV,x / pk,pk);ret %= pk;
	for(ll i = (x / pk) * pk + 1;i <= x;i++){//CAN BE PRE_CALC
		if(i % p != 0){
			ret = (ret * (i % pk)) % pk;
		}
	}
	return ret % pk;
}
inline ll GIWP(ll x,ll p,ll pk){return GetInvWithoutP(x,p,pk);}//DEFINE
inline ll GNOP_TEST(ll x,ll p,ll pk){
	ll ret = 0;
	while(x){
		ret += x / p;
		x /= p;
	}
	return ret;
}
inline ll ExLucas(ll n,ll m,ll p,ll k){
	if(n < m)return 0;
	ll pk = 1;
	for(int i = 1;i <= k;i++)pk *= p;
	sumPKINV = 1;
	for(ll i = 1;i <= pk;i++){
		if(i % p != 0)sumPKINV = (sumPKINV * i) % pk;
	}
	ll upper = GIWP(n,p,pk);
	ll lower = (GIWP(m,p,pk) * GIWP(n-m,p,pk)) % pk;
	ll ret = Div(upper,lower,pk);
	ll sumPTimes = GNOP(n,p) - GNOP(m,p) - GNOP(n-m,p);
	if(sumPTimes < 0){
		ret = Div(ret,KSM(p,-sumPTimes,pk),pk);
	}else{
		ret *= KSM(p,sumPTimes,pk);
	}
	return ret;
}

namespace EXCRT_SPC{
	ll nowa,nowm;
	inline void EXCRT(ll mod,ll a){
		if(nowa == 0 && nowm == 0){
			nowa = a,nowm = mod;
			return ;
		}
		const ll delta = (((a - nowa) % mod) + mod) % mod;
		ll p = 0,q = 0;
		ll mmgcd = Exgcd(nowm,mod,p,q);
		p = Mul(p,delta / mmgcd,mod / mmgcd);
		nowa += Mul(p,nowm,mod / mmgcd * nowm);
		nowm = mod / mmgcd * nowm;
		nowa = ((nowa % nowm) + nowm) % nowm;
		return ;
	}
	inline ll GetAns(){
		return nowa;
	}
	inline void Clear(){
		nowa = nowm = 0;
		return ;
	}
}
vector<int> stats;
ll a1[MAXN],a2[MAXN],cache[MAXS];
inline ll SolveCalc(ll n,ll m,ll nowp,ll prcnt,ll n1,ll mainp){
	ll ret = 0;
	for(auto stat : stats){
		int cnt1 = Cnt1(stat);
		int nown = n;
		for(int i = 1;i <= n1;i++){
			if(stat & 1){
				nown -= a1[i];
			}
			stat >>= 1;
		}
		ll nows = ExLucas(nown-1,m-1,nowp,prcnt) % mainp;
		if(cnt1 & 1){
			ret -= nows;
		}else{
			ret += nows;
		}
		ret = ((ret % mainp) + mainp) % mainp;
	}
	return ret % mainp;
}
inline void Pre(ll mainp){
	ll up = sqrt(mainp);
	for(ll i = 2;i <= up;i++){
		if(mainp % i == 0){
			pr[++pnt] = i;
		}
		while(mainp % i == 0){
			++pcnt[pnt];
			mainp /= i;
		}
	}
	if(mainp != 1){
		pr[++pnt] = mainp;
		pcnt[pnt] = 1;
	} 
	return ;
}
inline ll Solve(ll n,ll m,ll mainp,ll n1){
	EXCRT_SPC::Clear();
	for(int i = 1;i <= pnt;i++){
		CRTA[i] = SolveCalc(n,m,pr[i],pcnt[i],n1,mainp);
		EXCRT_SPC::EXCRT(KSM(pr[i],pcnt[i],LLONG_MAX),CRTA[i]);
	}
	return EXCRT_SPC::GetAns();
}
ll t,p,n,n1,n2,m;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t>>p;
	Pre(p);
	while(t--){
		cin>>n>>n1>>n2>>m;
		for(int i = 1;i <= n1;i++){
			cin>>a1[i]; 
		}
		for(int i = 1;i <= n2;i++){
			cin>>a2[i];
			m -= (a2[i]-1);
		}
		stats.clear();
		for(int i = 0;i < (1<<n1);i++){
			stats.push_back(i);
		}
		sort(stats.begin(),stats.end(),Cmp4Stat);
		cout<<Solve(m,n,p,n1)<<endl;
	}
	return 0;
}
