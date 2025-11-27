#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 6;
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
int n,m;
bool kol[MAXN],OK,vis[MAXN];
void dfs(int u,int sim){
	if(OK)return ;
	if(sim >= 2)return ;
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		const int newsim = sim + (kol[u] == kol[v]);
		if(!vis[v])dfs(v,newsim);
		if(vis[v] && newsim == 1){
			OK = true;
		}
	}
	vis[u] = false;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		cin>>kol[i];
	}
	for(int i = 1;i <= n;i++){
		if(!OK){
			dfs(i,false);
		}
	}
	if(OK){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
