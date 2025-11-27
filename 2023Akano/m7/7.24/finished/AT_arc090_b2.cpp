#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 8e5 + 1018 + 1108;
const int INF = 1e8;
struct Edge{
	int nxt,to,delta;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int delta){
	e[++cnt].to = to;
	e[cnt].delta = delta;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,h[MAXN];
bool OK = true;
void dfs(int u){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(h[v] != INF){
			if(h[v] != h[u] + e[i].delta)OK = false;
			continue;
		}
		h[v] = h[u] + e[i].delta;
		dfs(v);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int l,r,w;
		cin>>l>>r>>w;
		AddEdge(l,r,w);
		AddEdge(r,l,-w);
	}
	for(int i = 1;i <= n;i++){
		h[i] = INF;
	}
	for(int i = 1;i <= n;i++){
		if(h[i] == INF){
			h[i] = 0;
			dfs(i);
		}
	}
	if(OK){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
