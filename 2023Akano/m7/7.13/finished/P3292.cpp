#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e4 + 6;
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
struct LinearBasis{
	ll c[62];
	inline void Insert(ll val){
		for(int i = 60;i >= 0;i--){
			if(!val)break;
			if(!(val >> i))continue;
			if(!c[i]){
				c[i] = val;
				return ;
			}else{
				val ^= c[i];
			}
		}
		return ;
	}
	inline void Add(const LinearBasis& _in){
		for(int i = 60;i >= 0;i--){
			Insert(_in.c[i]);
		}
		return ;
	}
	inline ll GetAns(){
		ll ret = 0;
		for(int i = 60;i >= 0;i--){
			if((ret ^ c[i]) > ret)ret ^= c[i];
		}
		return ret;
	}
	LinearBasis(){memset(c,0,sizeof(c));}
}f[MAXN][16];
inline LinearBasis Merge(const LinearBasis& _a,const LinearBasis& _b){
	LinearBasis ret;
	for(int i = 60;i >= 0;i--){
		ret.Insert(_a.c[i]),ret.Insert(_b.c[i]);
	}
	return ret;
}
int n,q,fa[MAXN][16],dep[MAXN];
ll luck[MAXN];
void dfs(int u){
	dep[u] = dep[fa[u][0]] + 1;
	for(int i = 1;i <= 14;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
		f[u][i] = Merge(f[u][i-1],f[fa[u][i-1]][i-1]);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		fa[v][0] = u;
		f[v][0].Insert(luck[u]);
		dfs(v);
	}
	return ;
}
inline ll LCA(int x,int y){
	LinearBasis ret;
	ret.Insert(luck[x]),ret.Insert(luck[y]);
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = 14;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			ret.Add(f[x][i]);
			x = fa[x][i];
		}
	}
	if(x == y)return ret.GetAns();
	for(int i = 14;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			ret.Add(f[x][i]),ret.Add(f[y][i]);
			x = fa[x][i],y = fa[y][i];
		}
	}
	ret.Add(f[x][0]),ret.Add(f[y][0]);
	return ret.GetAns();
}
inline ll Read(){//no f
	ll ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int otp[666];
void Write(ll x){
	int tp = 0;
	while(x){
		otp[++tp] = x % 10;
		x /= 10;
	}
	while(tp)putchar(otp[tp--]+'0');
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P3292.in","r",stdin);
	freopen("P3292.out","w",stdout);
	n = Read(),q = Read();
	for(int i = 1;i <= n;i++){
		luck[i] = Read();
	}
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read();
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1);
	while(q--){
		int x = Read(),y = Read();
		Write(LCA(x,y)),putchar('\n');
	}
	return 0;
}

