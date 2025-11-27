#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006 + 1018 + 1108 + 1000;
using ll = long long;
const int INF = 1e6;
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
char ch;
bool imp[MAXN];
int n,k;
ll f[MAXN][2];
void dfs(int u,int fa){
	f[u][0] = 0,f[u][1] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		f[u][0] += min(f[v][0],f[v][1] + k);
		f[u][1] += min(f[v][0],f[v][1]);
	}
	if(imp[u])f[u][0] = INF;
	return ;
}
inline ll Solve(){
	dfs(1,1);
	return min(f[1][0],f[1][1] + k);
}
int arr[MAXN],tail,nowcnt[MAXN];
inline void Solve2(){
	ll nowans = 0;
	for(int i = 1;i <= n;i++){
		if(imp[i]){
			arr[++tail] = i;
			nowans++;
		}
	}
	for(int i = 2;i <= tail;i++){
		nowcnt[arr[i] - arr[i-1] - 1]++;
	}
	for(int i = 1;i <= n;i++){
		tail -= nowcnt[i];
		nowans += tail;
		cout<<nowans<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>ch;
		imp[i] = (ch == '1');
	}
	if(n > 5006){
		return 0;
		Solve2();
		return 0;
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(k = 1;k <= n;k++){
		cout<<Solve()<<'\n';
	}
	cout<<endl;
	return 0;
}

