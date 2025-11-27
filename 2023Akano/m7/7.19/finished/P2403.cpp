#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 2e6 + 1018 + 1108;
const int MAXR = 1e6 + 1018 + 1108;
const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,1,-1,1,-1};
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,useless,door[MAXN];
pii p[MAXN];
inline void ReadIn(){
	cin>>n>>useless>>useless;
	for(int i = 1;i <= n;i++){
		cin>>p[i].first>>p[i].second>>door[i];
	}
	return ;
}
int nameX[MAXR],nameY[MAXR];
map<pii,int> points;
vector<int> toX[MAXR],toY[MAXR];
inline void CreateEdge(){
	for(int u = 1;u <= n;u++){
		points[p[u]] = u;
		if(door[u] == 1){
			if(nameX[p[u].first]){
				AddEdge(u,nameX[p[u].first]);
				AddEdge(nameX[p[u].first],u);
			}else{
				nameX[p[u].first] = u;
			}
		}
		if(door[u] == 2){
			if(nameY[p[u].second]){
				AddEdge(u,nameY[p[u].second]);
				AddEdge(nameY[p[u].second],u);
			}else{
				nameY[p[u].second] = u;
			}
		}
		if(door[u] != 1)toX[p[u].first].push_back(u);
		if(door[u] != 2)toY[p[u].second].push_back(u);
	}
	for(int u = 1;u <= n;u++){
		if(door[u] == 1 && nameX[p[u].first] == u){
			for(auto v : toX[p[u].first]){
				AddEdge(u,v);
			}
		}
		if(door[u] == 2 && nameY[p[u].second] == u){
			for(auto v : toY[p[u].second]){
				AddEdge(u,v);
			}
		}
		if(door[u] == 3){
			for(int k = 0;k < 8;k++){
				const pii OBJ = make_pair(p[u].first + dx[k],p[u].second + dy[k]);
				if(points.find(OBJ) != points.end()){
					AddEdge(u,points[OBJ]);
				}
			}
		}
	}
	return ;
}
inline void BFAddEdge(){
	for(int u = 1;u <= n;u++){
		for(int v = 1;v <= n;v++){
			if(u == v)continue;
			if(door[u] == 1 && p[u].first == p[v].first){
				AddEdge(u,v);
			}
			if(door[u] == 2 && p[u].second == p[v].second){
				AddEdge(u,v);
			}
			if(door[u] == 3 && abs(p[u].first-p[v].first) <= 1 && abs(p[u].second-p[v].second) <= 1){
				AddEdge(u,v);
			}
		}
	}
	return ;
}
int dfn[MAXN],low[MAXN],dnt,bel[MAXN],sz[MAXN];
bool ins[MAXN];
stack<int,vector<int> > stk;
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	ins[u] = true;
	stk.push(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			bel[tp] = u;
			sz[u]++;
			ins[tp] = false;
			if(tp == u)break;
		}
	}
	return ;
}
inline void ExecuteTarjan(){
	for(int i = 1;i <= n;i++){
		if(!dfn[i])Tarjan(i);
	}
	return ;
}
int IN[MAXN];
inline void RebuildEdge(){
	vector<pii> edges;
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(bel[u] != bel[v]){
				edges.push_back(make_pair(bel[u],bel[v]));
			}
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : edges){
		AddEdge(i.first,i.second);
		IN[i.second]++;
	}
	return ;
}
int dp[MAXN];
inline int Topo(){
	int ret = 0;
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(bel[i] == i){
			dp[i] = sz[i];
			if(IN[i] == 0){
				q.push(i);
			}
			ret = max(ret,dp[i]);
		}
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		ret = max(ret,dp[u]);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			dp[v] = max(dp[v],dp[u] + sz[v]);
			IN[v]--;
			if(IN[v] == 0)q.push(v);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
//	BFAddEdge();
	CreateEdge();
	ExecuteTarjan();
	RebuildEdge();
	cout<<Topo()<<endl;
	return 0;
}
