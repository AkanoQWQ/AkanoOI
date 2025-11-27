#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 5e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
	ll val;
}e[MAXM * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
ll ans;
bool vis[MAXN];
inline bool BFS(){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			if((e[i].val & ans) != ans){
				continue;
			}
			const int v = e[i].to;
			if(vis[v])continue;
			q.push(v),vis[v] = true;
			if(v == n)return true;
		}
	}
	return vis[n];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	for(int i = 63;i >= 0;i--){
		ans += (1ll<<i);
		if(BFS() == false)ans -= (1ll<<i);
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
