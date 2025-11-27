#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
const int MAXT = 206; 
const int SZ = 25;
const int MAXMOD = 1e6 + 1018;
ll pr[SZ],pnt;
inline ll KSM(ll a,ll b,ll mod){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll a,ll b,ll mod){
	return (a * KSM(b,mod-2,mod)) % mod;
}
inline void GetPr(ll mainp){
	ll up = sqrt(mainp); 
	for(ll i = 2;i <= up;i++){
		if(mainp % i == 0){
			pr[++pnt] = i;
			mainp /= i;
		}
	}
	if(mainp != 1){
		pr[++pnt] = mainp;
	}
	return ;
}
pair<ll,ll> points[MAXT];
ll f[MAXT],t,totMOD;

template<typename T,int SIZE>
class CRT{
	private:
		T a[SIZE],mod[SIZE];
		int tot;
	public:
		inline void Clear(){
			tot = 0;
			return ;
		}
		inline void Insert(T _a,T _mod){
			tot++;
			a[tot] = _a,mod[tot] = _mod;
			return ;
		}
		inline T GetAns(){
			ll M = 1,ret = 0;
			for(int i = 1;i <= tot;i++){
				M *= mod[i];
			}
			for(int i = 1;i <= tot;i++){
				ll mi = M / mod[i];
				ll c = (mi * Div(1,mi,mod[i])) % M;
				ret = (ret + a[i] * c) % M;
			}
			return ret;
		}
};
CRT<ll,SZ> crt;
ll stp[MAXMOD];
inline void Pre(ll mod){
	stp[0] = 1;
	for(int i = 1;i <= mod;i++){
		stp[i] = (stp[i-1] * i) % mod;
	}
	return ;
}
ll C(ll n,ll m,ll mod){
	if(n < m)return 0;
	return Div(stp[n],(stp[m] * stp[n-m]) % mod,mod);
}
ll Lucas(ll n,ll m,ll mod){
	if(n == 0 || m == 0)return 1;//OK?
	if(n < m)return 0;
	return (C(n % mod,m % mod,mod) * Lucas(n / mod,m / mod,mod)) % mod;
}
inline ll Calc(ll mod){
	Pre(mod);
	for(int i = 1;i <= t;i++){
		f[i] = Lucas(points[i].first+points[i].second,points[i].first,mod);
		for(int j = 1;j < i;j++){
			if(points[j].first <= points[i].first && points[j].second <= points[i].second){
				ll deltaX = points[i].first - points[j].first,deltaY = points[i].second - points[j].second;
				ll delta = Lucas(deltaX+deltaY,deltaX,mod);
				f[i] -= (delta * f[j]) % mod;
				f[i] = ((f[i] % mod) + mod) % mod;
			}
		}
	}
	return f[t];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>points[1].first>>points[1].second>>t>>totMOD;
	t++;
	for(int i = 2;i <= t;i++){
		cin>>points[i].first>>points[i].second;
	}
	sort(points+1,points+t+1);
	GetPr(totMOD);
	for(int i = 1;i <= pnt;i++){
		crt.Insert(Calc(pr[i]),pr[i]);
	}
	cout<<crt.GetAns()<<endl;
	return 0;
}
