#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using ld = long double;
// using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
	ll x = 0, sgn = 0;
	char s = getchar();
	while(!isdigit(s)) sgn |= s == '-', s = getchar();
	while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
	return sgn ? -x : x;
}
inline void print(ll x) {
	if(x < 0) return putchar('-'), print(-x);
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 1e6 + 5;
constexpr int mod = 998244353;
constexpr int iv6 = (mod + 1) / 6;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int bin2(int x) {return 1ll * x * (x + 1) / 2 % mod;}
int bin3(int x) {return 1ll * x * (x + 1) % mod * (x + 2) % mod * iv6 % mod;}
int n, f[N], sf[N], g[N], sg[N];
bool Med;
int main() {
	fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
	FILE* IN = freopen("1.in", "r", stdin);
	FILE* OUT = freopen("1.out", "w", stdout);
#endif
	cin >> n;
	f[0] = sf[0] = 1;
	for(int i = 1; i <= n; i++) {
		g[i] = bin2(sf[i - 1]);
		if(i > 1) add(g[i], mod - bin2(sf[i - 2]));
		f[i] = f[i - 1], sf[i] = sf[i - 1], sg[i] = sg[i - 1];
		add(f[i], g[i]), add(sf[i], f[i]), add(sg[i], g[i]);
	}
	int ans = f[n];
	add(ans, bin3(sf[n - 1]));
	if(n > 1) add(ans, mod - bin3(sf[n - 2]));
	add(ans, ans - 1);
	for(int i = 1; i + 1 < n; i++) add(ans, 1ll * g[i] * sg[n - i - 1] % mod);
	for(int i = 1;i <= n;i++){
		cerr<<i<<" : "<<f[i]<<" and "<<sf[i]<<" and "<<g[i]<<" and "<<sg[i]<<endl;
	}
	cout << ans << "\n";
	cerr << TIME << " ms\n";
	return 0;
}
