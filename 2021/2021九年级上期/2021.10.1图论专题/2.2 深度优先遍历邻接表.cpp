#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 110,MAXE = 10010;
struct Edge{
	int to,dis,next;
	/*to 终点		dis 边权	next 下一条边的位置 */ 
};
Edge edge[MAXE]; 
int head[MAXN],n,e,cnt;
int vis[MAXN];
void add_edge(int from,int to,int dis){
	++cnt;
	edge[cnt].next = head[from];
	head[from] = cnt;
	edge[cnt].to = to;
	edge[cnt].dis = dis;
} 
void DFS(int be){
	cout<<be<<" ";
	vis[be] = 1;
	for(int i=head[be];i!=0;i=edge[i].next){
		if(vis[edge[i].to]==0){
			DFS(edge[i].to);
		}
	} 
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		int u,v,d;
		cin>>u>>v>>d;
		add_edge(u,v,d);
		add_edge(v,u,d);
	}
	DFS(0);
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

