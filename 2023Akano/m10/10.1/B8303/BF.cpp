#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 4e5 + 1018 + 1108;
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
vector<pair<int,int> > tarjanV[MAXN];
int n,q,ans[MAXN],dep[MAXN],ant;
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs(v,u);
	}
	return ;
}
struct Node{
	char type;
	int id,t,x;
};
bool Cmp(Node n1,Node n2){
	if(n1.t != n2.t)return n1.t < n2.t;
	if(n1.type != n2.type)return n1.type < n2.type;
	if(n1.x != n2.x)return n1.x < n2.x;
	return n1.id < n2.id;
}
Node ask[MAXN];
struct Query{
	int u,v,OBJ,id,anss;
	Query() = default;
	Query(int _u,int _v,int _OBJ,int _id){
		u = _u,v = _v,OBJ = _OBJ,id = _id;
		return ;
	}
};
vector<Query> query;
bool vis[MAXN];
int fa[MAXN];
int Find(int x){
	if(fa[x] == x)return x;
	return fa[x] = Find(fa[x]);
}
void Tarjan(int u){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		Tarjan(v);
		fa[v] = u;
	}
	for(auto v : tarjanV[u]){
		if(vis[v.first]){
			query[v.second].anss = Find(v.first);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= q;i++){
		cin>>ask[i].type>>ask[i].t>>ask[i].x;
		if(ask[i].type == 'q'){
			ask[i].id = ++ant;
		}else{
			ask[i].id = 0;
		}
	}
	dfs(1,0);
	sort(ask + 1,ask + q + 1,Cmp);
	for(int i = 1;i <= q;i++){
		if(ask[i].type == 'q')continue;
		for(int j = i+1;j <= q;j++){
			if(ask[j].t > ask[i].t + n)break;
			if(ask[j].type == 'b')continue;
			query.emplace_back(ask[i].x,ask[j].x,ask[j].t - ask[i].t,ask[j].id);
		}
		if(query.size() >= 1e8)break;
	}
	int ccnt = 0;
	for(auto qry : query){
		tarjanV[qry.u].emplace_back(qry.v,ccnt);
		tarjanV[qry.v].emplace_back(qry.u,ccnt);
		ccnt++;
	}
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	Tarjan(1);
	for(int i = 0;i < int(query.size());i++){
		int act = dep[query[i].u] + dep[query[i].v] - dep[query[i].anss] * 2;
		if(act == query[i].OBJ)ans[query[i].id]++;
	}
	for(int i = 1;i <= ant;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
