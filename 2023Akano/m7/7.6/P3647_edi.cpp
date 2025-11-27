#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
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
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 2e5 + 6;
const int INF = 1e7;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void Update(const int& edi,int& val1,int& val2){
	if(edi > val1){
		val2 = val1; 
		val1 = edi;
	}else if(edi > val2){
		val2 = edi;
	}
	return ;
}
int n,f[MAXN][2],faval[MAXN],ans,k[MAXN][2],g[MAXN][2];
int delta[MAXN][2],father[MAXN];
void DP(int u,int fa){
	delta[u][0] = delta[u][1] = -INF;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		faval[v] = e[i].val;
		DP(v,u);
		const int calc = max(f[v][0],f[v][1]+e[i].val);
		f[u][0] += calc;
		Update(f[v][0]+e[i].val-calc,delta[u][0],delta[u][1]);
	}
	f[u][1] = f[u][0] + delta[u][0];
	return ;
}
inline void MoveRoot(const int& u,const int& v,const int& fau,const int& EVAL){
	k[u][0] = g[u][0] - max(f[v][0],f[v][1] + EVAL);
	const int decVal = k[fau][0]+faval[u]-max(k[fau][0],k[fau][1]+faval[u]);
	const int vVal = f[v][0]+EVAL-max(f[v][0],f[v][1]+EVAL);
	int delt = 0;
	if(vVal == delta[u][0]){
		delt = delta[u][1];
	}else{
		delt = delta[u][0];
	}
	if(fau != u)delt = max(delt,decVal);
	k[u][1] = k[u][0] + delt;
	g[v][0] = f[v][0] + max(k[u][0],k[u][1] + EVAL);
	g[v][1] = g[v][0] + max(delta[v][0],k[v][0]+EVAL-max(k[v][0],k[v][1]+EVAL));
	return ;
}
void dfs2(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		MoveRoot(u,v,fa,e[i].val);
		dfs2(v,u);
	}
	return ;
}
int main(){
	n = Read();
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read(),w = Read();
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	DP(1,1);
	g[1][0] = f[1][0];
	dfs2(1,1);
	for(int i = 1;i <= n;i++){
		ans = max(ans,g[i][0]);
	}
	Write(ans);
	return 0;
}
