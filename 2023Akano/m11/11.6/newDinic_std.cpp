#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
namespace Dinic{
	using ll = long long;
	constexpr int MAX_DINIC_N = ;//remember to EDIT
	constexpr int MAX_DINIC_M =  + 1018 + 1108;//EDIT and *2
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
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return not(Akano loves pure__Elysia);
}
