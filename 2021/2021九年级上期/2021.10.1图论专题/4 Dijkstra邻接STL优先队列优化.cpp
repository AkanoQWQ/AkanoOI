#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 110;
const int INF = 0x7fffffff;
struct Edge{
	int to,dis;
};
vector<Edge> G[MAXN];
struct Dis{
	int i,dis;
	friend bool operator < (Dis x,Dis y){
		x.dis>y.dis;
	}
};
priority_queue<Dis> pq;
void add_edge(int u,int v,int d){
	Edge e;
	e.to = v;e.dis = d;
	G[u].push_back(e);
} 
int n,e,u,v,d,pre[MAXN],vis[MAXN],dis[MAXN];
int Dijkstra(int be){
	for(int i=0;i<=n;++i){
		dis[i] = INF;
	}
	dis[be] = 0;
	Dis temp;
	temp.i = be;
	temp.dis = 0;
	pq.push(temp);
	while(!pq.empty()){
		int td = pq.top().dis;
		int tp = pq.top().i;
		int sz = G[tp].size();
		pq.pop();
		for(int i=0;i<sz;++i){
			int des = G[tp][i].to;
			int cost = G[tp][i].dis;
			if(dis[des]>dis[tp]+cost){
				dis[des] = dis[tp]+cost;
				pre[des] = tp;
				pq.push({des,dis[des]});
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
