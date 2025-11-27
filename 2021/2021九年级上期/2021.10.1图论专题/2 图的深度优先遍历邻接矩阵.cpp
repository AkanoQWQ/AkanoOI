#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 100;
int G[MAXN][MAXN],vis[MAXN];
int n,e,u,v,d; 
int DFS(int be){
	cout<<be<<" ";
	vis[be] = 1;
	for(int i=n;i>=0;--i){
		if(G[be][i]!=0&&vis[i]==0){
			DFS(i);
		}
	}
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		cin>>u>>v>>d;
		G[u][v] = d;
		G[v][u] = d;
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

