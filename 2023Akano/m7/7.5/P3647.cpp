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
int delta[MAXN][2];
inline void Update(const int& OBJ,int& max1,int& max2){
	if(OBJ > max1){
		max1 = OBJ;
	}else if(OBJ > max2){
		max2 = OBJ;
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
		Update(f[v][0] + e[i].val - f[v][1] + faval[u],delta[u][0],delta[u][1]);
	}
	f[u][1] = f[u][0] + delta[u][0];//delta default 0
	return ;
}
inline void MoveRoot(int u,int v,int Eval){//u -> v
	f[u][0] -= f[v][1];
	if(Eval + faval[u] + f[v][0] - f[v][1] == delta[u][0]){
		f[u][1] = f[u][0] + delta[u][1];
	}else{
		f[u][1] = f[u][0] + delta[u][0];
	}
	f[v][0] += f[u][1];
	const int newdelta = Eval + 
	return ;
}
void dfs(int u,int fa){//nowroot is u
	ans = max(ans,f[u][0]);
	int nowans = f[u][0];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)return ;
		MoveRoot(u,v,e[i].val);
		dfs(v,u);
		MoveRoot(v,u,e[i].val);
	}
	return ;
}
int main(){
	freopen("P3647.in","r",stdin);
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
