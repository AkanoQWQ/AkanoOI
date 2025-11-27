#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1e4 + 1018 + 1108;
constexpr int MAXM = 1e6 + 1018 + 1108;
constexpr int SIZEN = 1e4 + 1000;
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
int T,lastans,dis[MAXN],q[MAXN];
inline void BFS(int ST){
	memset(dis,0,sizeof(dis));
	int qhead = 1,qtail = 0;
	q[++qtail] = ST;
	dis[ST] = 1;
	while(qhead <= qtail){
		const int u = q[qhead++];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] != 0)continue;
			dis[v] = dis[u] + 1;
			q[++qtail] = v;
		}
	}
	return ;
}
bool edgeval[12];
inline void LinkEdge(int n){
	for(int i = 0;i <= n;i++){
		int x = i;
		for(int j = 0;j <= 10;j++){
			edgeval[j] = false;
		}
		while(x){
			edgeval[x % 10] = true;
			x /= 10;
		}
		for(int j = 0;j <= 10;j++){
			if(edgeval[j]){
				AddEdge(i,i-j);
				AddEdge(i,i+j);
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	LinkEdge(SIZEN);
	while(T--){
		int x,y;
		cin>>x>>y;
		x ^= (lastans+1),y ^= (lastans+1);
		BFS(x);
		lastans = dis[y]-1;
		cout<<lastans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
