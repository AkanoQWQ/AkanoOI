#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN = 1e5 + 6;
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
	int nxt,to;
}e[MAXN*2];
int head[MAXN],ent = 1;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,m,r,mod,a[MAXN];
int dfn[MAXN],dnt,top[MAXN],fa[MAXN],sz[MAXN],son[MAXN],dep[MAXN],org[MAXN];
void dfs1(int u,int father){
	fa[u] = father,sz[u] = 1;
	dep[u] = dep[father] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs1(v,u);
		if(son[u] == 0 || sz[v] > sz[son[u]]){
			son[u] = v;
		}
		sz[u] += sz[v];
	}
	return ;
}
void dfs2(int u,int tp){
	dfn[u] = ++dnt,top[u] = tp;
	org[dnt] = u;
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
struct SegmentTree{
	int v,lazy,len;
}t[MAXN*4 + 6];
inline void pushup(int p){
	if(t[p].len != 1){
		t[p].v = (t[p*2].v + t[p*2+1].v) % mod;
	}
	return ;
}
inline void pushdown(int p){
	if(t[p].lazy != 0 && t[p].len != 1){
		t[p*2].v = (t[p*2].v + 1ll * t[p*2].len * t[p].lazy) % mod;
		t[p*2+1].v = (t[p*2+1].v + 1ll * t[p*2+1].len * t[p].lazy) % mod;
		t[p*2].lazy += t[p].lazy,t[p*2+1].lazy += t[p].lazy;// MOD
		t[p].lazy = 0;
	}
	return ;
}
void build(int l,int r,int p){
	t[p].lazy = 0;
	t[p].len = r - l + 1;
	if(l == r){
		t[p].v = a[org[l]] % mod;
		return ;
	}
	const int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	pushup(p);
	return ;
}
void update(int l,int r,int objl,int objr,int p,int val){
	if(objl <= l && r <= objr){
		t[p].v = (t[p].v + 1ll * t[p].len * val) % mod;
		t[p].lazy += val;//MOD
		return ;
	}
	const int mid = (l + r) >> 1;
	pushdown(p);
	if(mid >= objl)update(l,mid,objl,objr,p*2,val);
	if(mid < objr)update(mid+1,r,objl,objr,p*2+1,val);
	pushup(p);
	return ;
}
int query(int l,int r,int objl,int objr,int p){
	if(objl <= l && r <= objr){
		return t[p].v;
	}
	const int mid = (l + r) >> 1;
	int ret = 0;
	pushdown(p);
	if(mid >= objl)ret = query(l,mid,objl,objr,p*2);
	if(mid < objr)ret = (ret + query(mid+1,r,objl,objr,p*2+1)) % mod;
	return ret;
}
namespace SLPF{
	void SLPF_update(int x,int y,int z){
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])swap(x,y);
			update(1,n,dfn[top[x]],dfn[x],1,z);
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])swap(x,y);
		update(1,n,dfn[x],dfn[y],1,z);
		return ;
	}
	int SLPF_query(int x,int y){
		int ret = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])swap(x,y);
			ret = (ret + query(1,n,dfn[top[x]],dfn[x],1)) % mod;
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])swap(x,y);
		ret = (ret + query(1,n,dfn[x],dfn[y],1)) % mod;
		return ret;
	}
}
int main(){
	n = read(),m = read(),r = read(),mod = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	for(int i = 1;i < n;i++){
		int u = read(),v = read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	dfs1(r,r);
	dfs2(r,r);
	build(1,n,1);
	while(m--){
		int opt = read(),x = read(),y,z;
		if(opt == 1){
			y = read(),z = read();
			SLPF::SLPF_update(x,y,z);
		}else if(opt == 2){
			y = read();
			write(SLPF::SLPF_query(x,y)),putchar('\n');
		}else if(opt == 3){
			z = read();
			update(1,n,dfn[x],dfn[x]+sz[x]-1,1,z);
		}else{
			write(query(1,n,dfn[x],dfn[x]+sz[x]-1,1)),putchar('\n');
		}
	}
	return 0;
}
