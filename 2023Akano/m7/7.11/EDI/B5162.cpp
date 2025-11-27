#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1e6 + 6;
const int MAXM = 2e6 + 6;
struct Edge{
	int nxt,to;
}e[MAXM * 2];
int head[MAXN],cnt;
vector<pii> edges;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
int dfn[MAXN],low[MAXN],dnt,bel[MAXN],sz[MAXN],idcnt;
stack<int,vector<int> > stk;
bool ins[MAXN];
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	ins[u] = true;
	stk.push(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		++idcnt;
		while(!stk.empty()){
			const int _top = stk.top();
			stk.pop();
			bel[_top] = idcnt;
			ins[_top] = false;
			++sz[idcnt];
			if(_top == u)break;
		}
	}
	return ;
}
inline void UpdateEdge(){
	edges.reserve(cnt);
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			edges.push_back(make_pair(u,v));
		}
	}
	memset(head,0,sizeof(head));
	cnt = 0;
	for(auto i : edges){
		const int u = i.first,v = i.second;
		if(bel[u] != bel[v])AddEdge(bel[u],bel[v]);
	}
	return ;
}
int dp[MAXN],ans;
void dfs(int u){
	if(dp[u] != 0)return ;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		dfs(v);
		dp[u] = max(dp[u],dp[v]);
	}
	dp[u] += sz[u];
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B5162.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])Tarjan(i);
	}
	UpdateEdge();
	for(int i = 1;i <= idcnt;i++){
		if(!dp[i])dfs(i);
		ans = max(ans,dp[i]);
	}
	cout<<ans<<flush;
	return 0;
}
