#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
const ll INF = 1e15 + 1018 + 1108;
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
struct Node{
	int l,r,mindep,dist;
	ll val,lazy;
}node[MAXN * 2];
int nnt;
inline int NewNode(ll val,int dep){
	++nnt;
	node[nnt].val = val,node[nnt].mindep = dep;
	node[nnt].dist = 1;
	return nnt;
}
inline void PushDown(int p){
	if(!node[p].lazy)return ;
	node[node[p].l].val += node[p].lazy;
	node[node[p].l].lazy += node[p].lazy;
	node[node[p].r].val += node[p].lazy;
	node[node[p].r].lazy += node[p].lazy;
	node[p].lazy = 0;
	return ;
}
int Merge(int x,int y){
	if(!x || !y)return x + y;
	if(node[x].val > node[y].val)swap(x,y);
	PushDown(x);//改变树的结构前,先PushDown一下?
	node[x].r = Merge(node[x].r,y);
	if(node[node[x].l].dist < node[node[x].r].dist)swap(node[x].l,node[x].r);
	node[x].dist = node[node[x].r].dist + 1;
	return x;
}
inline void Pop(int& x){
	PushDown(x);
	x = Merge(node[x].l,node[x].r);
	return ;
}
int n,m,dep[MAXN],rt[MAXN];
ll least[MAXN];
void dfs(int u,int fa){
	ll tot = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		tot += least[v];
		node[rt[v]].lazy -= least[v],node[rt[v]].val -= least[v];
		rt[u] = Merge(rt[u],rt[v]);
	}
	node[rt[u]].lazy += tot,node[rt[u]].val += tot;
	PushDown(rt[u]);
	while(rt[u] != 0 && node[rt[u]].mindep >= dep[u]){
		Pop(rt[u]);
	}
	if(rt[u] != 0)least[u] = node[rt[u]].val;
	least[u] = min(least[u],INF); 
	return ;
}
void GetDep(int u,int fa){
	least[u] = INF;
	dep[u] = dep[fa] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetDep(v,u);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	GetDep(1,0);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		rt[u] = Merge(rt[u],NewNode(w,dep[v]));
	}
	dfs(1,-10181108);
	ll otp = 0;
	for(int i = head[1];i;i = e[i].nxt){
		otp += least[e[i].to];
	}
	if(otp >= INF)otp = -1;
	otp = max(otp,-1ll);//溢出肯定是-1,也许... 
	cout<<otp<<endl;
	return not(Akano loves pure__Elysia);
}
