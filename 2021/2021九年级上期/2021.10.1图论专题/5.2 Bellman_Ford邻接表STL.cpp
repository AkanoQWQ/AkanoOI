#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
const int INF = 1e9+7;
vector<pair<int,int> > E[MAXN];
int dis[MAXN],n,e,u,v,d;
int Bellman_Ford(int be){
	for(int i=0;i<=n;++i){
		dis[i] = INF;
	}
	dis[be] = 0;
	for(int k=1;k<= n;++k){
		int f = 0;
		for(int i=0;i<=n;++i){
			for(int j=0;j<E[i].size();++j){
				int to = E[i][j].first;
				int dist = E[i][j].second;
				if(dis[to]>dis[i]+dist){
					dis[to] = dis[i] + dist;
					f = 1;
				}
			}
		}
		if(f==0){
			return 0;
		}
	}
	int f = 0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<E[i].size();++j){
			int to = E[i][j].first;
			int dist = E[i][j].second;
			if(dis[to]>dis[i]+dist){
				dis[to] = dis[i]+dist;
				f = 1;
			} 
		}
	}
	if(f==0){
		return 0;
	}else{
		return 1;
	}
} 
int main(){
	scanf("%d %d",&n,&e);
	for(int i=1;i<=e;++i){
		scanf("%d %d %d",&u,&v,&d);
		E[u].push_back(pair<int,int>(v,d));
		E[v].push_back(pair<int,int>(u,d));
	}
	Bellman_Ford(0);
	for(int i=0;i<=n;++i){
		printf("%d %d\n",i,dis[i]);
	}
	return 0;
}

