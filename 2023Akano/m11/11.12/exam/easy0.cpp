#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 22;
constexpr int MAXS = (1<<20) + 1018 + 1108;
struct Edge{
	int nxt,to,id;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int id){
	e[++cnt].to = to;
	e[cnt].id = id;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int dfs(int u,int fa,int nows,bool val){
	int ret = val;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		bool eval = (1<<e[i].id) & nows;
		ret += dfs(v,u,nows,val ^ eval);
	}
	return ret;
}
int n,maxs,ansstat,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("easy/easy2.in","r",stdin);
	freopen("easy.txt","w",stdout);
	cin>>n;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v,i-1),AddEdge(v,u,i-1);
	}
	maxs = (1<<(n-1)) - 1;
	for(int stat = 0;stat <= maxs;stat++){
		int nowans = 0;
		for(int root = 1;root <= n;root++){
			nowans += dfs(root,root,stat,false);
		}
		nowans /= 2;
		if(nowans > ans){
			ans = nowans,ansstat = stat;
		}
	}
	cout<<ans<<endl;
	for(int stat = 0;stat <= maxs;stat++){
		int nowans = 0;
		for(int root = 1;root <= n;root++){
			nowans += dfs(root,root,stat,false);
		}
		nowans /= 2;
		if(nowans == ans){
			for(int i = 0;i < n-1;i++){
				cout<<bool(stat & (1<<i))<<" ";
			}
			cout<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
