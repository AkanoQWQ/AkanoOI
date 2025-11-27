#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1506;
const int MAXM = 6e5 + 6;
const int INF = 1e9;
struct Edge{
	int nxt,to,val;
	bool together;
}e[MAXM],e2[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool vis[MAXN];
int n,m;
inline void Dij(int ST,int* dis){
	priority_queue<pair<int,int> > q;
	for(int i = 1;i <= n;i++)dis[i] = INF;
	memset(vis,0,sizeof(vis));
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
	return ;
}
int ST1,ED1,ST2,ED2,disST1[MAXN],disST2[MAXN],disED1[MAXN],disED2[MAXN];
inline void Romeo(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(ST1);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(disST1[u] + e[i].val + disED1[v] == disST1[ED1]){
				e[i].together = e[i^1].together = true;
				if(vis[v] == false){
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	return ;
}
int disTOG[MAXN];
vector<int> path;
bool Cmp4Path(int pa,int pb){
	return disST2[pa] < disST2[pb];
}
inline void Juliet(){
	for(int i = 1;i <= n;i++){
		if(disST2[i] + disED2[i] == disST2[ED2]){
			path.push_back(i);
		}
	}
	sort(path.begin(),path.end(),Cmp4Path);
	return ;
}
inline int RomeoAndJuliet(){
	for(auto u : path){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			disTOG[v] = max(disTOG[v],disTOG[u] + e[i].val * e[i].together);
		}
	}
	return disTOG[ED2];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>ST1>>ED1>>ST2>>ED2;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	Dij(ST1,disST1),Dij(ST2,disST2),Dij(ED1,disED1),Dij(ED2,disED2);
	Romeo();
	Juliet();
	cout<<RomeoAndJuliet()<<endl;
	return 0;
}
