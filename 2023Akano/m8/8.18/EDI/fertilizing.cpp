#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e18;
const int MAXN = 2e5 + 1018 + 1108;
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
bool vis[MAXN];
ll n,T,arr[MAXN],f[MAXN],g[MAXN],t[MAXN],sz[MAXN],dep[MAXN],maxdep[MAXN];
bool Cmp(int x,int y){
	return t[x] * arr[y] < t[y] * arr[x];
}
void GetDep(int u,int fa){
	dep[u] = dep[fa] + 1,maxdep[u] = dep[u];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetDep(v,u);
		maxdep[u] = max(maxdep[u],maxdep[v]);
	}
	return ;
}
struct Element{
	ll a,t,sufa,sumt;
	Element(){}
	Element(ll _a,ll _t){a = _a,t = _t,sufa = sumt = 0;}
}ele[MAXN];
void dfs(int u,int fa){
	sz[u] = 1;
	vector<int> vec;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		sz[u] += sz[v],arr[u] += arr[v];
		vec.push_back(v);
	}
	t[u] = 2 * sz[u];
	sort(vec.begin(),vec.end(),Cmp);
	ll tail = 0,tot = 1;
	for(auto v : vec){
		f[u] += arr[v] * tot + f[v];
		tot += t[v];
	}
	for(auto i : vec){
		ele[++tail] = Element(arr[i],t[i]);
	}
	ele[0].sumt = 1;
	for(int i = 1;i <= tail;i++){
		ele[i].sumt = ele[i-1].sumt + ele[i].t;
	}
	ele[tail+1].sufa = 0;
	for(int i = tail;i >= 1;i--){
		ele[i].sufa = ele[i+1].sufa + ele[i].a;
	}
	g[u] = INF;
	for(int i = 1;i <= tail;i++){
		const int v = vec[i-1];
		if(maxdep[v] != maxdep[1])continue;
		ll UPD = f[u] + g[v] - f[v] - ele[i-1].sumt * ele[i].a - ele[i+1].sufa * ele[i].t + (ele[tail].sumt - ele[i].t) * ele[i].a;
		g[u] = min(g[u],UPD);
	}
	if(tail == 0)g[u] = 0;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>T;
	for(int i = 2;i <= n;i++){
		int v;
		cin>>v>>arr[i];
		AddEdge(i,v),AddEdge(v,i);
	}
	GetDep(1,1);
	dfs(1,1);
	if(T == 0){
		cout<<2*(n-1)<<" "<<f[1]<<endl;
	}else{
		cout<<2*(n-1) - maxdep[1] + 1<<" "<<g[1]<<endl;
	}
	return 0;
}
