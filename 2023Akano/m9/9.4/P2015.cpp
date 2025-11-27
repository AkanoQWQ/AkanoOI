#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 106;
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
int n,q,f[MAXN][MAXN],temp[MAXN];
void dfs(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		for(int i = 0;i <= q;i++)temp[i] = 0;
		for(int a = 0;a <= q;a++){
			for(int b = 0;a + b + 1 <= q;b++){
				temp[a+b+1] = max(temp[a+b+1],f[u][a] + f[v][b] + e[i].val);
//				cerr<<"upd "<<u<<","<<a+b+1<<" with ";
//				cerr<<u<<","<<a<<" and "<<v<<","<<b<<endl;
			} 
		}
		for(int i = 0;i <= q;i++)f[u][i] = max(temp[i],f[u][i]);
	}
//	cerr<<"now "<<u<<" : "<<endl;
//	for(int i = 0;i <= q;i++){
//		cerr<<i<<" : "<<f[u][i]<<endl;
//	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	dfs(1,-10181108);
	int ans = 0;
	for(int i = 0;i <= q;i++)ans = max(ans,f[1][i]);
	cout<<f[1][q]<<endl;
	return not(Akano loves pure__Elysia);
}
