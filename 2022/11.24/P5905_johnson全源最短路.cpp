#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 6;
const int MAXM = 4e5 + 6;
const int INF = 0x7fffffff;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void write(long long x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,w,from;
}e[MAXM];
int head[MAXN],tot = 1;
void AddEdge(int from,int to,int w){
	e[++tot].to = to;
	e[tot].from = from;
	e[tot].w = w;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dis[MAXN];
int n,m,s;
bool vis[MAXN];
void Dij(int st){
	priority_queue<pair<int,int> > q;
	for(int i = 0;i <= n;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
	q.push(make_pair(0,st));
	dis[st] = 0;
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w){
				dis[v] = dis[u] + e[i].w;
				if(vis[v] == 0)q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}
bool inq[MAXN];
int dms[MAXN],h[MAXN];
bool SPFA(int st){
	queue<int> q;
	while(!q.empty())q.pop();
	for(int i = 0;i <= n;i++){
		h[i] = INF;
		dms[i] = 0;
	}
	h[st] = 0;
	inq[st] = 1;
	q.push(st);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(h[v] > h[u] + e[i].w){
				h[v] = h[u] + e[i].w;
				if(inq[v] == 0){
					dms[v]++;
					if(dms[v] >= n + 1){
						return 0;
					}
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return 1;
}
signed main(){
	n = read(),m = read();
	s = 1;
	while(m--){
		int u = read(),v = read(),w = read();
		AddEdge(u,v,w);
	}
	for(int i = 1;i <= n;i++){
		AddEdge(0,i,0);
	}
	bool solveable = SPFA(0);
	if(solveable == 0){
		puts("-1");
		return 0;
	}
	for(int i = 0;i <= tot;i++){
		e[i].w = e[i].w + h[e[i].from] - h[e[i].to];
	}
	for(int i = 1;i <= n;i++){
		Dij(i);
		long long ans = 0;
		for(int j = 1;j <= n;j++){
			if(dis[j] == INF){
				ans = ans + 1000000000ll * j;
			}else{
				ans = ans + 1ll * (dis[j] - h[i] + h[j]) * j;
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
