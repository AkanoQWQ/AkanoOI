#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100006

vector<pair<int,int> >adj[MAX_N];
long long dis[MAX_N];
bool vis[MAX_N];
int n,k,q;

void dfs(int v){
	vis[v] = true;
	for(int i = 0;i < adj[v].size();i++){
		int u = adj[v][i].first;
		int w = adj[v][i].second;
		if(!vis[u]){
			dis[u] = dis[v] + w;
			dfs(u);
		}
		return ;
	}
} 
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	cin>>q>>k;
	dfs(k);
	while(q--){
		/* TODO (admin#4#): what */
		
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dis[x]+dis[y]);
	}
	return 0;
}
/* TODO (stb#2#): test */

