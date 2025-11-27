#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXN = 206;//remember to EDIT
const int MAXM = MAXN * MAXN * 2 + 1018 + 1108;//EDIT and *2
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to;
	ll cap;
}e[MAXM];
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
int n,VST,VED;
pii r[MAXN],b[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>r[i].first>>r[i].second;
	for(int i = 1;i <= n;i++)cin>>b[i].first>>b[i].second;
	VST = 2*n + 1,VED = 2*n + 2;
	for(int i = 1;i <= n;i++){
		CreateEdge(VST,i,1);
		CreateEdge(i+n,VED,1);
		for(int j = 1;j <= n;j++){
			if(r[i].first < b[j].first && r[i].second < b[j].second){
				CreateEdge(i,j+n,1);
			}
		}
	}
	cout<<Dinic(VED,VST,VED);
	return 0;
}
