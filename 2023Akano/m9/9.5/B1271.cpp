#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018 + 1108;
const int MAXM = 2006 + 1018 + 1108;
const int MAXV = 1018; 
const int INF = 1e9;
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
int n,m,no[MAXN],dis[MAXN],way[MAXN];
bool inq[MAXN];
inline bool SPFA(){
	queue<int> q; 
	for(int i = 1;i <= n;i++){
		q.push(i),inq[i] = true;//ÐéÄâÔ´µã 
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				way[v] = way[u] + 1;
				if(way[v] > n + 3){
					return false;
				}
				if(!inq[v]){
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u++,v++;
		n = max(n,v);
		AddEdge(v,u-1,-w);
	}
	for(int i = 0;i < n;i++){
		AddEdge(i+1,i,0);
		AddEdge(i,i+1,1);
	}
	if(SPFA()){
		int mx = -INF,mn = INF;
		for(int i = 1;i <= n;i++){
			mx = max(mx,dis[i]);
			mn = min(mn,dis[i]);
		}
		cout<<mx-mn;
	}else{
		cout<<-1;
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
