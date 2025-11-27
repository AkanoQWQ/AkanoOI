#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;

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

constexpr int MAXN = 5e5 + 1018 + 1108;
constexpr int MOD = 998244353;
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
InverseFactory<ll> invfac(MOD);
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll a,ll b){
	return (a * KSM(b,MOD-2)) % MOD;
}
int n;
ll fac[MAXN],inv[MAXN],f[MAXN],siz[MAXN],totans;
inline ll C(ll x,ll y){
	if(x < y)return 0;
	return (((fac[x] * inv[x-y]) % MOD) * inv[y]) % MOD;
}
void dfs(int u,int fa){
	f[u] = 1,siz[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		f[u] *= (C(siz[u] + siz[v],siz[v]) * f[v]) % MOD;
		f[u] %= MOD;
		siz[u] += siz[v];
	}
	siz[u]++;//root
	return ;
}
void ChangeRoot(int u,int fa){
	totans = (totans + f[u]) % MOD;
//	cerr<<u<<" f "<<f[u]<<endl;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		const ll deltau = (f[v] * C(n-1,siz[v])) % MOD;
		siz[u] -= siz[v];
		siz[v] += siz[u];
		f[u] = Div(f[u],deltau);
		const ll deltav = (f[u] * C(n-1,siz[u])) % MOD;
//		cerr<<u<<" -> "<<v<<" delta "<<deltau<<","<<deltav<<" siz "<<siz[u]<<" nowf "<<f[u]<<endl;
		f[v] = (f[v] * deltav) % MOD;
		ChangeRoot(v,u);
		f[v] = Div(f[v],deltav);
		f[u] = (f[u] * deltau) % MOD;
		siz[v] -= siz[u];
		
		siz[u] += siz[v];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("tree/tree2.in","r",stdin);
//	freopen("tree.out","w",stdout);
	cin>>n;
	fac[0] = inv[0] = 1;
	for(int i = 1;i <= n;i++){
		fac[i] = (fac[i-1] * i) % MOD;
		invfac.Insert(inv[i],fac[i]);
	}
	invfac.Solve();
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,1);
	ChangeRoot(1,1);
	cout<<totans<<endl;
	return not(Akano loves pure__Elysia);
}
