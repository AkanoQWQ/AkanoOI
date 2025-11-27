#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
const int MAXM = MAXN * 2 + 2006 + 1108;
int tot = 1,head[MAXN];
struct Edge{
	int nxt,to;
	bool bri;
}e[MAXM];
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int n,m;
int dfn[MAXN],low[MAXN],cnt,ans[MAXM];
void tarjan(int u,int father){
	dfn[u] = ++cnt;
	low[u] = dfn[u];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u]){
				e[i].bri = 1;
				e[i^1].bri = 1;
			}
		}else if(v != father){
			low[u] = min(low[u],dfn[v]);
		}
	}
	return ;
}
bool vis[MAXN];
void dfs(int u){
	vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(e[i].bri == 1)continue;
		if(ans[i/2] == 0){
			if(i%2 == 0){
				ans[i/2] = 1;
			}else{
				ans[i/2] = 2;
			}
		}
		if(vis[v])continue;
		dfs(v);
	}
	return ;
}
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= m;i++){
		int a,b;
		a = read(),b = read();
		AddEdge(a,b);
		AddEdge(b,a);
	}
	tarjan(1,1);
	for(int i = 1;i <= n;i++){
		if(!vis[i])dfs(i);
	}
	for(int i = 1;i <= m;i++){
		if(e[i*2].bri){
			putchar('0');
		}else{
			if(ans[i] == 0){
				putchar('1');
			}else{
				putchar(ans[i]+'0');
			}
		}
	}
	return 0;
}
