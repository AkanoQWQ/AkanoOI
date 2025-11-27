#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 1e5+10;
const int INF = 1e9+7;
vector<pair<int,int> > E[MAXN]; 
queue<int> Q;
int n,e,u,v,d,inq[MAXN],dis[MAXN];
void SPFA(int be){
	for(int i=0;i<=n;++i)	dis[i] = INF;
	dis[be] = 0;
	Q.push(be);
	inq[be] = 1;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		inq[now] = 0;
		for(int i=0;i<E[now].size();++i){
			int to = E[now][i].first;
			int dist = E[now][i].second;
			if(dis[to]>dis[now]+dist){
				dis[to] = dis[now]+dist;
				if(inq[to]==0){
					Q.push(to);
					inq[to] = 1;
				}
			}
		}
	}
}
int main(){
	cin>>n>>e;
	for(int i=1;i<=e;++i){
		cin>>u>>v>>d;
		E[u].push_back(pair<int,int>(v,d));
		E[v].push_back(pair<int,int>(u,d));
	}
	SPFA(0);
	for(int i=0;i<=n;++i){
		printf("%d %d\n",i,dis[i]);
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
