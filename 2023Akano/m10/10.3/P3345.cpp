#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
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
int n,q,a[MAXN];
namespace HeavyDecomposition{
	class SegmentTree{
	private:
		struct Node{
			ll val,len,lazy;
		}node[MAXN * 4];
		void Build(int p,int l,int r){
			node[p].val = node[p].lazy = 0;
			node[p].len = r - l + 1;
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		inline void PushUp(int p){
			node[p].val = node[p*2].val + node[p*2+1].val;
			return ;
		}
		inline void PushDown(int p){
			if(node[p].lazy == 0)return ;
			node[p*2].lazy += node[p].lazy;
			node[p*2].val += node[p*2].len * node[p].lazy;
			node[p*2+1].lazy += node[p].lazy;
			node[p*2+1].val += node[p*2+1].len * node[p].lazy;
			node[p].lazy = 0;
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,ll _val){
			if(OBJL <= l && r <= OBJR){
				node[p].val += node[p].len * _val;
				node[p].lazy += _val;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		ll Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return node[p].val;
			}
			const int mid = (l + r) >> 1;
			ll ret = 0;
			PushDown(p);
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
		int Find(int p,int l,int r,ll OBJ,ll preSum){
			if(l == r){
				if(2 * (preSum + node[p].val) >= OBJ){
					return l;
				}
				return n;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(2 * (preSum + node[p*2].val) >= OBJ){
				return min(mid,Find(p*2,l,mid,OBJ,preSum));
			}
			return Find(p*2+1,mid+1,r,OBJ,preSum + node[p*2].val);
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int l,int r,ll _val){
			Change(1,1,n,l,r,_val);
			return ;
		}
		inline ll Query(int l,int r){
			return Query(1,1,n,l,r);
		}
		inline int FindRootVal(){
			return Find(1,1,n,node[1].val,0);
		}
		inline ll Root(){
			return node[1].val;
		}
	}tr;
	int dfn[MAXN],dnt,siz[MAXN],heavy[MAXN],top[MAXN],fa[MAXN][22],dep[MAXN],org[MAXN];
	void dfs1(int u){
		siz[u] = 1,dep[u] = dep[fa[u][0]] + 1;
		for(int i = 1;i <= 20;i++){
			fa[u][i] = fa[fa[u][i-1]][i-1];
		}
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u][0])continue;
			fa[v][0] = u;
			dfs1(v);
			siz[u] += siz[v];
			if(siz[v] > siz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	void dfs2(int u,int tp){
		dfn[u] = ++dnt,top[u] = tp;
		org[dnt] = u;
		if(heavy[u])dfs2(heavy[u],tp);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u][0] || v == heavy[u])continue;
			dfs2(v,v);
		}
		return ;
	}
	inline void Init(){
		dfs1(1);
		dfs2(1,1);
		tr.Build();
		return ;
	}
	inline void Change(int u,ll w){
		tr.Change(dfn[u],dfn[u],w);
		return ;
	}
};
inline bool Judge(int x){
	using namespace HeavyDecomposition;
	return 2 * tr.Query(dfn[x],dfn[x] + siz[x] - 1) > tr.Root();
}
inline int Solve(){
	using namespace HeavyDecomposition;
	int ret = org[tr.FindRootVal()];
	for(int i = 20;i >= 0;i--){
		if(fa[ret][i] == 0)continue;
		if(Judge(fa[ret][i]) == false){
			ret = fa[ret][i];
		}
	}
	if(Judge(ret) == false)ret = fa[ret][0];
	if(ret <= 0)ret = 1;//???WHY
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v),AddEdge(v,u);
	}
	HeavyDecomposition::Init();
	while(q--){
		int u,w;
		cin>>u>>w;
		HeavyDecomposition::Change(u,w);
		cout<<Solve()<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
