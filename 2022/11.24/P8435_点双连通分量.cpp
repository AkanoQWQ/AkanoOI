#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 6;
const int MAXM = 4e6 + 6;
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
struct Edge{
	int nxt,to,from;
}e[MAXM];
int head[MAXN],ent;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int n,m,dfn[MAXN],low[MAXN],dnt,ans;
bool GD[MAXN];
vector<int> dcc[MAXN]; 
stack<int> stk; 
void AddDCC(int x,int y){
	++ans;
	while(!stk.empty()){
		const int tp = stk.top();
		stk.pop();
		dcc[ans].push_back(tp);
		if(tp == y)break;
	}
	dcc[ans].push_back(x);
	return ;
}
void tarjan(int u,int fa){
	int child = 0;
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			child++;
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u]){
				GD[u] = 1;
				AddDCC(u,v); 
			}
		}else if(v != fa){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(fa == -1 && child == 0){
		dcc[++ans].push_back(u);
	}
	return ;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= m;i++){
		int u = read(),v = read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])tarjan(i,-1);
	}
	write(ans),putchar('\n');
	for(int i = 1;i <= ans;i++){
		write(dcc[i].size());
		putchar(' ');
		for(int j = 0;j < dcc[i].size();j++){
			write(dcc[i][j]),putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
