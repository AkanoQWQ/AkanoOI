#include<bits/stdc++.h>
using namespace std;
const int MAXN = 114;
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
int n,dis[MAXN],pre[MAXN],farpos;
inline void Init(){
	memset(dis,0,sizeof(dis));
	memset(pre,0,sizeof(pre));
	return ;
}
void dfs(int u){
	if(dis[u] > dis[farpos])farpos = u;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(dis[v] != 0)continue;
		dis[v] = dis[u] + 1,pre[v] = u;
		dfs(v);
	}
	return ;
}
vector<int> d;
bool est[MAXN];
int dlen,id;
vector<int> cp,vis;
inline void Copy(int x){
	cp.push_back(x);
	vis.push_back(++id);
	return ;
}
inline void Vis(int x){
	vis.push_back(x);
	return ;
}
inline void GetD(){
	dis[1] = 1;
	dfs(1);
	Init();
	dis[farpos] = 1;
	dfs(farpos);
	dlen = dis[farpos];
	int pos = farpos;
	while(pos){
		d.push_back(pos);
		est[pos] = true;
		pos = pre[pos];
	}
	return ;
}
void dfs2(int u,int fa){
	Vis(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs2(v,u);
		Copy(u);
	}
	return ;
}
inline void Solve(){
	for(auto u : d){
		Vis(u);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(est[v])continue;
			dfs2(v,u);
			Copy(u);
		}
	}
	return ;
}
inline void Output(){
	cout<<cp.size()<<endl;
	for(auto i : cp)cout<<i<<" ";
	cout<<endl;
	for(auto i : vis)cout<<i<<" ";
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("combo/combo3.in","r",stdin);
	cin>>n;
	id = n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	GetD();
	Solve();
	Output();
	return 0;
}
