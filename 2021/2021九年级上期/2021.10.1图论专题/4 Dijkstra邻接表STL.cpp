#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 110;
const int INF = 0x7fffffff;
struct Edge{
	int to,dis;
};
vector<Edge> G[MAXN];
void add_edge(int u,int v,int d){
	Edge e;
	e.to = v;e.dis = d;
	G[u].push_back(e);
}
int n,e,u,v,d,dis[MAXN],vis[MAXN],pre[MAXN];
void Dijkstra(int be){
	for(int i=0;i<=MAXN;++i){
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[be] = 0;
	for(int k=0;k<=n;++k){
		int tx = INF,tp = -1;
		for(int i=0;i<=n;++i){
			if(vis[i]==0&&dis[i]<tx){
				tx = dis[i];
				tp = i;
			}
		}
		vis[tp] = 1;
		int sz = G[tp].size();
		for(int i=0;i<sz;++i){
			if(dis[G[tp][i].to]>dis[tp] + G[tp][i].dis){
				dis[G[tp][i].to] = dis[tp] + G[tp][i].dis;
				pre[G[tp][i].to] = tp; 
			}
		}
	}
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		cin>>u>>v>>d;
		add_edge(u,v,d);
		add_edge(v,u,d);
	}
	Dijkstra(0);
	pre[0] = -1;
	for(int i=0;i<=n;++i){
		cout<<i<<" "<<dis[i]<<endl;
		for(int j=i;j!=-1;j=pre[j]){
			cout<<j<<"->";
		}
		cout<<endl;
	}
	return 0;
}
/*
8 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 5 14
3 4 9
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
