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
ll n,k,pr[MAXPR],prCnt,f[2][MAXPR][MAXS],include[MAXPR];
int now = 0,nxt = 1;
ll a[MAXN],e[MAXN];
ll GCD(ll aval,ll bval){
	if(!bval)return aval;
	return GCD(bval,aval % bval);
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
vector<pair<vector<int>,int> > nums;
map<int,vector<int>*> idx;
map<int,int> org;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++)cin>>e[i];
	for(int i = 1;i <= n;i++){
		if(idx.find(a[i]) == idx.end()){
			nums.emplace_back(vector<int>(),a[i]);
			idx[a[i]] = &nums.back().first;
		}
		idx[a[i]]->push_back(e[i]);
	}
	ll totgcd = a[1];
	for(int i = 1;i <= n;i++){
		totgcd = GCD(totgcd,a[i]);
	}
	if(totgcd == 1){
		cout<<0<<endl;
		return not(Akano loves pure__Elysia);
	}
	for(ll x = 2;x * x <= totgcd;x++){
		while(totgcd % x == 0){
			totgcd /= x;
			if(pr[prCnt] != 0 && pr[prCnt] % x == 0){//相同质因数放一起
				//不进行操作了
				//pr[prCnt] *= x;
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
	
	memset(f,0x3f,sizeof(f));
	f[nxt][0][maxs] = 0;
	for(auto nowpr : nums){
		auto vec = nowpr.first;
		const int nowa = nowpr.second;
		sort(vec.begin(),vec.end());
		for(int i = 1;i < int(vec.size());i++){
			vec[i] += vec[i-1];
		}
		for(int j = 1;j <= prCnt;j++){
			include[j] = 1;
			while(nowa % (include[j] * pr[j]) == 0){
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
			for(int delta = 1;delta + used <= prCnt && delta <= int(vec.size());delta++){
				for(int stat = 0;stat <= maxs;stat++){//还有多少**未完成**
					if(f[now][used][stat] >= INF)continue;
					for(int sub = stat;;sub = (sub-1) & stat){
						bool OK = true;
						ll nowval = k,res = delta - 1;
						for(int j = 1;j <= prCnt;j++){
							if(sub & (1<<(j-1))){
								if(nowval % includes[])
									nowval *= include[j];
							}
						}
						cerr<<"use "<<delta<<" got "<<nowval<<endl;
						if(nowval > k*delta)continue;
						f[nxt][used+delta][stat ^ sub] = min(f[nxt][used+delta][stat ^ sub],f[now][used][stat] + vec[delta-1]);
						if(sub == 0)break;
					}
					f[nxt][used][stat] = min(f[nxt][used][stat],f[now][used][stat]);
				}
			}
		}
	}
	ll totans = INF;
	for(int j = 0;j <= prCnt;j++){
		if(f[nxt][j][0] >= INF)continue;
		totans = min(totans,f[nxt][j][0] * j);
	}
	cout<<totans<<endl;
	return not(Akano loves pure__Elysia);
}
