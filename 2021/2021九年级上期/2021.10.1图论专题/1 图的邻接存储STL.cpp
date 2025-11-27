#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 10005;
struct Edge{
	int v,d;
};
vector<Edge> G[MAXN];
void add_edge(int u,int v,int d){
	Edge e;e.v = v;e.d = d;
	G[u].push_back(e);
}
int n,e;
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		int u,v;
		cin>>u>>v;
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	for(int i=0;i<=n;++i){
		int sz = G[i].size();
		cout<<i<<"的邻接点有：";
		for(int j=0;j<sz;++j){
			cout<<G[i][j].v<<" ";
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

