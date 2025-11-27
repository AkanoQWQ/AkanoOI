#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 400006;
const ll INF = 11451419;
vector<ll> e[MAXN];
ll n,w[MAXN],q,fa[MAXN],dep[MAXN],size[MAXN],son[MAXN],cnt,dfn[MAXN],top[MAXN],org[MAXN];
long long sum[MAXN*4],b[MAXN * 4],r,MOD;
void dfs1(ll p,ll father){
	fa[p] = father,dep[p] = dep[father] + 1,size[p] = 1;
	for(ll i = 0;i < e[p].size();i++){
		const ll v = e[p][i];
		if(v == fa[p])continue;
		dfs1(v,p);
		size[p] += size[v];
		if(size[v] > size[son[p]]){
			son[p] = v;
		}
	}
	cout<<p<<" size "<<size[p]<<endl;
	return ;
}
void dfs2(ll p,ll tp){
	dfn[p] = ++cnt,top[p] = tp,org[cnt] = p;
	if(son[p])dfs2(son[p],tp);
	for(ll i = 0;i < e[p].size();i++){
		const ll v = e[p][i];
		if(v == fa[p] || v == son[p])continue;
		dfs2(v,v);
	}
	return ;
}
void push_up(ll p){
	sum[p] = (1ll* sum[p*2] + sum[p*2+1]) % MOD;
	return ;
}
void push_down(ll p,ll l,ll mid,ll r){
	if(b[p]){
		sum[p*2] = (sum[p*2] + 1ll * (mid - l + 1) * b[p])% MOD;
		sum[p*2+1] = (sum[p*2+1] + 1ll * (r - mid) * b[p]);
		b[p*2] += b[p],b[p*2+1] += b[p];
		b[p*2] %= MOD,b[p*2+1] %= MOD;
		b[p] = 0; 
	}
	return ;
}
void Build(ll l,ll r,ll p){
	if(l == r){
		sum[p] = w[org[l]] % MOD;
		return ;
	}
	ll mid = (l + r) >> 1;
	Build(l,mid,p*2);
	Build(mid+1,r,p*2+1);
	push_up(p);
	return ;
}
void Update(ll l,ll r,ll objl,ll objr,ll p,ll v){
	if(objl <= l && r <= objr){
		sum[p] += 1ll * (r - l + 1) * v;
		sum[p] %= MOD;
		b[p] += v;
		b[p] %= MOD;
		return ;
	}
	ll mid = (l + r) >> 1;
	if(l != r)push_down(p,l,mid,r);
	if(mid >= objl)Update(l,mid,objl,objr,p*2,v);
	if(mid < objr)Update(mid+1,r,objl,objr,p*2+1,v);
	push_up(p);
	return ; 
}
ll Qsum(ll l,ll r,ll objl,ll objr,ll p){
	if(objl <= l && r <= objr){
		return sum[p]; 
	}
	ll mid = (l + r) >> 1;
	long long cnt = 0;
	if(l != r)push_down(p,l,mid,r);
	if(mid >= objl)cnt = Qsum(l,mid,objl,objr,p*2);
	if(mid < objr)cnt += Qsum(mid+1,r,objl,objr,p*2+1);
	cnt %= MOD;
	return cnt;
}
ll QS(ll x,ll y){
	long long ret = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]])swap(x,y);
		ret += 1ll* Qsum(1,n,dfn[top[x]],dfn[x],1);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	ret += 1ll* Qsum(1,n,dfn[x],dfn[y],1);
	ret %= MOD;
	return ret;
}
void QU(ll x,ll y,ll z){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]])swap(x,y);
		Update(1,n,dfn[top[x]],dfn[x],1,z);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	Update(1,n,dfn[x],dfn[y],1,z);
	return ;
}
signed main(){//1185
	scanf("%lld%lld%lld%lld",&n,&q,&r,&MOD);
	for(ll i = 1;i <= n;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i = 1;i < n;i++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs1(r,0);
	dfs2(r,r);
	Build(1,n,1);
	for(int i = 1;i <= n;i++){
		cout<<dfn[i]<<" "; 
	}
	cout<<endl;
	while(q--){
		ll s,u,v,y,z;
		//cout<<"START"<<endl;
		//for(int i = 1;i <= n;i++){
		//	cout<<i<<":"<<Qsum(1,n,dfn[i],dfn[i],1)<<endl;
		//}
		scanf("%lld%lld",&s,&u);
		if(s == 1){
			scanf("%lld%lld",&v,&z);
			QU(u,v,z);
			//Update(1,n,dfn[u],dfn[v],1,z);
		}else if(s == 2){
			scanf("%lld",&v);
			printf("%lld\n",QS(u,v));
		}else if(s == 3){
			scanf("%lld",&z);
			Update(1,n,dfn[u],dfn[u]+size[u]-1,1,z);
		}else{
			printf("%lld\n",Qsum(1,n,dfn[u],dfn[u]+size[u]-1,1));
		}
		//for(int i = 1;i <= n;i++){
		//	cout<<i<<":"<<Qsum(1,n,dfn[i],dfn[i],1)<<endl;
		//}
	}
	return 0;
}
