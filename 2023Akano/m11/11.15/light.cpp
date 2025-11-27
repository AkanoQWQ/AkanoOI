#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 2e6 + 1018 + 1108;
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
int t,n,m,a[MAXN],b[MAXN],r[MAXN];
bool vis[MAXN];
pii dfs(int u){
	vis[u] = true;
	pii ret = {0,1};
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		ret.first++;
		if(vis[v])continue;
		pii delta = dfs(v);
		ret.first += delta.first,ret.second += delta.second;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1;i <= 2 * n;i++){
			head[i] = 0,vis[i] = false;
		}
		cnt = 0;
		for(int i = 1;i <= 2 * n;i++){
			cin>>a[i];
		}
		for(int i = 1;i <= n;i++){
			cin>>b[i];
			if(b[i] == 1){
				AddEdge(i,n + i),AddEdge(n + i,i);
			}
		}
		for(int i = 1;i <= 2 * n;i++){
			cin>>r[i];
		}
		bool OK = true;
		for(int i = 1;i <= 2 * n;i++){
			if(!vis[i]){
				pii epcnt = dfs(i);
				if(epcnt.second == 2 * (epcnt.first - 1)){
					
				}
			}
		}
		if(OK == false){
			cout<<"Yes"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
