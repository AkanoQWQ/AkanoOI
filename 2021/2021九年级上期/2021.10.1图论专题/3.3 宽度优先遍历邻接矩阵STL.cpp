#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 110;
struct Edge{
	int to,dis;
};
vector<Edge> G[MAXN];
void add_edge(int u,int v,int d){
	G[u].push_back({v,d});
} 
int n,e,u,v,d,q[MAXN],h,t,vis[MAXN];
void BFS(int be){
	h = t = 0;
	q[t++] = be;
	vis[be] = 1;
	while(h<t){
		int temp = q[h];
		int sz = G[temp].size();
		for(int i=0;i<sz;++i){
			if(vis[G[temp][i].to]==0){
				vis[G[temp][i].to] = 1;
				q[t++] = G[temp][i].to; 
			}
		} 
		cout<<q[h++]<<" ";
	}
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

