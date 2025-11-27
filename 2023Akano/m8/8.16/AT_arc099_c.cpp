#include<bits/stdc++.h>
using namespace std;
const int MAXN = 706;
const int MAXM = MAXN * MAXN * 2;
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
pair<int,int> block[MAXN];
int n,m,blk,wht,tail,ans = 1e9;
bool con[MAXN][MAXN],vis[MAXN],dp[MAXN][MAXN],kolor[MAXN],OK = true;
void dfs(int u,int from,bool kol){
	vis[u] = true;
	kolor[u] = kol;
	if(kol)blk++;
	if(!kol)wht++;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v] && kolor[v] == kol){
			OK = false;
		}
		if(vis[v])continue;
		dfs(v,u,!kol);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("SA1.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		con[u][v] = con[v][u] = true;
	}
	for(int i = 1;i <= n;i++){
		con[i][i] = true;
		for(int j = 1;j <= n;j++){
			if(con[i][j] == false)AddEdge(i,j);
		}
	}
	for(int i = 1;i <= n;i++){
		if(vis[i])continue;
		blk = wht = 0;
		dfs(i,10181108,true);
		block[++tail] = make_pair(blk,wht);
	}
	dp[1][0] = true;
	for(int i = 1;i <= tail;i++){
		for(int j = 0;j <= n;j++){
			if(j+block[i].first <= n)dp[i+1][j+block[i].first] |= dp[i][j];
			if(j+block[i].second <= n)dp[i+1][j+block[i].second] |= dp[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		if(dp[tail+1][i]){
			ans = min(ans,i * (i-1) / 2 + (n-i) * (n-i-1) / 2);
		}
	}
	if(ans == 1e9 || OK == false)ans = -1;
	cout<<ans;
	return 0;
}
