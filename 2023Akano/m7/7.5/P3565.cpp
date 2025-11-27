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
const int MAXN = 5006;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt,n;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int depcnt[MAXN];
void dfs(int u,int dep,int fa){
	depcnt[dep]++;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,dep+1,u);
	}
	for(int i = 0;i <= n;i++){
		if(u != fa && i != dep)depcnt[i] %= 3;
	}
	return ;
}
int C[MAXN][5];
inline void Pre(){
	for(int i = 0;i <= n;i++){
		C[i][0] = 1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return ;
}
inline int Solve(const int& u){
	int ret = 0;
	memset(depcnt,0,sizeof(depcnt));
	dfs(u,0,u);
	for(int i = 0;i <= n;i++){
		cout<<"dep "<<i<<" cnt "<<depcnt[i]<<endl;
		if(depcnt[i] == 0)break;
		ret += C[depcnt[i]][3];
	}
	return ret;
}
int main(){
	freopen("P3565.in","r",stdin);
	n = Read();
	Pre();
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read();
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		Write(Solve(i)),edl;
	}
	return 0;
}
