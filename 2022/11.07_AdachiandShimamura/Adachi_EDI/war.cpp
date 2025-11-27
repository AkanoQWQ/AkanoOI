#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXM = 500006;
const int MAXN = 250006;
const int MAXK = 5e5;
const int INF = 0x7fffffff;
const ll LINF = 1ll * INF / 2 * INF;
struct Edge{
	int nxt,to,v;
}e[MAXM],e2[MAXM];
int tot = 1,head[MAXN],t2 = 1;
void AddEdge(int from,int to,int w){
	e[++tot].to = to;
	e[tot].v = w;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dep[MAXN],fa[MAXN][24],dfn[MAXN],dnt;
ll le[MAXN];
void dfs(int u,int father){
	dfn[u] = ++dnt;
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			le[v] = min(e[i].v*1ll,le[u]);
			dfs(v,u);
		}
	}
}
int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int stk[MAXN],tp,h2[MAXN],req[MAXK],n,m;
void awa(int from,int to,int v){
	e2[++t2].to = to;
	e2[t2].nxt = h2[from];
	h2[from] = t2;
	return ;
}
void uwu(int from,int to,int v){
	awa(from,to,v);
	awa(to,from,v);
	return ;
}
inline void ins(int u){
	if(tp == 0){
		stk[++tp] = u;
		return ;
	}
	int lc = LCA(u,stk[tp]);
	while(tp > 1 && dep[lc] < dep[stk[tp-1]]){
		uwu(stk[tp-1],stk[tp],le[stk[tp]]);
		tp--;
	}
	if(tp != 0 && dep[lc] < dep[stk[tp]]){
		uwu(lc,stk[tp],le[stk[tp]]);
		tp--;
	}
	if(tp == 0 || stk[tp] != lc){
		stk[++tp] = lc;
	}
	stk[++tp] = u;
	return ;
}
bool est[MAXN];
ll dfs2(int u,int father){
	ll ret = LINF,sum = 0;
	for(int i = h2[u];i;i = e2[i].nxt){
		const int v = e2[i].to;
		if(v != father){
			sum += dfs2(v,u);
		}
	}
	if(est[u]){
		ret = le[u];
	}else{
		ret = min(1ll*le[u],sum);
	}
	est[u] = 0;
	h2[u] = 0;
	return ret;
}
bool cmp(int a,int b){
	return dfn[a] < dfn[b];
}
int main(){
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i < n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	le[1] = LINF;
	dfs(1,1);
	scanf("%d",&m);
	while(m--){
		t2 = 1;
		int k;
		scanf("%d",&k);
		ins(1);
		for(int i = 1;i <= k;i++){
			scanf("%d",&req[i]);
			est[req[i]] = 1;
		}
		sort(req+1,req+k+1,cmp);
		for(int i = 1;i <= k;i++){
			ins(req[i]);
		}
		while(tp > 1){
			uwu(stk[tp-1],stk[tp],le[stk[tp]]);
			tp--;
		}
		ll ans = dfs2(1,1);
		printf("%lld\n",ans);
	}
	return 0;
}
