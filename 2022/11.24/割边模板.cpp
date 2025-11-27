#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 6;
const int MAXM = 2e5 + 6;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,from;
	bool est;
}e[MAXM];
int head[MAXN],ent = 1;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].est = 0;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,m,dfn[MAXN],low[MAXN],dnt,ans;
bool GD[MAXN];
void tarjan(int u,int fa){
	int child = 0;
	dfn[u] = low[u] = ++dnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			child++;
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u]){
				e[i].est = 1;
				ans++;
			}
		}else if(v != fa){
			low[u] = min(low[u],dfn[v]);
		}
	}
	return ;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= m;i++){
		int u = read(),v = read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])tarjan(i,-1);
	}
	write(ans),putchar('\n');
	for(int i = 2;i <=ents;i++){
		if(GD[i])write(i),putchar(' ');
	}
	return 0;
}
