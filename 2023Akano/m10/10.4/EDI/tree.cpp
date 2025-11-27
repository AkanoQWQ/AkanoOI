#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXBLK = 1018 + 1108;
const int MAXN = 6e5 + 1018 + 1108;
const int NodeSize = 5e6;
const ll INF = 1e14;//够吗?
const ll PosINF = 1e6;
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
int n,q,kruFather[MAXN];
ll oldA[MAXN],a[MAXN],eval[MAXN],cache[MAXN];//把边泉挂在重构树的点上
//eval和a都已经映射到了dfn上
vector<pair<int,pii> > orgEdge;
inline void ReadIn(){
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>oldA[i];
	}
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		orgEdge.emplace_back(-w,make_pair(u,v));
	}
	return ;
}
namespace disjointUnion{
	int fa[MAXN];
	int Find(int x){
		if(fa[x] == x)return x;
		return fa[x] = Find(fa[x]);
	}
	inline void Init(int x){
		for(int i = 1;i <= x;i++)fa[i] = i;
		return ;
	}
}
namespace HeavyDecomposition{
	int dfn[MAXN],dep[MAXN],siz[MAXN],heavy[MAXN],fa[MAXN],top[MAXN],org[MAXN],dnt;
	
	inline void KruskalRemake(){
		int nnt = n;
		disjointUnion::Init(2 * n);
		sort(orgEdge.begin(),orgEdge.end());
		for(auto edge : orgEdge){
			nnt++;
			eval[nnt] = -edge.first;
			int u = edge.second.first,v = edge.second.second;
			u = disjointUnion::Find(u),v = disjointUnion::Find(v);
			if(u == v){
				cerr<<"ERR"<<endl;
				cerr<<edge.second.first<<" and "<<edge.second.second<<" already together"<<endl;
			}
			AddEdge(nnt,u),AddEdge(nnt,v);
			AddEdge(u,nnt),AddEdge(v,nnt);
			disjointUnion::fa[u] = nnt;
			disjointUnion::fa[v] = nnt; 
		}
		n = nnt;
		return ;
	}
	
	struct Segment{
		ll k,b;
		Segment(){
			k = 0,b = -INF;
			return ;
		}
		Segment(ll _k,ll _b){
			k = _k,b = _b;
			return ;
		}
		inline ll Calc(ll x){
			return k * x + b;
		}
	};
	ostream& operator<<(ostream& os,Segment seg){
		os<<"("<<seg.k<<"*x+"<<seg.b<<")";
		return os;
	}
	
	inline bool Cmp(Segment s1,Segment s2,ll x){
		ll _y1 = s1.Calc(x),_y2 = s2.Calc(x);
		return (_y1 > _y2);
	}
	
	struct Node{
		int l,r;
		Segment seg;
	}node[NodeSize];//共享内存
	
	int lazyCnt;
	
	class LiChaoSegmentTree{
	private:
		int root;
		int PushDown(int p,int l,int r,Segment v){
			if(!p){
				p = ++lazyCnt;
			}
			Segment& u = node[p].seg;
			const int mid = (l + r) >> 1;
			if(Cmp(v,u,mid))swap(u,v);
			bool psdL = Cmp(v,u,l),psdR = Cmp(v,u,r);
			if(psdL)node[p].l = PushDown(node[p].l,l,mid,v);
			if(psdR)node[p].r = PushDown(node[p].r,mid+1,r,v);
			return p;
		}
		int Change(int p,int l,int r,int OBJL,int OBJR,const Segment& v){
			if(!p){
				p = ++lazyCnt;
			}
			if(OBJL <= l && r <= OBJR){
				p = PushDown(p,l,r,v);//其实这个赋值没用
				return p;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)node[p].l = Change(node[p].l,l,mid,OBJL,OBJR,v);
			if(mid < OBJR)node[p].r = Change(node[p].r,mid+1,r,OBJL,OBJR,v);
			return p;
		}
		ll Query(int p,int l,int r,ll pos){
			if(!p)return -INF;
			ll ret = node[p].seg.Calc(pos);
			if(l == r)return ret;
			const int mid = (l + r) >> 1;
			if(mid >= pos)ret = max(ret,Query(node[p].l,l,mid,pos));
			if(mid < pos)ret = max(ret,Query(node[p].r,mid+1,r,pos));
			return ret;
		}
	public:
		inline void Change(int l,int r,Segment v){
			root = Change(root,-PosINF,PosINF,l,r,v);
			return ;
		}
		inline ll Query(int pos){
			return Query(root,-PosINF,PosINF,pos);
		}
		inline void Clear(){
			root = 0;//考虑回收?
			return ;
		}
	};
	
