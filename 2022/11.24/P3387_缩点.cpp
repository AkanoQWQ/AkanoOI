#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 6;
const int MAXM = 2e5 + 6;
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
}e1[MAXM],e2[MAXM];
int h1[MAXN],h2[MAXN],ent1 = 1,ent2 = 1;
void AddEdge1(int from,int to){
	e1[++ent1].to = to;
	e1[ent1].from = from;
	e1[ent1].nxt = h1[from];
	h1[from] = ent1;
	return ;
}
void AddEdge2(int from,int to){
	e2[++ent2].to = to;
	e2[ent2].nxt = h2[from];
	h2[from] = ent2;
	return ;
}
int p[MAXN],n,m,dfn[MAXN],dnt,bel[MAXN],in[MAXN],ans,dp[MAXN],low[MAXN];
vector<int> np;
queue<int> q;
void topo(){
	for(int i = 0;i < np.size();i++){
		const int u = np[i];
		if(in[u] == 0)q.push(u);
		dp[u] = p[u];
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = h2[u];i;i = e2[i].nxt){
			const int v = e2[i].to;
			in[v]--;
			if(in[v] == 0)q.push(v);
			dp[v] = max(dp[v],p[v] + dp[u]);
		}
	}
	for(int i = 0;i < np.size();i++){
		const int u = np[i];
		ans = max(ans,dp[u]);
	}
	return ;
}
stack<int> stk;
bool ins[MAXN];
void tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	ins[u] = 1;
	for(int i = h1[u];i;i = e1[i].nxt){
		const int v = e1[i].to;
		if(dfn[v] == 0){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			ins[tp] = 0;
			bel[tp] = u;
			if(tp == u)break;
			p[u] += p[tp];
		}
		np.push_back(u);
	}
	return ;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		p[i] = read(); 
	}
	for(int i = 1;i <= m;i++){
		int u = read(),v = read();
		AddEdge1(u,v);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int i = 2;i <= ent1;i++){
		const int u = bel[e1[i].from],v = bel[e1[i].to];
		if(u != v){
			AddEdge2(u,v);
			in[v]++;
		}
	}
	topo();
	write(ans);
	return 0;
}
