#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using ll = long long;
const int INF = 1e9;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(ll x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 1e5 + 6;
const int MAXV = 106;
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
int n,V,F[MAXN];//DP long long?
ll fromf[MAXN][MAXV][2],tof[MAXN][MAXV][2],near[MAXN],mans;
inline void Update(ll& org,const ll& newval){
	org = max(org,newval);
	return ;
}
void dfs(int u,int fa){
	fromf[u][0][1] = -INF,tof[u][0][1] = -INF;
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to != fa)near[u] += F[e[i].to];
	}
	fromf[u][1][1] = near[u] + F[fa];//start point
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		//CALC
		for(int j = 0;j <= V;j++){
			const int k = V - j;
			Update(mans,max(fromf[v][j][0],fromf[v][j][1])+max(tof[u][k][0],tof[u][k][1]+F[fa]-F[v]));
			Update(mans,max(tof[v][j][0],tof[v][j][1])+max(fromf[u][k][0],fromf[u][k][1]));
		}
		for(int j = 0;j <= V;j++){
			//Update fromf   ,from down to up
			//choose u
			if(j-1>=0)Update(fromf[u][j][1],max(fromf[v][j-1][0],fromf[v][j-1][1]) + near[u] + F[fa] - F[v]);
			//not choose u
			Update(fromf[u][j][0],max(fromf[v][j][0],fromf[v][j][1]));
			//update tof     ,from up to down
			//choose u
			if(j-1>=0)Update(tof[u][j][1],max(tof[v][j-1][0],tof[v][j-1][1]) + near[u]);
			//not choose u
			Update(tof[u][j][0],max(tof[v][j][0],tof[v][j][1]));
			//Update Presum
			if(j-1>=0)Update(tof[u][j][0],tof[u][j-1][0]);
			if(j-1>=0)Update(tof[u][j][1],tof[u][j-1][1]);
			if(j-1>=0)Update(fromf[u][j][0],fromf[u][j-1][0]);
			if(j-1>=0)Update(fromf[u][j][1],fromf[u][j-1][1]);
		}
	}
	return ;
}
int main(){
	freopen("P4657.in","r",stdin);
	n = Read(),V = Read();
	for(int i = 1;i <= n;i++){
		F[i] = Read();
	}
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read();
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,0);
	Write(mans);
	return 0;
}
