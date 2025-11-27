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
	int nxt,to;
};
struct Edges{
	Edge e[MAXM];
	int tot = 1,head[MAXN];
	Edge& operator[](int inx){
		return e[inx];
	}
	inline void AddEdge(int from,int to){
		e[++tot].to = to;
		e[tot].nxt = head[from];
		head[from] = tot;
		return ;
	}
	inline void st(int inx,int& stat){
		stat = head[inx];
		return ;
	}
	bool nxt(Edge& ine,int& stat){
		if(stat == 0)return 0;
		ine = e[stat];
		stat = e[stat].nxt;
		return 1;
	}
}e1,e2; 
int p[MAXN],n,m,dfn[MAXN],dnt,bel[MAXN],in[MAXN],ans,dp[MAXN],low[MAXN];
vector<int> np;
queue<int> q;
void topo(){
	for(auto i : np){
		if(in[i] == 0)q.push(i);
		dp[i] = p[i];
		ans = max(ans,dp[i]);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		Edge nowe;
		int nh;
		e2.st(u,nh);
		while(e2.nxt(nowe,nh)){
			const int v = nowe.to;
			in[v]--;
			if(in[v] == 0)q.push(v);
			dp[v] = max(dp[v],p[v] + dp[u]);
			ans = max(ans,dp[v]);
		}
	}
}
stack<int> stk;
bool ins[MAXN];
void tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	ins[u] = 1;
	int nh;
	e1.st(u,nh);
	Edge nowe;
	while(e1.nxt(nowe,nh)){
		const int v = nowe.to;
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
		e1.AddEdge(u,v);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int i = 1;i <= n;i++){
		int nh;
		e1.st(i,nh);
		const int u = i;
		Edge nowe;
		while(e1.nxt(nowe,nh)){
			const int v = nowe.to;
			if(bel[u] != bel[v]){
				e2.AddEdge(bel[u],bel[v]);
				in[bel[v]]++;
			}
		}
	}
	topo();
	write(ans);
	return 0;
}

