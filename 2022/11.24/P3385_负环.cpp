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
int n,m,t;
bool inq[MAXN];
int dms[MAXN],h[MAXN];
bool SPFA(int st){
	queue<int> q;
	while(!q.empty())q.pop();
	for(int i = 0;i <= n;i++){
		h[i] = INF;
		dms[i] = 0;
		inq[i] = 0;
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
					if(dms[v] >= n){
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
	t = read();
	while(t--){
		n = read(),m = read();
		for(int i = 1;i <= n;i++)head[i] = 0;
		tot = 1;
		for(int i = 1;i <= m;i++){
			int u = read(),v = read(),w = read();
			if(w >= 0){
				AddEdge(u,v,w);
				AddEdge(v,u,w);
			}else{
				AddEdge(u,v,w);
			}
		}
		if(SPFA(1)){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}
