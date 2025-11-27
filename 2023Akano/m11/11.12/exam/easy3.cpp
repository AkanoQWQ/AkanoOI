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
bool neede[MAXN],anse[MAXN];
int dfs(int u,int fa,bool val){
	int ret = val;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		bool eval = neede[e[i].id];
		ret += dfs(v,u,val ^ eval);
	}
	return ret;
}
int n,maxs,ans;
void STATdfs(int u){
	if(u >= n){
		int nowans = 0;
		for(int root = 1;root <= n;root++){
			nowans += dfs(root,root,false);
		}
		nowans /= 2;
		if(nowans > ans){
			cerr<<nowans<<" update "<<ans<<endl;
			ans = nowans;
			memcpy(anse,neede,sizeof(anse));
		}
		for(int i = 1;i < n;i++){
			cerr<<neede[i]<<" ";
		}
		cerr<<"is : "<<nowans<<endl;
		return ;
	}
	neede[u] = true;
	STATdfs(u+1);
	neede[u] = false;
	STATdfs(u+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("easy/easy3.in","r",stdin);
	cin>>n;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v,i),AddEdge(v,u,i);
	}
	STATdfs(1);
	cout<<ans<<endl;
	for(int i = 1;i < n;i++){
		cout<<anse[i]<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
