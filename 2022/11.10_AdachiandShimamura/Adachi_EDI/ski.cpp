#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
const int MAXN = 100006;
const int MAXM = 2000006;
int n,m,h[MAXN];
struct Edge{
	int nxt,to,v;
}e[MAXM];
struct Edge2{
	int u,to,val;
}b[MAXM];
bool cmp4b(Edge2 a,Edge2 bb){
	if(h[a.to] != h[bb.to])return (h[a.to] > h[bb.to]);
	return a.val < bb.val;
}
int ent = 1,head[MAXN],bnt;
void AddEdge(int from,int to,int v){
	e[++ent].to = to;
	e[ent].v = v;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
void AddNew(int from,int to,int v){
	b[++bnt].u = from;
	b[bnt].to = to;
	b[bnt].val = v;
	return ;
}
queue<int> q;
int reachable = 0;
ll cost = 0;
bool vis[MAXN];
int fa[MAXN];
int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void Solve(){
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		reachable++;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			AddNew(u,v,e[i].v);
			if(vis[v])continue;
			vis[v] = 1;
			q.push(v);
		}
	}
	sort(b+1,b+bnt+1,cmp4b);
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= bnt;i++){
		const int xa = find(b[i].to);
		const int xb = find(b[i].u);
		if(xa != xb){
			fa[xa] = xb;
			cost += b[i].val;
		}
	}
	return ;
}
int main(){
	freopen("ski.in","r",stdin);
	freopen("ski.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&h[i]);
	}
	while(m--){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		if(h[u] >= h[v]){
			AddEdge(u,v,k);
		}
		if(h[v] >= h[u]){
			AddEdge(v,u,k);
		}
	}
	Solve();
	printf("%d %lld",reachable,cost);
	return 0;
}
