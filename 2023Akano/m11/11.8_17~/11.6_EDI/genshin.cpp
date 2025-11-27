#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 3e5 + 1018 + 1108;

template<int SIZE,typename T = int>
class SegmentTree{
private:
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = len = 0;}
	};
	SegmentTreeNode node[(SIZE + 4) * 4];
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
	class Reference{
	private:
		friend class SegmentTree;
		SegmentTree* source;
		size_t l,r;
		Reference() = default;
		Reference(SegmentTree* _source,int _l,int _r){
			source = _source,l = _l,r = _r;
			return ;
		}
	public:
		operator T(){
			return source->Query(l,r);
		}
		Reference& operator+=(int x){
			source->Change(l,r,x);
			return *this;
		}
		Reference& operator-=(int x){
			source->Change(l,r,-x);
			return *this;
		}
	};
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
	inline Reference operator[](pair<int,int> lr){
		return Reference(this,lr.first,lr.second);
	}
	inline Reference operator()(int l,int r){
		return Reference(this,l,r);
	}
};

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

SegmentTree<MAXN> tr;
pii query[MAXN];
vector<int> offline[MAXN],vec[MAXN];//挂载lca
int n,m,totans;
int tag[MAXN],stat[MAXN],f[MAXN][2];
int dfn[MAXN],siz[MAXN],heavy[MAXN],fa[MAXN][22],dep[MAXN],top[MAXN],dnt;
inline int LCA(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[u][i]] >= dep[v])u = fa[u][i];
	}
	if(u == v)return u;
	for(int i = 20;i >= 0;i--){
		if(fa[u][i] != fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
void HDDFS1(int u){
	dep[u] = dep[fa[u][0]] + 1,siz[u] = 1;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		fa[v][0] = u;
		HDDFS1(v);
		siz[u] += siz[v];
		if(siz[v] > siz[heavy[u]])heavy[u] = v;
	}
	return ;
}
void HDDFS2(int u,int tp){
	top[u] = tp,dfn[u] = ++dnt;
	if(heavy[u] != 0){
		HDDFS2(heavy[u],tp);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0] || v == heavy[u])continue;
		HDDFS2(v,v);
	}
	return ;
}
inline void SegmentTreeClear(){
	for(int i = 1;i <= n;i++){
		tr(i,i) -= tr(i,i);
	}
	return ;
}
inline void Tadd(int l,int r,int v){
	tr(l,l) += v,tr(r+1,r+1) -= v;
	return ;
}
inline void HDChange(int u,int v,int val){
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]])swap(u,v);
		Tadd(dfn[top[u]],dfn[u],val);
		u = fa[top[u]][0];
	}
	Tadd(dfn[v],dfn[u],val);
	return ;
}
inline int HDQuery(int u,int v){
	int ret = 0;
	while(top[u] != top[v]){
		ret += tag[top[u]] - tag[heavy[u]];
		u = fa[top[u]][0];
	}
	ret += tag[v] - tag[heavy[u]];
	return ret;
}
inline void HeavyDecomposition(){
	HDDFS1(1);
	HDDFS2(1,1);
	return ;
}
void Solve(int u){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		Solve(v);
		f[u][0] += max(f[v][0],f[v][1]);
	}
	tag[u] = tag[heavy[u]];
	for(auto i : offline[u]){
		vec[u].push_back(f[u][0] - HDQuery(query[i].first,u) - HDQuery(query[i].second,u) + 1);
		f[u][1] = max(f[u][1],vec[u].back());
	}
	if(f[u][1] > f[u][0]){
		tag[u] += f[u][1] - f[u][0];
	}
	return ;
}

void PreCalc(int u){
	if(stat[u] || tr(1,dfn[u]) < tr(1,dfn[fa[u][0]])){
		if(f[u][0] >= f[u][1]){
			stat[u] = 2;
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(v == fa[u][0])continue;
				stat[v] = 1;
			}
		}
		if(f[u][0] <= f[u][1]){
			for(int i = 0;i < int(vec[u].size());i++){
				if(vec[u][i] == f[u][1]){
					const int nowq = offline[u][i];
					HDChange(query[nowq].first,u,1),HDChange(query[nowq].second,u,1);
					Tadd(dfn[u],dfn[u],-1);
				}
			}
		}
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		PreCalc(v);
	}
	return ;
}
int Calc(int u) {
	int res = (stat[u] == 2);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		res += Calc(v);
	}
	if(stat[fa[u][0]] == 2){
		return res;
	}else{
		totans += 1ll * res * res;
		return 0;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("genshin/genshin4.in","r",stdin);
	cin>>n>>m;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	HeavyDecomposition();
	for(int i = 1;i <= m;i++){
		cin>>query[i].first>>query[i].second;
		offline[LCA(query[i].first,query[i].second)].push_back(i);
	}
	Solve(1);
	stat[1] = 1;
	PreCalc(1),Calc(1);
	cout<<totans<<endl;
	return not(Akano loves pure__Elysia);
}
