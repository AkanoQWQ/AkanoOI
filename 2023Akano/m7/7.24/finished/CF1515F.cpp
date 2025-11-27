#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
const int MAXM = 6e5 + 1018 + 1108;
struct Edge{
	int nxt,to,id;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int id){
	e[++cnt].to = to;
	e[cnt].id = id;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
ll n,m,x,a[MAXN],arr[MAXN];
int heada = 0,tail;
ll sum;
bool vis[MAXN];
void dfs(int u){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		dfs(v);
		if(a[u] + a[v] >= x){
			arr[++heada] = e[i].id;
			a[u] = a[u] + a[v] - x;
		}else{
			arr[--tail] = e[i].id;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>x;
	tail = n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum += a[i];
	}
	if(sum < 1ll * x * (n-1)){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v,i),AddEdge(v,u,i);
	}
	dfs(1);
	for(int i = 1;i <= n-1;i++){
		cout<<arr[i]<<endl;
	}
	cout<<endl;
	return 0;
}
