#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 416;
const ll INF = 1e14;
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
int n,a[MAXN],siz[MAXN];
ll ans = -INF,f[MAXN][MAXN][2],dp[MAXN][MAXN];
bool Cmp(int x,int y){
	return siz[x] < siz[y];
}
void dfs(int u,int fa){
	siz[u] = 1;
	vector<int> sons;
	int totSize = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		sons.push_back(v);
		totSize += siz[v];
	}
	sort(sons.begin(),sons.end(),Cmp);
	for(int i = 0;i <= n+3;i++){
		for(int j = 0;j <= totSize + 3;j++){
			dp[i][j] = -INF;
		}
	}
	for(int i = 1;i <= n;i++){
		dp[i][1] = 1ll * i * a[u];
	}
	for(const auto v : sons){
		siz[u] += siz[v];
		for(int j = 1;j <= n;j++){
			for(int k = min(siz[u],j);k >= 1;k--){
				ll nxtDP = dp[j][k] + f[v][j][1];
				for(int s = min(k-1,siz[v]);s >= 1;s--){
					if(dp[j][k-s] <= -INF)break;
					nxtDP = max(nxtDP,dp[j][k-s] + f[v][s][0]);
				}
				dp[j][k] = nxtDP;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		f[u][i][0] = dp[i][i];
		f[u][i][1] = -INF;
		for(int j = i+1;j <= n && j-i <= siz[u];j++){
			f[u][i][1] = max(f[u][i][1],dp[j][j - i]);
		}
	}
	return ;
}
mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	int root = (rng() % n) + 1;
	dfs(root,root);
	for(int i = 1;i <= n;i++){
		ans = max(ans,f[root][i][0]);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
