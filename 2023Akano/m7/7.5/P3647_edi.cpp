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
int n,f[MAXN][2],faval[MAXN],ans;
int delta[MAXN];
inline void ConstDP(int u,int fa){
	f[u][0] = f[u][1] = delta[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		f[u][0] += f[v][1];
		delta[u] = max(delta[u],f[v][0] + e[i].val - f[v][1] + faval[u]);
	}
	f[u][1] = f[u][0];
	if(delta[u] > 0)f[u][1] += delta[u];
	return ;
}
inline void MoveRoot(int u,int v,int Eval){
	faval[u] = Eval,faval[v] = 0;
	ConstDP(u,v);ConstDP(v,v);
	return ;
}
void dfs(int u,int fa){//nowroot is u
	ans = max(ans,f[u][0]);
	int nowans = f[u][0];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)return ;
		int U_f0 = f[u][0];
		int U_f1 = f[u][1];
		int U_del = delta[u];
		int V_f0 = f[v][0];
		int V_f1 = f[v][1];
		int V_del = delta[v];
		MoveRoot(u,v,e[i].val);
		dfs(v,u);
		f[u][0] = U_f0;
		f[u][1] = U_f1;
		delta[u] = U_del;
		f[v][0] = V_f0;
		f[v][1] = V_f1;
		delta[v] = V_del;
	}
	return ;
}
void DP(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		faval[v] = e[i].val;
		DP(v,u);
		f[u][0] += f[v][1];
		delta[u] = max(delta[u],f[v][0] + e[i].val - f[v][1] + faval[u]);
	}
	f[u][1] = f[u][0];
	if(delta[u] > 0)f[u][1] += delta[u];
	return ;
}
int main(){
	n = Read();
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read(),w = Read();
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	DP(1,1);
	dfs(1,1);
	Write(ans),edl;
	return 0;
}
