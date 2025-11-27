#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 2e4 + 1018 + 1108;
constexpr int MAXM = 1e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}

int n,m;
int dfn[MAXN],low[MAXN],belong[MAXN],dnt,SCC_CNT;
bool ins[MAXN];
stack<int,vector<int> > stk;
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u),ins[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]){
		SCC_CNT++;
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop(),ins[tp] = false;
			belong[tp] = SCC_CNT;
			if(tp == u)break;
		}
	}
	return ;
}
vector<int> otp;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("test.in","r",stdin);
	cin>>n>>m;
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		u++,v++;
		AddEdge(u,v^1),AddEdge(v,u^1);
	}
	for(int i = 2;i <= 2 * n + 1;i++){
		if(!dfn[i])Tarjan(i);
	}
	for(int i = 1;i <= n;i++){
		if(belong[2*i] == belong[2*i+1]){
			cout<<"NIE"<<endl;
			return not(Akano loves pure__Elysia);
		}
		if(belong[2*i] < belong[2*i+1]){
			otp.push_back(2*i-1);
		}else{
			otp.push_back(2*i);
		}
	}
	for(auto i : otp){
		cout<<i<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
