#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1018;
const int MAXP = 1e6 + 1018 + 1108;
const int MAXSCC = 5e4 + 1018 + 1108;
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
int tid,n,m,q,id[MAXN][MAXN],bel[MAXP],siz[MAXP],nnt,SCC_CNT;
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
	cerr<<"point "<<SCC_CNT<<endl;
	return ;
}
bitset<MAXSCC> from[MAXSCC],to[MAXSCC];//from 可以从哪里来 to 可以到哪里去
inline void Topo(bitset<MAXSCC> st[]){
	queue<int> kueue;
	for(int i = 1;i <= SCC_CNT;i++){
		if(d[i] == 0)kueue.push(i);
	}
	while(!kueue.empty()){
		const int u = kueue.front();
		kueue.pop();
		st[u][u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			d[v]--;
			if(d[v] == 0)kueue.push(v);
			st[v] |= st[u];
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
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("maze/maze1.in","r",stdin);
	cin>>tid>>n>>m>>q;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
			id[i][j] = ++nnt;
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
	while(q--){
		int a,b,c,dd,u,v;
		cin>>a>>b>>c>>dd;
		u = bel[id[a][b]],v = bel[id[c][dd]];
		bitset<MAXSCC> cnts = from[v] & to[u];
		int ans = 0;
		for(int i = cnts._Find_first();i <= SCC_CNT;i = cnts._Find_next(i)){
			ans += siz[i];
		}
		if(ans == 0)ans = -1;
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
