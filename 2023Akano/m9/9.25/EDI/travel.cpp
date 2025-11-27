#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const ll INF = 2e14 + 10181108;
const int MAXN = 2e5 + 1018 + 1108;
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
int n,m,d[MAXN],c[MAXN];
namespace Subtask1{
	const int NOWN = 1108;
	vector<int> vecE[NOWN];
	ll dis[NOWN];
	inline void CreateEdge(int st){
		queue<int> q;
		for(int i = 1;i <= n;i++)dis[i] = 0;
		q.push(st);
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			if(dis[u] >= d[st])continue;
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(v == st || dis[v])continue;
				vecE[st].push_back(v);
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		return ;
	}
	bool vis[NOWN];
	inline void Dij(int st){
		priority_queue<pair<ll,int> > q;
		for(int i = 1;i <= n;i++){
			dis[i] = INF;
			vis[i] = false;
		}
		dis[st] = 0;
		q.push(make_pair(-dis[st],st));
		while(!q.empty()){
			const int u = q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u] = true;
			for(auto v : vecE[u]){
				if(dis[v] > dis[u] + c[u]){
					dis[v] = dis[u] + c[u];
					q.push(make_pair(-dis[v],v));
				}
			}
		}
		return ;
	}
	inline void Solve(){
		for(int i = 1;i <= n;i++)CreateEdge(i);
		Dij(1);
		for(int i = 2;i <= n;i++){
			cout<<dis[i]<<'\n';
		}
		return ;
	}
}
namespace Subtask2{
	template<int SIZE>
	class SegmentTree{
	private:
		int tot,root[SIZE];
		struct Node{
			int l,r;
			ll val;
		}node[SIZE];
		inline void PushUp(int p){
			node[p].val = INF;
			node[p].val = min(node[p].val,node[node[p].l].val);
			node[p].val = min(node[p].val,node[node[p].r].val);
			return ;
		}
		int Change(int p,int l,int r,int OBJ,ll _val){
			const int no = ++tot;
			node[no] = node[p];
			if(l == r){
				node[no].val = min(node[no].val,_val);
				return no;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)node[no].l = Change(node[no].l,l,mid,OBJ,_val);
			if(mid < OBJ)node[no].r = Change(node[no].r,mid+1,r,OBJ,_val);
			PushUp(no);
			return no;
		}
		ll Query(int p,int l,int r,int OBJL,int OBJR){
			if(p == 0)return INF;
			if(OBJL <= l && r <= OBJR){
				return node[p].val;
			}
			const int mid = (l + r) >> 1;
			ll ret = INF;
			if(mid >= OBJL)ret = min(ret,Query(node[p].l,l,mid,OBJL,OBJR));
			if(mid < OBJR)ret = min(ret,Query(node[p].r,mid+1,r,OBJL,OBJR));
			return ret;
		}
	public:
		inline void Change(int oldVer,int newVer,int pos,ll _val){
			root[newVer] = Change(root[oldVer],1,n,pos,_val);
		}
		inline ll Query(int ver,int l,int r){
			return Query(root[ver],1,n,l,r);
		}
		SegmentTree(){
			node[0].val = INF;//确保初始值是INF
			return ;
		}
	};
	SegmentTree<MAXN * 200> tr;
	int no[MAXN],nnt,dep[MAXN];
	ll ans[MAXN];
	void dfs(int u,int fa){
		no[u] = ++nnt,dep[u] = dep[fa] + 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa)continue;
			dfs(v,u);
		}
		return ;
	}
	void GetAns(int u,int fa){
		ans[u] = tr.Query(no[fa],dep[u],n);
		tr.Change(no[fa],no[u],dep[u] + d[u],ans[u] + c[u]);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa)continue;
			GetAns(v,u);
		}
		return ;
	}
	inline void Solve(){
		tr.Change(0,0,0,0);
		dfs(1,0);
		GetAns(1,0);
		for(int i = 2;i <= n;i++){
			cout<<ans[i]<<'\n';
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		cin>>d[i]>>c[i];
	}
	if(n <= 1018){
		Subtask1::Solve();
	}else if(m == n-1){
		Subtask2::Solve();
	}else{
		Subtask2::Solve();
	}
	return not(Akano loves pure__Elysia);
}
