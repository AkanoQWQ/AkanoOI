#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;
constexpr int MAXN = 10181108 * 2;
constexpr int MAXPR = 2e6 + 1018 + 1108;
constexpr int MAXSQT = sqrt(MAXN) + 10 + 18;
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
ll prime[MAXPR],prpow1[MAXSQT][MAXSQT],prpow2[MAXSQT][MAXSQT],prCnt;
bool notp[MAXN];
ll ans[MAXN],p[MAXN],deltaval;
inline ll GetPow(int pri,int x,int sqt){
	return (prpow1[pri][x % sqt] * prpow2[pri][x / sqt]) % MOD;
}
inline ll GetPrime(int up){
	ll ret = 0;
	ans[1] = p[0] = 1;
	ret ^= (ans[1] + deltaval) % MOD;
	const ll upSQt = sqrt(up);
	for(int i = 2;i <= up;i++){
		if(notp[i] == false){
			prime[++prCnt] = i;
			ans[i] = KSM(i,i);
			if(i <= upSQt + 2){
				prpow1[prCnt][0] = prpow2[prCnt][0] = 1;
				for(int j = 1;j <= upSQt;j++){
					prpow1[prCnt][j] = (prpow1[prCnt][j-1] * ans[i]) % MOD;
				}
				for(int j = 1;j <= upSQt;j++){
					prpow2[prCnt][j] = (prpow2[prCnt][j-1] * prpow1[prCnt][upSQt]) % MOD;
				}
			}
		}
		int lst = 0,now = 0;
		ll secondval = 1;
		for(int pri = 1;pri <= prCnt;pri++){
			const int pr = prime[pri];
			if(1ll * i * pr > up)break;
			notp[i * pr] = true;
			while(now < pr - lst){
				now++;
				p[now] = (p[now-1] * ans[i]) % MOD;
			}
			secondval = (secondval * p[pr - lst]) % MOD;
			ans[i * pr] = (GetPow(pri,i,upSQt) * secondval) % MOD;
			if(i % pr == 0)break;
			lst = pr;
		}
		ret ^= (ans[i] + deltaval) % MOD;
	}
	return ret;
}
ll n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("probsum.in","r",stdin);
	cin>>n>>deltaval;
	cout<<GetPrime(n)<<endl;
	return not(Akano loves pure__Elysia);
}
