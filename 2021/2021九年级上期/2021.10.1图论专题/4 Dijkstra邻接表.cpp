#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 110,MAXE = 10010;
int head[MAXN];
struct Edge{
	int to,dis,next;
};
Edge edge[MAXE];
int cnt;
void add_edge(int u,int v,int d){
	++cnt;
	edge[cnt].next = head[u];
	head[u] = cnt;
	edge[cnt].to = v;
	edge[cnt].dis = d;
}
int n,e,u,v,d,dis[MAXN],pre[MAXN],vis[MAXN];
void Dijkstra(int be){
	for(int i=0;i<=n;++i){
		dis[i] = 0x7fffffff;
	}
	dis[be] = 0;
	for(int k=0;k<=n;++k){
		int tx = 0x7fffffff,tp = -1;
		for(int i=0;i<=n;++i){
			if(vis[i]==0){
				if(dis[i]<tx){
					tx = dis[i];
					tp = i;
				}
			}
		}
		vis[tp] = 1;
		for(int i=head[tp];i!=0;i=edge[i].next){
			int to = edge[i].to;
			if(dis[to]>dis[tp]+edge[i].dis){
				dis[to] = dis[tp] + edge[i].dis;
				pre[to] =tp;
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

