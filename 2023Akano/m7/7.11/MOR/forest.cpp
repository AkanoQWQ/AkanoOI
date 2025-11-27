#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 6;
const int MOD = 1e9 + 7;
struct Edge{
	int nxt,to,no;
}e[MAXN * 2];
int head[MAXN],cnt;
bool del[MAXN];
inline void AddEdge(int from,int to,int no){
	e[++cnt].to = to;
	e[cnt].no = no;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
//BF
ll dis[MAXN],farpos,val[MAXN];
bool vis[MAXN];
stack<int,vector<int> > stk;
void dfs(int u,int fa){
	vis[u] = true;
	if(dis[u] > dis[farpos])farpos = u;
	stk.push(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || del[e[i].no])continue;
		dis[v] = dis[u] + val[v];
		dfs(v,u);
	}
	return ;
}
int n;
inline void Clear(){
	while(!stk.empty()){
		const int u = stk.top();
		stk.pop();
		dis[u] = 0;
	}
	return ;
}
inline ll Solve(){
	ll ret = 1;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			farpos = 0;
			dis[i] = val[i];
			dfs(i,i);
			Clear();
			dis[farpos] = val[farpos];
			dfs(farpos,farpos);
			ret = (ret * dis[farpos]) % MOD;
		}
	}
	return ret;
}

int main(){
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>val[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v,i),AddEdge(v,u,i);
	}
	cout<<Solve()<<'\n';
	for(int i = 1;i < n;i++){
		int delno;
		cin>>delno;
		del[delno] = true;
		cout<<Solve()<<'\n';
	}
	cout<<flush;
	return 0;
}
