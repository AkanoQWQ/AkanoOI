#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 200610 + 1018 + 1108;
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
int n,f[MAXN],ans;
void dfs(int u,int fa){
	int mx1 = 0,mx2 = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		if(f[v] > mx1){
			mx2 = mx1,mx1 = f[v];
		}else if(f[v] > mx2){
			mx2 = f[v];
		}
	}
	ans = max(ans,mx1+mx2+1);
	f[u] = mx1 + 1;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		u++,v++;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,1);
	cout<<ans-1<<endl;
	return not(Akano loves pure__Elysia);
}
