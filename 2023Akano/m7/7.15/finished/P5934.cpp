#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 20000 + 1018 + 1108;//remember to EDIT
const int MAXM = 800000 + 1018 + 1108;//EDIT and *2
const int MAXEDGE = 200000 + 1018 + 1108;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to;
	ll cap;
}e[MAXM];
struct Node{
	int u,v;
	ll cap;
}edges[MAXEDGE];
bool cmpMin(Node a,Node b){
	return a.cap < b.cap;
}
bool cmpMax(Node a,Node b){
	return a.cap > b.cap;
}
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].cap = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void CreateEdge(int from,int to,ll val){
	AddEdge(from,to,val);
	AddEdge(to,from,0);
	return ;
} 
int DFS_ED;//share 
int dep[MAXN],cur[MAXN];
bool BFS(int n,int ST,int ED){
	for(int i = 0;i <= n;i++){
		dep[i] = 0;
	}
	queue<int> q;
	dep[ST] = 1;
	q.push(ST);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		cur[u] = head[u];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dep[v] != 0 || e[i].cap <= 0)continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
	return (dep[ED] > 0);
}
int DFS(int u,ll val){
	if(u == DFS_ED || val == 0)return val;
	int ret = 0;
	for(int i = cur[u];i;i = e[i].nxt){
		const int v = e[i].to;
		cur[u] = i;
		if(e[i].cap <= 0 || dep[v] != dep[u] + 1)continue;
		const ll realPush = DFS(v,min(e[i].cap,val));
		ret += realPush;
		val -= realPush;
		e[i].cap -= realPush;
		e[i^1].cap += realPush;
		if(realPush == 0)dep[v] = -1;
		if(val == 0)break;
	}
	return ret;
}
inline ll Dinic(int n,int ST,int ED){
	ll ret = 0;
	DFS_ED = ED;
	while(BFS(n,ST,ED)){
		ret += DFS(ST,INF);
	}
	return ret;
}
int n,m,VST,VED;
ll inU,inV,inC;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	VST = 0,VED = n + 1;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u > v)swap(u,v);
		edges[i].u = u,edges[i].v = v,edges[i].cap = w;
	}
	cin>>inU>>inV>>inC;
	if(inU > inV)swap(inU,inV);
	sort(edges+1,edges+m+1,cmpMin);
	for(int i = 1;i <= m;i++){
		if(edges[i].cap >= inC)continue;
		CreateEdge(edges[i].u,edges[i].v,1);
		CreateEdge(edges[i].v,edges[i].u,1);
	}
	CreateEdge(VST,inU,INF),CreateEdge(inV,VED,INF);
	const ll DNC1 = Dinic(n+1,VST,VED);
	memset(head,0,sizeof(head)),cnt = 1;
	sort(edges+1,edges+m+1,cmpMax);
	for(int i = 1;i <= m;i++){
		if(edges[i].cap <= inC)continue;
		CreateEdge(edges[i].u,edges[i].v,1);
		CreateEdge(edges[i].v,edges[i].u,1);
	}
	CreateEdge(VST,inU,INF),CreateEdge(inV,VED,INF);
	const ll DNC2 = Dinic(n+1,VST,VED);
	cout<<DNC1 + DNC2;
	return 0;
}
