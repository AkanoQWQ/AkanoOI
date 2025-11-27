#include<iostream>
using namespace std;
const int MAXN = 1005;
int G[MAXN][MAXN],n,e; 
// 该图有 n 个点，e 条边 
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		int u,v;
		cin>>u>>v;
		G[u][v] = 1;
		G[v][u] = 1;
	}
	for(int i=0;i<=n;++i){
		cout<<i<<"的邻接点有：";
		for(int j=0;j<=n;++j){
			if(G[i][j]==1){
				cout<<j<<" ";
			} 
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
