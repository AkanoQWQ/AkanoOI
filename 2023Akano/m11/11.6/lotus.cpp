#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 506;
namespace Dinic{
	using ll = long long;
	constexpr int MAX_DINIC_N = 1018;
	constexpr int MAX_DINIC_M = (2006 + 1018 + 1108) * 20;
	constexpr int INF = 0x7fffffff;
	struct Edge{
		int nxt,to;
		ll cap;
	}e[MAX_DINIC_M];
	int head[MAX_DINIC_N],cnt = 1;
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
	int dep[MAX_DINIC_N],cur[MAX_DINIC_N];
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
	inline void Clear(int _n){
		for(int i = 1;i <= _n;i++){
			head[i] = 0;
		}
		cnt = 1;
		return ;
	}
}
using Dinic::CreateEdge;
using Dinic::Clear;
constexpr int INF = 1e9;

int n,m,Q,s[MAXN],k,a[MAXN],b[MAXN];
struct Customer1{
	int l,r,x;
}c1[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("lotus.in","r",stdin);
	freopen("lotus.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	for(int i = 1;i <= m;i++){
		cin>>c1[i].l>>c1[i].r>>c1[i].x;
	}
	for(int nowq = 1;nowq <= Q;nowq++){
		cin>>k;
		for(int j = 1;j <= k;j++){
			cin>>a[j]>>b[j];
		}
		const int VST = n + m + k + 1;
		const int VED = n + m + k + 2;
		Clear(VED);
		for(int i = 1;i <= n;i++){
			CreateEdge(i,VED,s[i]);
		}
		for(int i = 1;i <= m;i++){
			for(int j = c1[i].l;j <= c1[i].r;j++){
				CreateEdge(n+i,j,INF);
			}
			CreateEdge(VST,n+i,c1[i].x);
		}
		for(int i = 1;i <= k;i++){
			const int no = n + m + i;
			CreateEdge(VST,no,b[i]);
			for(int j = 1;j <= n;j++){
				CreateEdge(no,j,a[i]);
			}
		}
		cout<<Dinic::Dinic(VED,VST,VED)<<endl;
	}
	return not(Akano loves pure__Elysia);
}
