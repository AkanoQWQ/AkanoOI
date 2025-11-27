#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 106;
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
int n,m,mxdep,ans;
void dfs(int u,int fa,int dep){
	mxdep = max(mxdep,dep);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u,dep+1);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	m++;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		u++,v++;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,1,1);
	ans = min(m,mxdep);
	m -= ans;
	ans += m >> 1;
	ans = min(ans,n);
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
