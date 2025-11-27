#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
struct Edge{
	int nxt,to;	
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
struct Node{
	int l,r,val,mx;
};
Node node[MAXN * 32];
int tot,n,q,bel[MAXN],w[MAXN];
class SegmentTree{
	private:
		int OBJL,OBJR,OBJ,_val,root;
		inline void PushUp(int p){
			node[p].val = node[node[p].l].val + node[node[p].r].val;
			node[p].mx = max(node[node[p].l].mx,node[node[p].r].mx);
			return ;
		}
		int ChangeInner(int p,int l,int r){
			if(p == 0){
				p = ++tot;
				node[p].val = node[p].l = node[p].r = node[p].mx = 0;
			}
			if(l == r){
				node[p].val = node[p].mx = _val;
				return p;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)node[p].l = ChangeInner(node[p].l,l,mid);
			if(mid < OBJ)node[p].r = ChangeInner(node[p].r,mid+1,r);
			PushUp(p);
			return p;
		}
		int QuerySum(int p,int l,int r){
			if(OBJL <= l && r <= OBJR){
				return node[p].val;
			}
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL && node[p].l != 0)ret = QuerySum(node[p].l,l,mid);
			if(mid < OBJR && node[p].r != 0)ret += QuerySum(node[p].r,mid+1,r);
			return ret;
		}
		int QueryMx(int p,int l,int r){
			if(OBJL <= l && r <= OBJR){
				return node[p].mx;
			}
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL && node[p].l != 0)ret = max(ret,QueryMx(node[p].l,l,mid));
			if(mid < OBJR && node[p].r != 0)ret = max(ret,QueryMx(node[p].r,mid+1,r));
			return ret;
		}
	public:
		inline void Change(int pos,int inval){
			OBJ = pos,_val = inval;
			ChangeInner(root,1,MAXN);
			return ;
		}
		inline int QuerySum(int l,int r){
			OBJL = l,OBJR = r;
			return QuerySum(root,1,MAXN);
		}
		inline int QueryMx(int l,int r){
			OBJL = l,OBJR = r;
			return QueryMx(root,1,MAXN);
		}
		inline void Init(){
			root = ++tot;
			return ;
		}
		SegmentTree(){Init();}
}tr[MAXN];
namespace SLPF{
	int sz[MAXN],heavy[MAXN],fa[MAXN],r00t = 1;
	void dfs1(int u){
		sz[u] = 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u])continue;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if(sz[v] > sz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	int dfn[MAXN],dnt,top[MAXN],dep[MAXN];
	void dfs2(int u,int tp){
		top[u] = tp,dep[u] = dep[fa[u]] + 1,dfn[u] = ++dnt;
		if(heavy[u])dfs2(heavy[u],tp);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == heavy[u] || v == fa[u])continue;
			dfs2(v,v); 
		}
		return ; 
	}
	inline void Solve(){
		dfs1(r00t);
		dfs2(r00t,r00t);
		return ;
	}
	inline int QuerySum(int x,int y){
		const int c = bel[x];
		int ret = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])swap(x,y);//dep_top_x > dep_top_y
			ret += tr[c].QuerySum(dfn[top[x]],dfn[x]);
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])swap(x,y);//dep_x < dep_y
		ret += tr[c].QuerySum(dfn[x],dfn[y]);
		return ret;
	}
	inline int QueryMax(int x,int y){
		const int c = bel[x];
		int ret = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]])swap(x,y);//dep_top_x > dep_top_y
			ret = max(ret,tr[c].QueryMx(dfn[top[x]],dfn[x]));
			x = fa[top[x]];
		}
		if(dep[x] > dep[y])swap(x,y);//dep_x < dep_y
		ret = max(ret,tr[c].QueryMx(dfn[x],dfn[y]));
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P3313_1.in","r",stdin);
	freopen("P3313.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>w[i]>>bel[i];
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	SLPF::Solve();
	for(int i = 1;i <= n;i++){
		tr[bel[i]].Change(SLPF::dfn[i],w[i]);
	}
	for(int nowq = 1;nowq <= q;nowq++){
		string opt;
		int x,c,y;
		cin>>opt;
		if(opt == "CC"){
			cin>>x>>c;
			tr[bel[x]].Change(SLPF::dfn[x],0);
			bel[x] = c;
			tr[bel[x]].Change(SLPF::dfn[x],w[x]);
		}else if(opt == "CW"){
			cin>>x;
			cin>>w[x];
			tr[bel[x]].Change(SLPF::dfn[x],w[x]);
		}else if(opt == "QS"){
			cin>>x>>y;
			cout<<SLPF::QuerySum(x,y)<<'\n';
		}else{
			cin>>x>>y;
			cout<<SLPF::QueryMax(x,y)<<'\n';
		}
	}
	return 0;
}
