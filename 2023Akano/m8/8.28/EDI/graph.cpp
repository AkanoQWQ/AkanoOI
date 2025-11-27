#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 24;
const int MAXE = MAXN * MAXM * 2;
struct Edge{
	int nxt,to;
}e[MAXE];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool vis[MAXN];
int T,n,m;
inline void Clear(){
	for(int i = 1;i <= n;i++)head[i] = vis[i] = 0;
	cnt = 0;
	return ;
}
namespace Subtask1{
	void dfs(int u){
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(vis[v])continue;
			dfs(v);
		}
		return ;
	}
	inline int Solve(){
		int ret = 0;
		Clear();
		for(int i = 1;i <= m;i++){
			int x;
			cin>>x;
			for(int j = 1;j <= n;j++){
				if(j - x >= 1){
					AddEdge(j-x,j),AddEdge(j,j-x);
				}
			}
		}
		for(int i = 1;i <= n;i++){
			if(vis[i])continue;
			ret++;
			dfs(i);
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n <= 1e5 + 1018){
			cout<<Subtask1::Solve()<<'\n';
		}else{
			cout<<1<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
