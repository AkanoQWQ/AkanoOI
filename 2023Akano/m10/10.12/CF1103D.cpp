#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 1e6 + 1018 + 1108;
const ll MAXC = 104;
const int MAXPR = 16;//相同的不重复计数,最多不到20个
const int MAXS = (1<<15) + 1018 + 1108;
const ll INF = 200610181108;
ll n,k,pr[MAXPR],prCnt,f[2][MAXPR][MAXS],include[MAXPR],tail,maxs,totgcd;
int now = 0,nxt = 1;
pll ae[MAXN],cache[MAXN];
ll GCD(ll aval,ll bval){
	if(!bval)return aval;
	return GCD(bval,aval % bval);
}
inline void ReadIn(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>ae[i].first;
	for(int i = 1;i <= n;i++)cin>>ae[i].second;
	return ;
}
inline void GetPrime(){
	totgcd = ae[1].first;
	for(int i = 1;i <= n;i++){
		totgcd = GCD(totgcd,ae[i].first);
	}
	if(totgcd == 1){
		cout<<0<<endl;
		exit(0);
	}
	ll cacheGCD = totgcd;
	for(ll x = 2;x * x <= cacheGCD;x++){
		while(cacheGCD % x == 0){
			cacheGCD /= x;
			if(pr[prCnt] != 0 && pr[prCnt] % x == 0){//相同质因数放一起
				//不进行操作了
				//pr[prCnt] *= x;
			}else{
				pr[++prCnt] = x;
			}
		}
	}
	if(cacheGCD != 1){
		pr[++prCnt] = cacheGCD;
	}
	maxs = (1<<prCnt) - 1;
	return ;
}
inline void Execute4Array(){
	tail = 0;
	for(int i = 1;i <= n;i++){
		ll save = 1;
		while(true){
			ll gcd = GCD(ae[i].first,totgcd);
			if(gcd == 1)break;
			save *= GCD(ae[i].first,totgcd);
			ae[i].first /= gcd;
		}
		cache[++tail] = make_pair(save,ae[i].second);
	}
	n = tail;
	for(int i = 1;i <= n;i++){
		ae[i] = cache[i];
	}
	tail = 0;
	for(int i = 1;i <= n;i++){
		if(i > prCnt + 1 && ae[i - prCnt - 1].first == ae[i].first){
			continue;
		}
		cache[++tail] = ae[i];
	}
	n = tail;
	for(int i = 1;i <= n;i++){
		ae[i] = cache[i];
	}
	if()
	return ;
}
inline void DP(){
	memset(f,0x3f,sizeof(f));
	f[nxt][0][maxs] = 0;
	for(int i = 1; i <= n;i++){
		for(int j = 1;j <= prCnt;j++){
			include[j] = 1;
			while(ae[i].first % (include[j] * pr[j]) == 0){
				include[j] *= pr[j];
			}
		}
		swap(now,nxt);
		for(int used = 0;used <= prCnt;used++){
			for(int stat = 0;stat <= maxs;stat++){
				f[nxt][used][stat] = INF;
			}
		}
		for(int used = 0;used <= prCnt;used++){
			for(int stat = 0;stat <= maxs;stat++){//还有多少**未完成**
				if(f[now][used][stat] >= INF)continue;
				for(int sub = stat;;sub = (sub-1) & stat){
					ll nowval = 1;
					for(int j = 1;j <= prCnt;j++){
						if(sub & (1<<(j-1))){
							nowval *= include[j];
						}
					}
					if(nowval > k)continue;
					f[nxt][used+1][stat ^ sub] = min(f[nxt][used+1][stat ^ sub],f[now][used][stat] + ae[i].second);
					if(sub == 0)break;
				}
				f[nxt][used][stat] = min(f[nxt][used][stat],f[now][used][stat]);
			}
		}
		
	}
	return ;
}
inline void Output(){
	ll totans = INF;
	for(int j = 0;j <= prCnt;j++){
		if(f[nxt][j][0] >= INF)continue;
		totans = min(totans,f[nxt][j][0] * j);
	}
	if(totans >= INF)totans = -1;
	cout<<totans<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	GetPrime();
	Execute4Array();
	DP();
	Output();
	return not(Akano loves pure__Elysia);
}
