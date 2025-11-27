#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second 

constexpr int M = 2e6 + 5, mod = 998244353; 
constexpr int INF = 0x3f3f3f3f; 

typedef long long ll; 
typedef unsigned long long ull;
typedef double db; 
typedef __int128 i128; 
typedef std :: pair < int, int > pii; 

inline int read() { 
	int f = 1, s = 0; char ch = getchar(); 
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar(); 
	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar(); 
	return f * s; 
}

namespace Solver {
	int n, m; ll c[M]; int lim[M], d[M]; 
	i128 ans; 
	inline ll get(int x) {
		d[m] = x;
		for(int i = m - 1; i; --i){
			d[i] = min(lim[i] - d[i + 1], i > 1 ? lim[i - 1] : INF);
		}
		for(int i = m + 1; i <= n; ++i){
			d[i] = min(lim[i - 1] - d[i - 1], i < n ? lim[i] : INF);
		}
		i128 s = 0; 
		for(int i = 1; i <= n; ++i){
			s += (i128)d[i] * c[i];
		}
		ans = max(ans, s);
		return s; 
	}
	inline void write(i128 x) {if(x > 9) write(x / 10); putchar(x % 10 + '0'); }
	inline void solve() {
		n = read(), m = read(), ans = 0; 
		for(int i = 1; i < n; ++i){
			lim[i] = read();
		}
		for(int i = 1, x; i <= m; ++i){
			x = read();
			c[i] += x;
			c[n - (m - i) + 1] -= x;
		}
		for(int i = 1; i <= n; ++i){
			c[i] += c[i - 1];
		}
		lim[0] = lim[n] = INF; 
		int L = 1, R = min(lim[m - 1], lim[m]);
		get(0); 
		while(L <= R) {
			int mid = (L + R) >> 1; 
			if(get(mid - 1) < get(mid)){
				L = mid + 1;
			}else{
				R = mid - 1;
			}
		} 
		write(ans), puts(""); 
		for(int i = 1; i <= n + 1; ++i) c[i] = 0; 
	}
	inline void mian() {
		int typ = read(); int t = read(); 
		while(t --) solve(); 
	}
}

int main() 
{
	freopen("var/var0.in", "r", stdin); 
//	freopen("var.out", "w", stdout); 
	Solver :: mian(); 
	return 0; 
}   
