#include<bits/stdc++.h>
using namespace std;
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
int n,father[MAXN];
namespace Subtask1{
	const int MAXS = (1<<10) + 1018 + 1108;
	const int NOWN = 14;
	int maxs,f[MAXS][NOWN],sz[MAXN];
	vector<int> stats;
	inline bool IsSon(int u,int v){
		if(v == 1)return true;
		while(u != 1){
			if(u == v)return true;
			u = father[u];
		}
		return false;
	}
	int Cnt1(int x){
		int ret = 0;
		while(x){
			ret += (x & 1);
			x >>= 1;
		}
		return ret;
	}
	bool Cmp(int ia,int ib){
		return Cnt1(ia) < Cnt1(ib);
	}
	void dfs(int u,int fa){
		sz[u] = 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa)continue;
			dfs(v,u);
			sz[u] += sz[v];
		}
		return ;
	}
	inline int Solve(){
		maxs = (1<<n) - 1;
		dfs(1,1);
		stats.reserve(maxs+1);
		for(int i = 0;i <= maxs;i++){
			stats.push_back(i);
			for(int j = 1;j <= n;j++)f[i][j] = 1e7;
		}
		for(int i = 1;i <= n;i++){
			f[1<<(i-1)][i] = sz[i];
		}
		sort(stats.begin(),stats.end(),Cmp);
		for(auto stat : stats){
			for(int i = 1;i <= n;i++){
				if((stat & (1<<(i-1))) == 0)continue;
				for(int j = 1;j <= n;j++){
					if((stat & (1<<(j-1))) != 0)continue;
					int cost = f[stat][i];
					if(IsSon(i,j) || IsSon(j,i)){
						int mx = max(sz[i],sz[j]),mn = min(sz[i],sz[j]);
						cost += mx - mn;
					}else{
						cost += sz[i] + sz[j];
					}
					f[stat | (1<<(j-1))][j] = min(f[stat | (1<<(j-1))][j],cost);
				}
			}
		}
		int ret = 1e7;
		for(int i = 1;i <= n;i++){
			ret = min(ret,f[maxs][i] + sz[i]);
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("activation.in","r",stdin);
//	freopen("activation.out","w",stdout);
	cin>>n;
	for(int i = 2;i <= n;i++){
		cin>>father[i];
		AddEdge(i,father[i]),AddEdge(father[i],i);
	}
	if(n <= 14){
		cout<<Subtask1::Solve()<<endl;
	}
	return 0;
}
