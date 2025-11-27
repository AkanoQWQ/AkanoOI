#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int SPLIT = 20;
const int MAXN = 206;
const int MOD = 998244353;
const bool DEBUG_SUB2_ONLY = false;
bool have1[MAXN],have2[MAXN];
int n,m,c1,c2;
vector<int> e[MAXN];
namespace Subtask1{
	const int MAXSTAT = (1<<(SPLIT+1)) + 1018;
	ll f[MAXSTAT],nxt[MAXSTAT];
	inline ll Solve(){
		ll ret = 0;
		memset(f,0,sizeof(f));
		f[0] = 1;
		const int maxs = (1<<(c2 + 1)) - 1;
		for(int i = 1;i <= n;i++){
			for(int stat = maxs;stat >= 0;stat--){
				nxt[stat] = f[stat];
				if(stat & 1){
					f[stat] = 0;
					continue;
				}
				if(have1[i] && not((1<<c1) & stat)){
					nxt[stat + (1<<c1)] = (nxt[stat + (1<<c1)] + f[stat]) % MOD;
				}
				if(have2[i] && not((1<<c2) & stat)){
					nxt[stat + (1<<c2)] = (nxt[stat + (1<<c2)] + f[stat]) % MOD;
				}
				f[stat] = 0;
			}
			for(int stat = 0;stat <= maxs;stat++){
				f[stat >> 1] = (f[stat >> 1] + nxt[stat]) % MOD;
			}
		}
		for(int i = 0;i <= maxs;i++){
			ret = (ret + f[i]) % MOD;
		}
		return ret;
	}
}
namespace Subtask2{
	const int MAXSTAT = (1<<12) + 1018;
	using pii = pair<int,int>;
	ll f[MAXSTAT],g[MAXSTAT],x[MAXN],y[MAXN],dir[MAXN][MAXN],maxx,maxy;
	vector<pii> extraEdge;
	int vis[MAXN];
	inline ll Calc(){
		ll ret = 0;
		const int maxs = (1<<maxy) - 1;
		for(int i = 0;i <= maxs;i++){
			f[i] = 0;
		}
		f[0] = 1;
		for(int nowx = maxx;nowx >= 1;nowx--){
			for(int nowy = 1;nowy <= maxy;nowy++){
				const int u = dir[nowx][nowy];
				if(u == -1)continue;//直接continue,相当于继承
				for(int i = 0;i <= maxs;i++)g[i] = 0;
				for(int stat = 0;stat <= maxs;stat++){
					if(f[stat] == 0)continue;
					if(stat & (1<<(y[u]-1))){//自己已经有连了,不能连其他的,直接跳过
						const int nxt = stat - (1<<(nowy-1));
						g[nxt] = (g[nxt] + f[stat]) % MOD;
						continue;
					}
					g[stat] = (g[stat] + f[stat]) % MOD;
					if(vis[u])continue;//已经被特殊边选过了,继承完就结束
					for(auto v : e[u]){
						if(vis[v])continue;
						if(x[u] < x[v])continue;
						if(x[u] == x[v]){
							if(y[u]+1 == y[v] && not(stat & (1<<(y[v]-1)))){
								const int nxt = stat + (1<<(y[v]-1));
								g[nxt] = (g[nxt] + f[stat]) % MOD;
							}
						}else if(x[u] > x[v] && (y[u] == y[v] || y[u] == y[v]+1)){
							if(not(stat & (1<<(y[v]-1)))){
								const int nxt = stat + (1<<(y[v]-1));
								g[nxt] = (g[nxt] + f[stat]) % MOD;
							}
						}
					}
				}
				for(int i = 0;i <= maxs;i++)f[i] = g[i];
			}
		}
		for(int i = 0;i <= maxs;i++){
			ret = (ret + f[i]) % MOD;
		}
		return ret;
	}
	mt19937 rng(10181108 + 999);
	inline void Make(){
		extraEdge.clear();
		memset(vis,0,sizeof(vis));
		maxx = 0,maxy = 0;
		int xCnt = 0;
		for(int st = 0;st < c2;st++){
			for(int pos = st;vis[pos] != 2;pos = (pos + c1) % c2){
				if(vis[pos] == 0){
					xCnt++;
					for(int i = pos,yCnt = 0;i < n;i += c2){
						vis[i] = 1;
						x[i] = xCnt,y[i] = ++yCnt;
						maxy = max(maxy,ll(yCnt));
					}
					maxx = xCnt;
				}
				vis[pos] = 2;
			}
		}
		for(int u = 0;u < n;u++){
			for(auto v : e[u]){
				if(y[v] > y[u] && x[u] > x[v]){
					extraEdge.emplace_back(u,v);
				}
			}
		}
		return ;
	}
	inline void MakeF(){
		extraEdge.clear();
		memset(vis,0,sizeof(vis));
		maxx = 0,maxy = 0;
		int xCnt = 0;
		for(int st = c2-1;st >= 0;st--){
			for(int pos = st;vis[pos] != 2;pos = (pos + c1) % c2){
				if(vis[pos] == 0){
					xCnt++;
					for(int i = pos,yCnt = 0;i < n;i += c2){
						vis[i] = 1;
						x[i] = xCnt,y[i] = ++yCnt;
						maxy = max(maxy,ll(yCnt));
					}
					maxx = xCnt;
				}
				vis[pos] = 2;
			}
		}
		for(int u = 0;u < n;u++){
			for(auto v : e[u]){
				if(y[v] > y[u] && x[u] > x[v]){
					extraEdge.emplace_back(u,v);
				}
			}
		}
		return ;
	}
	inline ll Solve(){
		const static int MAXSIZE = 20;
		ll ret = 0;
		Make();
		if(int(extraEdge.size()) > MAXSIZE)MakeF();
		memset(dir,-1,sizeof(dir));
		for(int i = 0;i < n;i++){
			dir[x[i]][y[i]] = i;
		}
//		for(int i = 1;i <= maxx;i++){
//			for(int j = 1;j <= maxy;j++){
//				cerr<<dir[i][j]<<" ";
//			}
//			cerr<<endl;
//		}
		const int maxs = (1<<extraEdge.size()) - 1;
		assert(extraEdge.size() <= 25);
		for(int stat = 0;stat <= maxs;stat++){
			for(int i = 0;i < n;i++){
				vis[i] = false;
			}
			bool leadout = false;
			for(int i = 0;i < int(extraEdge.size());i++){
				if((1<<i) & stat){
					if(vis[extraEdge[i].first] || vis[extraEdge[i].second]){
						leadout = true;
					}
					vis[extraEdge[i].first] = vis[extraEdge[i].second] = true;
				}
			}
			if(leadout)continue;
			ret = (ret + Calc()) % MOD;
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("graph/graph4.in","r",stdin);
	cin>>n>>m>>c1>>c2;
	if(c1 > c2)swap(c1,c2);//c1 <= c2
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		if(u > v)swap(u,v);
		if(v - u == c1)have1[u] = true;
		if(v - u == c2)have2[u] = true;
		e[u-1].push_back(v-1),e[v-1].push_back(u-1);
	}
	if(DEBUG_SUB2_ONLY == false && c2 <= SPLIT){
		cout<<Subtask1::Solve()<<endl;
	}else{
		cout<<Subtask2::Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
