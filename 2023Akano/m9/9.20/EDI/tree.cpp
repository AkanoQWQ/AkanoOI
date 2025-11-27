#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 50;
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
/*题目相关*/
int n,k,q,a[MAXN],b[MAXN];
inline void ReadIn(){
	cin>>n>>k>>q;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	return ;
}
/*淀粉树相关*/
int tot,mss[MAXN],siz[MAXN],root;
bool solved[MAXN];
vector<pair<int,int> > newEdge;
void GetSize(int u,int fa){
	siz[u] = 1,mss[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],tot - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
void BuildTree(int u,int fa){
	solved[u] = true;
	if(u != fa)newEdge.emplace_back(u,fa);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		tot = siz[v],root = 0;
		BuildTree(v,u);
	}
	return ;
}
inline void Remake(){
	mss[0] = 1e9;
	tot = n;
	GetSize(1,1),GetSize(root,root);
	BuildTree(root,root);
	for(int i = 1;i <= n;i++)head[i] = 0;
	cnt = 0;
	for(auto i : newEdge){
		AddEdge(i.first,i.second);
		AddEdge(i.second,i.first);
	}
	return ;
}
/*和重建后的dfs建立序列相关*/
int dfn[MAXN],dnt;
void dfs1(int u,int fa){
	dfn[u] = ++dnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		
	}
}
inline void Solve(){
	
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Remake();
	Solve();
	return not(Akano loves pure__Elysia);
}
/*
dp[stat][i][j]
size(n,n,k)
*/
