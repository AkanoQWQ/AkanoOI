#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 10010
#define MAXM 105
#define int long long
using namespace std;
int n,m;
int q[MAXM];
struct Edge{
	int nxt,to,val;
}edge[MAXN<<1];
int head[MAXN],tot;
inline void add_edge(int u,int v,int w){
	edge[++tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=head[u];
	head[u]=tot;
}
int pos,siz[MAXN],wei;
bool vis[MAXN];
int rt,sum;
bool fl[MAXM];
void getcon(int now,int fath){
	siz[now]=1;
	int weight=0;
	for(int i=head[now];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fath||vis[v]) continue;
		getcon(v,now);
		siz[now]+=siz[v];
		weight=max(weight,siz[v]);
	}
	weight=max(weight,sum-weight);
	if(weight<wei){
		rt=now;
		wei=weight;
	}
}
int dd[MAXN],d[MAXN];
int cnt;
void dfs(int now,int fath){
	dd[++cnt]=d[now];
	for(int i=head[now];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fath||vis[v]) continue;
		d[v]=d[now]+edge[i].val;
		dfs(v,now);
	}
}
bool hd[10000010];
queue<int>qu;
void calc(int x,int fath){
	hd[0]=true;
	qu.push(0);
	vis[x]=true;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fath||vis[v]) continue;
		d[v]=edge[i].val;
		dfs(v,x);
		for(int k=1;k<=cnt;k++){
			for(int j=1;j<=m;j++){
				if(q[j]>=dd[k]&&hd[q[j]-dd[k]]) fl[i]=true;
			}
		}
		for(int k=1;k<=cnt;k++){
			if(dd[k]<=10000000){
				qu.push(dd[k]);
				hd[dd[k]]=true;
			}
			
		}
		cnt=0;
	}
	while(!qu.empty()){
		hd[qu.front()]=false;
		qu.pop();
	}
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fath||vis[v]) continue;
		sum=siz[v];
		wei=INF;
		getcon(v,x);
		getcon(rt,-1);
		calc(rt,x);
	}
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&q[i]);
	}
	wei=INF;
	sum=n;
	
	getcon(1,0);
	
	getcon(rt,0);
	
	calc(rt,0);
	
	for(int i=1;i<=m;i++){
		if(fl[i]) printf("AYE\n");
		else printf("NAY\n");
	}
	return 0;
}
