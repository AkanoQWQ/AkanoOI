#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018;
const int MAXM = 2006 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt,d[MAXN];
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int t,n,m;
bool OK,vis[MAXN];
inline void Clear(){
	for(int i = 1;i <= n;i++)head[i] = d[i] = vis[i] = 0;
	cnt = 0,OK = false;
	return ;
}
void dfs(int u){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!vis[v])dfs(v);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		Clear();
		for(int i = 1;i <= m;i++){
			int u,v;
			cin>>u>>v;
			AddEdge(u,v),AddEdge(v,u);
			d[u]++,d[v]++;
		}
		int num = 0,st = 1;
		for(int i = n;i >= 1;i--){
			if(d[i] & 1){
				st = i;
				num++;
			}
		}
		dfs(1);
		for(int i = 1;i <= n;i++){
			if(!vis[i])num = -1;
		}
		if(num == 0 || num == 2){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}

