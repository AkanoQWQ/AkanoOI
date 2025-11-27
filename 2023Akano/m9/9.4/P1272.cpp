#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 161;
const int INF = 1e7;
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
int n,p,f[MAXN][MAXN],siz[MAXN],ans = INF;
void GetSize(int u,int fa){
	siz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetSize(v,u);
		siz[u] += siz[v];
	}
	return ;
}
void dfs(int u,int fa){
	for(int i = 0;i <= siz[u];i++)f[u][i] = INF;
	f[u][siz[u]] = 1,f[u][0] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		for(int a = siz[u];a >= 0;a--){
			for(int b = 0;b <= min(a,siz[v]);b++){
				f[u][a] = min(f[u][a],f[u][a-b] + f[v][b]);
			}
		}
	}
	if(siz[u] >= p){
		ans = min(ans,f[u][siz[u] - p] + (u != fa));
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		GetSize(i,i);
		dfs(i,i);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
