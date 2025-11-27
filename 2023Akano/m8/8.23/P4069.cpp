#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const ll INF = 123456789123456789;
struct Edge{
	int nxt,to;
	ll val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
namespace HLD{
	ll dfn[MAXN],dnt,sz[MAXN],dep[MAXN],fa[MAXN],heavy[MAXN],top[MAXN],dis[MAXN],org[MAXN];
	namespace LCA{
		int lcafa[MAXN][22];
		inline void Pre(int u){
			for(int i = 1;i <= 20;i++){
				lcafa[u][i] = lcafa[lcafa[u][i-1]][i-1];
			}
			return ;
		}
		inline int LCA(int u,int v){
			if(dep[u] < dep[v])swap(u,v);
			for(int i = 20;i >= 0;i--){
				if(dep[lcafa[u][i]] >= dep[v]){
					u = lcafa[u][i];
				}
			}
			if(u == v)return u;
			for(int i = 20;i >= 0;i--){
				if(lcafa[u][i] != lcafa[v][i]){
					u = lcafa[u][i];
					v = lcafa[v][i];
				}
			}
			return lcafa[u][0];
		}
	}
	struct Segment{
		ll k,b;
		Segment(){k = 0,b = INF;}
		Segment(ll _k,ll _b){k = _k,b = _b;}
		inline ll Calc(ll x){
			return k * dis[org[x]] + b;
		}
	};
	inline bool Cmp(Segment s1,Segment s2,ll x){
		return s1.Calc(x) < s2.Calc(x);
	}
	class LiChaoSegmentTree{
		private:
			Segment lazy[MAXN * 8];
			ll val[MAXN * 8];
			inline void PushUp(int p,int l,int r){
				val[p] = min(val[p*2],val[p*2+1]);
				val[p] = min(val[p],lazy[p].Calc(l));
				val[p] = min(val[p],lazy[p].Calc(r));
				return ;
			}
			inline void PushDown(int p,int l,int r,Segment v){
				Segment& u = lazy[p];
				const int mid = (l + r) >> 1;
				if(Cmp(v,u,mid))swap(u,v);
				if(l == r){
					PushUp(p,l,r);
					return ;//OK??????
				}
				bool psdL = Cmp(v,u,l),psdR = Cmp(v,u,r);
				if(psdL)PushDown(p*2,l,mid,v);
				if(psdR)PushDown(p*2+1,mid+1,r,v);
				PushUp(p,l,r);
				return ;
			}
			void Change(int p,int l,int r,int OBJL,int OBJR,Segment v){
				if(OBJL <= l && r <= OBJR){
					PushDown(p,l,r,v);
					PushUp(p,l,r);
					return ;
				}
				const int mid = (l + r) >> 1;
				if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,v);
				if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,v);
				PushUp(p,l,r);
				return ;
			}
			ll Query(int p,int l,int r,int OBJL,int OBJR){
				if(OBJL <= l && r <= OBJR){
					return val[p];
				}
				const int mid = (l + r) >> 1;
				ll ret = INF;
				if(top[org[l]] == top[org[r]]){
					ret = min(lazy[p].Calc(max(OBJL,l)),lazy[p].Calc(min(OBJR,r)));
				}
				if(mid >= OBJL)ret = min(ret,Query(p*2,l,mid,OBJL,OBJR));
				if(mid < OBJR)ret = min(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
				return ret;
			}
		public:
			inline void Init(){
				fill(val,val+MAXN*8,INF);
				return ;
			}
			inline void Change(int l,int r,Segment v){
				Change(1,1,MAXN,l,r,v);
				return ;
			}
			inline ll Query(int l,int r){
				return Query(1,1,MAXN,l,r);
			}
	}tr;
	void dfs1(int u){
		sz[u] = 1;
		LCA::lcafa[u][0] = fa[u];
		LCA::Pre(u);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u])continue;
			fa[v] = u,dep[v] = dep[u] + 1,dis[v] = dis[u] + e[i].val;
			dfs1(v);
			sz[u] += sz[v];
			if(sz[v] > sz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	void dfs2(int u,int tp){
		dfn[u] = ++dnt,top[u] = tp,org[dnt] = u;
		if(heavy[u])dfs2(heavy[u],tp);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u] || v == heavy[u])continue;
			dfs2(v,v);
		}
		return ;
	}
	inline void Solve(){
		dis[1] = 1,dep[1] = 1;
		dfs1(1),dfs2(1,1);
		tr.Init();
		return ;
	}
	inline void Insert(int u,int v,ll k,ll b){
		const int lca = LCA::LCA(u,v);
		Segment inv1 = Segment(-k,b - dis[u] * (-k));
		while(top[u] != top[lca]){
			tr.Change(dfn[top[u]],dfn[u],inv1);
			u = fa[top[u]];
		}
		tr.Change(dfn[lca],dfn[u],inv1);
		ll newb = inv1.Calc(dfn[lca]);
		Segment inv2 = Segment(k,newb - dis[lca] * k);
		while(top[v] != top[lca]){
			tr.Change(dfn[top[v]],dfn[v],inv2);
			v = fa[top[v]];
		}
		tr.Change(dfn[lca],dfn[v],inv2);
		return ;
	}
	inline ll Query(int u,int v){
		ll ret = INF;
		while(top[u] != top[v]){
			if(dep[top[u]] < dep[top[v]])swap(u,v);
			ret = min(ret,tr.Query(dfn[top[u]],dfn[u]));
			u = fa[top[u]];
		}
		if(dep[u] > dep[v])swap(u,v);
		ret = min(ret,tr.Query(dfn[u],dfn[v]));
		return ret;
	}
}
int n,q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	HLD::Solve();
	while(q--){
		ll opt,s,t,a,b;
		cin>>opt;
		if(opt == 1){
			cin>>s>>t>>a>>b;
			HLD::Insert(s,t,a,b);
		}else{
			cin>>s>>t;
			cout<<HLD::Query(s,t)<<'\n';
		}
	}
	return 0;
}
