#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXR = 2006;
const int MAXP = MAXR * 2 + 1018 + 1108;//remember to EDIT
const int MAXM = MAXP * 16 + 1018 + 1108;//EDIT and *2
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
pll points[MAXR];
int n,VST,VED,ST2,nnt,no[MAXR][2];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>points[i].first>>points[i].second;
		no[i][0] = ++nnt,no[i][1] = ++nnt;
	}
	VST = ++nnt,ST2 = ++nnt,VED = ++nnt;
	CreateEdge(VST,ST2,2,0);
	sort(points+1,points+n+1);
	for(int i = 1;i <= n;i++){
		CreateEdge(ST2,no[i][0],1,0);
		CreateEdge(no[i][0],no[i][1],1,-1);
		CreateEdge(no[i][0],no[i][1],1,0);
		CreateEdge(no[i][1],VED,1,0);
		ll nowmin = LLONG_MAX;
		for(int j = i+1;j <= n;j++){
			if(points[j].second < points[i].second)continue;
			if(points[j].second > nowmin)continue;
			nowmin = points[j].second;
			CreateEdge(no[i][1],no[j][0],4,0);
		}
	}
	const pll ans = MCMF::MCMF(nnt,VST,VED);
	cout<<-ans.second;
	return 0;
}
