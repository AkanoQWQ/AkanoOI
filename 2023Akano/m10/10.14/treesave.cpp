//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//const int TOT_MAXN = 2e5 + 1018 + 1108;
//struct Edge{
//	int nxt,to;
//}e[TOT_MAXN * 2];
//int head[TOT_MAXN],cnt;
//inline void AddEdge(int from,int to){
//	e[++cnt].to = to;
//	e[cnt].nxt = head[from];
//	head[from] = cnt;
//	return ;
//}
//bool black[TOT_MAXN];
//int T,n,t;
//namespace Subtask1{
//	const int MAXN = 1108;
//	int ans[MAXN],dis[MAXN];
//	bool vis[MAXN];
//	inline void BFS(int st){
//		int maxdis = 0;
//		vector<int> maxpoints;
//		queue<int> q;
//		memset(vis,0,sizeof(vis));
//		dis[st] = 0,vis[st] = true,q.push(st);
//		while(!q.empty()){
//			const int u = q.front();
//			q.pop();
//			for(int i = head[u];i;i = e[i].nxt){
//				const int v = e[i].to;
//				if(vis[v])continue;
//				vis[v] = true,dis[v] = dis[u] + 1,q.push(v);
//				if(black[v] && dis[v] > maxdis){
//					maxdis = dis[v],maxpoints.clear();
//					maxpoints.push_back(v);
//				}else if(black[v] && dis[v] == maxdis){
//					maxpoints.push_back(v);
//				}
//			}
//		}
//		for(auto i : maxpoints)ans[i]++;
//		return ;
//	}
//	inline int Solve(){
//		for(int i = 1;i <= n;i++){
//			ans[i] = 0;
//		}
//		for(int i = 1;i <= n;i++){
//			if(!black[i])BFS(i);
//		}
//		int ret = 0;
//		for(int i = 1;i <= n;i++){
//			ret = max(ret,ans[i]);
//		}
//		return ret;
//	}
//}
//namespace Subtask2{
//	const int MAXN = TOT_MAXN;
//	int root,fa[MAXN],dep[MAXN],maxdep[3];//maxdep记录的是深度,depset记录的是点集
//	vector<int> depset[MAXN];
//	int belong[MAXN];
//	bool imp[MAXN];//important
//	bool dfs(int u){
//		dep[u] = dep[fa[u]] + 1;
//		bool ret = black[u];
//		if(ret){
//			imp[u] = true;
//		}else{
//			imp[u] = false;
//		}
//		for(int i = head[u];i;i = e[i].nxt){
//			const int v = e[i].to;
//			if(v == fa[u])continue;
//			fa[v] = u;
//			bool res = dfs(v);
//			if(res){
//				ret = true;
//				imp[u] = false;
//			}
//		}
//		if(imp[u]){
//			if(dep[u] > maxdep[1]){
//				maxdep[2] = maxdep[1];
//				swap(depset[1],depset[2]);
//				depset[1].clear();
//				maxdep[1] = dep[u];
//				depset[1].push_back(u);
//			}else if(dep[u] == maxdep[1]){
//				depset[1].push_back(u);
//			}else if(dep[u] > maxdep[2]){
//				depset[2].clear();
//				maxdep[2] = dep[u];
//				depset[2].push_back(u);
//			}else if(dep[u] == maxdep[2]){
//				depset[2].push_back(u);
//			}
//		}
//		return ret;
//	}
//	void GetBelong(int u,int kol){
//		if(u == root)return ;
//		belong[u] = kol;
//		if(u != kol)assert(black[u] == false);//TEST ONLY!!!!!!!!!!!!!
//		for(int i = head[u];i;i = e[i].nxt){
//			const int v = e[i].to;
//			if(v == fa[u])continue;
//			GetBelong(v,kol);
//		}
//		return ;
//	}
//	inline int Solve(){
//		int ret = 0;
//		int blackCnt = 0;
//		for(int i = 1;i <= n;i++)blackCnt += black[i];
//		if(blackCnt == 1)return n-1;//剩下的都选
//		root = -1;
//		for(int i = n;i >= 1;i--){
//			if(black[i] == 0)root = i;
//		}
//		if(root == -1)return 0;
//		fa[root] = dep[root] = 0;
//		maxdep[1] = maxdep[2] = 0;
//		depset[1].clear(),depset[2].clear();
//		dfs(root);
//		memset(belong,0,sizeof(belong));
//		for(int i = 1;i <= n;i++){
//			if(imp[i]){
//				GetBelong(i,i);
//				GetBelong(fa[i],i);
//			}
//		}
//		for(int i = 1;i <= n;i++){
//			if(black[i])continue;
//			if(belong[i] == 0){//上方节点
//				
//			}
//		}
//		return ret;
//	}
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("tree/tree2.in","r",stdin);
//	freopen("tree2.out","w",stdout);
//	cin>>T;
//	while(T--){
//		cin>>n>>t;
//		for(int i = 1;i <= n;i++)head[i] = 0;
//		cnt = 0;
//		for(int i = 1;i < t;i++){
//			AddEdge(i,i+1),AddEdge(i+1,i);
//		}
//		if(t != 1)AddEdge(t,1),AddEdge(1,t);
//		for(int i = t+1;i <= n;i++){
//			int fa;
//			cin>>fa;
//			AddEdge(fa,i),AddEdge(i,fa);
//		}
//		for(int i = 1;i <= n;i++)cin>>black[i];
//		if(n <= 1018){
//			cout<<Subtask1::Solve()<<endl;
//		}else if(t == 1){
//			cout<<Subtask2::Solve()<<endl;
//		}
//	}
//	return not(Akano loves pure__Elysia);
//}
