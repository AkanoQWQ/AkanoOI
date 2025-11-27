#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N=3e5+5;
struct BIT{
	int s[N];
	void add(int d,int nw){
		while(d<N){
			s[d]+=nw;
			d+=d&-d;
		}
	}
	int query(int d){
		int res=0;
		while(d){
			res+=s[d];
			d-=d&-d;
		}
		return res;
	}
	int rgsum(int l,int r){
		return query(r)-query(l-1);
	}
}T0,T1;
int n,m;
vi G[N];
pi Path[N];
void Input(){
	cin>>n>>m;
	rep(i,1,n-1){
		int u,v;cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	rep(i,1,m){
		cin>>Path[i].fi>>Path[i].se;
	}
}
int fa[N],dep[N],sz[N],dfn[N],id[N],dfc;
void dfs0(int u){
	dfc++,dfn[u]=dfc,id[dfc]=u;
	dep[u]=dep[fa[u]]+1;
	for(int v:G[u]){
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		dfs0(v);
	}
	sz[u]=dfc-dfn[u]+1;
}
int mn[N][19];
void Init(){
	dfs0(1);
	rep(i,1,n){
		mn[i][0]=id[i];
	}
	rep(j,1,18){
		rep(i,1,n-(1<<j)+1){
			int A=mn[i][j-1],B=mn[i+(1<<(j-1))][j-1];
			mn[i][j]=(dep[A]<dep[B]?A:B);
		}
	}
}
int LCA(int u,int v){
	if(u==v){
		return u;
	}
	if( (u=dfn[u])>(v=dfn[v]) ){
		swap(u,v);
	}
	int lg=__lg(v-(u++)),A=mn[u][lg],B=mn[v-(1<<lg)+1][lg];
	return fa[ dep[A]<dep[B]?A:B ];
}
vi LCAp[N];

int f[N],g[N][2],w[N];
int sum[N];
void dp(int u){
	for(int v:G[u]){
		if(v==fa[u]){
			continue;
		}
		dp(v);
		sum[u]+=f[v];
	}
	g[u][0]=sum[u];
	for(int id:LCAp[u]){
		w[id]=sum[u]+(T0.query(dfn[ Path[id].fi ])+T0.query(dfn[ Path[id].se ])-T0.query(dfn[u])*2)+1;
		g[u][1]=max(g[u][1],w[id]);
	}
	f[u]=max(g[u][0],g[u][1]);
	T0.add(dfn[u],sum[u]-f[u]);
	T0.add(dfn[u]+sz[u],-(sum[u]-f[u]));
}
bool c0[N],c1[N];
void dfs1(int u){
	if(!c0[u] && T1.rgsum(dfn[u],dfn[u]+sz[u]-1) < T1.rgsum(dfn[fa[u]],dfn[fa[u]]+sz[fa[u]]-1) ){// 上面存在一条可选边 使得选了它之后当前点不被选择 
		c0[u]=1;
	}
	if(c0[u]){
		if(g[u][0]==f[u]){
			c1[u]=1;
			for(int v:G[u]){
				if(v==fa[u]){
					continue;
				}
				c0[v]=1;
			}
		}
		if(g[u][1]==f[u]){
			for(int id:LCAp[u]){
				if(w[id]==f[u]){
					T1.add(dfn[ Path[id].fi ],1);
					T1.add(dfn[ Path[id].se ],1);
					T1.add(dfn[u],-1);
					if(fa[u]){
						T1.add(dfn[fa[u]],-1);
					}
				}
			}
		}
	}
	for(int v:G[u]){
		if(v==fa[u]){
			continue;
		}
		dfs1(v);
	}
}
long long ans;
int Getans(int u){
	int cur=1;
	for(int v:G[u]){
		if(v==fa[u]){
			continue;
		}
		cur+=Getans(v);
	}
	if(!c1[u]){
		return 0;
	}
	if(!c1[fa[u]]){
		ans+=(long long)cur*cur;
		return 0;
	}
	return cur;
}
void solve(){
	Init();
	rep(i,1,m){
		LCAp[ LCA(Path[i].fi,Path[i].se) ].pb(i);
	}
	dp(1);
	c0[1]=1;
	dfs1(1);
	Getans(1);
	cout<<ans<<endl;
}
signed main(){
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Input();
	solve();
	return 0;
}
