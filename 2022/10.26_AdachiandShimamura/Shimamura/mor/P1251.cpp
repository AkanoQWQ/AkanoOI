#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 6006;
const int MAXM = 150006;
const ll INF = 1ll * 0x7fffffff * ((0x7fffffff)/4);
int n,s,t,tot = 1,head[MAXN];
ll mincost,maxflow;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct Edge{
	int to,nxt;
	ll cap,cost;	
}e[MAXM];
void AddEdge(int u,int v,ll cap,ll cost){
	e[++tot].cap = cap;
	e[tot].to = v;
	e[tot].cost = cost;
	e[tot].nxt = head[u];
	head[u] = tot;
	return ;
}
void AdasEgxo(int u,int v,ll cap,ll cost){
	AddEdge(u,v,cap,cost);
	AddEdge(v,u,0,-cost);
}
bool inq[MAXN];
int pre[MAXN];
ll incf[MAXN],dis[MAXN];
queue<int> q;
bool SPFA(int st,int ed){
	memset(incf,0,sizeof(incf));
	memset(pre,0,sizeof(pre));
	for(int i = 1;i <= t;i++)dis[i] = INF;
	inq[st] = 1,dis[st] = 0,incf[st] = INF;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		inq[u] = 0;
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			if(e[i].cap <= 0)continue;
			const int v = e[i].to;
			if(dis[u] + e[i].cost < dis[v]){
				dis[v] = dis[u] + e[i].cost;
				pre[v] = i;
				incf[v] = min(incf[u],e[i].cap);
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return (pre[ed] != 0);
}
void Dinic(int st,int ed){
	while(SPFA(st,ed)){
		int pos = ed;
		maxflow += incf[ed];
		mincost += incf[ed] * dis[ed]; 
		while(pos != st){
			e[pre[pos]].cap -= incf[ed];
			e[pre[pos]^1].cap += incf[ed];
			pos = e[pre[pos]^1].to;
		}
	}
	return ;
}
int p,m,f,n2,s2;
int main(){
	s = 0,t = 5006;
	n = read();
	for(int i = 1;i <= n;i++){
		ll ino;
		ino = read();
		AdasEgxo(s,i,ino,0);
		AdasEgxo(i+n,t,ino,0);
	}
	p = read(),m = read(),f = read(),n2 = read(),s2 = read();
	for(int i = 1;i <= n;i++){
		if(i+1 <= n)AdasEgxo(i,i+1,INF,0);
		if(i+m <= n)AdasEgxo(i,i+n+m,INF,f);
		if(i+n2 <= n)AdasEgxo(i,i+n+n2,INF,s2);
		AdasEgxo(s,i+n,INF,p);
	}
	Dinic(s,t);
	cout<<mincost;
	return 0;
}
