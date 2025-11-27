#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXM = 2006 + 1018 + 1108;
const int MAXN = 1018;
const int MOD = 1e9 + 7;
struct Edge{
	int u,v,w,id;
	inline void Read(int _id){
		cin>>u>>v>>w;
		id = _id;
		return ;
	}
}e[MAXM];
bool Cmp(Edge e1,Edge e2){
	if(e1.w != e2.w)return e1.w < e2.w;
	return e1.id < e2.id;
}
ll n,m,x,a,b,c;
int fa[MAXN];
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
inline ll Krus(int imp){
	ll ret = 0;
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		if(e[i].id == imp){
			ret += e[i].w;
			fa[GetFa(e[i].u)] = fa[e[i].v];
		}
	}
	for(int i = 1;i <= m;i++){
		const int u = GetFa(e[i].u),v = GetFa(e[i].v);
		if(u != v){
			fa[u] = v;
			ret += e[i].w;
		}
	}
	return ret;
}
ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
ll ans = 1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>x;
	for(int i = 1;i <= m;i++)e[i].Read(i);
	sort(e+1,e+m+1,Cmp);
	for(int i = 1;i <= m;i++){
		ll res = Krus(i);
//		cout<<i<<" iS "<<res<<endl;
		if(res < x){
			a++;
		}else if(res == x){
			b++;
		}else{
			c++;
		}
	}
	if(b == 0){
		cout<<0<<endl;
		return 0;
	}
	if(a == 0){
		ans = (ans * (KSM(2,b)-2)) % MOD;
		ans = (ans * KSM(2,c)) % MOD;
	}else{
		ans = (2 * ans * (KSM(2,b)-1)) % MOD;
		ans = (ans * KSM(2,c)) % MOD;
	}
	cout<<ans<<endl;
	return 0;
}
