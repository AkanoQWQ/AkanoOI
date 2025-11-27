#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
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
int n,p[MAXN];
double k;
bool vis[MAXN],FD,est[MAXN];
void FindRoad(int u,int from){
	vis[u] = true;
	if(FD)return ;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!vis[v]){
			FindRoad(v,u);
		}else if(v != from){
			FD = true;
			est[u] = est[v] = true;
			break;
		}
	}
	return ;
}
int dp[MAXN][2];
void dfs(int u,int fa){
	dp[u][1] = p[u];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || (est[u] && est[v]))continue;
		dfs(v,u);
		dp[u][0] += max(dp[v][0],dp[v][1]);
		dp[u][1] += dp[v][0];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>p[i];
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u); 
	}
	dfs(1,1);
	cout<<max(dp[1][0],dp[1][1]);
	return 0;
}
