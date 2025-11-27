#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 1e5 + 1018 + 1108;
const int INF = 1e9;
struct Edge{
	int nxt,to,val;
	Edge(){}
	Edge(int u,int v,int w){nxt = u,to = v,val = w;}
}e[MAXM * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,k;
inline void ReadIn(){
	cin>>n>>k;
	for(int i = 1;i <= k;i++){
		int x,a,b;
		cin>>x>>a>>b;
		if(x == 1){
			AddEdge(a,b,0),AddEdge(b,a,0);
		}else if(x == 2){
			AddEdge(b,a,-1);
		}else if(x == 3){
			AddEdge(a,b,0);
		}else if(x == 4){
			AddEdge(a,b,-1);
		}else{
			AddEdge(b,a,0);
		}
	}
	return ;
}
int dfn[MAXN],low[MAXN],dnt,bel[MAXN],siz[MAXN],SCC_cnt;
stack<int,vector<int> > stk;
bool ins[MAXN],OK = true;
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	ins[u] = true;
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
		++SCC_cnt;
		while(!stk.empty()){
			const int tp = stk.top();
			ins[tp] = false;
			stk.pop();
			bel[tp] = SCC_cnt;
			siz[SCC_cnt]++;
			if(tp == u)break;
		}
	}
	return ;
}
int in[MAXN];
inline void Remake(){
	vector<Edge> nowe;
	for(int i = 1;i <= n;i++){
		if(!dfn[i])Tarjan(i);
	}
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(bel[u] == bel[v]){
				if(e[i].val != 0)OK = false;
				continue;
			}
			nowe.emplace_back(bel[u],bel[v],e[i].val);
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : nowe){
		in[i.nxt]++;//注意加没加对,要改一起改 
		AddEdge(i.to,i.nxt,-i.val);//建的是反边反值 
	}
	n = SCC_cnt;
	return ;
} 
int vis[MAXN];
void dfs(int u){
	vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v] == 0){
			dfs(v); 
		}else if(vis[v] == 1){
			OK = false;
		}
	}
	vis[u] = 2;
	return ;
}
inline void GetCircle(){
	for(int i = 1;i <= n;i++){
		if(!vis[i])dfs(i);
	}
	return ;
}
int val[MAXN]; 
inline long long Topo(){
	long long ans = 0;
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(in[i] == 0)q.push(i);
		val[i] = 1;
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		ans += val[u] * siz[u];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			in[v]--;
			if(in[v] == 0)q.push(v);
			val[v] = max(val[v],val[u] + e[i].val);
		}
	} 
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Remake();
	GetCircle();
	if(!OK){
		cout<<-1<<endl;
		return 0;
	}
	cout<<Topo()<<endl;
	return not(Akano loves pure__Elysia);
}
