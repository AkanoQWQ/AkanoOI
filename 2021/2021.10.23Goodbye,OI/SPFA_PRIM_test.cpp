#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5006;
const int MAXM = 200006;
const int INF = (1<<30);
int n,m,dis[MAXN],a,b,c,pts,val;
vector<pair<int,int> >edg[MAXM];
bool vis[MAXN];
void prim(int BE){
	for(int i = 1;i <= n;i++)dis[i] = INF;
	dis[BE] = 0;
	for(int k = 0;k < n;k++){
		int pos = -1,mmin = INF;
		for(int i = 1;i <= n;i++){
			if(dis[i] < mmin && vis[i] == 0){
				pos = i,mmin = dis[i];
			}
		}
		if(pos == -1)return ;
		pts++,val += dis[pos],vis[pos] = 1;
		for(int i = 0;i < edg[pos].size();i++){
			int to = edg[pos][i].first;
			int dist = edg[pos][i].second;
			dis[to] = min(dis[to],dist);
		}
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	while(m--){
		cin>>a>>b>>c;
		edg[a].push_back(pair<int,int>(b,c));
		edg[b].push_back(pair<int,int>(a,c));
	}
	prim(1);
	if(pts < n){
		cout<<"orz";
		return 0;
	}
	cout<<val;
	return 0;
}

