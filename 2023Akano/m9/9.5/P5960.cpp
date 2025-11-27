#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e4;
const int MAXM = 1e4;
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
int n,m,dis[MAXN],way[MAXN];
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
				if(way[v] > n)return false;
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
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(v,u,w);
	}
	if(SPFA()){
		for(int i = 1;i <= n;i++){
			cout<<dis[i]<<" ";
		}
	}else{
		cout<<"NO";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
