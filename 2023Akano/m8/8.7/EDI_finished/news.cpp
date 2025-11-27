#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 2006 + 1018 + 1108;
const int MAXM = MAXN * 2;
const int MX_VAL = 1e6 + 1018 + 1108;
const int INF = 1e9;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,ans[MAXN],t[MX_VAL],mainans = INF,f[MAXN],g[MAXN];//long long?
vector<int> vec[MAXN],l[MAXN],r[MAXN];
inline void GetLR(int u){
	const int sz = vec[u].size();
	l[u].resize(sz),r[u].resize(sz);
	for(int i = 0;i < sz;i++){
		const int nowno = sz - i;
		l[u][i] = vec[u][i] + nowno;
		if(i-1 >= 0)l[u][i] = max(l[u][i],l[u][i-1]);
	}
	for(int i = sz-1;i >= 0;i--){
		const int nowno = sz - i;
		r[u][i] = vec[u][i] + nowno;
		if(i+1 < sz)r[u][i] = max(r[u][i],r[u][i+1]);
	}
	return ;
}
void dfs(int u,int fa){
	f[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		vec[u].push_back(f[v]);
	}
	sort(vec[u].begin(),vec[u].end());
	const int sz = vec[u].size();
	for(int i = 0;i < sz;i++){
		const int nowno = sz - i;
		f[u] = max(f[u],vec[u][i] + nowno);
	}
	return ;
}
void DP(int u,int fa){
	if(g[u] != 0){
		vector<int> gvec,cache;
		gvec.push_back(g[u]);
		merge(gvec.begin(),gvec.end(),vec[u].begin(),vec[u].end(),back_inserter(cache));
		vec[u] = cache;
	}
	GetLR(u);
	ans[u] = r[u][0];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		int pos = lower_bound(vec[u].begin(),vec[u].end(),f[v]) - vec[u].begin();
		int mx = 1;
		if(pos > 0){
			mx = max(mx,l[u][pos-1]-1);
		}
		if(pos+1 < int(r[u].size())){
			mx = max(mx,r[u][pos+1]);
		}
		g[v] = mx;
		DP(v,u);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 2;i <= n;i++){
		int dirfa;
		cin>>dirfa;
		AddEdge(i,dirfa),AddEdge(dirfa,i);
	}
	dfs(1,-1018);
	DP(1,0);
	for(int i = 1;i <= n;i++){
		mainans = min(mainans,ans[i]);
	}
	cout<<mainans<<endl;
	for(int i = 1;i <= n;i++){
		if(ans[i] == mainans){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
//»»¸ùDP
