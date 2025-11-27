#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXLG = 22;
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
struct Answer{
	int x,y,w;
}cheat[MAXN];
int n,m;
int dfn[MAXN],dnt,siz[MAXN],fa[MAXN][MAXLG],dep[MAXN],lastfa;
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0;i--){ 
		if(dep[fa[x][i]] > dep[y]){
			x = fa[x][i];
		}
	}
	lastfa = x;
	if(x == y || fa[x][0] == y)return y;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i],y = fa[y][i];
		}
	}
	return fa[x][0];
}
void dfs(int u){
	dep[u] = dep[fa[u][0]] + 1,siz[u] = 1,dfn[u] = ++dnt;
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
namespace ScanningLine{
	int nowid;
	struct Node{
		int val,lazy;
	};
	class SegmentTree{
		private:
			Node node[MAXN * 4];
			inline void PushUp(int p){
				node[p].val = max(node[p*2].val,node[p*2+1].val);
				return ;
			}
			inline void PushDown(int p){
				if(!node[p].lazy)return ;
				node[p*2].val += node[p].lazy,node[p*2+1].val += node[p].lazy;
				node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
				node[p].lazy = 0;
				return ;
			}
			void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
				if(OBJL <= l && r <= OBJR){
					node[p].val += _val,node[p].lazy += _val;
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
				int ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
				if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
				return ret;
			}
		public:
			inline void Change(int l,int r,int _val){
				Change(1,1,n,l,r,_val);
				return ;
			}
			inline int Query(){
				return Query(1,1,n,1,n);
			}
	}tr;
	struct Query{
		int l,r,x,val;
		Query(){}
		Query(int _l,int _r,int _x,int _val){l = _l,r = _r,x = _x,val = _val;}
	};
	vector<Query> ask;
	bool Cmp(Query q1,Query q2){
		if(q1.x != q2.x)return q1.x < q2.x;
		if(q1.val != q2.val)return q1.val < q2.val;//负数在前面
		if(q1.l != q2.l)return q1.l < q2.l;
		return q1.r < q2.r;
	}
	inline void Insert(int _y1,int _y2,int _x1,int _x2,int val){
		ask.push_back(Query(_y1,_y2,_x1,val));
		ask.push_back(Query(_y1,_y2,_x2+1,-val));
		return ;
	}
	inline int Solve(){
		int ret = 0;
		sort(ask.begin(),ask.end(),Cmp);
		for(auto query : ask){
			tr.Change(query.l,query.r,query.val);
			ret = max(ret,tr.Query());
		}
		return ret;
	}
}
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= m;i++){
		cin>>cheat[i].x>>cheat[i].y>>cheat[i].w;
	}
	return ;
}
int val[MAXN];
inline void PreExecute(){
	dfs(1);
	for(int i = 1;i <= m;i++){
		int lca = LCA(cheat[i].x,cheat[i].y);
		int xST = dfn[cheat[i].x],xED = dfn[cheat[i].x] + siz[cheat[i].x] - 1;
		int yST = dfn[cheat[i].y],yED = dfn[cheat[i].y] + siz[cheat[i].y] - 1;
		if(cheat[i].x == cheat[i].y){
			val[cheat[i].x] += cheat[i].w;
		}else if(lca == cheat[i].x){
			const int lST = dfn[lastfa],lED = dfn[lastfa] + siz[lastfa] - 1;
			if(lST-1 >= 1)ScanningLine::Insert(1,lST-1,yST,yED,cheat[i].w);
			if(lED+1 <= n)ScanningLine::Insert(lED+1,n,yST,yED,cheat[i].w);
		}else if(lca == cheat[i].y){
			const int lST = dfn[lastfa],lED = dfn[lastfa] + siz[lastfa] - 1;
			if(lST-1 >= 1)ScanningLine::Insert(xST,xED,1,lST-1,cheat[i].w);//-1?
			if(lED+1 <= n)ScanningLine::Insert(xST,xED,lED+1,n,cheat[i].w);
		}else{
			ScanningLine::Insert(xST,xED,yST,yED,cheat[i].w);
		}
	}
	for(int u = 1;u <= n;u++){
		if(!val[u])continue;
		int xST = dfn[u],xED = dfn[u] + siz[u] - 1;
		ScanningLine::Insert(1,n,1,n,val[u]);
		if(xST-1 >= 1)ScanningLine::Insert(1,xST-1,1,xST-1,-val[u]);
		if(xST-1 >= 1 && xED+1 <= n)ScanningLine::Insert(1,xST-1,xED+1,n,-val[u]);
		if(xST-1 >= 1 && xED+1 <= n)ScanningLine::Insert(xED+1,n,1,xST-1,-val[u]);
		if(xED+1 <= n)ScanningLine::Insert(xED+1,n,xED+1,n,-val[u]);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u][0])continue;
			ScanningLine::Insert(dfn[v],dfn[v] + siz[v] - 1,dfn[v],dfn[v] + siz[v] - 1,-val[u]);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	PreExecute();
	cout<<ScanningLine::Solve()<<endl;
	return (Akano loves pure__Elysia);
}
