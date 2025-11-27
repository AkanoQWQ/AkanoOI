//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//using ll = long long;
//const int MAXN = 106;
//const int MAXM = MAXN * MAXN;
//const int MOD = 1e9 + 9;
//struct Edge{
//	int nxt,to;
//	bool isBridge;
//}e[MAXM];
//int head[MAXN],cnt = 1;
//inline void AddEdge(int from,int to){
//	e[++cnt].to = to;
//	e[cnt].nxt = head[from];
//	head[from] = cnt;
//	return ;
//}
//int n,m;
//inline void ReadIn(){
//	cin>>n>>m;
//	for(int i = 1,u,v;i <= m;i++){
//		cin>>u>>v;
//		AddEdge(v,u),AddEdge(u,v);
//	}
//	return ;
//}
//int dfn[MAXN],low[MAXN],dnt;
//ll f[MAXN][MAXN],siz[MAXN],C[MAXN][MAXN],ans[MAXN],nxtans[MAXN],g[MAXN];//f : u子树已经选了k个,当前选没选的方案数   g : u子树泉部选了的方案数
//inline void Pre(){
//	for(int i = 0;i <= n;i++){
//		C[i][0] = 1;
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
//		}
//	}
//	return ;
//}
//void Tarjan(int u,int from){
//	dfn[u] = low[u] = ++dnt;
//	for(int i = head[u];i;i = e[i].nxt){
//		const int v = e[i].to;
//		if(!dfn[v]){
//			Tarjan(v,u);
//			low[u] = min(low[u],low[v]);
//			if(low[v] > dfn[u]){
//				e[i].isBridge = e[i^1].isBridge = true;
//			}
//		}else if(v != from){
//			low[u] = min(low[u],dfn[v]);
//		}
//	}
//	return ;
//}
//bool vis[MAXN],est[MAXN];
//
//void dfs(int u,int& nowcnt){
//	vis[u] = est[u] = true;
//	nowcnt++;
//	for(int i = head[u];i;i = e[i].nxt){
//		const int v = e[i].to;
//		if(e[i].isBridge || vis[v])continue;
//		dfs(v,nowcnt);
//	}
//	return ;
//}
//inline void FindCircle(){
//	for(int i = 1;i <= n;i++){
//		if(!dfn[i])Tarjan(i,i);
//	}
//	for(int i = 1,cnts = 0;i <= n;i++){
//		if(!vis[i]){
//			cnts = 0;
//			dfs(i,cnts);
//			if(cnts == 1)est[i] = false;
//		}
//	}
//	return ;
//}
//void DP(int u,int fa,bool tag){
//	vis[u] |= tag;
//	siz[u] = 1;
//	memset(f[u],0,sizeof(f[u]));//多根数据清空
//	f[u][0] = g[u] = 1;//不选 / 选
//	for(int i = head[u];i;i = e[i].nxt){
//		const int v = e[i].to;
//		if(v == fa || est[v])continue;
//		DP(v,u,tag);
//		for(int j = siz[u];j >= 0;j--){
//			f[u][j + siz[v]] += (((f[u][j] * g[v]) % MOD) * C[j + siz[v]][siz[v]]) % MOD;//子树泉部选
////			cerr<<u<<" addall "<<j+siz[v]<<" which "<<f[u][j] * 1<<endl;
//			for(int k = siz[v];k > 0;k--){//不能不选k(==0),不然会算重
////				cerr<<u<<","<<j+k<<" add "<<f[u][j] * f[v][k] * C[j+k][k]<<" from "<<j<<" + "<<k<<endl;
//				f[u][j+k] += f[u][j] * f[v][k] * C[j+k][k];//有序,需要插入选择 * C[j+k][k]
//			}
//		}
//		g[u] = (((g[u] * g[v]) % MOD) * C[siz[u] + siz[v] - 1][siz[v]]) % MOD;//-1 是因为u点肯定最后选
//		siz[u] += siz[v];
//	}
//	return ;
//}
//inline void Calc(int root,bool tag){//tag 是否要打标记
//	DP(root,root,tag);
//	for(int i = 0;i <= siz[root];i++){
//		cerr<<root<<","<<i<<" f "<<f[root][i]<<endl;
//	}
//	cerr<<root<<" g "<<g[root]<<endl;
//	memset(nxtans,0,sizeof(nxtans));
//	for(int i = n;i >= 0;i--){
//		for(int j = siz[root];j >= 0;j--){//不能算上什么都不选的情况?
//			if(i+j <= n){
//				nxtans[i+j] += (((ans[i] * f[root][j]) % MOD) * C[i+j][i]) % MOD;
//			}
//		}
//		if(i + siz[root] <= n)nxtans[i + siz[root]] += (((ans[i] * g[root]) % MOD) * C[i+siz[root]][i]) % MOD;
//	}
//	memcpy(ans,nxtans,sizeof(ans));
//	cerr<<root<<","<<siz[root]<<" g "<<g[root]<<endl;
//	return ;
//}
//inline void Solve(){
//	memset(vis,0,sizeof(vis));
//	ans[0] = 1;
//	for(int u = 1;u <= n;u++){//先找和边双相连的子树,根已确定
//		if(!est[u])continue;
//		for(int i = head[u];i;i = e[i].nxt){
//			const int v = e[i].to;
//			if(est[v])continue;
//			Calc(v,true);
//		}
//	}
//	for(int u = 1;u <= n;u++){//然后尝试从度数大于1的点中选一个,作为独立子树的根
//		if(!vis[u] && !est[u]){
//			Calc(u,false);
//		}
//	}
//	for(int i = 0;i <= n;i++){
//		if(i != n){
////			ans[i] /= (n-i);
//		}
//		cout<<ans[i]<<endl;
//	}
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("CF512D.in","r",stdin);
//	ReadIn();
//	Pre();
//	FindCircle();
//	Solve();
//	return not(Akano loves pure__Elysia);
//}
