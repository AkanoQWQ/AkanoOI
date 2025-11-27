#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
const int MAXM = 2e5 + 6;
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
}
int n,m;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],tot = 1;
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dnt,dfn[MAXN],sz[MAXN],fa[MAXN];
void dfs(int u,int father){
	dfn[u] = ++dnt;
	fa[u] = father;
	sz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
	return ;
}
struct req{
	int a,b,v,t,lst,nxt;
}r[MAXM];
int rnt = 2,rfir,rlst,pos[MAXN];//1 fir  2 lst
void ins(int ina,int inb,int inv,int inint){
	++rnt;
	const int llst = r[2].lst;
	r[llst].nxt = rnt;
	r[2].lst = rnt;
	r[rnt].lst = llst;
	r[rnt].a = ina,r[rnt].b = inb,r[rnt].v = inv,r[rnt].t = inint;
	pos[inint] = rnt;
	return ;
}
int cnto = 0;
void del(int t){
	int llst = r[pos[t]].lst;
	int nnxt = r[pos[t]].nxt;
	r[llst].nxt = nnxt;
	r[nnxt].lst = llst;
	return ;
}
int query(int x){
	int ret = -1;
	int pos = r[1].nxt;
	while(pos > 2){
		int a = -1,b = -1;
		int j = 0;
		for(int i = head[x];i;i = e[i].nxt){
			j++;
			const int v = e[i].to;
			if(v == fa[x])continue;
			if(dfn[r[pos].a] >= dfn[v] && dfn[r[pos].a] <= dfn[v]+sz[v]-1){
				a = j;
			}
			if(dfn[r[pos].b] >= dfn[v] && dfn[r[pos].b] <= dfn[v]+sz[v]-1){
				b = j;
			}
		}
		if(a == b && (r[pos].a != x && r[pos].b != x)){
			ret = max(ret,r[pos].v);
		}
		pos = r[pos].nxt;
	}
	return ret;
}
int main(){
	freopen("worknet.in","r",stdin);
	freopen("worknet.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i < n;i++){
		int u = read(),v = read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	dfs(1,0);
	r[1].nxt = 2;
	r[2].lst = 1;
	for(int t = 1;t <= m;t++){
		int opt = read();
		if(opt == 0){
			int a = read(),b = read(),v = read();
			ins(a,b,v,t);
		}else if(opt == 1){
			int x = read();
			del(x);
		}else if(opt == 2){
			int x = read();
			write(query(x)),putchar('\n');
		}
	}
	return 0;
}
