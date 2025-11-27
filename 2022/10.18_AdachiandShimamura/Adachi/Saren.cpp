#include<bits/stdc++.h>
using namespace std;
const int MAXN = 64;
const int MOD = 1000000007;
int st;
vector<int> e[MAXN];
struct pr{
	int a,b,c[66];
}p[66];
int dis[MAXN][MAXN],prtot;
void dfs(int u,int fa,int dep){
	dis[st][u] = dep;
	for(int i = 0;i < e[u].size();i++){
		const int v = e[u][i];
		if(v == fa)continue;
		dfs(v,u,dep+1);
	}
	return ;
}
int pth[66],cnt,nowp;
void dfs2(int u,int fa,int obj){
	pth[++cnt] = u;
	if(u == obj){
		for(int i = 1;i <= cnt;i++){
			p[nowp].c[i] = pth[i];
		}
		--cnt;
		return ;
	}
	for(int i = 0;i < e[u].size();i++){
		const int v = e[u][i];
		if(v == fa)continue;
		dfs2(v,u,obj);
	}
	--cnt;
}
int n,m,k,ans = 1,_k[1006];
int tk[66];
bool calc(){
	for(int i = 1;i <= prtot;i++){
		int pos = 2,maink = tk[p[i].c[1]];
		bool dif = 0;
		while(1){
			if(p[i].c[pos] == 0)break;
			if(tk[p[i].c[pos]] != maink){
				dif = 1;
				break;
			}
			pos++;
		}
		if(!dif)return false;
	}
	return true;
}
void dfs3(int dep){
	if(dep >= n+1){
		ans += calc();
		return ;
	}
	tk[dep] = 1;
	dfs3(dep+1);
	tk[dep] = 0;
	dfs3(dep+1);
	return ;
}
int main(){
	freopen("Saren.in","r",stdin);
	freopen("Saren.out","w",stdout);
	cin>>n>>m>>k;
	_k[0] = 1;
	for(int i = 1;i <= 1000;i++){
		_k[i] = (1ll * _k[i-1] * k) % MOD;
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n <= 15 && k == 2 && m != 1){
		ans--;
		while(m--){
			int a,b;
			cin>>a>>b;
			p[++prtot].a = a;
			p[prtot].b = b;
		}
		for(int i = 1;i <= prtot;i++){
			nowp = i;
			dfs2(p[i].a,114514,p[i].b);
		}
		dfs3(1);
		cout<<ans;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		st = i;
		dfs(i,114514,0);
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		ans = (1ll * ans * (_k[dis[a][b]] - k)) % MOD;
	}
	cout<<ans;
	return 0;
}
