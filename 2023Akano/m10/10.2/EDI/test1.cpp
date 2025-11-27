#include <bits/stdc++.h>
#define fi first 
#define se second

using std :: cin;
using std :: min; 
using std :: max; 
using std :: cout; 
using std :: vector; 

constexpr int M = 1e5 + 5, mod = 1e9 + 7; 
constexpr int INF = 0x3f3f3f3f; 

typedef long long ll; 
typedef unsigned long long ull; 
typedef long double db; 
typedef std :: pair < int, int > pii; 

//char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
//#define getchar() (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)? EOF : *p1++

inline int read() { 
	int f = 1, s = 0; char ch = getchar(); 
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar(); 
	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar(); 
	return f * s; 
}

namespace Solver {
	int fac[M], ifac[M], inv[M]; 
	inline int qpow(int a, int b, int p) {
		int s = 1; 
		for(int bas = a; b; b >>= 1, bas = (ll)bas * bas % p)
			if(b & 1) s = (ll)s * bas % p; 
		return s; 
	}
	inline void init(int n) {
		fac[0] = ifac[0] = inv[0] = inv[1] = 1; 
		for(int i = 2; i <= n; ++i) inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod; 
		for(int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % mod; 
		ifac[n] = qpow(fac[n], mod - 2, mod); 
		for(int i = n; i; --i) ifac[i - 1] = (ll)ifac[i] * i % mod; 
	}
	inline int add(int x, int y) {return (x += y) >= mod ? x - mod : x;}
	inline int dec(int x, int y) {return (x -= y) < 0 ? x + mod : x; }
	inline void Ad(int &x, const int &y) {if((x += y) >= mod) x -= mod;}
	int n, p[M], vis[M], occ[M]; 
#define vec vector < int > 
	inline void sb1() {
		int ans = fac[n]; 
		for(int i = 1; i <= n; ++i) vis[i] = occ[i] = 0;  
		for(int i = 1; i <= n; ++i) if(!vis[i]) {
			int s = 0, u = i; while(!vis[u]) vis[u] = 1, u = p[u], ++s; 
			occ[s] ++, ans = (ll)ans * inv[s] % mod; 
		}
		for(int i = 1; i <= n; ++i) ans = (ll)ans * ifac[occ[i]] % mod; 
		cout << dec(ans, 1) << '\n'; 
	}
	vector < int > adj[M]; 
	inline ull g(ull x) {return x * x * x * 13ll + x * x * 101ll + x * 1331 + 19265307; }
	inline ull ff(ull x) {return g(x & ((1ll << 31) - 1)) * 71 + g(x >> 31ll) * 131; }
	inline void clr() {
		for(int i = 0; i <= n; ++i) adj[i].clear(); 
	}
	int dp[M], sz[M], tot, inc[M]; ull h[M]; 
	inline void dfs(int x) {
		++tot; 
		h[x] = sz[x] = dp[x] = 1; if(!x) sz[x] = 0; vector < ull > A; 
		for(int &y : adj[x]) if(!inc[y]) dfs(y), sz[x] += sz[y], h[x] += ff(h[y]), dp[x] = (ll)dp[x] * dp[y] % mod * ifac[sz[y]] % mod, A.push_back(h[y]); 
		dp[x] = (ll)dp[x] * fac[sz[x]] % mod; 
		std :: sort(A.begin(), A.end()); 
		for(int l = 0, r, s = A.size(); l < s; l = r + 1) {
			r = l; while(r + 1 < s && A[r + 1] == A[r]) ++r; 
			dp[x] = (ll)dp[x] * ifac[r - l + 1] % mod; 
		}
	}
	inline int gcd(int a, int b) {return !b ? a : gcd(b, a % b);}
	inline void sb2() {
		tot = 0; 
		for(int i = 1; i <= n; ++i) if(p[i] < i) adj[p[i]].push_back(i); else adj[0].push_back(i); 
		dfs(0); cout << dec(dp[0], 1) << '\n'; 
	}
	int prt[M], sgn, bc; 
	vector < int > C[M]; int stk[M], tp; 
	inline void dfs2(int x) {
		if(vis[x]) {
			if(vis[x] != sgn) return ; ++bc; 
			int u; do {u = stk[tp --], C[bc].push_back(u), inc[u] = 1; } while(u ^ x); 
			return ; 
		}
		vis[x] = sgn, stk[++tp] = x, dfs2(p[x]); 
	}
	ull s[M << 1]; int m; 
	std :: map < ull, int > ds;
	ull bas[M]; 
	inline void lyndon() {
		int lst = 1; 
		for(int i = 1; i <= m; ++i) s[i + m] = s[i]; 
		for(int i = 1; i <= m; ) {
			int j = i, k = i + 1; 
			while(k <= 2 * m && s[k] >= s[j]) {
				if(s[k] > s[j]) j = i; else ++j; 
				++k; 
			}
			while(i <= j) i += k - j, lst = (i <= m ? i : lst); 
		}
		ull w = 0; 
		for(int t = 1; t <= m; ++t, lst = (lst == m ? 1 : lst + 1)) w = w * bas[1] + s[lst]; 
		ds[w] ++; 
	}
	ull pre[M]; 
	int ok[M], prd[M]; 
	inline int chk(int g) {
		if(~ok[g]) return ok[g];
		for(int i = g; i <= m; i += g) if(pre[g] != pre[i] - pre[i - g] * bas[g]) return ok[g] = 0; 
		return ok[g] = 1; 
	}
	inline void solve() {
		n = read(); for(int i = 1; i <= n; ++i) vis[i] = 0; int ko = 1; 
		for(int i = 1; i <= n; ++i) p[i] = read(), vis[p[i]] = 1, ko &= (p[i] <= i); 
		int cnt = 0; for(int i = 1; i <= n; ++i) cnt += vis[i]; 
//		if(cnt == n) return sb1(), void(); 
		if(ko) return sb2(), void(); 
		for(int i = 1; i <= n; ++i) vis[i] = inc[i] = 0, adj[p[i]].push_back(i), prt[i] = p[i]; 
		bc = 0;
		for(int i = 1; i <= n; ++i) if(!vis[i]) tp = 0, ++sgn, dfs2(i); 
		int ans = fac[n], st = 0; 
		for(int i = 1; i <= bc; ++i) {
			m = 0, prd[0] = 1; tot = 0; int w = 1; 
			for(int &x : C[i]) dfs(x), s[++m] = h[x], pre[m] = pre[m - 1] * bas[1] + s[m], w = (ll)w * dp[x] % mod * ifac[sz[x]] % mod; 
			for(int j = 1; j <= m; ++j) ok[j] = -1; int sz = C[i].size(), len = 0; 
			for(int j = 1; j <= sz; ++j) if(sz % j == 0) {
				int ok = 1; 
				for(int k = 0; k + j <= sz; k += j) {
					int fl = 1; 
					for(int r = 1; r <= j; ++r) fl &= (s[r] == s[r + k]); 
					if(!fl) {ok = 0; break;}
				}
				if(ok) {len = j; break;}
			}
			int up = (ll)w * fac[tot] % mod * inv[sz / len] % mod; 
			ans = (ll)ans * up % mod * ifac[tot] % mod; 
			lyndon(); C[i].clear(); 
		}
		for(auto &it : ds) ans = (ll)ans * ifac[it.se] % mod; 
		ds.clear(); 
		cout << dec(ans, 1) << '\n'; 
	}
	inline void mian() {
		int t = read(); init(M - 5); 
		bas[0] = 1; for(int i = 1; i < M; ++i) bas[i] = bas[i - 1] * 114514191ull; 
		while(t --) solve(), clr(); 
	}
	
}

int main() 
{
//	freopen("ex_langue2.in", "r", stdin);  
	Solver :: mian(); 
	return 0; 
}     
