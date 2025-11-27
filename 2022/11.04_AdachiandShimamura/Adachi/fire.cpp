#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300006;
int n,s;
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
struct Edge{
	int nxt,to,v;
}e[MAXN*4];
int head[MAXN],tot = 1;
void AddEdge(int from,int to,int val){
	e[++tot].to = to;
	e[tot].v = val;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int maxval,ans = 0x7fffffff;
void dfs(int u,int fa,int val){
	if(val > maxval)maxval = val;
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to != fa)dfs(e[i].to,u,val + e[i].v);
	}
	return ;
}
int main(){
	freopen("fire.in","r",stdin);
	freopen("fire.out","w",stdout);
	n = read(),s = read();
	for(int i = 1;i < n;i++){
		int a = read(),b = read();
		int c = read();
		AddEdge(a,b,c);
		AddEdge(b,a,c);
	}
	for(int i = 2;i <= tot;i += 2){
		if(e[i].v > s)continue;
		int x = e[i].to,y = e[i+1].to;
		maxval = 0;
		dfs(x,y,0);
		dfs(y,x,0);
		ans = min(ans,maxval);
	}
	printf("%d",ans);
	return 0;
}
