#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pii = pair<int,int>;
constexpr int MAXN = 66;
constexpr int MOD = 1e9 + 7;

template<int MaxSetSize>
class DisjointSet{
private:
	int size;
	int setFather[MaxSetSize],setSize[MaxSetSize];
	inline int Find(int x){
		if(setFather[x] == x){
			return x;
		}
		return setFather[x] = Find(setFather[x]);
	}
public:
	inline void Init(int _size){
		size = _size;
		for(int i = 1;i <= size;i++){
			setFather[i] = i,setSize[i] = 1;
		}
		return ;
	}
	inline int GetFa(int x){
		return Find(x);
	}
	inline bool Merge(int u,int v){
		u = Find(u),v = Find(v);
		if(u == v)return false;
		if(setSize[u] < setSize[v])swap(u,v);//siz_u >= siz_u;
		setFather[v] = u,setSize[u] += setSize[v];
		return true;
	}
	inline bool ToGether(int u,int v){
		return Find(u) == Find(v);
	}
	DisjointSet(){
		size = 0;
		return ;
	}
	DisjointSet(int _size){
		size = _size;
		return ;
	}
};

struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt = 1;
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
int n,m,k,maxs,dep[MAXN],fae[MAXN],father[MAXN];
pii pass[MAXN];
vector<int> eset[MAXN];
DisjointSet<MAXN> dsu;
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1,father[u] = fa;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		fae[v] = i / 2;
		dfs(v,u);
	}
	return ;
}
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
//	freopen("pearl.in","r",stdin);
//	freopen("pearl.out","w",stdout);
	cin>>n>>m>>k;
	maxs = (1<<m) - 1;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,1);
	for(int i = 1;i <= m;i++){
		cin>>pass[i].first>>pass[i].second;
		int u = pass[i].first,v = pass[i].second;
		while(u != v){
			if(dep[u] < dep[v])swap(u,v);
			eset[i].push_back(fae[u]);
			u = father[u];
		}
	}
	ans = KSM(k,n-1);
	for(int stat = 1;stat <= maxs;stat++){
		dsu.Init(n);
		int siz = 0,cntval = 0;
		for(int i = 1;i <= m;i++){
			if(stat & (1<<(i-1))){
				for(auto u : eset[i]){
					dsu.Merge(u,eset[i].back());
				}
				siz++;
			}
		}
		for(int i = 1;i < n;i++){
			if(dsu.GetFa(i) == i){
				cntval++;
			}
		}
		if(siz & 1){
			ans -= KSM(k,cntval);
		}else{
			ans += KSM(k,cntval);
		}
		ans = (ans + MOD) % MOD;
	}
	cout<<ans<<endl;
	return 0;
}

