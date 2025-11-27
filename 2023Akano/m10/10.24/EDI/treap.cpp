#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 1018 + 1108;

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
			if(b & 1)ret = (ret * a) % MOD;
			a = (a * a) % MOD;
			b >>= 1;
		}
		return ret;
	}
public:
	T MOD;
	InverseFactory(){
		MOD = 1;
		Build();
		return ;
	}
	InverseFactory(T _mod){
		MOD = _mod;
		Build();
		return ;
	}
	inline void Insert(T& pos,T val){
		arr.emplace_back(pos,val),sum.push_back((sum.back() * val) % MOD);
		return ;
	}
	inline void Solve(){
		const int nowSize = int(sum.size()) - 1;
		inv.resize(sum.size());
		for(int i = 1;i <= nowSize;i++){
			sum[i] = (sum[i-1] * arr[i].second) % MOD;
		}
		inv[nowSize] = KSM(sum[nowSize],MOD-2);
		for(int i = nowSize;i >= 1;i--){
			inv[i-1] = (inv[i] * arr[i].second) % MOD;
		}
		for(int i = nowSize;i >= 1;i--){
			inv[i] = (inv[i] * sum[i-1]) % MOD;
			arr[i].first = inv[i];
		}
		Build();
		return ;
	}
};

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
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
ll p,ans,nowans = 1,inv[MAXN],invp[MAXN];
int n,siz[MAXN];
inline ll Calc(int u){
	return (((p-1) * inv[siz[u]]) % MOD) + 1;
}
inline ll FCalc(int u){
	return (siz[u] * invp[siz[u]]) % MOD;//siz[u] + p - 1 
}
inline void GetInv(){
	InverseFactory<ll> invfac(MOD);
	for(int i = 1;i <= n;i++){
		invfac.Insert(inv[i],i);
	}
	for(int i = 1;i <= n;i++){
		invfac.Insert(invp[i],i+p-1);
	}
	invfac.Solve();
	return ;
}
void GetSize(int u,int fa){
	siz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetSize(v,u);
		siz[u] += siz[v];
	}
	nowans = (nowans * Calc(u)) % MOD;
	return ;
}
void dfs(int u,int fa){
	ans = (ans + nowans) % MOD;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		nowans = (nowans * FCalc(u)) % MOD;
		nowans = (nowans * FCalc(v)) % MOD;
		siz[u] -= siz[v];
		siz[v] += siz[u];
		nowans = (nowans * Calc(u)) % MOD;
		nowans = (nowans * Calc(v)) % MOD;
		dfs(v,u);
		nowans = (nowans * FCalc(u)) % MOD;
		nowans = (nowans * FCalc(v)) % MOD;
		siz[v] -= siz[u];
		siz[u] += siz[v];
		nowans = (nowans * Calc(u)) % MOD;
		nowans = (nowans * Calc(v)) % MOD;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	GetInv();
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	GetSize(1,1);
	dfs(1,1);
	ans = (ans * inv[n]) % MOD;
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
