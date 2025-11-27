#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
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
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,w;
}e[MAXM];
int head[MAXN],ent = 0;
void AddEdge(int from,int to,int val){
	e[++ent].to = to;
	e[ent].w = val;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int n,m,ans;
int dis[MAXN];
bool vis[MAXN];
bool Prim(){
	for(int i = 1;i <= n;i++){
		dis[i] = INF;
	}
	dis[1] = 0;
	for(int i = 1;i <= n;i++){
		int minc = INF,mp;
		for(int i = 1;i <= n;i++){
			if(vis[i])continue;
			if(dis[i] < minc){
				minc = dis[i];
				mp = i;
			}
		}
		if(minc == INF)return 0;
		ans += minc;
		vis[mp] = 1;
		for(int i = head[mp];i;i = e[i].nxt){
			const int v = e[i].to;
			dis[v] = min(dis[v],e[i].w);
		}
	}
	return 1;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= m;i++){
		int u = read(),v = read(),w = read();
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	if(Prim()){
		write(ans);
	}else{
		puts("orz");
	}
	return 0;
}
