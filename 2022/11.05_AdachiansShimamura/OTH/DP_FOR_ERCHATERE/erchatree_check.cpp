#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 4e6+6;
ll n,m,ans[MAXN],x,dfn;
void dfs(int u){
	if(u > n)return ;
	ans[u] = ++dfn;
	dfs(u*2);
	dfs(u*2+1);
	return ;
}
int main(){
	freopen("erchatree.in","r",stdin);
	freopen("erchatree.ans","w",stdout);
	scanf("%lld%lld",&n,&m);
	dfs(1);
	while(m--){
		scanf("%lld",&x);
		printf("%lld\n",ans[x]);
	}
	return 0;
}
