#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 2e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt,IN[MAXN];
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool vis[MAXN];
void dfs(int u){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		dfs(v);
	}
	return ;
}
int n,m;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("graph2.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1);
	for(int i = 1;i <= n;i++){
		if(!vis[i])cerr<<"ERR!"<<endl;
	}
	return not(Akano loves pure__Elysia);
}

