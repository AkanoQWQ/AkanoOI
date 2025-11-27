#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018;
const int INF = 1e9;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,f[MAXN][MAXN],siz[MAXN];//i节点有j个人观看的最大利润
void dfs(int u,int fa){
	siz[u] = (u >= n-m+1); 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		siz[u] += siz[v];
		for(int a = siz[u];a >= 0;a--){
			for(int b = 0;b <= min(siz[v],a);b++){//equal? 
				f[u][a] = max(f[u][a],f[u][a-b] + f[v][b] - e[i].val);
			}
		}
	}
//	cerr<<"now "<<u<<" : "<<endl;
//	for(int i = 0;i <= m;i++){
//		cerr<<i<<" : "<<f[u][i]<<endl;
//	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n-m;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int no,cost;
			cin>>no>>cost;
			AddEdge(i,no,cost); 
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			f[i][j] = -INF;
		}
	}
	for(int i = n-m+1;i <= n;i++){
		cin>>f[i][1];
	}
	dfs(1,1);
	int ans = 0;
	for(int i = 1;i <= m;i++){
		if(f[1][i] >= 0)ans = i;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}

