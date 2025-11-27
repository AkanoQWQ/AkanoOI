#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXN = 2e5 + 6;
const int INF = 0x7fffffff;
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
ll ans[MAXN],f[MAXN],tot[MAXN],sz[MAXN];
void dfs(int u,int fa){
	tot[u] = f[u],sz[u] = 1;
	vector<pii> vec;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		vec.push_back(make_pair(tot[v],sz[v]));
		sz[u] += sz[v];
		tot[u] += tot[v];
		ans[u] += ans[v];
	}
	int add_ans = tot[u],nowtot = tot[u] - f[u];
	for(int i = 0;i < vec.size();i++){
		int cost = INF,pos = 0;
		for(int j = 0;j < vec.size();j++){
			if(vec[j].first == -1)continue;
			if(vec[j].second * (nowtot - vec[j].first) < cost){
				cost = vec[j].second * (nowtot - vec[j].first);
				pos = j;
			}
		}
		add_ans += cost;
		nowtot -= vec[pos].first;
		vec[pos].first = -1;
	}
	ans[u] += add_ans;
	return ;
}
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("signin.in","r",stdin);
	freopen("signin.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++)cin>>f[i];
	ll mainans = INF;
	for(int root = 1;root <= n;root++){
		memset(ans,0,sizeof(ans));
		memset(tot,0,sizeof(tot));
		memset(sz,0,sizeof(sz));
		dfs(root,root);
		mainans = min(mainans,ans[root]);
	}
	cout<<mainans<<endl;
	return 0;
}
