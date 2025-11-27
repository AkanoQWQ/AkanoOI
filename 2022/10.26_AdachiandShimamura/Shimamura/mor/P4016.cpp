#include<bits/stdc++.h>
using namespace std;
const int MAXN = 606;
const int MAXM = 10006;
const int INF = 0x7fffffff;
int n,m,s,t,tot = 1,head[MAXN],mincost,maxflow;
inline int read(){
	int x=0,f=1;
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
	int to,cap,cost,nxt;	
}e[MAXM];
void AddEdge(int u,int v,int cap,int cost){
	e[++tot].cap = cap;
	e[tot].to = v;
	e[tot].cost = cost;
	e[tot].nxt = head[u];
	head[u] = tot;
	return ;
}
bool inq[MAXN];
int pre[MAXN],incf[MAXN],dis[MAXN];
queue<int> q;
bool SPFA(int st,int ed){
	memset(incf,0,sizeof(incf));
	memset(pre,0,sizeof(pre));
	for(int i = 1;i <= 300;i++)dis[i] = INF;
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
int cog[2006],cgos;
int main(){
	n = read();
	s = 0,t = 206;
	for(int i = 1;i <= n;i++){
		cog[i] = read();
		cgos += cog[i];
	}
	cgos /= n;
	for(int i = 1;i <= n;i++){
		cog[i] -= cgos;
		if(cog[i] > 0){
			AddEdge(s,i,cog[i],0);
			AddEdge(i,s,0,0);
		}else{
			AddEdge(i,t,-cog[i],0);
			AddEdge(t,i,0,0);
		}
		if(i == 1){
			AddEdge(1,2,INF,1);
			AddEdge(2,1,0,-1);
			AddEdge(1,n,INF,1);
			AddEdge(n,1,0,-1);
		}else if(i == n){
			AddEdge(n,n-1,INF,1);
			AddEdge(n-1,n,0,-1);
			AddEdge(n,1,INF,1);
			AddEdge(1,n,0,-1);
		}else{
			AddEdge(i,i+1,INF,1);
			AddEdge(i+1,i,0,-1);
			AddEdge(i,i-1,INF,1);
			AddEdge(i-1,i,0,-1);
		}
	}
	Dinic(s,t);
	cout<<mincost;
	return 0;
}
