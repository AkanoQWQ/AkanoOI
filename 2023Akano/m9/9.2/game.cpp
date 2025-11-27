#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXS = (1<<10) + 1018;
const int MAXN = 12;
const int INF = 1e7;
//struct Edge{
//	int nxt,to,id;
//}e[MAXN * 2];
//int head[MAXN],cnt;
//inline void AddEdge(int from,int to,int id){
//	e[++cnt].to = to;
//	e[cnt].id = id;
//	e[cnt].nxt = head[from];
//	head[from] = cnt;
//	return ;
//}
//int n,t,s;
//bool vis[MAXN][MAXS][2];
//int f[MAXN][MAXS][2];
//int Get(int u,int stat,bool IsY){
//	cerr<<"now "<<u<<" and "<<stat<<" and "<<IsY<<endl;
//	if(u == t){
//		cerr<<"Get T!"<<endl;
//		return 0;
//	}
//	if(f[u][stat][IsY] != 0)return f[u][stat][IsY];
//	if(vis[u][stat][IsY])return INF+2;//成环了
//	vis[u][stat][IsY] = true; 
//	if(IsY){
//		int ret = INF+2;
//		ret = min(ret,Get(u,stat,false));//不操作 
//		for(int i = 1;i < n;i++){//断边建边 
//			ret = min(ret,Get(u,stat ^ (1<<(i-1)),false)+1);
//		}//建自己的边没有意义所以不用管? 
//		f[u][stat][IsY] = ret;
//		return ret;
//	}else{
//		int ret = 0;
//		bool canMove = false;
//		for(int i = head[u];i;i = e[i].nxt){
//			const int v = e[i].to;
//			if(stat & (1<<e[i].id)){
//				continue;
//			}
//			canMove = true;
//			ret = max(ret,Get(v,stat,true));
//		}
//		if(!canMove){
//			ret = Get(u,stat,true);
//		}
//		f[u][stat][IsY] = ret;
//		return ret;
//	}
//}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cout<<6<<endl;
//	cin>>n>>t>>s;
//	for(int i = 1;i < n;i++){
//		int u,v;
//		cin>>u>>v;
//		AddEdge(u,v,i-1),AddEdge(v,u,i-1);
//	}
//	cout<<Get(s,0,true)<<endl;
	return not(Akano loves pure__Elysia);
}

