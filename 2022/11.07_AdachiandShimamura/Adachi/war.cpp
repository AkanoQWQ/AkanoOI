#include<bits/stdc++.h>
using namespace std;
const int MAXM = 500006;
const int MAXN = 250006;
const int MAXK = 20;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to,v;
}e[MAXM];
int tot = 1,head[MAXN];
void AddEdge(int from,int to,int w){
	e[++tot].to = to;
	e[tot].v = w;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dep[MAXN],le[MAXN],fa[MAXN][24];
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			le[v] = min(e[i].v,le[u]);
			dfs(v,u);
		}
	}
}
int n,m;
int mset[MAXK],tail;
void show(){
	for(int i = 1;i <= tail;i++){
		cout<<mset[i]<<" ";
	}
	cout<<endl;
	return ;
}
void ins(int inx){
	for(int i = 1;i <= tail;i++){
		if(inx == mset[i])return ;
	}
	mset[++tail] = inx;
	return ;
}
void ers(int ox){
	for(int i = 1;i <= tail;i++){
		if(mset[i] == ox){
			for(int j = i;j < tail;j++){
				mset[j] = mset[j+1];
			}
			tail--;
			return ;
		}
	}
	return ;
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
void solve(){
	while(1){
		bool cg = 0;
		for(int i = 1;i <= tail;i++){
			for(int j = i+1;j <= tail;j++){
				int lc = LCA(mset[i],mset[j]);
				if(lc != 1 && le[lc] < le[mset[i]] + le[mset[j]]){
					int era = mset[i],erb = mset[j];
					ers(era);
					ers(erb);
					ins(lc);
					cg = 1;
				}
				if(cg)break;
			}
			if(cg)break;
		}
		if(!cg || tail == 1)break;
	}
	return ;
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
	le[1] = INF/4;
	dfs(1,1);
	scanf("%d",&m);
	while(m--){
		int k;
		scanf("%d",&k);
		tail = 0;
		while(k--){
			int c;
			scanf("%d",&c);
			ins(c);
		}
		solve();
		int ans = 0;
		for(int i = 1;i <= tail;i++){
			ans += le[mset[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
