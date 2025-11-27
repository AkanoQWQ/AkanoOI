#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018 + 1108;
const int MAXM = MAXN * 2;
const int MOD = 19260817;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,k,a[MAXN],mn,mx;
ll f[MAXN][2],now;
void DP(int u,int fa){
	f[u][0] = (a[u] != mx),f[u][1] = (a[u] == mx);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || a[v] > mx || a[v] < mn)continue;
		if(v < now && a[v] == mn)continue;
		DP(v,u);	
		f[u][1] += (f[u][1] * f[v][0] + f[u][0] * f[v][1] + f[u][1] * f[v][1]) % MOD;
		f[u][0] += (f[u][0] * f[v][0]) % MOD;
	}
	return ;
}
inline ll Solve(){
	ll ret = 0;
	for(int i = 1;i <= n;i++){
		now = i;
		mn = a[i],mx = mn + k;
		DP(i,i);
		ret = (ret + f[i][1]) % MOD;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("lkf.in","r",stdin);
//	freopen("lkf.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u); bn 
	}
	cout<<Solve()<<endl;
	return 0;
}

