#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const ll INF = 1e16 + 10181108;
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
int n,a[MAXN],b[MAXN];
ll f[MAXN][2],g[2][MAXN];//0向下1向上
bool CmpByDelta(int x,int y){
	return (f[x][1] - f[x][0] < f[y][1] - f[y][0]);
}
void dfs(int u,int fa){
	vector<int> son;
	int is0 = 0,is1 = 0;//默认泉部选0
	ll tot = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		if(b[u] > b[v]){//只能选0
			is0++;
			tot += f[v][0];
		}else if(b[u] < b[v]){
			is1++;
			tot += f[v][1];
		}else{
			son.push_back(v);
			is0++,tot += f[v][0];
		}
		
	}
	sort(son.begin(),son.end(),CmpByDelta);
	f[u][0] = f[u][1] = INF;
	for(auto i : son){
		f[u][0] = min(f[u][0],tot + 1ll * max(is0,is1 + (u != 1)) * a[u]);
		f[u][1] = min(f[u][1],tot + 1ll * max(is0 + (u != 1),is1) * a[u]);
		is0--,is1++;
		tot += f[i][1] - f[i][0];
	}
	f[u][0] = min(f[u][0],tot + 1ll * max(is0,is1 + (u != 1)) * a[u]);
	f[u][1] = min(f[u][1],tot + 1ll * max(is0 + (u != 1),is1) * a[u]);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++)cin>>b[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,1);
	cout<<min(f[1][0],f[1][1])<<endl;
	return not(Akano loves pure__Elysia);
}
