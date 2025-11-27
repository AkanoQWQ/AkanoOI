#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)
#define Forr(i, j, k) for (int i = j; i >= k; i--)

using namespace std;

const int N = 5e5 + 10;
const int Mod = 1e9 + 7;

int Pow(int x, long long e) {
	int ret = 1;
	while (e) {
		if (e & 1) ret = 1ll * ret * x % Mod;
		x = 1ll * x * x % Mod;
		e >>= 1;
	}
	return ret;
}

int fac[N], rfac[N];

int work(int a, int b, int la, int lb, int w) {
	int ans = 0;
	For(i, 0, a) {
		int s = Pow(Pow(w + 1, la + a - i) - Pow(w, la + a - i) + Mod, b);
		s = 1ll * s * Pow(w + 1, 1ll * lb * (a - i)) % Mod * Pow(w, 1ll * (b + lb) * i) % Mod;
		s = 1ll * s * rfac[i] % Mod * rfac[a - i] % Mod;
		if (i & 1) ans = (ans - s + Mod) % Mod; else ans = (ans + s) % Mod;
	}
	return 1ll * ans * fac[a] % Mod;
}

int A[N], B[N], num[N << 1];
int n, c;

int main() {

	freopen("silhouette.in", "r", stdin);
	freopen("silhouette.out", "w", stdout);

	scanf("%d", &n);
	For(i, 1, n) scanf("%d", &A[i]), num[++c] = A[i];
	For(i, 1, n) scanf("%d", &B[i]), num[++c] = B[i];

	fac[0] = 1;
	For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % Mod;
	rfac[n] = Pow(fac[n], Mod - 2);
	Forr(i, n, 1) rfac[i - 1] = 1ll * rfac[i] * i % Mod;

	sort(A + 1, A + n + 1, greater<int>());
	sort(B + 1, B + n + 1, greater<int>());
	sort(num + 1, num + c + 1, greater<int>());
	c = unique(num + 1, num + c + 1) - num - 1;

	int la = 0, lb = 0;
	int ans = 1;
	For(i, 1, c) {
		int ra = la, rb = lb;
		while (ra < n && A[ra + 1] == num[i]) ++ra;
		while (rb < n && B[rb + 1] == num[i]) ++rb;
		ans = 1ll * ans * work(ra - la, rb - lb, la, lb, num[i]) % Mod;
		if (ans == 0) break;
		la = ra, lb = rb;
	}
	printf("%d\n", ans);

	return 0;
}
