#include<bits/stdc++.h>
using namespace std;
const int Q = 200005;
const long long INF = (1ll << 60);
typedef long long ll;
#define rg register int
#define cint const register int
#define gc getchar
#define pc putchar
inline bool ig(const char c) {
	return c >= 48 && c <= 57;
}
inline void read(rg& oi) {
	char c;
	rg f = 1, res = 0;
	while(c = gc(), (!ig(c)) && c^'-');
	c^'-' ? res = (c ^ 48) : f = -1;
	while(c = gc(), ig(c))res = res * 10 + (c ^ 48);
	oi = f * res;
}
inline void print(rg oi) {
	char io[23];
	rg l = 0;
	if(oi < 0)pc('-'), oi = ~oi + 1;
	do io[++l] = (oi % 10 + 48);
	while(oi /= 10);
	for(; l; --l)pc(io[l]);
}
inline void write(cint oi, const char c) {
	print(oi);
	pc(c);
}
char _ST_;
inline void Max(ll& x, const ll y) {
	(x < y)&& (x = y);
}
int CC, T, n, m, a[Q], b[Q], lp[Q], rp[Q], st[Q], top;
int v[Q], s1[Q], s2[Q], pt[Q], nxt[Q];
ll f[2][Q], s[Q];
bool is[Q];
char _ED_;
int main() {
	freopen("letter/letter6.in","r",stdin);
	read(CC);
	read(T);
	for(; T--;) {
		read(n);
		read(m);
		{
			char c;
			while(c = gc(), c < 'a' || c > 'z');
			a[1] = c - 'a';
		}
		for(rg i = 2; i <= n; ++i)a[i] = gc() - 'a';
		{
			char c;
			while(c = gc(), c < 'a' || c > 'z');
			b[1] = c - 'a';
		}
		for(rg i = 2; i <= m; ++i)b[i] = gc() - 'a';
		for(rg i = 1; i <= n; ++i)read(v[i]);
		for(rg i = 0; i < 26; ++i)lp[i] = rp[i] = 0;
		top = 0;
		for(rg i = 1; i <= m; ++i)rp[b[i]] = i;
		for(rg i = m; i >= 1; --i)lp[b[i]] = i;
		for(rg i = 0; i < 26; ++i)if(lp[i])
				st[++top] = lp[i], st[++top] = rp[i], st[++top] = rp[i] + 1;
		st[++top] = 1;
		st[++top] = m + 1;
		std::sort(st + 1, st + 1 + top);
		top = std::unique(st + 1, st + 1 + top) - st - 1;
		rg sn = 0, sp = 1;//sn 为滚动数组,为nxt ; sp 为 now
		for(rg i = 0; i <= n; ++i)f[sn][i] = 0;
		for(rg T = 1; T < top; ++T) {
			sn ^= 1;
			sp ^= 1;
			for(rg i = 0; i <= n; ++i)f[sn][i] = -INF;
			cint l = st[T], r = st[T + 1] - 1;
			rg t1 = 0, t2 = 0;
			for(rg i = 0; i < 26; ++i)if(rp[i] && lp[i] <= l && r <= rp[i])is[i] = 1;//不能删除
				else is[i] = 0;
			for(rg i = 1; i <= n; ++i){
				if(is[a[i]]){
					s1[++t1] = a[i], pt[t1] = i, s[t1] = s[t1 - 1] + v[i];
					if(T == 1)cerr<<i<<" val "<<s[t1]<<endl;
				}
			}
//			for(int i = 1;i <= t1;i++){
//				cerr<<pt[i]<<" "<<s[i]<<endl;
//			}
//			cerr<<"BR---BR"<<endl;
			for(rg i = l; i <= r; ++i){
				s2[++t2] = b[i];
			}
//			for(int i = 1;i <= t2;i++){
//				cerr<<char(s2[i] + 'a');
//			}
//			cerr<<"#";
//			for(int i = 1;i <= t1;i++){
//				cerr<<char(s1[i] + 'a');
//			}
//			cerr<<endl;
			s2[t2 + 1] = -1;
			nxt[0] = nxt[1] = 0;
			for(rg i = 2, j = 0; i <= t2; ++i) {//KMP过程
				for(; j && s2[j + 1]^s2[i]; j = nxt[j]);
				if(s2[j + 1] == s2[i])++j;
				nxt[i] = j;
			}
			for(rg i = 1, j = 0; i <= t1; ++i) {
				for(; j && s2[j + 1]^s1[i]; j = nxt[j]);
				if(s2[j + 1] == s1[i])++j;
				if(j == t2){
//					cerr<<"trans from "<<i<<" in "<<T<<endl;
//					cerr<<pt[i]<<" <- "<<pt[i - t2 + 1] - 1<<" + "<<s[i] - s[i - t2]<<endl;
					cerr<<"update "<<i<<endl;
					cerr<<f[sp][pt[i - t2 + 1] - 1]<<" + "<<s[i] - s[i - t2]<<endl;
					Max(f[sn][pt[i]], f[sp][pt[i - t2 + 1] - 1] + s[i] - s[i - t2]);
				}
			}
			for(rg i = 1; i <= n; ++i) {
				cint c = a[i];
				
				if(!rp[c]){
					Max(f[sn][i], f[sn][i - 1]);//如果这个字符压根没有出现过那么只能删除
				}
				if(r < lp[c] || l >= rp[c]){
					Max(f[sn][i], f[sn][i - 1]);//如果在第一次之前或者最后一次之后就可以删除
				}
			}
		}
		ll S = 0;
		for(rg i = 1; i <= n; ++i)S += v[i];
		printf("%lld\n", f[sn][n] > 0 ? S - f[sn][n] : -1);
	}
	return 0;
}
