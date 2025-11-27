#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 3e5 + 6;
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
int n,val[MAXN],sz[MAXN];
ll ans[MAXN],delta[MAXN],tot[MAXN],mainans = LLONG_MAX;
bool cmp(pll _a,pll _b){
	return _a.second * _b.first <  _a.first * _b.second;
}
vector<pll> vec[MAXN],sum[MAXN];
inline void Calc(int u){
	delta[u] = 0;
	sum[u].reserve(vec[u].size());
	int nowsize = 1;
	long long presum = 0;
	for(auto i : vec[u]){
		presum += i.first;
		delta[u] += i.first * nowsize;
		sum[u].push_back(make_pair(presum,nowsize));
		nowsize += i.second;
	}
	return ;
}
ll insertv[MAXN][2],banv[MAXN][2];
void dfs(int u,int fa){
	sz[u] = 1,tot[u] = val[u],ans[u] = val[u];
	int son = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		sz[u] += sz[v],tot[u] += tot[v],ans[u] += ans[v];
		vec[u].push_back(make_pair(tot[v],sz[v]));
	}
	sort(vec[u].begin(),vec[u].end(),cmp);
	Calc(u);
	ans[u] += delta[u];
	return ;
}
inline void MoveRoot(int u,int v){
	ans[u] -= delta[u] + ans[v];
	banv[u][0] = tot[v],banv[u][1] = sz[v];
	Calc(u);
	
	ans[u] += delta[u];
	sz[u] -= sz[v];
	tot[u] -= tot[v];
	ans[v] += ans[u];
	ans[v] -= delta[v];
	insertv[v][0] = tot[u],insertv[v][1] = sz[u];
	CalcMain(v);
	ans[v] += delta[v];
	sz[v] += sz[u];
	tot[v] += tot[u];
	return ;
}
inline vector<ll> Save(int u){
	vector<ll> ret(8);
	ret[0] = ans[u];
	ret[1] = sz[u];
	ret[2] = tot[u];
	ret[3] = insertv[u][0];
	ret[4] = insertv[u][1];
	ret[5] = banv[u][0];
	ret[6] = banv[u][1];
	ret[7] = delta[u];
	return ret;
}
inline void Load(int u,const vector<ll>& sv){
	ans[u] = sv[0];
	sz[u] = sv[1];
	tot[u] = sv[2];
	insertv[u][0] = sv[3];
	insertv[u][1] = sv[4];
	banv[u][0] = sv[5];
	banv[u][1] = sv[6];
	delta[u] = sv[7];
	return ;
}
inline void Print(int u){
	cout<<"ans:"<<ans[u]<<endl;
	cout<<"tot:"<<tot[u]<<endl;
	cout<<"sz:"<<sz[u]<<endl;
	if(insertv[u][0] != 0)cout<<"INSERT "<<insertv[u][0]<<","<<insertv[u][1]<<endl;
	if(banv[u][0] != 0)cout<<"BAN "<<banv[u][0]<<","<<banv[u][1]<<endl;
	cout<<"--------------------"<<endl;
	return ;
} 
void ChangeRoot(int u,int fa){
	Print(u);
	mainans = min(mainans,ans[u]);
	vector<ll> saveu = Save(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		vector<ll> savev = Save(v);
		MoveRoot(u,v);
		ChangeRoot(v,u);
		Load(u,saveu),Load(v,savev);
	}
	return ;
}
inline ll Read(){
	ll ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int otp[166];
inline void Write(ll x){
	int tp = 0;
	while(x)otp[++tp] = x % 10,x /= 10;
	while(tp)putchar(otp[tp--] + '0');
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B6304.in","r",stdin);
	n = Read();
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read();
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++)val[i] = Read();
	dfs(1,1);
	ChangeRoot(1,1);
	Write(mainans);
	return 0;
}
