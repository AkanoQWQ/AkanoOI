#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#define x first
#define y second
#define pb push_back
using namespace std;
const int N = 100005;
typedef long long ll;
typedef long long ul;
ul key0, key1, pw[N * 2];
const int mod = 1e9 + 7;
int T, n;

int ksm(int x, int k, int mod) {
	int s = 1;
	while(k) {
		if(k & 1) s = 1ll * s * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return s;
}

int fac[N], ifac[N], inv[N];
void prepare() {
	fac[0] = 1;
	for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[1] = ifac[0] = ifac[1] = 1;
	for(int i = 2; i < N; i++) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	}
}

ul key[N];
int way[N], sz[N];

vector<int> adj[N];
bool in[N];
int prt[N];

int getf(int x) {
	if(x == prt[x]) return prt[x];
	prt[x] = getf(prt[x]);
	return prt[x];
}

bool vis[N];

struct data {
	int way, sz, tot;//way 计数,sz大小,tot出现次数
	data(int way = 0, int sz = 0, int tot = 0): way(way), sz(sz), tot(tot) {}
};

int combine(const map<ul, data>& all) {//对统计进行去重合并
	int tmp = 1, sum = 0;
	for(auto u : all) {
		for(int i = 0; i < u.y.tot; i++)
			tmp = 1ll * tmp * u.y.way % mod * ifac[u.y.sz] % mod;// *=  way / siz!
		sum += u.y.tot * u.y.sz;//统计siz和,会重复统计(同构子树的siz)
		tmp = 1ll * tmp * ifac[u.y.tot] % mod;
	}
	tmp = 1ll * tmp * fac[sum] % mod;
	return tmp;
}

void dfs(int x) {
	sz[x] = 1;
	vis[x] = 1;
	map<ll, data> all;
	for(auto y : adj[x])
		if(!vis[y]) {
			dfs(y);
			sz[x] += sz[y];
			all[key[y]].way = way[y];
			all[key[y]].sz = sz[y];
			++all[key[y]].tot;
		}
	way[x] = 1ll * sz[x] * combine(all) % mod;
	key[x] = 1;
	for(auto u : all) for(int i = 0; i < u.y.tot; i++)
			key[x] = key[x] * pw[u.y.sz << 1] + u.x;//为什么要乘以二?
	key[x] *= key0;
}

int minp(const vector<ul>& a) {//找最小循环节?对齐最小循环节?
	int i = 0, j = 1;
	int l = a.size();
	while(i < l && j < l) {
		int k = 0;
		while(a[(i + k) % l] == a[(j + k) % l] && k < l) k++;
		if(k == l) return i;
		if(a[(i + k) % l] > a[(j + k) % l]) {
			if(i + k + 1 > j) i += k + 1;
			else i = j + 1;
		} else if(j + k + 1 > i) j += k + 1;
		else j = i + 1;
	}
	if(i < l) return i;
	return j;
}

int fa[N];
pair<ul, pair<int, int> > work(int x) {
	int u = fa[x];
	vector<ul> all;
	int tot = 0, nu = 1;//nu应该就是对答案的计数
	vis[x] = 1;
	do {
		dfs(u);//对基环树的分支dfs
		tot += sz[u];
		nu = 1ll * nu * way[u] % mod * ifac[sz[u]] % mod;
		all.pb(key[u]);
		u = fa[u];
	} while(u != fa[x]);
	int m = all.size();
	nu = 1ll * nu * fac[tot] % mod;//这个地方乘以 fac_tot 不是和前面抵消了吗?有什么用?
	rotate(all.begin(), all.begin() + minp(all), all.end());
	
	ul ke = 0;
	for(int i = 0; i < m; i++) ke = ke * key1 + all[i];//总的哈希值
	
	//找最小循环节?
	int Min = m;
	for(int i = 1; i <= m; i++) if(!(m % i)) {
			bool Ok = 0;
			for(int j = 0; j < m - i; j++) if(all[j] != all[j + i]) {
					Ok = 1;
					break;
				}
			if(!Ok) {
				Min = i;
				break;
			}
		}
	return make_pair(ke, make_pair(1ll * nu * inv[m / Min] % mod, tot));
}
int main() {
//	freopen("langue/langue3.in","r",stdin);
	prepare();
	key0 = -9092369829429151887ll;
	key1 = 6401520762018806277ll;
	pw[0] = 1;
	for(int i = 1; i < (N << 1); i++) pw[i] = pw[i - 1] * key0;
	cin>>T;
	while(T--) {
		cin>>n;
		memset(in, 0, sizeof(in));
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			prt[i] = i;
			adj[i].clear();
		}
		for(int i = 0; i < n; i++) {
			cin>>fa[i];
			--fa[i];
			adj[fa[i]].pb(i);
		}
		for(int i = 0; i < n; i++) {
			if(getf(i) == getf(fa[i])) in[i] = 1;//在环上,只有最后一个才会有 in == 1?
			else prt[getf(i)] = getf(fa[i]);
		}
		map<ul, data>all;
		for(int i = 0; i < n; i++){
			if(in[i]) {
				pair<ul, pair<int, int> > ret = work(i);
				all[ret.x].way = ret.y.x;
				all[ret.x].sz = ret.y.y;
				++all[ret.x].tot;//如果有相同的，它会覆盖相同的内容并增加tot
			}
		}
		int ans = combine(all);
		ans = (ans - 1 + mod) % mod;
		cout<<ans<<endl;
	}


	return 0;
}
