#include<bits/stdc++.h>
using std::cerr;
using std::endl;
namespace awa
{
//#define LOCAL ___________Don_t_define_me_____________
	char _ST_;
#define ll long long
//#define int long long
#define inf 0x3f3f3f3f
//#define inf 0x3f3f3f3f3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define gline debug("now is #%d\n", __LINE__)
#define pii std::pair <int, int>
#define mkp std::make_pair
#define fi first
#define se second
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *iS = ibuf, *iT = ibuf;
	char obuf[BUFSIZE], *oS = obuf, *oT = obuf + BUFSIZE;
	char getc()
	{
#ifdef LOCAL
		return getchar();
#else
		if(iS == iT) iT = (iS = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
		return iS == iT ? EOF : *iS++;
#endif
	}
	
	void FLUSH()
	{
		fwrite(obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	
	struct FLUSHER { ~FLUSHER() { FLUSH(); } }awaqwqpwpawa;
	
	void putc(char c)
	{
#ifdef LOCAL
		putchar(c);
#else
		*oS++ = c;
		if(oS == oT) FLUSH();
#endif
	}
	
	template <typename T = int> T read()
	{
		T x = 0, f = 1; char c = getc();
		for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
		for(;  isdigit(c); c = getc()) x = (x << 3) + (x << 1) + (c ^ 48);
		return x * f; 
	}
	
	int bufsta[BUFSIZE], buftop;
	template <typename T> void print(T x, char c)
	{
		buftop = 0;
		if(x < 0) putc('-'), x = -x;
		if(x == 0) bufsta[buftop = 1] = 0;
		for(; x; x /= 10) bufsta[++buftop] = x % 10;
		while(buftop) putc(bufsta[buftop--] ^ 48);
		if(c) putc(c);
	}
	
	int readstr(char *s, int base)
	{
		int idx = base - 1; char c = getc();
		for(; !isdigit(c) && !isalpha(c) && c != '#' && c != '.'; c = getc());
		for(;  isdigit(c) ||  isalpha(c) || c == '#' || c == '.'; c = getc()) s[++idx] = c;
		return idx - base + 1;
	}
	
	template <typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
	template <typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }
//#define mod 998244353
#define mod 1000000007
	void plus_(int &x, int y) { x = x + y >= mod ? x + y - mod : x + y; }
	void mul_(int &x, int y) { x = 1ll * x * y % mod; }
	int ksm(int a, int b) { if(b < 0) return 0; int res = 1; for(; b; b >>= 1, mul_(a, a)) if(b & 1) mul_(res, a); return res; }
#define ull unsigned long long
	ull sd = 114514;
	ull rnd()
	{
		sd ^= sd << 13;
		sd ^= sd >> 7;
		sd ^= sd << 11;
		return sd;
	}
#define N 2000010
	int n, m;
	int dep[N], h[N], e[N << 1], ne[N << 1], idx = -1;
	bool vis[N << 1], is_tree[N << 1]; ull val[N], a[N];
	void add_edge(int x, int y) { ne[++idx] = h[x], h[x] = idx, e[idx] = y; }
	void add(int x, int y) { add_edge(x, y), add_edge(y, x); }
//int sta[N], top;
	bool solved[N];
	void dfs1(int k)
	{
		solved[k] = 1;
//	sta[++top] = k;
		for(int i = h[k]; ~i; i = ne[i])
		{
			if(vis[i]) continue;
			vis[i] = vis[i ^ 1] = 1;
			int nx = e[i];
			if(!dep[nx])
			{
				dep[nx] = dep[k] + 1;
				is_tree[i] = 1;
//			printf("tree[%d to %d]\n", k, nx);
				dfs1(nx);
			}
			else
			{
				ull t = rnd();
				val[i >> 1] = t;
				a[nx] ^= t;
				a[k] ^= t;
//				printf("a[%d] ^= %llu, b[%d] ^= %llu\n", sta[dep[nx] + 1], t, k, t);
			}
		}
//	top--;
	}
	ull dfs2(int k, int in_edge)
	{
//	debug("%d", solved[k]); 
		solved[k] = 1;
//	printf("k = %d\n", k);
		ull v = a[k];
		for(int i = h[k]; ~i; i = ne[i])
		{
			int nx = e[i]; if(!is_tree[i]) continue;
			v ^= dfs2(nx, i);
		}
		if(in_edge){
			val[in_edge >> 1] = v;
		}
		return v;
	}
	void solve()
	{
		memset(h, idx = -1, sizeof(h));
		idx = 1;
		n = read(), m = read();
		for(int i = 1, x, y; i <= m; i++) 
		{	
			x = read(), y = read();
			add(x, y);
		}
		int c = 0;
		for(int i = 1; i <= n; i++)
			if(!solved[i])
				dep[i] = 1, dfs1(i), c++;
		memset(solved, 0, sizeof(solved));
//	debug("awa\n");
		for(int i = 1; i <= n; i++)
			if(!solved[i])
				dfs2(i, 0);
		
		std::sort(val + 1, val + 1 + m);
		int tp = 1;
		while(tp <= m && !val[tp]) tp++;
//	for(int i = 1; i <= m; i++) printf("val[%d] = %llu\n", i, val[i]);
		if(tp > m) { print(0, '\n'); return; }
//	printf("m = %d, n = %d, c = %d\n", m, n, c);
		int v1 = ksm(2, m - n + c - 1);
		int v2 = ksm(2, m - n + c - 2);
//	printf("v1 = %d, v2 = %d\n", v1, v2);
		int ans = 0;
		cerr<<"block "<<c<<" vs "<<v1<<","<<v2<<endl;
		for(int i = 1;i <= m;i++){
			std::cerr<<i<<" val "<<val[i]<<std::endl;
		}
		for(int l = tp, r; l <= m; l = r + 1)
		{
			for(r = l; r <= m && val[r + 1] == val[l]; r++);
			int len = r - l + 1;
			cerr<<len<<" add "<<1ll * len * len % mod * v1 % mod<<" adn "<<1ll * len * (m - r) % mod * v2 % mod * 2 % mod<<" res "<<(m - r)<<endl;
			plus_(ans, 1ll * len * len % mod * v1 % mod);
			plus_(ans, 1ll * len * (m - r) % mod * v2 % mod * 2 % mod);
		}
		print(ans, '\n');
	}
	
	void init()
	{
		
	}
	
	char _ED_;
	void mian()
	{
		debug("%.3f MB\n", abs(&_ST_ - &_ED_) / 1024.0 / 1024);
		init();
		for(int T = 1; T; solve(), T--);
	}
	
#ifdef int
#undef int
#endif 
	
}

int main()
{
	freopen("fish/fish1.in", "r", stdin);
//	freopen("fish.out", "w", stdout);
	awa::mian();
	return 0;
} 
