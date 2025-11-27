#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2006;
const ll INF = 123456789123456789;
bool st;
ll dep[MAXN],n,q,fa[MAXN],upv[MAXN],val[MAXN];
vector<pair<int,int> > e[MAXN];
void dfs(int u){
	val[u] = INF;
	for(auto ee : e[u]){
		const int v = ee.first;
		if(v == fa[u])continue;
		fa[v] = u,dep[v] = dep[u] + 1,upv[v] = ee.second;
		dfs(v);
	}
	return ;
}
inline int LCA(int x,int y){
	if(x == y)return x;
	while(x != y){
		if(dep[x] < dep[y])swap(x,y);
		x = fa[x];
	}
	return x;
}
bool ed;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v,val;
		cin>>u>>v>>val;
		e[u].push_back(make_pair(v,val)),e[v].push_back(make_pair(u,val));
	}
	dfs(1);
	while(q--){
		ll opt,x,y,a,b;
		cin>>opt;
		if(opt == 1){
			cin>>x>>y>>a>>b;
			int lca = LCA(x,y);
			while(x != lca){
				val[x] = min(val[x],b);
				b += a * upv[x];
				x = fa[x];
			}
			val[lca] = min(val[lca],b);
			vector<int> path;
			while(y != lca){
				path.push_back(y);
				y = fa[y];
			}
			reverse(path.begin(),path.end());
			for(auto u : path){
				b += a * upv[u];
				val[u] = min(val[u],b);
			}
		}else{
			ll ret = INF;
			cin>>x>>y;
			while(x != y){
				if(dep[x] < dep[y])swap(x,y);
				ret = min(ret,val[x]);
				x = fa[x];
			}
			ret = min(ret,val[x]);
			cout<<ret<<endl;
		}
	}
	return 0;
}

