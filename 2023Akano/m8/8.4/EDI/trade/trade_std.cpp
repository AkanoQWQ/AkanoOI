#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int TOT_MAXN = (1<<18) + 1018 + 1108;
const int MOD = 998244353;
const ll INF = 1e16;
int n,m;
namespace Subtask1{
	const int MAXN = (1<<12) + 10 + 18 + 11 + 8;
	const int MAXM = (MAXN + 2006 + 1108 + 2006 + 1018) * 2;
	struct Edge{
		int nxt,to,val;
	}e[MAXM];
	int head[MAXN],cnt;
	inline void AddEdge(int from,int to,int val){
		e[++cnt].to = to;
		e[cnt].val = val;
		e[cnt].nxt = head[from];
		head[from] = cnt;
		return ;
	}
	
	ll dis[MAXN];
	bool vis[MAXN];
	inline ll Dij(int ST){
		ll ret = 0;
		priority_queue<pair<ll,int> > q;
		for(int i = 1;i <= n;i++){
			dis[i] = INF;
			vis[i] = false;
		}
		dis[ST] = 0;
		q.push(make_pair(-dis[ST],ST));
		while(!q.empty()){
			const int u = q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u] = true;
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(dis[v] > dis[u] + e[i].val){
					dis[v] = dis[u] + e[i].val;
					q.push(make_pair(-dis[v],v));
				}
			}
		}
		for(int i = 1;i <= n;i++){
			if(dis[i] != INF){
				ret = (ret + dis[i]) % MOD;
			}
		}
		return ret;
	}
	inline ll Solve(){
		ll ret = 0;
		n = (1<<n)-1;//n changed!
		for(int i = 2;i <= n;i++){
			int a;
			cin>>a;
			AddEdge(i,i/2,a);
		}
		for(int i = 1;i <= m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			AddEdge(u,v,w);
		}
		for(int i = 1;i <= n;i++){
			ret = (ret + Dij(i)) % MOD;
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("trade/data.in","r",stdin);
//	freopen("trade.out","w",stdout);
	cin>>n>>m;
	cout<<Subtask1::Solve()<<endl;
	return 0;
}
