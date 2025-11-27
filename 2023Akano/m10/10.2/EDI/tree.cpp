#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const ll INF = 1e14;
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
bool blk[MAXN],wht[MAXN];
ll n,blkCnt,whtCnt,f[MAXN][3];//空白 黑 白
void dfs(int u,int fa){
	if(blk[u])f[u][0] = f[u][2] = INF;
	if(wht[u])f[u][0] = f[u][1] = INF;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		f[u][0] += min(f[v][0],min(f[v][1] + e[i].val,f[v][2] + e[i].val));
		f[u][1] += min(f[v][1],min(f[v][0],f[v][2] + e[i].val));
		f[u][2] += min(f[v][2],min(f[v][0],f[v][1] + e[i].val));
		f[u][0] = min(f[u][0],INF);
		f[u][1] = min(f[u][1],INF);
		f[u][2] = min(f[u][2],INF);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	cin>>blkCnt;
	for(int i = 1,no;i <=blkCnt;i++){
		cin>>no;
		blk[no] = true;
	}
	cin>>whtCnt;
	for(int i = 1,no;i <=whtCnt;i++){
		cin>>no;
		wht[no] = true;
	}
	dfs(1,-10181108);
	cout<<min(f[1][0],min(f[1][1],f[1][2]))<<endl;
	return not(Akano loves pure__Elysia);
}
