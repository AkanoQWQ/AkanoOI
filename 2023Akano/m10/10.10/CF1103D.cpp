#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 1e6 + 1018 + 1108;
const ll MAXC = 70;
const int MAXPR = 16;//相同的不重复计数,最多不到20个
const int MAXS = (1<<15) + 1018 + 1108;
const ll INF = 200610181108;
ll n,k,pr[MAXPR],prCnt,f[MAXC][MAXPR][MAXS];
pll ea[MAXN];
ll GCD(ll a,ll b){
	if(!b)return a;
	return GCD(b,a % b);
}
inline string Bit(ll x,ll w){
	string ret;
	for(ll i = 1;i <= w;i++){
		if(x & 1){
			ret += '1';
		}else{
			ret += '0';
		}
		x >>= 1;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>ea[i].second;
	for(int i = 1;i <= n;i++)cin>>ea[i].first;
	ll totgcd = ea[1].second;
	for(int i = 1;i <= n;i++){
		totgcd = GCD(totgcd,ea[i].second);
	}
	if(totgcd == 1){
		cout<<0<<endl;
		return not(Akano loves pure__Elysia);
	}
	for(ll x = 2;x * x <= totgcd;x++){
		while(totgcd % x == 0){
			totgcd /= x;
			if(pr[prCnt] != 0 && pr[prCnt] % x == 0){//相同质因数放一起
				pr[prCnt] *= x;
			}else{
				pr[++prCnt] = x;
			}
		}
	}
	if(totgcd != 1){
		pr[++prCnt] = totgcd;
	}
	const int maxs = (1<<prCnt) - 1;
	for(int i = 1;i <= prCnt;i++){
		if(pr[i] > k){//题意?
			cout<<-1<<endl;
			return not(Akano loves pure__Elysia);
		}
	}
	for(int i = 1;i <= n+1;i++){
		for(int j = 0;j <= prCnt;j++){
			for(int ks = 0;ks <= maxs;ks++){
				f[i][j][ks] = INF;
			}
		}
	}
	f[1][0][maxs] = 0;
	sort(ea+1,ea+n+1);
	for(int i = 1;i <= min(n,MAXC-1);i++){//正在考虑第i个e
		for(int used = 0;used <= prCnt;used++){
			for(int stat = 0;stat <= maxs;stat++){//还有多少**未完成**
				if(f[i][used][stat] >= INF)continue;
				for(int sub = stat;;sub = (sub-1) & stat){
					ll now = 1;
					for(int j = 1;j <= prCnt;j++){
						if(sub & (1<<(j-1))){
							now *= GCD(pr[j],ea[i].second);
						}
					}
					if(now > k)continue;
					f[i+1][used+1][stat ^ sub] = min(f[i+1][used+1][stat ^ sub],f[i][used][stat] + ea[i].first);
					if(sub == 0)break;
				}
				f[i+1][used][stat] = min(f[i+1][used][stat],f[i][used][stat]);
			}
		}
	}
	ll totans = INF;
	for(int j = 0;j <= prCnt;j++){
		if(f[min(n,MAXC-1) + 1][j][0] >= INF)continue;
		totans = min(totans,f[min(n,MAXC-1) + 1][j][0] * j);
	}
	cout<<totans<<endl;
	return not(Akano loves pure__Elysia);
}
