#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 6;
struct Edge{
	int nxt,to,v;
} e[MAXN*2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	e[cnt].v = val;
	head[from] = cnt;
	return ;
}
bool vis[MAXN];
int ans = 0x7fffffff,n,m;
void dfs(int u,int from,int dep){
	vis[u] = 1;
	if(dep > ans)return ;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v]){
			if(v == 1 && from != v){
				ans = min(ans,dep + e[i].v);
			}
			continue;
		}
		dfs(v,u,dep+e[i].v);
	}
	vis[u] = 0;
	return ;
}
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= m;i++){
		int u = read(),v = read(),val = read();
		AddEdge(u,v,val);
		AddEdge(v,u,val);
	}
	dfs(1,0,0);
	if(ans == 0x7fffffff){
		ans = -1;
	}
	write(ans);
	putchar('\n');
	return 0;
}
