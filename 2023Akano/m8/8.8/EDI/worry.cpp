#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108; 
const int MAXM = MAXN * 2;
struct Edge{
	int nxt,to;
}e[MAXM];
struct Road{
	int u,v,w;
}r[MAXN];
bool Cmp(Road r1,Road r2){
	return r1.w < r2.w;
}
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
namespace SLPF{
	const int INF = 2e9 + 1018 + 1108;
	struct Node{
		int val,lazy;
	};
	class SegmentTree{
		private:
			Node node[MAXN * 4];
			inline void PushUp(int p){
				node[p].val = min(node[p*2].val,node[p*2+1].val);
				return ;
			}
			inline void PushDown(int p){
				if(node[p].lazy == INF)return ;
				node[p*2].val = min(node[p*2].val,node[p].lazy);
				node[p*2].lazy = min(node[p*2].lazy,node[p].lazy);
				node[p*2+1].val = min(node[p*2+1].val,node[p].lazy);
				node[p*2+1].lazy = min(node[p*2+1].lazy,node[p].lazy);
				node[p].lazy = INF;
				return ;
			}
			void Build(int p,int l,int r){
				node[p].lazy = node[p].val = INF;
				if(l == r)return ;
				const int mid = (l + r) >> 1;
				Build(p*2,l,mid),Build(p*2+1,mid+1,r);
				return ;
			}
			void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
				if(OBJL <= l && r <= OBJR){
					node[p].val = min(node[p].val,_val);
					node[p].lazy = min(node[p].lazy,_val);
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
				if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
				PushUp(p);
				return ;
			}
			int Query(int p,int l,int r,int OBJL,int OBJR){
				if(OBJL <= l && r <= OBJR){
					return node[p].val;
				}
				const int mid = (l + r) >> 1;
				int ret = INF;
				PushDown(p);
				if(mid >= OBJL)ret = min(ret,Query(p*2,l,mid,OBJL,OBJR));
				if(mid < OBJR)ret = min(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
				return ret;
			}
		public:
			inline void Build(){
				Build(1,1,n);
				return ;
			}
			inline void Change(int l,int r,int _val){
				if(l > r){
					return ;
				}
				Change(1,1,n,l,r,_val);
				return ;
			}
			inline int Query(int l,int r){
				return Query(1,1,n,l,r);
			}
	}tr;
	int dfn[MAXN],dnt,fa[MAXN],dep[MAXN],sz[MAXN],heavy[MAXN],top[MAXN],upper[MAXN],ans[MAXN];
	void dfs1(int u){
		sz[u] = 1,dep[u] = dep[fa[u]] + 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u])continue;
			fa[v] = u;
			upper[v] = i / 2;
			dfs1(v);
			if(sz[v] > sz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	void dfs2(int u,int tp){
		dfn[u] = ++dnt,top[u] = tp;
		if(heavy[u] != 0){
			dfs2(heavy[u],tp);
		}
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u] || v == heavy[u])continue;
			dfs2(v,v);
		}
		return ;
	}
	inline void Change(int u,int v,int _val){
		while(top[u] != top[v]){
			if(dep[top[u]] < dep[top[v]])swap(u,v);//dep_topu > dep_topv
			tr.Change(dfn[top[u]],dfn[u],_val);
			u = fa[top[u]];
		}
		if(dep[u] > dep[v])swap(u,v);//dep_u < dep_v
		tr.Change(dfn[u]+1,dfn[v],_val);//+1,maybe -,not include u
		return ;
	}
	inline void Query(){
		for(int i = 2;i <= n;i++){
			int val = tr.Query(dfn[i],dfn[i]);
			ans[upper[i]] = val;
		}
		return ;
	}
	inline void Solve(){
		dfs1(1);
		dfs2(1,1);
		tr.Build();
		for(int i = 1;i <= m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			Change(u,v,w);
		}
		Query();
		for(int i = 1;i < n;i++){
			if(ans[i] == INF)ans[i] = -1;
			cout<<ans[i]<<'\n';
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("worry.in","r",stdin);
	freopen("worry.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	SLPF::Solve();
	return 0;
}
