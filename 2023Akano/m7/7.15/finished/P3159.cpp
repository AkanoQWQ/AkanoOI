#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXR = 24;
const int MAXP = MAXR*MAXR + 1018 + 1108;//remember to EDIT
const int MAXM = MAXP * 6 + 1018 + 1108;//EDIT and *2
const int INF = 1e9;
const int dx[8] = {1,0,-1,0,1,-1,1,-1};
const int dy[8] = {0,1,0,-1,1,-1,-1,1};
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
int no[MAXR][MAXR][2],nnt,VST,VED,n,m,chess;
char MP1[MAXR][MAXR],MP2[MAXR][MAXR];
inline bool Judge(int x,int y){
	return (x >= 1 && x <= n) && (y >= 1 && y <= m);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			no[i][j][0] = ++nnt;
			no[i][j][1] = ++nnt;
		}
	}
	VST = ++nnt,VED = ++nnt;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>MP1[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>MP2[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			char ch;
			cin>>ch;
			int chance = ch - '0';
			if(MP1[i][j] == '1' && MP2[i][j] == '1'){
				//DO NOTHING
			}else if(MP1[i][j] == '1'){
				++chess;
				if(chance == 0){
					cout<<-1<<endl;
					return 0;
				}
				--chance;
				CreateEdge(VST,no[i][j][1],1,0);
			}else if(MP2[i][j] == '1'){
				if(chance == 0){
					cout<<-1<<endl;
					return 0;
				}
				--chance;
				CreateEdge(no[i][j][0],VED,1,0);
			}
			CreateEdge(no[i][j][0],no[i][j][1],chance/2,0);
			for(int k = 0;k < 8;k++){
				const int OX = i + dx[k],OY = j + dy[k];
				if(!Judge(OX,OY))continue;
				CreateEdge(no[i][j][1],no[OX][OY][0],INF,1);
			}
		}
	}
	pair<ll,ll> ans = MCMF::MCMF(nnt,VST,VED);
	if(ans.first != chess){
		cout<<-1<<endl;
	}else{
		cout<<ans.second<<endl;
	}
	return 0;
}
