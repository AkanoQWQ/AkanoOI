#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const int MOD = 998244353;
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
ll f[MAXN][3],n,sons[MAXN],faeval[MAXN],pre01[MAXN],suf02[MAXN];
void dfs(int u,int fa,int eval){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u,e[i].id);
	}
	int sonTail = 0,maxd = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		sons[++sonTail] = v;
		faeval[sonTail] = e[i].id;
	}
	reverse(sons+1,sons+sonTail+1);
	reverse(faeval+1,faeval+sonTail+1);
	for(int i = 1;i <= sonTail;i++){
		if(faeval[i] < eval)maxd = i;
		assert(faeval[i] > faeval[i-1]);
	}
	pre01[0] = suf02[sonTail + 1] = 1;
	for(int i = 1;i <= sonTail;i++){
		pre01[i] = (pre01[i-1] * (f[sons[i]][0] + f[sons[i]][1])) % MOD;
	}
	for(int i = sonTail;i >= 1;i--){
		suf02[i] = (suf02[i+1] * (f[sons[i]][0] + f[sons[i]][2])) % MOD;
	}
	for(int i = 1;i <= maxd;i++){
		f[u][0] += ((pre01[i-1] * f[sons[i]][2]) % MOD) * suf02[i+1];
		f[u][0] %= MOD;
	}
	f[u][1] = (pre01[maxd] * suf02[maxd+1]) % MOD;
	for(int i = maxd + 1;i <= sonTail;i++){
		f[u][2] += ((pre01[i-1] * f[sons[i]][2]) % MOD) * suf02[i+1];
		f[u][2] %= MOD;
	}
	f[u][2] = (f[u][2] + pre01[sonTail]) % MOD;//???
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(v,u,i),AddEdge(u,v,i);
	}
	dfs(1,0,n+1);
	cout<<(f[1][0] + f[1][1]) % MOD<<endl;
	return not(Akano loves pure__Elysia);
}
