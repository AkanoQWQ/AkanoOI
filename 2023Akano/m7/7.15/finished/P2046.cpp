#include<bits/stdc++.h>
using namespace std;
const int MAXR = 606;
const int MAXN = MAXR * MAXR + MAXR;
const int MAXM = MAXN * 4 * 2;
const int INF = 1e9;
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
inline void AddUDE(int from,int to,int val){
	AddEdge(from,to,val),AddEdge(to,from,val);
	return ;
}
namespace TSW{
	int dis[MAXN];
	bool vis[MAXN];
	inline int Dij(int n,int ST,int ED){
		priority_queue<pair<int,int> >q;
		for(int i = 1;i <= n;i++)dis[i] = INF,vis[i] = false;
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
		return dis[ED];
	}
} 
int n,VST,VED,nnt,no[MAXR][MAXR],pop;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	VST = ++nnt,VED = ++nnt;
	for(int i = 0;i <= n+1;i++){
		for(int j = 0;j <= n+1;j++){
			no[i][j] = ++nnt;
		}
	}
	for(int i = 1;i <= n;i++){
		AddUDE(no[i][0],no[i+1][0],0);
		AddUDE(no[n+1][i-1],no[n+1][i],0);
		AddUDE(no[i-1][n+1],no[i][n+1],0);
		AddUDE(no[0][i],no[0][i+1],0);
	}
	AddEdge(VST,no[n+1][0],0),AddEdge(no[0][n+1],VED,0);
	for(int i = 1;i <= n+1;i++){
		for(int j = 1;j <= n;j++){
			cin>>pop;
			AddEdge(no[i][j],no[i-1][j],pop);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			cin>>pop;
			AddEdge(no[i][j],no[i][j+1],pop);
		}
	}
	for(int i = 0;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>pop;
			AddEdge(no[i][j],no[i+1][j],pop);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n+1;j++){
			cin>>pop;
			AddEdge(no[i][j],no[i][j-1],pop);
		}
	}
	cout<<TSW::Dij(nnt,VST,VED);
	return 0;
}

