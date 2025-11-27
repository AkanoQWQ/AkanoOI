#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 2006 + 1018 + 1108 + 1000;
constexpr int MOD = 1e9 + 7;

template<typename T>
class InverseFactory{
private:
	vector<pair<T&,T> > arr;
	vector<T> sum,inv;
	inline void Build(){
		T cacheval;
		arr.clear(),sum.clear(),inv.clear();
		arr.emplace_back(cacheval,T(1)),sum.push_back(T(1)),inv.push_back(T(1));
		return ;
	}
	inline T KSM(T a,T b){
		T ret = 1;
		while(b){
			if(b & 1)ret = (ret * a) % factoryMOD;
			a = (a * a) % factoryMOD;
			b >>= 1;
		}
		return ret;
	}
public:
	T factoryMOD;
	InverseFactory(){
		factoryMOD = 1;
		Build();
		return ;
	}
	InverseFactory(T _mod){
		factoryMOD = _mod;
		Build();
		return ;
	}
	inline void Insert(T& pos,T val){
		arr.emplace_back(pos,val),sum.push_back((sum.back() * val) % factoryMOD);
		return ;
	}
	inline void Solve(){
		const int nowSize = int(sum.size()) - 1;
		inv.resize(sum.size());
		for(int i = 1;i <= nowSize;i++){
			sum[i] = (sum[i-1] * arr[i].second) % factoryMOD;
		}
		inv[nowSize] = KSM(sum[nowSize],factoryMOD-2);
		for(int i = nowSize;i >= 1;i--){
			inv[i-1] = (inv[i] * arr[i].second) % factoryMOD;
		}
		for(int i = nowSize;i >= 1;i--){
			inv[i] = (inv[i] * sum[i-1]) % factoryMOD;
			arr[i].first = inv[i];
		}
		Build();
		return ;
	}
};
InverseFactory<ll> invFactory;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,q,siz[MAXN];
ll f[MAXN][MAXN],fac[MAXN],facinv[MAXN];
inline ll C(ll x,ll y){
	if(x < y)return 0;
	return (((fac[x] * facinv[y]) % MOD) * facinv[x-y]) % MOD;
}
bool CmpBySize(int u,int v){
	return siz[u] < siz[v];
}
void dfs(int u,int fa){
	static ll cache[MAXN];
	f[u][0] = 1;
	vector<int> sons;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		sons.push_back(v);
	}
	sort(sons.begin(),sons.end(),CmpBySize);
	for(auto v : sons){
		memset(cache,0,sizeof(cache));
		for(int j = 0;j <= siz[u];j++){
			for(int k = 0;k <= siz[v];k++){
				cache[j+k] += C(siz[u] + siz[v] - j - k,siz[u] - j) * ((f[u][j] * f[v][k]) % MOD);
				cache[j+k] %= MOD;
			}
		}
		memcpy(f[u],cache,sizeof(cache));
		siz[u] += siz[v];
	}
	memcpy(cache,f[u],sizeof(cache));
	for(int i = 0;i <= siz[u];i++){
		cache[i] += (siz[u] - i) * f[u][i];
		cache[i+1] += (siz[u] - i) * f[u][i];
		cache[i] %= MOD,cache[i+1] %= MOD;
	}
	siz[u]++;
	memcpy(f[u],cache,sizeof(cache));
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("north.in","r",stdin);
	freopen("north.out","w",stdout);
	invFactory.factoryMOD = MOD;
	cin>>n>>q;
	fac[0] = facinv[0] = 1;
	for(int i = 1;i <= n;i++){
		fac[i] = (fac[i-1] * i) % MOD;
		invFactory.Insert(facinv[i],fac[i]);
	}
	invFactory.Solve();
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,10181108);
	while(q--){
		int root,x;
		cin>>root>>x;
		ll ans = 0;
		for(int i = 0;i <= siz[root] - x;i++){
			if(i & 1){
				ans -= C(i+x,x) * f[root][i+x];
			}else{
				ans += C(i+x,x) * f[root][i+x];
			}
			ans = ((ans % MOD) + MOD) % MOD;
		}
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
