#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 1018;
constexpr int MAXM = (2006 + 1018 + 1108) * 4;
constexpr int INF = 1e9 + 7;
constexpr int MOD = 1e9 + 7;
int eid;
struct Edge{
	int nxt,to,nowid;
	ll cap,maxcap;
	inline void Update(){
		if(nowid != eid){
			cap = maxcap;
			nowid = eid;
		}
		return ;
	}
}e[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].nowid = -1;
	e[cnt].maxcap = val;
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
			e[i].Update();
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
		e[i].Update();
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
	eid++;
	while(BFS(n,ST,ED)){
		ret += DFS(ST,INF);
	}
	return ret;
}
int n,m;
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("flow.in","r",stdin);
	freopen("flow.out","w",stdout);
	cin>>n>>m;
	for(int i = 1,u,v,w;i <= m;i++){
		cin>>u>>v>>w;
		CreateEdge(u,v,w);
		CreateEdge(v,u,w);
	}
	for(int u = 1;u <= n;u++){
		for(int v = u + 1;v <= n;v++){
			ans = (ans + Dinic(n,u,v)) % MOD;
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
