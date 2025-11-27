#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const ll INF = 1e16;
struct Edge{
	int nxt,to,val;
	bool onTree;
}e[MAXN * 2];
int head1[MAXN],head2[MAXN],head3[MAXN],cnt = 1,saveCnt;
inline void AddEdge(int from,int to,int val,int head[]){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,q,fa[MAXN],lst[MAXN],lcafa[MAXN][21],dep[MAXN];
bool Cmp(int a,int b){
	return dep[e[a].to] > dep[e[b].to];
}
ll dis[MAXN];
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = 20;i >= 0;i--){
		if(dep[lcafa[x][i]] >= dep[y])x = lcafa[x][i];
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(lcafa[x][i] != lcafa[y][i]){
			x = lcafa[x][i];
			y = lcafa[y][i];
		}
	}
	return lcafa[x][0];
}
vector<int> imp;
bool est[MAXN];
void dfs(int u){
	lcafa[u][0] = fa[u];
	dep[u] = dep[fa[u]] + 1;
	for(int i = 1;i <= 20;i++){
		lcafa[u][i] = lcafa[lcafa[u][i-1]][i-1];
	}
	for(int i = head1[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u])continue;
		if(dis[v] != 0 || v == 1)continue;
		fa[v] = u,dis[v] = dis[u] + e[i].val;
		e[i].onTree = e[i^1].onTree = true;
		dfs(v);
	}
	return ;
}
void dfs2(int u){
	if(est[u]){
		cerr<<u<<" lst "<<lst[u]<<" with "<<dis[u] - dis[lst[u]]<<endl;
		if(lst[u])AddEdge(u,lst[u],dis[u] - dis[lst[u]],head2);
		if(lst[u])AddEdge(lst[u],u,dis[u] - dis[lst[u]],head2);
		lst[u] = u;
	}
	for(int i = head1[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u] || e[i].onTree == false)continue;
		lst[v] = lst[u];
		dfs2(v);
	}
	return ;
}
inline ll DirDis(int u,int v){
	int lca = LCA(u,v);
	return dis[u] + dis[v] - 2 * dis[lca];
}
ll dijdis[MAXN];
bool vis[MAXN];
ll Dij(int st,int ed){
	priority_queue<pair<int,int> > pq;
	for(auto i : imp)dijdis[i] = INF,vis[i] = false;
	dijdis[st] = dijdis[ed] = INF,vis[st] = vis[ed] = false;
	dijdis[st] = 0;
	pq.push(make_pair(-dijdis[st],st));
	while(!pq.empty()){
		const int u = pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head2[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dijdis[v] > dijdis[u] + e[i].val){
				dijdis[v] = dijdis[u] + e[i].val;
				pq.push(make_pair(-dijdis[v],v));
			}
		}
		for(int i = head3[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dijdis[v] > dijdis[u] + e[i].val){
				dijdis[v] = dijdis[u] + e[i].val;
				pq.push(make_pair(-dijdis[v],v));
			}
		}
	}
	return dijdis[ed];
}
inline ll Query(int u,int v){
	saveCnt = cnt;
	if(lst[u] != u){
		AddEdge(u,lst[u],dis[u] - dis[lst[u]],head3);
		AddEdge(lst[u],u,dis[u] - dis[lst[u]],head3);
	}
	if(lst[v] != v){
		AddEdge(v,lst[v],dis[v] - dis[lst[v]],head3);
		AddEdge(lst[v],v,dis[v] - dis[lst[v]],head3);
	}
	ll ret = Dij(u,v);
	for(auto i : imp)head3[i] = 0;
	head3[u] = head3[v] = 0;
	cnt = saveCnt;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w,head1),AddEdge(v,u,w,head1);
	}
	dfs(1);
	for(int i = 2;i <= cnt;i++){
		const int v = e[i].to;
		if(e[i].onTree == false){
			cerr<<"est "<<v<<endl;
			est[v] = true;
			imp.push_back(v);
		}
	}
	for(int u = 1;u <= n;u++){
		for(int i = head1[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(e[i].onTree == false)AddEdge(u,v,e[i].val,head2);
		}
	}
	est[1] = true;
	if(find(imp.begin(),imp.end(),1) == imp.end())imp.push_back(1);//Òª¼ÓÈë1 
	dfs2(1);
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<Query(u,v)<<endl;
	}	
	return not(Akano loves pure__Elysia);
}
