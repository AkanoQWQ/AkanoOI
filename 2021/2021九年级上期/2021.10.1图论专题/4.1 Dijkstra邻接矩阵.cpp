#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 110;
int G[MAXN][MAXN],dis[MAXN],vis[MAXN],pre[MAXN];
int n,e,u,v,d;
void Dijkstra(int be){
	for(int i=0;i<=MAXN;++i){
		dis[i] = 0x7fffffff;
	}
	dis[be] = 0;
	for(int k=1;k<=n;++k){
		int tx = -1,tp = 0x7fffffff;
		for(int i=0;i<=n;++i){
			if(vis[i]==0){
				if(dis[i]<tp){
					tx = i;
					tp = dis[i];
				}
			}
		}
		for(int i=0;i<=n;++i){
			if(G[tx][i]!=0&&vis[i]==0)
			if(dis[tx]+G[tx][i]<dis[i]){
				dis[i] = dis[tx]+G[tx][i];
				pre[i] = tx;
			}
		}
		vis[tx] = 1;
	} 
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		cin>>u>>v>>d;
		G[u][v] = d;
		G[v][u] = d;
	}
	Dijkstra(0);
	for(int i=0;i<=n;++i){
		cout<<i<<" "<<dis[i]<<endl;
		for(int j=i;j!=0;j=pre[j]){
			cout<<j<<"->";
		}
		cout<<0;
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
