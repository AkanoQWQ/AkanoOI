#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const ll INF = 2e14 + 10181108;
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
int n,m,d[MAXN],c[MAXN];
namespace Subtask1{
	const int NOWN = 1108;
	vector<int> vecE[NOWN];
	ll dis[NOWN];
	inline void CreateEdge(int st){
		queue<int> q;
		for(int i = 1;i <= n;i++)dis[i] = 0;
		q.push(st);
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			if(dis[u] >= d[st])continue;
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(v == st || dis[v])continue;
				vecE[st].push_back(v);
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		return ;
	}
	bool vis[NOWN];
	inline void Dij(int st){
		priority_queue<pair<ll,int> > q;
		for(int i = 1;i <= n;i++){
			dis[i] = INF;
			vis[i] = false;
		}
		dis[st] = 0;
		q.push(make_pair(-dis[st],st));
		while(!q.empty()){
			const int u = q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u] = true;
			for(auto v : vecE[u]){
				if(dis[v] > dis[u] + c[u]){
					dis[v] = dis[u] + c[u];
					q.push(make_pair(-dis[v],v));
				}
			}
		}
		return ;
	}
	inline void Solve(){
		for(int i = 1;i <= n;i++)CreateEdge(i);
		Dij(1);
		for(int i = 2;i <= n;i++){
			cout<<dis[i]<<'\n';
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		cin>>d[i]>>c[i];
	};
	Subtask1::Solve();
	return not(Akano loves pure__Elysia);
}
