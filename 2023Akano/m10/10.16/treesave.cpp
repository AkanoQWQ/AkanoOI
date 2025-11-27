#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 14;
const int MAXS = (1<<13) + 1018;
const int MOD = 1e9 + 7;
ll tid,T,n,l[MAXN],r[MAXN],child,root,fa[MAXN];
ll f[MAXN][MAXS];
inline bool ISFA(ll u,ll v){//v是否是u的父亲
	while(u){
		if(u == v)return true;
		u = fa[u];
	}
	return false;
}
ll dfs(int u,int used){
	if(child >= n)return 0;
	if(u > n){
		return (child == n-1);
	}
	if(f[u][used] != -1)return f[u][used];
	ll ret = 0;
	if(l[u] <= 0 && 0 <= r[u]){
		ret += dfs(u+1,used);
		ret %= MOD;
	}
	if(l[u] <= 1 && 1 <= r[u]){
		child++;
		for(int i = u+1;i <= n;i++){
			if((1<<(i-1) & used) || ISFA(u,i))continue;
			fa[i] = u;
			ret += dfs(u+1,used + (1<<(i-1))) * 2;
			fa[i] = 0;
			ret %= MOD;
		}
		child--;
	}
	if(l[u] <= 2 && 2 <= r[u]){
		child += 2;
		for(int i = u+1;i <= n;i++){
			if((1<<(i-1) & used) || u == i || ISFA(u,i))continue;
			int now = used + (1<<(i-1));
			fa[i] = u;
			for(int j = 1;j < i;j++){
				if((1<<(j-1) & now) || u == j || ISFA(u,j))continue;
				fa[j] = u;
				ret += dfs(u+1,now + (1<<(j-1))) * 2;
				ret %= MOD;
				fa[j] = 0;
			}
			fa[i] = 0;
		}
		child -= 2;
	}
	ret %= MOD;
	f[u][used] = ret;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>tid>>T;
	while(T--){
		cin>>n;
		memset(f,-1,sizeof(f));
		if(n > 13){
			for(int i = 1;i <= n;i++){
				cin>>l[0]>>r[0];
			}
			cout<<"aK4n0不知道哦"<<endl;
			continue;
		}
		for(int i = 1;i <= n;i++){
			cin>>l[i]>>r[i];
		}
		cout<<dfs(1,0) % MOD<<endl;
	}
	return not(Akano loves pure__Elysia);
}
