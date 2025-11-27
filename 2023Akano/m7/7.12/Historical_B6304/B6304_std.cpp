#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 2e5 + 6;
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
int n;
ll ans[MAXN],delta[MAXN],tot[MAXN],mainans = LLONG_MAX,val[MAXN],sz[MAXN];
bool cmp(pll _a,pll _b){
	return _a.second * _b.first <  _a.first * _b.second;
}
vector<pll> vec[MAXN];
inline void CalcBanIns(int u,ll insertFirst,ll insertSecond,ll banFirst,ll banSecond){
	delta[u] = 0;
	int nowsize = 1;bool inserted = false,banned = false;
	if(insertFirst == 0)inserted = true;
	if(banFirst == 0)banned = true;
	for(auto i : vec[u]){
		if(!inserted && insertSecond * i.first <  insertFirst * i.second){
			inserted = true;
			delta[u] += insertFirst * nowsize;
			nowsize += insertSecond;
		}
		if(!banned && i.first == banFirst && i.second == banSecond){
			banned = true;
			continue;
		}
		delta[u] += i.first * nowsize;
		nowsize += i.second;
	}
	if(!inserted){
		delta[u] += insertFirst * nowsize;
		nowsize += insertSecond;
	}
	return ;
}
ll insertv[MAXN][2],banv[MAXN][2];
inline void CalcMain(int u){
	CalcBanIns(u,insertv[u][0],insertv[u][1],banv[u][0],banv[u][1]);
	return ;
}
void dfs(int u,int fa){
	sz[u] = 1,tot[u] = val[u],ans[u] = val[u],vec[u].clear();
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		sz[u] += sz[v],tot[u] += tot[v],ans[u] += ans[v];
		vec[u].push_back(make_pair(tot[v],sz[v]));
	}
	sort(vec[u].begin(),vec[u].end(),cmp);
	CalcBanIns(u,0,0,0,0);
	ans[u] += delta[u];
	return ;
}
inline void MoveRoot(int u,int v){
	ans[u] -= delta[u];
	ans[u] -= ans[v];
	banv[u][0] = tot[v],banv[u][1] = sz[v];
	CalcMain(u);
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
	vector<ll> ret;
	ret.reserve(7);
	ret.push_back(ans[u]);
	ret.push_back(sz[u]);
	ret.push_back(tot[u]);
	ret.push_back(insertv[u][0]);
	ret.push_back(insertv[u][1]);
	ret.push_back(banv[u][0]);
	ret.push_back(banv[u][1]);
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
	return ;
}
void ChangeRoot(int u,int fa){
	cout<<u<<" ans "<<ans[u]<<endl;
	mainans = min(mainans,ans[u]);
	vector<ll> saveu = Save(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		vector<ll> savev = Save(v);
		MoveRoot(u,v);
		ChangeRoot(v,u);
		Load(u,saveu),Load(v,savev);
		CalcMain(u),CalcMain(v);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B6304.in","r",stdin);
	freopen("B6304.ans","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++)cin>>val[i];
	dfs(1,1);
	ChangeRoot(1,1);
	cout<<mainans<<flush;
	return 0;
}
