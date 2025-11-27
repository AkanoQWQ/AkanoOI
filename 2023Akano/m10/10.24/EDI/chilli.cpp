#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108;
const int INF = 1e8 + 1018 + 1108;
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
int n,dep[MAXN],siz[MAXN],heavy[MAXN],fa[MAXN],dfn[MAXN],dfnSize[MAXN],tp[MAXN],org[MAXN],dnt;
void dfs1(int u){
	dep[u] = dep[fa[u]] + 1,siz[u] = 1;
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
void dfs2(int u,int top){
	tp[u] = top,dfn[u] = ++dnt;
	dfnSize[dfn[u]] = siz[u],org[dfn[u]] = u;
	if(heavy[u])dfs2(heavy[u],top);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == heavy[u] || v == fa[u])continue;
		dfs2(v,v);
	}
	return ;
}
class SegmentTree{
private:
	struct Node{
		int l,r,cnt;
	}node[MAXN * 20];
	int tot,root[MAXN];
	inline void PushUp(int p){
		node[p].cnt = node[node[p].l].cnt + node[node[p].r].cnt;
		return ;
	}
	void Change(int& p,int l,int r,int OBJ,int _val){
		node[++tot] = node[p];
		p = tot;
		if(l == r){
			node[p].cnt += _val;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)Change(node[p].l,l,mid,OBJ,_val);
		if(mid < OBJ)Change(node[p].r,mid+1,r,OBJ,_val);
		PushUp(p);
		return ;
	}
	int QueryPre(int p1,int p2,int l,int r,int pos){
		if(node[p2].cnt - node[p1].cnt <= 0)return -INF;
		if(l == r){
			if(node[p2].cnt - node[p1].cnt > 0)return l;
			return -INF;
		}
		const int mid = (l + r) >> 1;
		if(mid >= pos){
			return QueryPre(node[p1].l,node[p2].l,l,mid,pos);
		}
		int ret = QueryPre(node[p1].r,node[p2].r,mid+1,r,pos);
		if(ret <= 0)ret = QueryPre(node[p1].l,node[p2].l,l,mid,pos);
		return ret;
	}
	int QueryNext(int p1,int p2,int l,int r,int pos){
		if(node[p2].cnt - node[p1].cnt <= 0)return INF;
		if(l == r){
			if(node[p2].cnt - node[p1].cnt > 0)return l;
			return INF;
		}
		const int mid = (l + r) >> 1;
		if(mid <= pos){
			return QueryNext(node[p1].r,node[p2].r,mid+1,r,pos);
		}
		int ret = QueryNext(node[p1].l,node[p2].l,l,mid,pos);
		if(ret >= INF)ret = QueryNext(node[p1].r,node[p2].r,mid+1,r,pos);
		return ret;
	}
public:
	inline void Copy(int oldVer,int newVer){
		root[newVer] = root[oldVer];
		return ;
	}
	inline void Change(int ver,int pos,int _val){
		Change(root[ver],1,n,pos,_val);
		return ;
	}
	inline int QueryPre(int verL,int verR,int pos){
		return QueryPre(root[verL],root[verR],1,n,pos);
	}
	inline int QueryNext(int verL,int verR,int pos){
		return QueryNext(root[verL],root[verR],1,n,pos);
	}
}tr;
int ans = INF;
inline int Solve(int x){
	int ret = INF;
	int siz1 = siz[x];
	vector<pii> segs;
	segs.emplace_back(n+1,n+1);
	segs.emplace_back(dfn[x],dfn[x] + siz[x] - 1);
	x = fa[x];
	while(x){
		segs.emplace_back(dfn[tp[x]],dfn[x]);
		int l = dfn[tp[x]],r = dfn[x] + 1;
		while(l < r){
			const int mid = (l + r) >> 1;
			const int siz2 = dfnSize[mid] - siz1,siz3 = n - dfnSize[mid];
			ret = min(ret,max(max(siz1,siz2),siz3) - min(min(siz1,siz2),siz3));
			if(2 * dfnSize[mid] > n + siz1){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		x = fa[tp[x]];
	}
	segs.emplace_back(0,0);
	reverse(segs.begin(),segs.end());
	for(int i = 1;i < int(segs.size());i++){
		int l = segs[i-1].second + 1,r = segs[i].first - 1;
		int OBJL = tr.QueryPre(l-1,r,(n-siz1) >> 1),OBJR = tr.QueryNext(l-1,r,(n-siz1) >> 1);
		const int sizL2 = OBJL,sizL3 = n - OBJL - siz1;
		ret = min(ret,max(max(siz1,sizL2),sizL3) - min(min(siz1,sizL2),sizL3));
		const int sizR2 = OBJR,sizR3 = n - OBJR - siz1;
		ret = min(ret,max(max(siz1,sizR2),sizR3) - min(min(siz1,sizR2),sizR3));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("chilli.in","r",stdin);
	freopen("chilli.out","w",stdout);
	cin>>n;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs1(1),dfs2(1,1);
	for(int i = 1;i <= n;i++){
		tr.Copy(i-1,i);
		tr.Change(i,dfnSize[i],1);
	}
	for(int i = 2;i <= n;i++){
		ans = min(ans,Solve(i));
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
