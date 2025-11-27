#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1018;
constexpr int MAXM = 2006 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,q;
int win[MAXN][MAXN][2];
bool vis[MAXN][MAXN][2];
int BFSvis[MAXN],BFSid;
inline vector<int> BFS(int ST,int ban){
	vector<int> vec;
	queue<int> kueue;
	BFSid++;
	kueue.push(ST);
	BFSvis[ST] = BFSid;
	while(!kueue.empty()){
		const int u = kueue.front();
		if(u != ST)vec.push_back(u);
		kueue.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(BFSvis[v] == BFSid || v == ban)continue;
			kueue.push(v),BFSvis[v] = BFSid;
		}
	}
	return vec;
}
int dfs(int u,int v,bool jerry){
	if(win[u][v][jerry] != 0)return win[u][v][jerry];
	vis[u][v][jerry] = true;
	int ret = -1;
	if(jerry){
		vector<int> reach = BFS(u,v);
		for(auto i : reach){
			if(vis[i][v][!jerry] == true){//对手是输自己赢
				bool OK = true;
				for(int j = head[v];j;j = e[j].nxt){
					const int obj = e[j].to;
					if(j == i)OK = false;
				}
				if(OK){
					ret = 1;
					break;
				}
			}else if(dfs(i,v,!jerry) == -1){
				ret = 1;
				break;
			}
		}
	}else{
		for(int i = head[v];i;i = e[i].nxt){
			const int obj = e[i].to;
			if(obj == u){
				ret = 1;
				break;
			}else if(vis[u][obj][!jerry]){
				//do nothing
			}else{
				int res = dfs(u,obj,!jerry);
				if(res == -1){//对手是输自己赢
					ret = 1;
					break;
				}
			}
		}
	}
	win[u][v][jerry] = ret;
	vis[u][v][jerry] = false;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("soldier.in","r",stdin);
	freopen("soldier.out","w",stdout);
	cin>>n>>m>>q;
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans = dfs(b,a,true);
		if(ans == 1){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
