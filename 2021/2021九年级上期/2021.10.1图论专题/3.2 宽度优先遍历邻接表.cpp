#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 110,MAXE = 10010;
struct Edge{
	int to,dis,next;
};
Edge edge[MAXE];
int n,e,cnt,u,v,d,head[MAXN],vis[MAXN];
int q[MAXN],h,t;
void add_edge(int u,int v,int d){
	++cnt;
	edge[cnt].next = head[u];
	head[u] = cnt;
	edge[cnt].to = v;
	edge[cnt].dis = d;
}
void BFS(int be){
	h = t = 0;
	q[t++] = be;
	vis[be] = 1;
	while(h<t){
		for(int i=head[q[h]];i!=0;i=edge[i].next){
			if(vis[edge[i].to]==0){
				q[t++] = edge[i].to;
				vis[edge[i].to] = 1;
			}
		}
		cout<<q[h++]<<" ";
	}
	return ;
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		cin>>u>>v>>d;
		add_edge(u,v,d);
		add_edge(v,u,d);
	}
	BFS(0);
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
