#include<bits/stdc++.h>
using namespace std;
const int MAXN = 602006;
int n,s;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct Edge{
	int nxt,to,v;
}e[MAXN*4];
int head[MAXN],tot = 1;
void AddEdge(int from,int to,int val){
	e[++tot].to = to;
	e[tot].v = val;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int maxval,ans = 0x7fffffff;
void dfs(int u,int fa,int val){
	if(val > maxval)maxval = val;
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to != fa)dfs(e[i].to,u,val + e[i].v);
	}
	return ;
}//dek dekstra
int farpos,dis[MAXN],dek,maldek,profundo[MAXN],diametro[MAXN],d2[MAXN],fa[MAXN];
int lend,tail2;
bool estas_diametro[MAXN];
void FindDiametro(int x,int y){
	diametro[++lend] = x;
	d2[++tail2] = y;
	while(x != y && fa[x] != y && fa[y] != x){
		if(profundo[x] > profundo[y]){
			x = fa[x];
			diametro[++lend] = x;
		}else{
			y = fa[y];
			d2[++tail2] = y;
		}
	}
	for(int i = tail2;i >= 1;i--){
		diametro[++lend] = d2[i];
	}
	return ;
}
void dfs(int u,int father){
	if(!fa[u])fa[u] = father;
	if(!profundo[u])profundo[u] = profundo[father] + 1;
	if(dis[u] > dis[farpos])farpos = u;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father || estas_diametro[v])continue;
		dis[v] = dis[u] + e[i].v;
		dfs(v,u);
	}
	return ;
}
int main(){
	freopen("fire.in","r",stdin);
	freopen("fire.out","w",stdout);
	n = read(),s = read();
	for(int i = 1;i < n;i++){
		int a = read(),b = read();
		int c = read();
		AddEdge(a,b,c);
		AddEdge(b,a,c);
	}
	dfs(1,1);
	maldek = farpos;
	farpos = 0;
	dis[maldek] = 0;
	dfs(maldek,maldek);
	dek = farpos;
	FindDiametro(dek,maldek);
	tail2 = 0;
	for(int i = 1;i <= lend;i++){
		estas_diametro[diametro[i]] = 1;
		while(dis[diametro[i]] - dis[diametro[tail2+1]] <= s && tail2+1 <= lend)tail2++;
		ans = min(ans,max(dis[diametro[1]]-dis[diametro[i]],dis[diametro[tail2]]));
	}
	for(int i = 1;i <= lend;i++){
		dis[diametro[i]] = 0;
		dfs(diametro[i],diametro[i]);
	}
	for(int i = 1;i <= n;i++){
		ans = max(ans,dis[i]);
	}
	printf("%d",ans);
	return 0;
}
