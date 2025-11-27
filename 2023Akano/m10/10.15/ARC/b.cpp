#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using Bigint = __int128;
const int MAXPR = 77;
const int MOD = 998244353;
const int div2 = (MOD + 1) / 2;
ll a,b,pr[MAXPR],prcnt[MAXPR],prtail;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	ll val = a;
	for(ll i = 2;i * i <= a;i++){
		while(val % i == 0){
			val /= i;
			if(pr[prtail] == i){
				prcnt[prtail]++;
			}else{
				pr[++prtail] = i;
				prcnt[prtail]++;
			}
		}
	}
	if(val != 1){
		pr[++prtail] = val;
		prcnt[prtail]++;
	}
	ll poss = 1;
	bool ou = false;
	for(int i = 1;i <= prtail;i++){
		if((Bigint(prcnt[i]) * b + 1) % 2 == 0)ou = true;
		poss *= (Bigint(prcnt[i]) * b + 1) % MOD;
		poss %= MOD;
	}
	if(ou == false){
		poss = (poss - 1 + MOD) % MOD;
	}
	poss = (poss * div2) % MOD;
	poss = (Bigint(poss) * b) % MOD;
	if(ou == false){
		poss = (poss + b / 2) % MOD;//自己和自己可以组成一个
	}
	cout<<poss<<endl;
	return not(Akano loves pure__Elysia);
}
