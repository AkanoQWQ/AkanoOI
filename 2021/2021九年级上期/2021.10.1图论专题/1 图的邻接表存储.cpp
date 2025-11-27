#include<iostream>
using namespace std;
const int MAXN = 10005,MAXE = 10005*10005;
int head[MAXN],e,n,cnt;//总共n个点 e条边
// cnt 记录当前统计到第几条边 
struct Edge{
	int next,v,dis;
	// v 表示当前边的目的地
	// dis 表示当前边的长度
	// next 表示当前边的下一条边的位置 
}; 
Edge edge[MAXE];
void add_edge(int u,int v,int dis){	
	++cnt;	
	edge[cnt].next = head[u];
	head[u] = cnt;
	edge[cnt].v = v;
	edge[cnt].dis = dis;
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		int u,v;
		cin>>u>>v;	
		add_edge(u,v,1);
	}
	
	for(int i=0;i<=n;++i){
		cout<<i<<"的邻接点有：";
		for(int j=head[i];j!=0;j=edge[j].next){
			cout<<edge[j].v<<" ";
		}
		cout<<endl; 
	} 
	return 0;
}
/*
12 13
0 1
0 2
0 5
0 6
3 4
3 5
4 5
4 6
7 8
9 10
9 11
9 12
11 12
*/
