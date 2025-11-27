#include<bits/stdc++.h>
using namespace std;
const int N = 20006,M = 20006 * 2,INF = 1<<30;
int i,j,next[M],first[M],v[M],son[M],cnt,n,ans,size = INF,x,y;
bool vis[M];
void add(int x,int y){
	next[++cnt] = first[x];
	first[x] = cnt;
	v[cnt] = y;
}
void dfs(int cur){
	vis[cur] = 1;
	son[cur] = 0;
	int tmp = 0;
	for(int i = first[cur];i;next[i]){
		int u = v[i];
		if(!vis[u]){
			dfs(u);
			son[cur] += son[u]+1;
			tmp = max(tmp,son[u]+1);             
		}
	}
	tmp = max(tmp,n-son[cur]-1);
	if(tmp < size || tmp == size && cur < ans){
		ans = cur;
		size = tmp;
	}
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1);
	cout<<ans<<" "<<size;
	return 0;
}

