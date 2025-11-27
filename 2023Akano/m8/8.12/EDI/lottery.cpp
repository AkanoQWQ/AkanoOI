#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll money1 = 300000;
const ll money2 = 4000;
const ll money3 = 500;
const int MAXVAL = 1e6 + 1018 + 1108;
ll n,valcnt[MAXVAL],appearcnt[MAXVAL][4],inval;
ll value[114][4];
namespace MCMF{//using long long!
	const int MAXN = 2006 + 1018 + 1108;//OK?
	const int MAXM = 1e6 + 1018 + 1108;//OK?
	//200p
	const ll INF = 1e11;
	struct Edge{
		int nxt,to;
		ll val,cap;
	}e[MAXM];
	int head[MAXN],cnt = 1;
	inline void AddEdge(int from,int to,ll cap,ll val){
		e[++cnt].to = to;
		e[cnt].val = val;
		e[cnt].cap = cap;
		e[cnt].nxt = head[from];
		head[from] = cnt;
		return ;
	}
	inline void CreateEdge(int from,int to,ll cap,ll val){
		AddEdge(from,to,cap,val);
		AddEdge(to,from,0,-val);
		return ;
	}
	ll dis[MAXN],pre[MAXN],flow[MAXN];
	bool inq[MAXN];
	inline bool SPFA(int SIZE,int ST,int ED){
		queue<int> q;
		for(int i = 1;i <= SIZE;i++){
			dis[i] = INF,flow[i] = 0;
			inq[i] = false;
		}
		dis[ST] = 0,flow[ST] = INF;
		q.push(ST);
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			inq[u] = false;
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(e[i].cap <= 0)continue;
				if(dis[v] > dis[u] + e[i].val){
					dis[v] = dis[u] + e[i].val;
					pre[v] = i;
					flow[v] = min(flow[u],e[i].cap);
					if(inq[v] == false){
						inq[v] = true;
						q.push(v);
					}
				}
			}
		}
		return (dis[ED] != INF);
	}
	inline pair<ll,ll> MCMF(int SIZE,int ST,int ED){
		ll maxflow = 0,mincost = 0;
		while(SPFA(SIZE,ST,ED)){
			int pos = ED;
			while(pos != ST){
				e[pre[pos]].cap -= flow[ED];
				e[pre[pos]^1].cap += flow[ED];
				pos = e[pre[pos]^1].to;
			}
			maxflow += flow[ED],mincost += flow[ED] * dis[ED];
		}
		return make_pair(maxflow,mincost);
	}
	int nnt,VST,VED,ST2,no[MAXN],outflow[7];
	inline ll Solve(){
		ll ret = 0;
		VST = ++nnt,VED = ++nnt,ST2 = ++nnt;
		CreateEdge(VST,ST2,5,0);
		for(int i = 1;i <= 3;i++){
			outflow[i] = ++nnt;
			if(i != 3){
				CreateEdge(outflow[i],VED,1,0);
			}else{
				CreateEdge(outflow[i],VED,3,0);
			}
		}
		for(int i = 0;i < 100;i++){
			no[i] = ++nnt;
			CreateEdge(ST2,no[i],1,0);
			for(int j = 1;j <= 3;j++){
				CreateEdge(no[i],outflow[j],1,-value[i][j]);
			}
		}
		ret = -MCMF(nnt,VST,VED).second;
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("lottery.in","r",stdin);
	freopen("lottery.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>inval;
		valcnt[inval]++;
	}
	for(int i = 1;i <= 1e6;i++){
		appearcnt[i][1] += valcnt[i];
		appearcnt[i % 10000][2] += valcnt[i];
		appearcnt[i % 100][3] += valcnt[i];
	}
	for(int i = 0;i < 1000000;i++){
		value[i % 100][1] = max(value[i % 100][1],appearcnt[i][1] * money1);
	}
	for(int i = 0;i < 10000;i++){
		value[i % 100][2] = max(value[i % 100][2],appearcnt[i][2] * money2);
	}
	for(int i = 0;i < 100;i++){
		value[i % 100][3] = max(value[i % 100][3],appearcnt[i][3] * money3);
	}
	cout<<MCMF::Solve()<<endl;
	return 0;
}
//Finished
