#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 110,MAXE = 10010;
const int INF = 1e9; 
struct Edge{
	int from,to,dis,next;
}; 
Edge edge[MAXE];
int cnt,head[MAXN],dis[MAXN];
void add_edge(int u,int v,int d){
	++cnt;
	edge[cnt].next = head[u];
	head[u] = cnt;
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].dis = d;
}
int u,v,d,n,e;
int Bellman_Ford(int be){
	for(int i=0;i<=n;++i){
		dis[i] = INF;
	}
	dis[be] = 0;
	for(int k=1;k<n;++k){
		int flag = 0;
		for(int i=1;i<=cnt;++i){
			int from = edge[i].from;
			int to = edge[i].to;
			int ds = edge[i].dis;
			if(dis[to]>dis[from]+ds){
				dis[to] = dis[from] + ds; 
				flag = 1;
			}
		} 
		if(flag == 0){
			return 0;
		}
	}
	int flag = 0;
	for(int i=1;i<=cnt;++i){
		int from = edge[i].from;
		int to = edge[i].to;
		int ds = edge[i].dis;
		if(dis[to]>dis[from]+ds){
			dis[to] = dis[from] + ds; 
			flag = 1;
		}
	}
	if(flag!=0){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i) {
		cin>>u>>v>>d;
		add_edge(u,v,d);
		add_edge(v,u,d);
	}
	Bellman_Ford(0);
	for(int i=0;i<=n;++i){
		printf("%d %d\n",i,dis[i]);
	}

}
