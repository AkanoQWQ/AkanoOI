#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400006;
const int MAXM = MAXN * 2;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],ent = 1;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,q;
string opt;
string sread(){
	string ret = "";
	char ch = getchar();
	while(ch < 'a' || ch > 'z'){
		ch = getchar();
	}
	while(ch >= 'a' && ch <= 'z'){
		ret += ch;
		ch = getchar();
	}
	return ret;
}
int child[MAXN],fa[MAXN],sz[MAXN],dep[MAXN];
void dfs1(int u,int father){
	sz[u] = 1,fa[u] = father,dep[u] = dep[father] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs1(v,u);
		if(child[u] == 0 || sz[v] > sz[child[u]]){
			child[u] = v;
		}
		sz[u] += sz[v];
	}
	return ;
}
int dfn[MAXN],dnt,top[MAXN];
void dfs2(int u,int tp){
	dfn[u] = ++dnt,top[u] = tp;
	if(child[u] != 0){
		dfs2(child[u],tp);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u] || v == child[u])continue;
		dfs2(v,v);
	}
	return ;
}
struct Segment_tree{
	int lazy,v,sz;
}t[MAXN*5];
void build(int l,int r,int p){
	t[p].sz = r - l + 1;
	t[p].lazy = -1;
	t[p].v = 0;
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
void pushdown(int p){
	if(t[p].sz > 1 && t[p].lazy != -1){
		t[p*2].v = t[p*2].sz * t[p].lazy;
		t[p*2+1].v = t[p*2+1].sz * t[p].lazy;
		t[p*2].lazy = t[p].lazy,t[p*2+1].lazy = t[p].lazy;//!!!!!debug 1h!!!!!!
		t[p].lazy = -1;
	}
	return ;
}
void pushup(int p){
	if(t[p].sz == 1)return ;
	t[p].v = t[p*2].v + t[p*2+1].v;
	return ;
}
void update(int l,int r,int objl,int objr,int p,int val){
	if(objl <= l && r <= objr){
		t[p].v = t[p].sz * val;
		t[p].lazy = val;
		return ;
	}
	if(t[p].lazy != -1)pushdown(p);
	int mid = (l + r) / 2;
	if(mid >= objl)update(l,mid,objl,objr,p*2,val);
	if(mid < objr)update(mid+1,r,objl,objr,p*2+1,val);
	pushup(p);
	return ;
}
void change(int x,int y,int val){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]])swap(x,y);
		update(1,n,dfn[top[x]],dfn[x],1,val);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	update(1,n,dfn[x],dfn[y],1,val);
	return ;
}
int main(){
	//freopen("P2146.in","r",stdin);
	//freopen("P2146.out","w",stdout);
	scanf("%d",&n);
	for(int i = 2;i <= n;i++){
		int x;
		scanf("%d",&x);
		AddEdge(x+1,i);
		AddEdge(i,x+1);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,n,1);
	scanf("%d",&q);
	while(q--){
		opt = sread();
		int x;
		scanf("%d",&x);
		x++;
		int org = t[1].v,aft = 114514;
		if(opt[0] == 'i'){
			change(1,x,1);
		}else{
			update(1,n,dfn[x],dfn[x]+sz[x]-1,1,0);
		}
		aft = t[1].v;
		printf("%d\n",abs(org-aft));
	}
	return 0;
}
