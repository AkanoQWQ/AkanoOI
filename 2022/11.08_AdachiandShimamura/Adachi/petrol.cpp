#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200006;
const int MAXM = MAXN * 2;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m,s,q,totald,avgd;
bool add_fuel[MAXN];
struct Edge{
	int nxt,to,v;
}e[MAXM];
int head[MAXN],tot = 1;
void AddEdge(int from,int to,int v){
	e[++tot].to = to;
	e[tot].v = v;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
bool vis[MAXN],inq[MAXN];
int dis[MAXN];
queue<int> sq;
bool solve1(int st,int ed,int b){
	while(!sq.empty())sq.pop();
	for(int i = 1;i <= n;i++)vis[i] = 0;
	for(int i = 1;i <= n;i++)dis[i] = 0x7fffffff;
	sq.push(st);
	dis[st] = 0;
	while(!sq.empty()){
		const int u = sq.front();
		sq.pop();
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[u] + e[i].v <= b && dis[u] + e[i].v <= dis[v]){
				dis[v] = dis[u] + e[i].v;
				if(add_fuel[v])dis[v] = 0;
				if(inq[v])continue;
				inq[v] = 1;
				sq.push(v);
			}
		}
	}
	return (dis[ed] < 0x7fffffff);
}
bool CCF_NMSL(int inb){
	bool FUCK_CCF = 1;
	if(avgd * (n/s) > inb)return 0;
	return 1;
}
int main(){
	freopen("petrol.in","r",stdin);
	freopen("petrol.out","w",stdout);
	n = read(),s = read(),m = read();
	for(int i = 1;i <= s;i++){
		int c = read();
		add_fuel[c] = 1;
	}
	while(m--){
		int u = read(),v = read(),d = read();
		AddEdge(u,v,d);
		AddEdge(v,u,d);
		totald += d;
	}
	avgd = totald / m;
	q = read();
	while(q--){
		int x = read(),y = read(),b = read();
		if(n < 1000){
			if(solve1(x,y,b)){
				puts("TAK");
			}else{
				puts("NIE");
			}
		}else{
			if(CCF_NMSL(b)){
				puts("TAK");
			}else{
				puts("NIE");
			}
		}
	}
	return 0;
}
