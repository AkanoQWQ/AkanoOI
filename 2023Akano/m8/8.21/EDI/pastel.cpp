#include<bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const int MAXN = 3e5 + 1018 + 1108;
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
namespace Container{
	template<typename T>
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = len = 0;}
	};
	template<typename T,int SIZE>
	class SegmentTree{//支持区间加减,查询区间和的线段树 
		private:
			SegmentTreeNode<T> node[(SIZE + 4) * 4];
			int OBJL,OBJR,_val;
			T* arr;
			inline void PushUp(int p){
				node[p].val = node[p*2].val + node[p*2+1].val;
				return ;
			}
			inline void PushDown(int p){
				if(node[p].lazy == 0)return ;
				node[p*2].val += node[p*2].len * node[p].lazy;
				node[p*2+1].val += node[p*2+1].len * node[p].lazy;
				node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
				node[p].lazy = 0;
				return ;
			}
			void Build(int p,int l,int r){
				node[p].len = r - l + 1;
				if(l == r){
					if(arr != nullptr){
						node[p].val = arr[l];
					}
					return ;
				}
				const int mid = (l + r) >> 1;
				Build(p*2,l,mid),Build(p*2+1,mid+1,r); 
				PushUp(p);
				return ;
			}
			void ChangeInner(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					node[p].val += _val * node[p].len;
					node[p].lazy += _val;
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJL)ChangeInner(p*2,l,mid);
				if(mid < OBJR)ChangeInner(p*2+1,mid+1,r);
				PushUp(p);
				return ;
			}
			T Query(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					return node[p].val;
				}
				const int mid = (l + r) >> 1;
				T ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = Query(p*2,l,mid);
				if(mid < OBJR)ret += Query(p*2+1,mid+1,r);
				return ret;
			}
		public:
			inline void Build(){
				Build(1,1,SIZE);
				return ;
			}
			inline void Build(T* _arr){
				arr = _arr;
				Build(1,1,SIZE);
				arr = nullptr;
				return ;
			}
			inline void Change(int l,int r,int inval){
				OBJL = l,OBJR = r,_val = inval;
				ChangeInner(1,1,SIZE);
				return ;
			}
			inline T Query(int l,int r){
				OBJL = l,OBJR = r;
				return Query(1,1,SIZE);
			}
			SegmentTree(){
				Build();
				return ;
			}
			SegmentTree(T* _arr){
				Build(_arr);
				return ;
			}
	};
	template<typename T,int SIZE>
	class BIT{
		private:
			T val[SIZE];
			inline int Lowbit(int x){
				return x & (-x);
			}
			inline T QueryPre(int x){
				T ret = 0;
				while(x){
					ret += val[x];
					x -= Lowbit(x);
				}
				return ret;
			}
		public:
			inline void Change(int x,T _val){
				while(x <= SIZE){
					val[x] += _val;
					x += Lowbit(x);
				}
				return ;
			}
			inline T Query(int l,int r){
				return QueryPre(r) - QueryPre(l-1);
			}
	};
	struct SST_Node{
		ui val,sz,sum,lazy;
	};
	class SpecialSegmentTree{ 
		private:
			SST_Node node[MAXN * 4];
			inline void PushUp(int p){
				node[p].val = node[p*2].val + node[p*2+1].val;
				node[p].sz = node[p*2].sz + node[p*2+1].sz;
				node[p].sum = node[p*2].sum + node[p*2+1].sum;
				return ;
			}
			inline void Add(int p,ui _val){
				node[p].val += _val,node[p].sum += node[p].sz * _val;
				node[p].lazy += _val;
				return ;
			}
			inline void PushDown(int p){
				Add(p*2,node[p].lazy),Add(p*2+1,node[p].lazy);
				node[p].lazy = 0;
				return ;
			}
			void ChangeVal(int p,int l,int r,int OBJL,int OBJR,ui _val){
				if(OBJL <= l && r <= OBJR){
					Add(p,_val);
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJL)ChangeVal(p*2,l,mid,OBJL,OBJR,_val);
				if(mid < OBJR)ChangeVal(p*2+1,mid+1,r,OBJL,OBJR,_val);
				PushUp(p);
				return ;
			}
			void ChangeSize(int p,int l,int r,int OBJ,ui _val){
				if(l == r){
					node[p].sz += _val,node[p].sum += _val * node[p].val;
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJ)ChangeSize(p*2,l,mid,OBJ,_val);
				if(mid < OBJ)ChangeSize(p*2+1,mid+1,r,OBJ,_val);
				PushUp(p);
				return ;
			}
			ui QuerySum(int p,int l,int r,int OBJL,int OBJR){
				if(OBJL <= l && r <= OBJR){
					return node[p].sum;
				}
				const int mid = (l + r) >> 1;
				ui ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = QuerySum(p*2,l,mid,OBJL,OBJR);
				if(mid < OBJR)ret += QuerySum(p*2+1,mid+1,r,OBJL,OBJR);
				return ret;
			}
			ui QuerySize(int p,int l,int r,int OBJL,int OBJR){
				if(OBJL <= l && r <= OBJR){
					return node[p].sz;
				}
				const int mid = (l + r) >> 1;
				ui ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = QuerySize(p*2,l,mid,OBJL,OBJR);
				if(mid < OBJR)ret += QuerySize(p*2+1,mid+1,r,OBJL,OBJR);
				return ret;
			}
			ui QueryVal(int p,int l,int r,int OBJL,int OBJR){
				if(OBJL <= l && r <= OBJR){
					return node[p].val;
				}
				const int mid = (l + r) >> 1;
				ui ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = QueryVal(p*2,l,mid,OBJL,OBJR);
				if(mid < OBJR)ret += QueryVal(p*2+1,mid+1,r,OBJL,OBJR);
				return ret;
			}
		public:
			int SIZE;
			inline void ChangeVal(int l,int r,ui _val){
				ChangeVal(1,1,SIZE,l,r,_val);
				return ;
			}
			inline void ChangeSize(int pos,ui _val){
				ChangeSize(1,1,SIZE,pos,_val);
				return ;
			}
			inline ui QuerySum(int l,int r){
				if(r > l)return 0;
				return QuerySum(1,1,SIZE,l,r);
			}
			inline ui QuerySize(int l,int r){
				if(r > l)return 0;
				return QuerySize(1,1,SIZE,l,r);
			}
			inline ui QueryVal(int l,int r){
				if(r > l)return 0;
				return QueryVal(1,1,SIZE,l,r);
			}
	}SST;
}
namespace HLD{
	int dfn[MAXN],siz[MAXN],dnt,heavy[MAXN],fa[MAXN],top[MAXN],org[MAXN];
	set<int> bel[MAXN];
	void dfs1(int u){
		siz[u] = 1;
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
		top[u] = tp,dfn[u] = ++dnt,org[dnt] = u;
//		cerr<<u<<" dfn "<<dfn[u]<<endl;
		if(heavy[u])dfs2(heavy[u],tp);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u] || v == heavy[u])continue;
			dfs2(v,v);
		}
		return ;
	}
	inline void Solve(){
		dfs1(1);
		dfs2(1,1);
		return ;
	}
	inline int Belong(int x){
		while(bel[top[x]].empty() || (*bel[top[x]].begin()) > dfn[x]){//TLE?
			x = fa[top[x]];
		}
		auto it = bel[top[x]].upper_bound(dfn[x]);
		it--;
		return org[*it];
	}
	inline void InsertBlack(int x){
		bel[top[x]].insert(dfn[x]);
		return ;
	}
}
int n,q;
Container::SegmentTree<ui,MAXN> normal;
Container::SpecialSegmentTree special;
using HLD::dfn;
inline void ReadIn(){
	cin>>n>>q;
	for(int i = 2;i <= n;i++){
		int ffather;
		cin>>ffather;
		AddEdge(ffather,i),AddEdge(i,ffather);
	}
	return ;
}
inline void Init(){
	HLD::InsertBlack(1);
	special.SIZE = n;
	special.ChangeSize(dfn[1],n);
	return ;
}
inline ui Solve1(int u){
	int blk = HLD::Belong(u);
	return special.QueryVal(dfn[blk],dfn[blk]) + normal.Query(dfn[u],dfn[u]);
}
inline void Solve2(int u,ui w){
	special.ChangeVal(dfn[u],dfn[u],w);
	return ;
}
inline ui Solve3(int u){
	int blk = HLD::Belong(u);
	ui ret = 0,delta = 0;
	ret += normal.Query(dfn[u],dfn[u]+HLD::siz[u]);
	ret += special.QuerySum(dfn[u]+1,dfn[u]+HLD::siz[u]);
	delta = special.QueryVal(dfn[blk],dfn[blk]);
	delta *= HLD::siz[u] - special.QuerySize(dfn[u]+1,dfn[u]+HLD::siz[u]);
	ret += delta;
	cout<<normal.Query(dfn[u],dfn[u]+HLD::siz[u])<<" and ";
	cout<<special.QuerySum(dfn[u]+1,dfn[u]+HLD::siz[u])<<" and ";
	cout<<special.QueryVal(dfn[blk],dfn[blk])<<" * ";
	cout<<HLD::siz[u] - special.QuerySize(dfn[u]+1,dfn[u]+HLD::siz[u])<<endl;
	return ret;
}
inline void Solve4(int u,ui w){
	special.ChangeVal(dfn[u],dfn[u]+HLD::siz[u],w);
	return ;
}
inline void Solve5(int u){
	int blk = HLD::Belong(u);
//	cerr<<"before "<<special.QuerySize(dfn[u],dfn[u])<<" and "<<special.QuerySize(dfn[blk],dfn[blk])<<endl;
	int delta = HLD::siz[u] - special.QuerySize(dfn[u]+1,dfn[u]+HLD::siz[u]);
	special.ChangeSize(dfn[blk],-delta),special.ChangeSize(dfn[u],delta);
	ui _val = special.QueryVal(dfn[blk],dfn[blk]);
	ui nowv = special.QueryVal(dfn[u],dfn[u]);
	special.ChangeVal(dfn[u],dfn[u],_val - nowv);
//	cerr<<u<<" COPY "<<_val<<" size "<<delta<<endl;
//	cerr<<"after "<<special.QuerySize(dfn[u],dfn[u])<<" and "<<special.QuerySize(dfn[blk],dfn[blk])<<endl;
	HLD::InsertBlack(u);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("pastel/pastel2.in","r",stdin);
	freopen("pastel.out","w",stdout);
	ReadIn();
	HLD::Solve();
	Init();
	for(int i = 1;i <= q;i++){
		int opt,k,w;
		cin>>opt;
		if(opt == 1 || opt == 3)cout<<i<<","<<opt<<" : ";
		if(opt == 1){
			cin>>k;
			cout<<Solve1(k)<<'\n';
		}else if(opt == 2){
			cin>>k>>w;
			Solve2(k,w);
		}else if(opt == 3){
			cin>>k;
			cout<<Solve3(k)<<'\n';
		}else if(opt == 4){
			cin>>k>>w;
			Solve4(k,w);
		}else if(opt == 5){
			cin>>k;
			Solve5(k);
		}else if(opt == 6){
			cin>>k;
		}
	}
	return 0;
}
