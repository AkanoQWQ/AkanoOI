#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
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
//图的相关信息
int dfn[MAXN],dep[MAXN],fa[MAXN][22],siz[MAXN],dnt;
void dfs(int u){
	dfn[u] = ++dnt,siz[u] = 1,dep[u] = dep[fa[u][0]] + 1;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		fa[v][0] = u;
		dfs(v);
		siz[u] += siz[v];
	}
	return ;
}
int n,q,a[MAXN];
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
inline int LastLCA(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[u][i]] > dep[v])u = fa[u][i];
	}
	return u;
}
inline int GetIntersection(int u,int v){//不会出现 dep_u = dep_v 的情况,已经特判
	int lca = LCA(u,v);
	if(dep[u] - dep[lca] == dep[v] - dep[lca])return lca;
	if(dep[u] - dep[lca] > dep[v] - dep[lca])swap(u,v);//u在上方,离lca更近
	int ret = v;//直到ret都归v管
	for(int i = 20;i >= 0;i--){
		const int nxt = fa[ret][i];
		if(nxt <= 0)continue;
		const int disU = dep[u] - dep[lca] + dep[nxt] - dep[lca],disV = dep[v] - dep[nxt];
		if(disU > disV){
			ret = nxt;
		}else if(disU == disV){
			if(u == a[1]){
				//do nothing 原因见下
			}
			if(v == a[1]){
				ret = nxt;//返回的是fa,需要往上走
			}
		}
	}
	if(u == a[1]){//返回的是归属于 a[k] k!=1 的点
		return ret;
	}else if(v == a[1]){
		return fa[ret][0];
	}
	return 10181108;
}
class SegmentTree{
private:
	struct Node{
		int len,lazy,val;
		Node(){
			len = 0,lazy = -1,val = 0;
			return ;
		}
	}node[MAXN * 4];
	inline void PushUp(int p){
		node[p].val = node[p*2].val + node[p*2+1].val;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].lazy == -1)return;
		node[p*2].val = node[p].lazy * node[p*2].len;
		node[p*2+1].val = node[p].lazy * node[p*2+1].len;
		node[p*2].lazy = node[p*2+1].lazy = node[p].lazy;
		node[p].lazy = -1;
		return ;
	}
	void Build(int p,int l,int r){
		node[p].len = r - l + 1,node[p].val = 0,node[p].lazy = -1;
		if(l == r)return ;
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		return ;
	}
	void Change(int p,int l,int r,int OBJL,int OBJR,int tag){
		if(OBJL <= l && r <= OBJR){
			node[p].val = tag * node[p].len;
			node[p].lazy = tag;
			return ;
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,tag);
		if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,tag);
		PushUp(p);
		return ;
	}
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline void Clear(){//置1
		node[1].lazy = 1;
		node[1].val = node[1].len;
		return ;
	}
	inline void Change(int l,int r,int tag){
		if(l > r)return ;
		Change(1,1,n,l,r,tag);
		return ;
	}
	inline int Query(){
		return node[1].val;
	}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("civilization.in","r",stdin);
	freopen("civilization.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1);
	tr.Build();
	while(q--){
		tr.Clear();
		int k;
		cin>>k;
		for(int i = 1;i <= k;i++){
			cin>>a[i];
		}
		for(int i = 2;i <= k;i++){
			if(dep[a[1]] == dep[a[i]]){//需要特判dep相同的情况,不然不好算啊
				int lca = LCA(a[1],a[i]);
				int p = LastLCA(a[i],lca);
				int l = dfn[p],r = dfn[p] + siz[p] - 1;
				tr.Change(l,r,0);
			}else if(dep[a[1]] < dep[a[i]]){//a[1] 在更上方,那么肯定交点在lca下方靠近a[i]的地方,其子树不可用
				int point = GetIntersection(a[1],a[i]);
				tr.Change(dfn[point],dfn[point] + siz[point] - 1,0);
			}else if(dep[a[1]] > dep[a[i]]){//是a[1] 父亲
				int point = GetIntersection(a[1],a[i]);
				int p = LastLCA(a[1],point);
				int l = dfn[p],r = dfn[p] + siz[p] - 1;
				tr.Change(1,l-1,0),tr.Change(r+1,n,0);
			}
		}
		cout<<tr.Query()<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
