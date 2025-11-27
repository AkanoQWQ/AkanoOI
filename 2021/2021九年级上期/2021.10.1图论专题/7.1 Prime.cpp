#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
const int INF = 1e9+7;
int dis[MAXN],tot,vis[MAXN];
vector<pair<int,int> > E[MAXN];
int n,e,u,v,d; 
void Prime(){
	for(int i=1;i<=n;++i){
		dis[i] = INF;
	}
	dis[0] = 0;
	for(int k=0;k<=n;++k){
		int val = INF,pos = -1;
		for(int i=0;i<=n;++i){
			if(dis[i]<val&&vis[i]==0){
				val = dis[i];
				pos = i;
			}
		} 	
		cout<<pos<<" "<<val<<endl;
		tot+=val;
		vis[pos] = 1;
		for(int i=0;i<E[pos].size();++i){
			int to = E[pos][i].first;
			int dist = E[pos][i].second;
			if(vis[to]==0)
				dis[to] = min(dis[to],dist);
		}
	}
}
int main(){
	scanf("%d %d",&n,&e);
	for(int i=1;i<=e;++i){
		scanf("%d %d %d",&u,&v,&d);
		E[u].push_back(pair<int,int>(v,d));
		E[v].push_back(pair<int,int>(u,d));
	}
	
	Prime();
	cout<<tot;
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
