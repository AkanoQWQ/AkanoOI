#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 206;
bool e[MAXN][MAXN],vis[MAXN];
int ans,n;
void dfs(int u,int now){
	if(now == n){
		ans++;
		return ;
	}
	vis[u] = true;
	for(int v = 1;v <= n;v++){
		if(vis[v] || !e[u][v])continue;
		dfs(v,now+1);
	}
	vis[u] = false;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>e[i][j];
		}
	}
	for(int i = 1;i <= n;i++)dfs(i,1);
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
