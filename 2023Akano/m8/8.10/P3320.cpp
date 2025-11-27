#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
int n,q;
ll ans;
struct Edge{
	int nxt,to;
	ll val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
ll dep[MAXN],dis[MAXN],fa[MAXN][22],dfn[MAXN],org[MAXN],dnt;
void dfs(int u){
	dep[u] = dep[fa[u][0]] + 1,dfn[u] = ++dnt,org[dfn[u]] = u;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		fa[v][0] = u,dis[v] = dis[u] + e[i].val;
		dfs(v);
	}
	return ;
}
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y;
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i],y = fa[y][i];
		}
	}
	return fa[x][0];
}
inline ll GetDis(int x,int y){
	int lca = LCA(x,y);
	return dis[x] + dis[y] - 2 * dis[lca];
}
bool est[MAXN];
set<int> now;
inline void Push(int x){
	est[x] = true;
	auto it = now.insert(dfn[x]).first;
	auto lst = it,nxt = it;
	if(it != now.begin()){
		lst--;
		ans += GetDis(org[*lst],x);
	}
	nxt++;
	if(nxt != now.end()){
		if(it != now.begin())ans -= GetDis(org[*lst],org[*nxt]);
		ans += GetDis(org[*nxt],x);
	}
	return ;
}
inline void Delete(int x){
	est[x] = false;
	auto it = now.find(dfn[x]);
	auto lst = it,nxt = it;
	if(it != now.begin()){
		lst--;
		ans -= GetDis(org[*lst],x);
	}
	nxt++;
	if(nxt != now.end()){
		if(it != now.begin())ans += GetDis(org[*lst],org[*nxt]);
		ans -= GetDis(org[*nxt],x);
	}
	now.erase(dfn[x]);
	return ;
}
inline ll ED(){
	if(now.size() <= 1)return 0;
	auto it1 = now.begin(),it2 = now.end();
	it2--;
	return GetDis(org[*it1],org[*it2]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	dfs(1);
	while(q--){
		int x;
		cin>>x;
		if(est[x]){
			Delete(x);
		}else{
			Push(x);
		}
		cout<<ans + ED()<<endl;
	}
	return 0;
}