	void dfs1(int u){
		siz[u] = 1,dep[u] = dep[fa[u]] + 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u])continue;
			fa[v] = u;
			dfs1(v);
			siz[u] += siz[v];
			if(siz[v] > siz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	void dfs2(int u,int tp){
		dfn[u] = ++dnt,top[u] = tp;
		org[dnt] = u;
		a[dnt] = oldA[u];
		if(heavy[u]){
			dfs2(heavy[u],tp);
			a[dfn[u]] += a[dfn[heavy[u]]];
		}
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u] || v == heavy[u])continue;
			dfs2(v,v);
			a[dfn[u]] += a[dfn[v]];
		}
		return ;
	}
	
	int belong[MAXN],blk_len,blk_cnt;
	struct Block{
		int controlL,controlR,lazy;
		LiChaoSegmentTree tr;
		inline void Build(){
			tr.Clear();
			for(int i = controlL;i <= controlR;i++){
				a[i] += lazy;
				ll val = eval[i] * a[i];
				tr.Change(-PosINF,PosINF,Segment(eval[i],val));
				val = tr.Query(0);
			}
			lazy = 0;
			return ;
		}
		inline ll Query(){
			return tr.Query(lazy);
		}
	}block[MAXBLK];
	inline void Init(){
		dfs1(n);
		dfs2(n,n);
		//映射eval
		for(int i = 1;i <= n;i++){
			cache[dfn[i]] = eval[i];
		}
		memcpy(eval,cache,sizeof(eval));
		blk_len = 800;//对固定块长进行调参
		for(int i = 1;i <= n;i++){
			belong[i] = ((i-1) / blk_len) + 1;
			if(block[belong[i]].controlL == 0)block[belong[i]].controlL = i;
			block[belong[i]].controlR = i;
		}
		blk_cnt = belong[n];
		for(int i = 1;i <= blk_cnt;i++){
			block[i].Build();
		}
		return ;
	}
	inline void Change(int l,int r,int val){//l,r已经是dfn了
		int blkL = belong[l],blkR = belong[r];
		//特判边界
		if(blkL == blkR){
			for(int i = l;i <= r;i++){
				a[i] += val;
			}
			block[blkL].Build();
			return ;
		}
		//暴力重构散块
		for(int i = l;i <= block[blkL].controlR;i++){
			a[i] += val;
		}
		for(int i = block[blkR].controlL;i <= r;i++){
			a[i] += val;
		}
		block[blkL].Build(),block[blkR].Build();
		//整块打标记
		for(int i = blkL + 1;i <= blkR - 1;i++){
			block[i].lazy += val;
		}
		return ;
	}
}
inline void Update(int u,int newval){
	using namespace HeavyDecomposition;
	ll delta = newval - oldA[u];
	oldA[u] = newval;
	u = fa[u];
	while(u){
		Change(dfn[top[u]],dfn[u],delta);
		u = fa[top[u]];
	}
	return ;
}
inline ll Query(){
	using namespace HeavyDecomposition;
	ll ret = -INF;
	for(int i = 1;i <= blk_cnt;i++){
		ret = max(ret,block[i].Query());
	}
	return ret;
}
inline void Solve(){
	while(q--){
		int obj,newval;
		cin>>obj>>newval;
		Update(obj,newval);
		cout<<Query()<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	HeavyDecomposition::KruskalRemake();
	HeavyDecomposition::Init();
	Solve();
	return not(Akano loves pure__Elysia);
}
