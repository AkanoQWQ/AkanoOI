#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 506;
struct Edge{
	int nxt,to;
}e[MAXN * MAXN * 2];
int heads[MAXN][MAXN],cnt;
inline void AddEdge(int from,int to,int head[]){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,k;
bitset<MAXN> sets[MAXN][MAXN],allset,now;
void dfs(int u,int fa,int root,int nowt){
	now[u] = true;
	if(root < u){
		sets[root][u] &= now;
	}
	for(int i = heads[nowt][u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u,root,nowt);
	}
	now[u] = false;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("trees.in","r",stdin);
	freopen("trees.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= k;i++){
		for(int j = 1,u,v;j < n;j++){
			cin>>u>>v;
			AddEdge(u,v,heads[i]),AddEdge(v,u,heads[i]);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			sets[i][j].set();
		}
	}
	for(int root = 1;root <= n;root++){
		for(int nowt = 1;nowt <= k;nowt++){
			dfs(root,root,root,nowt);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i < j){
				cout<<sets[i][j].count()<<" ";
			}else if(i == j){
				cout<<1<<" ";
			}else if(i > j){
				cout<<sets[j][i].count()<<" ";
			}
		}
		cout<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
