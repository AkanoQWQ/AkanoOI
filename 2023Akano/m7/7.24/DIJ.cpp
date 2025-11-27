#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 6;
const int MAXM = 6e5 + 6;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to,val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	e[cnt].val = val;
	head[from] = cnt;
	return ;
}
int n,m,ST,dis[MAXN];
bool vis[MAXN];
inline void DIJ(){
	priority_queue<pair<int,int> > q;
	for(int i = 1;i <= n;i++){
		dis[i] = INF;
		vis[i] = false;
	}
	dis[ST] = 0;
	q.push(make_pair(-dis[ST],ST));
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>ST;
	while(m--){
		int u,v,t;
		cin>>u>>v>>t;
		AddEdge(u,v,t);
	}
	DIJ();
	for(int i = 1;i <= n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
