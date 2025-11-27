#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int MOD = 998244353;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
};
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
ll n,maxdepth,value[MAXN],depth[MAXN],factorial[MAXN],factorialInverse[MAXN],contribute[MAXN],father[MAXN];
inline void ReadIn(){
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++)cin>>value[i];
	return ;
}
void GetDepth(int u,int fa){
	depth[u] = depth[fa] + 1;
	father[u] = fa;
	maxdepth = max(maxdepth,depth[u]);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetDepth(v,u);
	}
	return ;
}
inline ll C(ll n,ll m){
	if(n < m)return 0;
	ll ret = (factorial[n] * factorialInverse[n-m]) % MOD;
	ret = (ret * factorialInverse[m]) % MOD;
	return ret;
}
inline void Prepare(){
	GetDepth(1,0);
	factorial[0] = factorialInverse[0] = 1;
	for(int i = 1;i <= n;i++){
		factorial[i] = (factorial[i-1] * i) % MOD;
		factorialInverse[i] = KSM(factorial[i],MOD-2);
	}
	for(int len = 1;len <= maxdepth;len++){
		for(int subLen = 1;subLen <= len;subLen++){//枚举长度为subLen的子序列
			//len-1里选出subLen-1个元素作为子序列内容,特别地第一个要选1
			//放在序列里的subLen个位置中,贡献 C_len_subLen
			//剩下 len-subLen 个元素随便选,有阶乘个
			ll delta = (C(len-1,subLen-1) * C(len,subLen)) % MOD;
			delta = (delta * factorial[len - subLen]) % MOD;
			contribute[len] = (contribute[len] + delta) % MOD;
		}
	}
	return ;
}
ll Solve(){
	ll ret = 0;
	for(int i = 1;i <= n;i++){
		ret = (ret + value[i] * factorial[n]) % MOD;//每个元素自己会出现一次,一共n!种情况
	}
	for(int i = 1;i <= n;i++){
		for(int dis = 1,now = i;now != 0;dis++,now = father[now]){
			ll delta = (contribute[dis] * C(n,dis)) % MOD;
			delta = (delta * factorial[n-dis]) % MOD;
			delta = (delta * value[now]) % MOD;
			ret = (ret + delta) % MOD;
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Prepare();
	cout<<Solve()<<endl;
	return not(Akano loves pure__Elysia);
}
