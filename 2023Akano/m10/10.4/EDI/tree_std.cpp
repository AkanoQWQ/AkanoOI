#include <bits/stdc++.h>
#define fi first
#define se second

using std :: cin;
using std :: min;
using std :: max;
using std :: cout;
using std :: vector;

constexpr int M = 6e5 + 5;
constexpr long long INF = 1e18;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std :: pair < int, int > pii;

char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
#define getchar() (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)? EOF : *p1++

inline int read() {
	int f = 1, s = 0;
	char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return f * s;
}

namespace Solver {
	char _st;
	int n, m, a[M], tot, rt[M], len, belong[M], lc[M], rc[M], L[M], R[M], sgn, fp[M];
	int f[M], cnt, d[M];
	inline int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}
	struct E {
		int x, y, z;
	} e[M];
	int ch[M][2];
	ll sum[M], val[M];
	int son[M], sz[M], top[M], prt[M], mxd;
	inline void dfs(int x) {
		mxd = max(mxd, d[x]);
		sum[x] = (x <= n ? a[x] : 0), sz[x] = 1;
		if(x <= n) return ;
		for(int i = 0, y; i < 2; ++i) y = ch[x][i], prt[y] = x, d[y] = d[x] + 1, dfs(y), sum[x] += sum[y], sz[x] += sz[y], (sz[y] >= sz[son[x]]) && (son[x] = y, 1);
	}
	inline void dfs2(int x, int sp) {
		if(x <= n) return ;
		top[x] = sp, fp[L[x] = ++sgn] = x;
		if(son[x]) dfs2(son[x], sp);
		for(int i = 0, y; i < 2; ++i) if((y = ch[x][i]) != son[x])dfs2(y, y);
		R[x] = sgn;
	}
	ll ans;
	template < typename T > bool chkmx(T& x, const T& y) {
		return x < y ? x = y, 1 : 0;
	}
	ll tag[M];
	struct line {
		ll k, b;
		line(ll k = 0, ll b = -INF) : k(k), b(b) {}
	} ;
	struct LCT {
		int l, r;
		line seg;
	} t[M >> 1];
	const int Lim = 1e5;
	int reuse[M >> 1], tp;
	inline ll get(line x, ll b) {
		return x.k * b + x.b;
	}
	inline int new_node() {
		int p = tp ? reuse[tp --] : ++cnt;
		t[p].l = t[p].r = 0, t[p].seg = line();
		return p;
	}
	inline int ins(int p, int l, int r, line x) {
		if(!p) return p = new_node(), t[p].seg = x, p;
		int mid = (l + r) >> 1;
		if(get(x, mid) > get(t[p].seg, mid)) std :: swap(t[p].seg, x);
		if(get(x, l) > get(t[p].seg, l)) t[p].l = ins(t[p].l, l, mid, x);
		if(get(x, r) > get(t[p].seg, r)) t[p].r = ins(t[p].r, mid + 1, r, x);
		return p;
	}
	inline ll TotalQuery(int p, int l, int r, int x){
		if(!p) return -INF;
		ll v = get(t[p].seg, x);
		if(l == r) return v;
		int mid = (l + r) >> 1;
		return max(v, x <= mid ? TotalQuery(t[p].l, l, mid, x) : TotalQuery(t[p].r, mid + 1, r, x));
	}
	inline int Clear(int p) {
		if(!p) return 0;
		reuse[++tp] = p, Clear(t[p].l), Clear(t[p].r);
		return p;
	}
	ll ori[M], sumA[M], edgeMin[M];
	inline void Pushdown(int t) {
		const int L = lc[t], R = rc[t];
		ll w = tag[t];
		tag[t] = 0;
		Clear(rt[t]), rt[t] = 0;
		for(int i = L; i <= R; ++i) sumA[i] += w;
	}
	inline void Rebuild(int t) {
		const int L = lc[t], R = rc[t];
		for(int i = L; i <= R; ++i){
			ori[i] = (ll)edgeMin[i] * sumA[i];
			rt[t] = ins(rt[t], -Lim, Lim, line(edgeMin[i], ori[i]));
		}
	}
	inline void upd(int l, int r, ll v) {
		const int L = belong[l], R = belong[r];
		if(L == R) {
			Pushdown(L);
			for(int i = l; i <= r; ++i) sumA[i] += v;
			Rebuild(L);
			return ;
		}
		Pushdown(L), Pushdown(R);
		for(int i = L + 1; i < R; ++i) tag[i] += v;//整块打标记修改
		for(int i = l; i <= rc[L]; ++i) sumA[i] += v;//散块暴力修改
		Rebuild(L);//修改完重构
		for(int i = lc[R]; i <= r; ++i) sumA[i] += v;
		Rebuild(R);
	}
	inline void upd(int x, int y) {
		int dt = y - a[x];
		a[x] = y;
		x = prt[x];
		while(x) upd(L[top[x]], L[x], dt), x = prt[top[x]];
	}
	char _ed;
	inline void mian(){
		n = read(), m = read();
		for(int i = 1; i <= n; ++i) a[i] = read();
		for(int i = 1; i < n; ++i) e[i].x = read(), e[i].y = read(), e[i].z = read();
		std :: sort(e + 1, e + n, [](E a, E b) {
			return a.z > b.z;
		});
		tot = n;
		std :: iota(f + 1, f + n + 1, 1);
		for(int i = 1; i < n; ++i) {
			int x = e[i].x, y = find(e[i].y);
			x = find(x), y = find(y);
			int ex = ++tot;
			f[x] = f[y] = f[ex] = ex, val[ex] = e[i].z, ch[ex][0] = x, ch[ex][1] = y;
		}
		dfs(tot), dfs2(tot, tot);
		len = 240;
		for(int i = 1; i <= sgn; ++i) belong[i] = (i - 1) / len + 1;
		for(int i = 1; i <= belong[sgn]; ++i) {
			lc[i] = rc[i - 1] + 1, rc[i] = min(sgn, lc[i] + len - 1);
			for(int j = lc[i]; j <= rc[i]; ++j){
				sumA[j] = sum[fp[j]];
				edgeMin[j] = val[fp[j]];//b,也就是斜率
				ori[j] = sumA[j] * edgeMin[j];
				//为什么斜率是b?因为还要考虑整块有tag,就用这个解决
				rt[i] = ins(rt[i], -Lim, Lim, line(edgeMin[j], ori[j]));
			}
		}
		while(m --){
			int x = read(), y = read();
			upd(x, y);
			ll ans = -INF;
			for(int i = 1; i <= belong[sgn]; ++i) chkmx(ans,TotalQuery(rt[i], -Lim, Lim, tag[i]));
			cout << ans << '\n';
		}
	}
}

int main() {
	Solver::mian();
	return 0;
}
