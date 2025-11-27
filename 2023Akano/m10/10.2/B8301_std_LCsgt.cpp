#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 200005;
const int inf = 1e18;
int n, top, a[N], stk[N], pre[N], suf[N], ret[N];

namespace LCsgtree {
	struct lines {
		int k, b;
	};
	struct segtree {
		int lc, rc;
		lines zx;
	};
	int tot, tmpall;
	int* stk1[N * 50];
	lines stk2[N * 50];
	segtree tree[N];
	int calc(lines ls, int x) {
		return x * ls.k + ls.b;
	}
	void insert(int& x, int l, int r, lines ls) {
		if(! x) {
			tree[x = ++ tot] = (segtree) {
				0, 0, ls
			};
			stk1[++ tmpall] = &x;
			stk2[tmpall].k = inf;
			return;
		}
		int mid = (l + r) >> 1;
		if(calc(ls, mid) > calc(tree[x].zx, mid)) stk1[++ tmpall] = &x, stk2[tmpall] = tree[x].zx, swap(ls, tree[x].zx);
		if(l == r) return;
		if(ls.k > tree[x].zx.k) insert(tree[x].rc, mid + 1, r, ls);
		else insert(tree[x].lc, l, mid, ls);
	}
	int query(int x, int l, int r, int pl) {
		if(! x) return -1;
		int mid = (l + r) >> 1;
		int ans = calc(tree[x].zx, pl);
		if(pl <= mid) ans = max(ans, query(tree[x].lc, l, mid, pl));
		else ans = max(ans, query(tree[x].rc, mid + 1, r, pl));
		return ans;
	}
	void dlete(int ed) {
		while(tmpall > ed) {
			if(stk2[tmpall].k == inf) *stk1[tmpall] = 0, tot --;
			else tree[* stk1[tmpall]].zx = stk2[tmpall];
			tmpall --;
		}
	}
};
using namespace LCsgtree;

signed main() {
	int root = 0;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i ++) {
		while(top && a[stk[top]] >= a[i]) dlete(ret[top --]);
		stk[++ top] = i;
		ret[top] = tmpall;
		insert(root, 1, n, (lines) {
			a[i], (- (stk[top - 1] + 1) + 1) * a[i]
		});
		pre[i] = max(query(root, 1, n, i), pre[i - 1]);
	}
	top = tmpall = tot = 0;
	stk[0] = n + 1;
	for(int i = n; i >= 1; i --) {
		while(top && a[stk[top]] >= a[i]) dlete(ret[top --]);
		stk[++ top] = i;
		ret[top] = tmpall;
		insert(root, 1, n, (lines) {
			- a[i], ((stk[top - 1] - 1) + 1) * a[i]
		    });
		suf[i] = max(query(root, 1, n, i), suf[i + 1]);
	}
	for(int i = 1; i <= n; i ++) printf("%lld\n", max(pre[i - 1], suf[i + 1]));
	return 0;
}
