#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 5;
struct node {
	int l, r;
	int val, size, tag;
	unsigned long long key;
} fhq[maxn];
int cnt, root;
unsigned long long seed = 1;
int x, y, z, p, q;
int newnode(int val) {
	fhq[++cnt] = (node) {
		0, 0, val, 1, 0, seed *= 20070509
	};
	return cnt;
}
void put(int x, int v) {
	if(!x)return;
	fhq[x].val += v, fhq[x].tag += v;
	return;
}
void pushdown(int x) {
	if(fhq[x].tag)put(fhq[x].l, fhq[x].tag), put(fhq[x].r, fhq[x].tag), fhq[x].tag = 0;
	return;
}
void update(int now) {
	fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
	return;
}
void vsplit(int now, int val, int& x, int& y) {
	if(!now)x = y = 0;
	else {
		pushdown(now);
		if(fhq[now].val <= val)x = now, vsplit(fhq[now].r, val, fhq[now].r, y);
		else y = now, vsplit(fhq[now].l, val, x, fhq[now].l);
		update(now);
	}
	return;
}
void ssplit(int now, int size, int& x, int& y) {
	if(!now)x = y = 0;
	else {
		pushdown(now);
		if(fhq[fhq[now].l].size + 1 > size)y = now, ssplit(fhq[now].l, size, x, fhq[now].l);
		else x = now, ssplit(fhq[now].r, size - fhq[fhq[now].l].size - 1, fhq[now].r, y);
		update(now);
	}
	return;
}
int merge(int x, int y) {
	if(!x || !y)return x + y;
	pushdown(x), pushdown(y);
	if(fhq[x].key > fhq[y].key) {
		fhq[x].r = merge(fhq[x].r, y);
		update(x);
		return x;
	} else {
		fhq[y].l = merge(x, fhq[y].l);
		update(y);
		return y;
	}
}
int gmx(int x) {
	while(fhq[x].r)pushdown(x), x = fhq[x].r;
	return fhq[x].val;
}
int n;
signed main() {
	freopen("match/match2.in", "r", stdin);
//	freopen("match.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int amx = gmx(root), nv = -1;
		cerr<<"getmax "<<amx<<endl;
		if(amx < r)nv = std::max(amx + 1, l);
		vsplit(root, l - 1, x, y), vsplit(y, r - 1, y, z);
		ssplit(z, 1, p, z);
		int mx = std::max(l - 1, gmx(x));
		if(nv == -1){
			cerr<<"nv "<<0<<endl;
		}else{
			cerr<<"nv "<<nv<<endl;
		}
		cerr<<"lastPre "<<mx<<endl;
//		cerr<<"vals "<<x<<","<<y<<","<<p<<","<<z<<endl;
//		cerr<<"size "<<fhq[x].size<<","<<fhq[y].size<<","<<fhq[p].size<<","<<fhq[z].size<<endl;
		if(y || p) {
			//在l的值前面插入mx(最小也为l-1,在加一后就是l),并令这些值加一
			y = merge(newnode(mx), y), put(y, 1);
//			cerr<<"successful Shift becuase "<<bool(y)<<" and "<<bool(p)<<endl;
			if(!p) { //删除末尾值
//				cerr<<"Delete end "<<fhq[y].size - 1<<endl;
				ssplit(y, fhq[y].size - 1, y, q);
			}
		}
		//组装剩下的部分
		root = merge(x, merge(y, z));
		if(nv != -1) { //插入nv值
			cerr<<"insert "<<nv<<endl;
			root = merge(root, newnode(nv));
		}
		cerr<<"end root "<<root<<" size "<<fhq[root].size<<endl;
	}
	printf("%d", fhq[root].size);
	return 0;
}
