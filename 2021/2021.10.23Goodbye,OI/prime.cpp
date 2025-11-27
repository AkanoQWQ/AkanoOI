#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
const int MAXM = 200006;
const int INF = (1<<30);
int dis[MAXN],n,m,a,b,c,val,ps;
vector<pair<int,int> >E[MAXM];
bool vis[MAXN];
void prim(int BE){
	for(int i = 1;i <= n;i++)dis[i] = INF;
	dis[BE] = 0;
	for(int k = 0;k < n;k++){
		int pos = -1;
		int mmin = INF;
		for(int i = 1;i <= n;i++){
			if(dis[i] < mmin && vis[i] == 0){
				mmin = dis[i];
				pos = i;
			}
		}
		if(pos == -1)return ;
		val += dis[pos],vis[pos] = 1,ps++;
		for(int i = 0;i < E[pos].size();++i){
			int to = E[pos][i].first;
			int w = E[pos][i].second;
			if(vis[to] == 0){
				dis[to] = min(dis[to],w);
			}
		}
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < m;i++){
		cin>>a>>b>>c;
		E[a].push_back(pair<int,int>(b,c));
		E[b].push_back(pair<int,int>(a,c));
	}
	prim(1);
	if(ps < n){
		cout<<"orz";
		return 0;
	}
	cout<<val;
	return 0;
}
/*
5 6
1 2 3
2 3 4
3 1 4
4 5 6
5 4 6
1 3 5

*/
