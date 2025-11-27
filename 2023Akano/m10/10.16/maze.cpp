#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1018;
const int MAXP = 1e6 + 1018 + 1108;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
struct Edge{
	int nxt,to;
}e[MAXP * 10];
int head[MAXP],d[MAXP],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int tid,n,m,q,id[MAXN][MAXN],bel[MAXP],siz[MAXP],saveSiz[MAXP],preSize[MAXP],nnt,SCC_CNT;
char mp[MAXN][MAXN];

int dfn[MAXP],low[MAXP],dnt;
stack<int,vector<int> > stk;
bool ins[MAXP];

void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	ins[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]){
		SCC_CNT++;
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			ins[tp] = false;
			bel[tp] = SCC_CNT;
			siz[SCC_CNT]++;
			if(tp == u)break;
		}
	}
	return ;
}
inline void Remake(){
	set<pair<int,int> > saveEdge;
	vector<int> vec;
	for(int i = 1;i <= SCC_CNT;i++){
		vec.push_back(i);
	}
	for(int u = 1;u <= nnt;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(bel[u] == bel[v])continue;
			saveEdge.insert(make_pair(bel[u],bel[v]));
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : saveEdge){
		AddEdge(i.first,i.second);
		d[i.second]++;
	}
	cerr<<"POINT "<<SCC_CNT<<endl;
	return ;
}
vector<pii> from[MAXP],to[MAXP]; 
inline vector<pii> Merge(vector<pii>& vec1,vector<pii>& vec2){
	vector<pii> ret;
	auto it1 = vec1.begin(),it2 = vec2.begin();
	while(it1 != vec1.end() || it2 != vec2.end()){
		pii now;
		if(it1 == vec1.end()){
			now = *(it2++);
		}else if(it2 == vec2.end()){
			now = *(it1++);
		}else if((*it1) < (*it2)){
			now = *(it1++);
		}else{
			now = *(it2++);
		}
		if(ret.empty()){
			ret.push_back(now);
		}else if(now.first <= ret.back().second + 1){
			ret.back().second = max(now.second,ret.back().second);
		}else{
			ret.push_back(now);
		}
	}
	return ret;
}
inline void Topo(vector<pii> st[]){
	queue<int> kueue;
	for(int i = 1;i <= SCC_CNT;i++){
		if(d[i] == 0)kueue.push(i);
	}
	while(!kueue.empty()){
		const int u = kueue.front();
		kueue.pop();
		vector<pii> vec;
		vec.emplace_back(u,u);
		st[u] = Merge(st[u],vec);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			d[v]--;
			if(d[v] == 0)kueue.push(v);
			st[v] = Merge(st[v],st[u]);
		}
	}
	return ;
}
inline void Reverse(){
	vector<pair<int,int> > saveEdge;
	for(int u = 1;u <= SCC_CNT;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			saveEdge.emplace_back(u,v);
		}
		head[u] = 0;
		d[u] = 0;
	}
	cnt = 0;
	for(auto i : saveEdge){
		AddEdge(i.second,i.first);
		d[i.first]++;
	}
	return ;
}
mt19937 rng(time(0));
inline void BFS(int nowt){
	queue<pii> kueue;
	for(int i = 1;i <= nowt;i++){
		int x = (rng() % n) + 1,y = (rng() % m) + 1;
		if(id[x][y])
		kueue.push(make_pair(x,y));
		id[x][y] = ++nnt;
	}
	
	while(!kueue.empty()){
		const pii u = kueue.front();
		kueue.pop();
		for(int k = 0;k < 4;k++){
			const int OX = u.first + dx[k],OY = u.second + dy[k];
			if(not(1 <= OX && OX <= n && 1 <= OY && OY <= m) || id[OX][OY])continue;
			id[OX][OY] = ++nnt;
			kueue.push(make_pair(OX,OY));
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("maze.in","r",stdin);
//	freopen("maze.out","w",stdout);
	cin>>tid>>n>>m>>q;
	BFS(5);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(mp[i][j] != 'L' && id[i][j-1])AddEdge(id[i][j],id[i][j-1]);
			if(mp[i][j] != 'R' && id[i][j+1])AddEdge(id[i][j],id[i][j+1]);
			if(mp[i][j] != 'U' && id[i-1][j])AddEdge(id[i][j],id[i-1][j]);
			if(mp[i][j] != 'D' && id[i+1][j])AddEdge(id[i][j],id[i+1][j]);
		}
	}
	for(int i = 1;i <= nnt;i++){
		if(!dfn[i])Tarjan(i);
	}
	Remake();
	Topo(from);
	Reverse();
	Topo(to);
	for(int i = 1;i <= SCC_CNT;i++){
		preSize[i] = preSize[i-1] + siz[i];
	}
	while(q--){
		int a,b,c,dd,u,v;
		cin>>a>>b>>c>>dd;
		u = bel[id[a][b]],v = bel[id[c][dd]];
		int ans = 0;
		auto it = to[u].begin();
		for(auto i : from[v]){
			while(it != to[u].end()){
				int realL = max(i.first,it->first);
				int realR = min(i.second,it->second);
				if(realR >= realL){
					ans += preSize[realR] - preSize[realL - 1];
				}
				if(it->second <= i.second){
					++it;
				}else{
					break;
				}
			}
		}
		if(ans == 0)ans = -1;
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
