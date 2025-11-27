#include<bits/stdc++.h>
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
void write(int x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,w;
}e[MAXM];
int head[MAXN],tot;
void AddEdge(int from,int to,int w){
	e[++tot].to = to;
	e[tot].w = w;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dis[MAXN];
int n,m,s;
bool vis[MAXN];
priority_queue<pair<int,int> > q;
void Dij(int st){
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
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}
int main(){
	n = read(),m = read();
	s = 1;
	while(m--){
		int u = read(),v = read(),w = read();
		AddEdge(u,v,w);
	}
	Dij(s);
	for(int i = 1;i <= n;i++){
		write(dis[i]),putchar(' ');
	}
	return 0;
}
