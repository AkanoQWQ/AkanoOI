#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 1018 + 1108;
const int MAXM = 6e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
} 
int T,n,m;
bool vis[MAXN],blk[MAXN],wht[MAXN];
inline void Clear(){
	for(int i = 1;i <= n;i++){
		head[i] = 0;
		vis[i] = blk[i] = wht[i] = false;
	}
	cnt = 0;
	return ;
}
int dfs(int u){
	vis[u] = true;
	if(!wht[u])blk[u] = true;
	int ret = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(blk[u])wht[v] = true;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!vis[v]){
			ret += dfs(v);
		}
	}
	return ret;
}
inline void Solve(){
	cin>>n>>m;
	Clear(); 
	for(int i = 1;i <= m;i++){
		int u,v;cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	int tot = dfs(1),blkcnt = 0;
	if(tot != n){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	for(int i = 1;i <= n;i++){
		blkcnt += blk[i];
	}
	cout<<blkcnt<<endl;
	for(int i = 1;i <= n;i++){
		if(blk[i])cout<<i<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
