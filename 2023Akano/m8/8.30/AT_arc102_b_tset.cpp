#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e4;
const int MAXM = 1e5;
const int MAXV = 1e7;
struct Edge{
	int nxt,to,val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool vis[MAXN];
bool cnts[MAXV];
int n,m;
void dfs(int u,int dis){
	if(u == n){
//		cout<<"now "<<dis<<endl;
		if(cnts[dis])cerr<<dis<<" ERR repeat"<<endl;
		cnts[dis] = true;
		return ;
	}
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		dfs(v,dis + e[i].val);
	}
	vis[u] = false;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w);
	}
	dfs(1,0);
	for(int i = 0;i <= 1e7;i++){
		if(!cnts[i]){
			cerr<<"dont have "<<i<<endl;
			return 0;
		}
	}
	return not(Akano loves pure__Elysia);
}
/*
4 5
1 2 1
1 2 0
2 3 2
2 3 0
3 4 0
*/
