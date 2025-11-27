#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5006;
const int MAXM = (5006*5006) / 2;
struct edge{
	ll u,v;
}e[MAXM];
ll mp[MAXN][MAXN],n,m,cnt,cost = 0;
bool cmp4edge(edge a,edge b){
	return (mp[a.u][a.v] + mp[a.v][a.u]) < (mp[b.u][b.v] + mp[b.v][b.u]);
}
int fa[MAXN];
int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
int main(){
	freopen("season.in","r",stdin);
	freopen("season2.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b,c,d,w;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&w);
		for(int i = a;i <= b;i++){
			mp[i][c] += w;
			mp[i][d+1] -= w;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			mp[i][j] += mp[i][j-1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			e[++cnt].u = i;
			e[cnt].v = j;
		}
	}
	sort(e+1,e+cnt+1,cmp4edge);
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= cnt;i++){
		const int faa = find(e[i].u);
		const int fab = find(e[i].v);
		if(faa != fab){
			fa[fab] = faa;
			cost += mp[e[i].u][e[i].v] + mp[e[i].v][e[i].u];
		}
	}
	printf("%lld",cost);
	return 0;
}

