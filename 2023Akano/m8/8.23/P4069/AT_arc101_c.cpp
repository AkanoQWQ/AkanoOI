#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018 + 1108 + 1000;
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
ll n,f[MAXN][MAXN],temp[MAXN];
void dfs(int u,int fa){
	f[u][1] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		for(int j = 1;j <= n;j++)temp[i] = 0;//TEST
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,1);
	return 0;
}

