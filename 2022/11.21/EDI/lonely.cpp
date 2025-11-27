#pragma GCC optmize(2)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 6;
struct Edge{
	int nxt,to;
}e[MAXN*2];
int head[MAXN],tot;
const bool deb = 0;
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dep[MAXN],son[MAXN],sz[MAXN],fa[MAXN],top[MAXN],dnt,dfn[MAXN];
void dfs1(int u,int father){
	dep[u] = dep[father] + 1;
	sz[u] = 1;
	fa[u] = father;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]){
			son[u] = v;
		}
	}
	return ;
}
void dfs2(int u,int tp){
	dfn[u] = ++dnt;
	top[u] = tp;
	if(son[u] != 0){
		dfs2(son[u],tp);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u] || v == son[u])continue;
		dfs2(v,v);
	}
	return ;
}
int t,n,q;
struct segment_tree{
	int v,lk,rk,lazy,len;	
}tr[MAXN*4];
void build(int l,int r,int p){
	tr[p].v = 0;
	tr[p].lk = l;
	tr[p].rk = r;
	tr[p].len = r - l + 1;
	tr[p].lazy = 0;
	if(l == r)return ;
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
inline void pushup(int p){
	tr[p].v = tr[p*2].v + tr[p*2+1].v + (tr[p*2].rk == tr[p*2+1].lk);
	tr[p].lk = tr[p*2].lk,tr[p].rk = tr[p*2+1].rk;
	return ;
}
inline void pushdown(int p){
	if(tr[p].lazy != 0){
		tr[p*2].v = tr[p*2].len - 1,tr[p*2].lazy = tr[p].lazy;
		tr[p*2].lk = tr[p].lazy,tr[p*2].rk = tr[p].lazy;
		tr[p*2+1].v = tr[p*2+1].len - 1,tr[p*2+1].lazy = tr[p].lazy;
		tr[p*2+1].lk = tr[p].lazy,tr[p*2+1].rk = tr[p].lazy;
		tr[p*2].lazy = tr[p].lazy,tr[p*2+1].lazy = tr[p].lazy;
		tr[p].lazy = 0;
	}
	return ;
}
void update(int l,int r,int objl,int objr,int p,int kol){
	if(objl <= l && r <= objr){
		tr[p].lazy = kol;
		tr[p].lk = kol;
		tr[p].rk = kol;
		tr[p].v = tr[p].len - 1;
		return ;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if(mid >=objl)update(l,mid,objl,objr,p*2,kol);
	if(mid < objr)update(mid+1,r,objl,objr,p*2+1,kol);
	pushup(p);
	return ;
}
int ask(int l,int r,int objl,int objr,int p){
	if(objl <= l && r <= objr){
		return tr[p].v;
	}
	pushdown(p);
	int mid = (l + r) >> 1,ret = 0;
	if(mid >= objl)ret = ask(l,mid,objl,objr,p*2);
	if(mid < objr)ret += ask(mid+1,r,objl,objr,p*2+1);
	if(mid >= objl && mid < objr)ret += (tr[p*2].rk == tr[p*2+1].lk);
	return ret;
}
int getkol(int l,int r,int obj,int p){
	if(l == obj && r == obj){
		return tr[p].lk;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if(mid >= obj)return getkol(l,mid,obj,p*2);
	if(mid < obj)return getkol(mid+1,r,obj,p*2+1);
	return 0;
}
namespace SLPF{
	void SLPF_change(int x,int y,int kol){
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])swap(x,y);
			update(1,n,dfn[top[x]],dfn[x],1,kol);
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])swap(x,y);
		update(1,n,dfn[x],dfn[y],1,kol);
		return ;
	}
	int SLPF_query(int x,int y){
		int ret = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])swap(x,y);
			ret += ask(1,n,dfn[top[x]],dfn[x],1);
			if(getkol(1,n,dfn[fa[top[x]]],1) == getkol(1,n,dfn[top[x]],1)){
				ret++;
			}
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])swap(x,y);
		ret += ask(1,n,dfn[x],dfn[y],1);
		return ret;
	}
}
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
		x = -x;
		putchar('-');
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int main(){
	freopen("lonely.in","r",stdin);
	freopen("lonely.out","w",stdout);
	t = read();
	while(t--){
		n = read();
		q = read();
		tot = 1;
		dnt = 0;
		for(int i = 0;i <= n;i++){
			head[i] = 0;
			son[i] = 0;
		}
		for(int i = 1;i < n;i++){
			int u = read(),v = read();
			AddEdge(u,v);
			AddEdge(v,u);
		}
		dep[1] = 0;
		dfs1(1,1);
		dfs2(1,1);
		build(1,dnt,1);
		int k = n;
		while(q--){
			int opt = read(),u = read(),v = read();
			++k;
			if(opt == 1){
				SLPF::SLPF_change(u,v,k);
			}else{
				write(SLPF::SLPF_query(u,v));
				putchar('\n');
			}
		}
	}
	return 0;
}
