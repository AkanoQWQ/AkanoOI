#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int MAXN = 1e5 + 6;
const int MAXM = 2e6 + 6;
const int INF = 1e9;
struct Edge{
	int nxt,to,val,no;
	bool BRI;
}e[MAXM];
struct Edge2{
	int u,v,val,no;
}edges[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,int val,int no){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].no = no;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool cmp(Edge2 _a,Edge2 _b){
	return _a.val < _b.val;
}
int setFa[MAXN];
int GetFa(int x){
	if(setFa[x] == x)return x;
	return setFa[x] = GetFa(setFa[x]);
}
int fa[MAXN][22],maxlen[MAXN][22],dep[MAXN];
void TreeDFS(int u,int father){
	dep[u] = dep[fa[u][0]] + 1;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
		maxlen[u][i] = max(maxlen[u][i-1],maxlen[fa[u][i-1]][i-1]);
	}
 	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father || !e[i].BRI)continue;
		fa[v][0] = u,maxlen[v][0] = e[i].val;
		TreeDFS(v,u);
	}
	return ;
}
int n,m,ans[MAXM];
inline void Kruskal(){
	for(int i = 1;i <= n;i++){
		setFa[i] = i;
	}
	sort(edges+1,edges+m+1,cmp);
	for(int i = 1;i <= m;i++){
		const int x = GetFa(edges[i].u),y = GetFa(edges[i].v);
		if(x != y){
			setFa[y] = x;
			e[edges[i].no*2].BRI = e[edges[i].no*2+1].BRI = true;
		}
	}
	TreeDFS(1,1);
	return ;
}
int LCAVAL(int x,int y){
	int ret = 0;
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			ret = max(ret,maxlen[x][i]);
			x = fa[x][i];
		}
	}
	if(x == y)return ret;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			ret = max(ret,maxlen[x][i]),ret = max(ret,maxlen[y][i]);
			x = fa[x][i],y = fa[y][i];
		}
	}
	return max(ret,max(maxlen[x][0],maxlen[y][0]));
}
int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i],y = fa[y][i];
		}
	}
	return fa[x][0];
}
namespace SLPF{
	class SegmentTree{
		private:
			int val[MAXN * 4],lazy[MAXN * 4];
			int OBJL,OBJR,nowval;
			inline void PushUp(int p){
				val[p] = min(val[p*2],val[p*2+1]);
				return ;
			}
			inline void PushDown(int p){
				if(lazy[p] == INF)return ;
				lazy[p*2] = min(lazy[p*2],lazy[p]);
				lazy[p*2+1] = min(lazy[p*2+1],lazy[p]);
				val[p*2] = min(val[p*2],lazy[p]);
				val[p*2+1] = min(val[p*2+1],lazy[p]);
				lazy[p] = INF;
				return ;
			}
			void Build(int p,int l,int r){
				val[p] = lazy[p] = INF;
				if(l == r)return ;
				const int mid = (l + r) >> 1;
				Build(p*2,l,mid);
				Build(p*2+1,mid+1,r);
				//no PushUp();
				return ;
			}
			void Change(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					val[p] = min(val[p],nowval),lazy[p] = min(lazy[p],nowval);
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJL)Change(p*2,l,mid);
				if(mid < OBJR)Change(p*2+1,mid+1,r);
				PushUp(p);
				return ;
			}
			int Query(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					return val[p];
				}
				int mid = (l + r) >> 1,ret = INF;
				PushDown(p);
				if(mid >= OBJL)ret = min(ret,Query(p*2,l,mid));
				if(mid < OBJR)ret = min(ret,Query(p*2+1,mid+1,r));
				return ret;
			}
		public:
			inline void Build(){
				Build(1,1,n);
				return ;
			}
			inline void Change(int l,int r,int _val,bool IDK){
				if(l > r)return ;
				OBJL = l,OBJR = r,nowval = _val;
				Change(1,1,n);
				return ;
			}
			inline int Query(int l,int r){
				if(l > r)return INF;
				OBJL = l,OBJR = r;
				return Query(1,1,n);
			}
	}tr;
	int heavy[MAXN],dfn[MAXN],dnt,sz[MAXN],top[MAXN];//dep in LCA
	void dfs1(int u,int father){
		sz[u] = 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == father || !e[i].BRI)continue;
			dfs1(v,u);
			sz[u] += sz[v];
			if(sz[v] > sz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	void dfs2(int u,int tp){
		dfn[u] = ++dnt,top[u] = tp;
		if(heavy[u])dfs2(heavy[u],tp);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(!e[i].BRI || dfn[v])continue;
			dfs2(v,v);
		}
		return ;
	}
	inline void Init(){
		tr.Build();
		dfs1(1,1),dfs2(1,1);
		return ;
	}
	inline void Change(int x,int y,int _val){
		//no need to swap(),dep_x > dep_y 
		while(top[x] != top[y]){
			tr.Change(dfn[top[x]],dfn[x],_val,true);
			x = fa[top[x]][0];
		}
		if(x == y)return ;
		tr.Change(dfn[y]+1,dfn[x],_val,true);
		return ;//+1  trans point to edge,avoid Changing other edges
	}
	inline int GetVal(int no){
		int u = e[no].to,v = e[no^1].to;
		if(dep[u] < dep[v])swap(u,v);//dep_u > dep_v
		return tr.Query(dfn[u],dfn[u]);
	}
	inline void UpdateVal(int no){
		int u = e[no].to,v = e[no^1].to;
		int lca = LCA(u,v);
		if(dep[u] < dep[v])swap(u,v);//dep_u > dep_v
		Change(u,lca,e[no].val);
		Change(v,lca,e[no].val);
		return ;
	}
}
inline void EDI(){
	SLPF::Init();
	for(int i = 1;i <= m;i++){
		const int no = i * 2;
		if(!e[no].BRI){
			SLPF::UpdateVal(no);
		}
	}
	return ;
}
inline int Solve(int no){
	int ret = 0;
	if(e[no].BRI)return SLPF::GetVal(no);
	return LCAVAL(e[no].to,e[no^1].to);
}
int main(){
	memset(maxlen,-1,sizeof(maxlen));
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w,i),AddEdge(v,u,w,i);
		edges[i].u = u,edges[i].v = v,edges[i].val = w,edges[i].no = i;
	}
	Kruskal();
	EDI();
	for(int i = 1;i <= m;i++){
		ans[e[i*2].no] = Solve(i*2);
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<'\n';
	}
	cout<<flush;
	return 0;
}
