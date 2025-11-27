#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 806;
const int MAXP = 2006 + 1018 + 1108;//remember to EDIT
const int MAXM = 2e5 + 1018 + 1108;//EDIT and *2
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to;
	ll cap,cost;
}e[MAXM];
int head[MAXP],cnt = 1;
inline void AddEdge(int from,int to,ll val,ll cost){
	e[++cnt].to = to;
	e[cnt].cap = val;
	e[cnt].cost = cost;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void CreateEdge(int from,int to,ll val,ll cost){
	AddEdge(from,to,val,cost),AddEdge(to,from,0,-cost);
	return ;
}
namespace MCMF{
	bool inq[MAXP];
	ll dis[MAXP],nowf[MAXP];
	int pre[MAXP];
	inline bool SPFA(int n,int ST,int ED){
		queue<int> q;
		for(int i = 0;i <= n;i++){
			dis[i] = INF;
			nowf[i] = 0;
		}
		q.push(ST);
		dis[ST] = 0,nowf[ST] = INF,inq[ST] = true;
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			inq[u] = false;
			for(int i = head[u];i;i = e[i].nxt){
				if(e[i].cap <= 0)continue;
				const int v = e[i].to;
				if(dis[v] > dis[u] + e[i].cost){
					dis[v] = dis[u] + e[i].cost;
					if(!inq[v]){
						q.push(v),inq[v] = true;
					}
					pre[v] = i,nowf[v] = min(nowf[u],e[i].cap);
 				}
			}
		}
		return (dis[ED] != INF);
	}
	inline pair<ll,ll> MCMF(int n,int ST,int ED){
		ll minCost = 0,maxFlow = 0;
		while(SPFA(n,ST,ED)){
			ll pos = ED,cost = 0;
			while(pos != ST){
				cost += e[pre[pos]].cost;
				e[pre[pos]].cap -= nowf[ED],e[pre[pos]^1].cap += nowf[ED];
				pos = e[pre[pos]^1].to;
			}
			minCost += cost * nowf[ED],maxFlow += nowf[ED];
		}
		return make_pair(maxFlow,minCost);
	}
}
int n,m,no[MAXN][2],nnt,VST,VED,ST2;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	VST = ++nnt,VED = ++nnt,ST2 = ++nnt;
	CreateEdge(VST,ST2,INF,0);
	for(int i = 1;i <= n;i++){
		int STVAL = 0;
		cin>>STVAL;
		no[i][0] = ++nnt,no[i][1] = ++nnt;
		CreateEdge(VST,no[i][0],1,0);
		CreateEdge(no[i][1],VED,1,0);
		CreateEdge(ST2,no[i][1],1,STVAL);	
	}
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u > v)swap(u,v);
		CreateEdge(no[u][0],no[v][1],1,w);
	}
	const pair<ll,ll> ans = MCMF::MCMF(nnt,VST,VED);
	cout<<ans.second<<endl;
	return 0;
}
