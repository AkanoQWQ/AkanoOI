#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10006;
const int MAXM = 500006;
const int INF = 0x7fffffff;
int n,m,ST;
struct edg{
	int from,to,v;
}edg_[MAXM];
struct edge{
	int to,v;
};
vector<edge> e[MAXN];
void AddEdge(int u,int v,int w){
	edge a;
	a.to = v,a.v = w;
	e[u].push_back(a);
	return ;
}
bool cmp4edg(edg a,edg b){
	return a.v < b.v;
}
int tail = 1;
int dis[MAXN],mans = INF;
bool inq[MAXN];
queue<int> q;
void SPFA(){
	for(int i = 1;i <= n;i++)dis[i] = INF;
	memset(inq,0,sizeof(inq));
	inq[ST] = 1;
	dis[ST] = 0;
	while(!q.empty())q.pop();
	q.push(ST);
	while(!q.empty()){
		const int u = q.front();
		inq[u] = 0;
		q.pop();
		for(int i = 0;i < e[u].size();i++){
			const int v = e[u][i].to;
			if(dis[u] + e[u][i].v < dis[v]){
				dis[v] = dis[u] + e[u][i].v;
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("P3371_3.in","r",stdin);
	//freopen("iut.out","w",stdout);
	cin>>n>>m>>ST;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w);
	}
	SPFA();
	for(int i = 1;i <= n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
