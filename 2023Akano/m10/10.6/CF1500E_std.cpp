#include <bits/stdc++.h>
#define inf 1e13
#define eps 1e-6
#define mp make_pair
#define pb push_back
#define re register ll
#define fr first
#define sd second
#define pa pair<ll,ll>
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define N 200010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
inline ll read() {
	char ch = getchar();
	ll s = 0, w = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
inline ll lowbit(ll x) {
	return x & (-x);
}
struct node {
	ll sum, LS, RS, num; // LS 是前缀和， RS 是后缀和
} t[N * 60];
node st[N];
ll top = 0;
int ls[N * 60], rs[N * 60];
ll n, q, tot;
int rt;
ll a[N], x[N], op[N], p[N << 1], tmp;
#define mid ((l+r)>>1)
inline void pushup(ll x) {
	t[x].num = t[ls[x]].num + t[rs[x]].num;
	t[x].sum = t[ls[x]].sum + t[rs[x]].sum;
	t[x].LS = t[ls[x]].LS + t[rs[x]].LS + t[rs[x]].num * t[ls[x]].sum;
	t[x].RS = t[ls[x]].RS + t[rs[x]].RS + t[ls[x]].num * t[rs[x]].sum;
}
void add(ll l, ll r, int& x, ll pos, ll opt) {
	if(!x)x = ++tot;
	if(l == r) {
		if(opt > 0) {
			t[x].num = 1;
			t[x].sum = t[x].LS = t[x].RS = p[l];
		} else {
			t[x].num = 0;
			t[x].sum = t[x].LS = t[x].RS = 0;
		}
		return ;
	}
	if(pos <= mid)add(l, mid, ls[x], pos, opt);
	else add(mid + 1, r, rs[x], pos, opt);
	pushup(x);
}
ll QueryPreSuf(ll l, ll r, ll x, ll k, ll op, ll& s) { // 询问第 k 小与前 k 小的和/前 k 大与前 k 大的和
	if(l == r) {
		s += p[l];
		return l;
	}
	if(!op) {
		if(t[ls[x]].num >= k)return QueryPreSuf(l, mid, ls[x], k, op, s);
		else {
			s += t[ls[x]].sum;
			return QueryPreSuf(mid + 1, r, rs[x], k - t[ls[x]].num, op, s);
		}
	} else {
		if(t[rs[x]].num >= k)return QueryPreSuf(mid + 1, r, rs[x], k, op, s);
		else {
			s += t[rs[x]].sum;
			return QueryPreSuf(l, mid, ls[x], k - t[rs[x]].num, op, s);
		}
	}
}
void qry(ll l, ll r, ll x, ll ql, ll qr) { //将一个区间的线段树节点取出
	if(ql > qr || !x)return ;
	if(l == ql && r == qr) {
		st[++top] = t[x];
		return ;
	}
	if(qr <= mid)qry(l, mid, ls[x], ql, qr);
	else if(ql > mid)qry(mid + 1, r, rs[x], ql, qr);
	else {
		qry(l, mid, ls[x], ql, mid);
		qry(mid + 1, r, rs[x], mid + 1, qr);
	}
}
inline ll QS(ll l, ll r) { //询问区间和
	top = 0;
	qry(1, tmp, rt, l, r);
	ll s = 0;
	FOR(i, 1, top)s += st[i].sum;
	return s;
}
inline ll qsum(ll l, ll r, ll op) { //询问区间前缀和/后缀和
	top = 0;
	qry(1, tmp, rt, l, r);
	ll s = 0, ans = 0;
	if(op == 0) {
		FOR(i, 1, top) {
			ans += st[i].LS + s * st[i].num;
			s += st[i].sum;
		}
	}
	if(op == 1) {
		REP(i, top, 1) {
			ans += st[i].RS + s * st[i].num;
			s += st[i].sum;
		}
	}
	return ans;
}
inline void Test(int x){
	ll s1 = 0, s2 = 0;
	QueryPreSuf(1, tmp, rt, x + 1, 0, s1),QueryPreSuf(1, tmp, rt, x, 1, s2);
	cerr<<x<<" is "<<s1<<" and "<<s2<<endl;
	return ;
}
inline ll qans() {
	if(n == 0) {
		return 0;
	}
	ll l = 1, r = n - 1, pl = 0, pr = 0;
	ll ans = 0;
	while(l <= r) {
		ll s1 = 0, s2 = 0;
		QueryPreSuf(1, tmp, rt, mid + 1, 0, s1),QueryPreSuf(1, tmp, rt, mid, 1, s2);
		if(s1 <= s2)pl = mid, r = mid - 1;
		else l = mid + 1;
	}
	l = 1, r = n - 1;
	while(l <= r) {
		ll s1 = 0, s2 = 0;
		QueryPreSuf(1, tmp, rt, mid + 1, 0, s1),QueryPreSuf(1, tmp, rt, mid, 1, s2);
		if(s1 <= s2)pr = mid + 1, l = mid + 1;
		else r = mid - 1;
	}
	for(int i = 1;i <= n;i++)Test(i);
	cerr<<pl<<" and "<<pr<<endl;
	if(pl == 0) {//没有第三区间,只需要 sumR - sumL
		return qsum(1, tmp, 1) - qsum(1, tmp, 0);
	}
	if(pr < n) {//存在第三区间
		ll s = 0;
		ll L = QueryPreSuf(1, tmp, rt, pr + 1, 0, s), R = QueryPreSuf(1, tmp, rt, pr + 1, 1, s);
		ans += qsum(1, R - 1, 1) + QS(R, tmp) * (n - pr);
		ans -= qsum(L + 1, tmp, 0) + QS(1, L) * (n - pr);
	}
	if(pl > 1) {//存在第一区间
		ll s = 0;
		ll L = QueryPreSuf(1, tmp, rt, pl - 1, 0, s), R = QueryPreSuf(1, tmp, rt, pl - 1, 1, s);
		ans += qsum(R, tmp, 1);
		ans -= qsum(1, L, 0);
	}
	ll s = 0;
	ans -= QS(1, QueryPreSuf(1, tmp, rt, pl, 0, s));
	ans += QS(QueryPreSuf(1, tmp, rt, pr, 1, s), tmp);
	return ans;
}
int main() {
	freopen("CF1500E.in","r",stdin);
	//freopen("CF1500E.out","w",stdout);
	n = read(), q = read();
	FOR(i, 1, n)a[i] = read(), p[++tmp] = a[i];
	FOR(i, 1, q)op[i] = read(), x[i] = read(), p[++tmp] = x[i];
	sort(p + 1, p + tmp + 1);
	tmp = unique(p + 1, p + tmp + 1) - p - 1;
	FOR(i, 1, n)a[i] = lower_bound(p + 1, p + tmp + 1, a[i]) - p;
	FOR(i, 1, q)x[i] = lower_bound(p + 1, p + tmp + 1, x[i]) - p;
	FOR(i, 1, n)add(1, tmp, rt, a[i], 1);
	cout << qans() << '\n';
	FOR(i, 1, q) {
		ll opt = op[i], X = x[i];
		if(opt == 1) {
			add(1, tmp, rt, X, 1);
			n++;
		}
		if(opt == 2) {
			add(1, tmp, rt, X, -1);
			n--;
		}
		cout << qans() << '\n';
	}
	return 0;
}
