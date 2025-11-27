#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 306;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
int ans[MAXN],f[MAXN][MAXN],score[MAXN];
vector<int> roots;
void dfs(int u,int fa){
	f[u][1] = score[u];
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		dfs(v,u);
		for(int i = m;i >= 0;i--){
			for(int j = 0;j < i;j++){
				f[u][i] = max(f[u][i],f[u][i-j] + f[v][j]);
			}
		}
	}
	if(u == fa){
		for(int i = m;i >= 0;i--){
			for(int j = 0;j <= i;j++){
				ans[i] = max(ans[i],ans[i-j] + f[u][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		int fa;
		cin>>fa>>score[i];
		if(fa == 0){
			roots.push_back(i);
		}else{
			AddEdge(fa,i);
		}
	}
	for(auto root : roots){
		dfs(root,root);
	}
	int main_ans = 0;
	for(int i = 0;i <= m;i++)main_ans = max(main_ans,ans[i]);
	cout<<main_ans<<endl;
	return not(Akano loves pure__Elysia);
}
