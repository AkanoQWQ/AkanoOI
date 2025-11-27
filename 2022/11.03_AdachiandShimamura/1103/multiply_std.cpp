#include<bits/stdc++.h>
using namespace std;
template <typename T>inline void re(T &x) {
	int f=1;
	x=0;
	char c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
	return;
}
template <typename T>void wr(T x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
	return;
}
int T,n;
int a[1005];
int b[1005];
const int prime[15]= {2,3,5,7,11,13,17,19,23,29,31};
const int N=11;
int f[1005][1<<11];
bool vis[1005];
vector<int>t[1001];
const int maxn=(1<<11)-1;
signed main() {
	freopen("multiply.in","r",stdin);
	freopen("multiply.ans","w",stdout);
	re(T);
	while(T--) {
		for(register int i=1; i<=1000; ++i) if(t[i].size()) t[i].clear();
		memset(vis,0,sizeof vis);
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		re(n);
		for(register int i=1; i<=n; ++i) re(a[i]);
		for(register int i=1; i<=n; ++i) {
			for(register int j=0; j<N; ++j) {
				if(a[i]%prime[j]==0) b[i]|=(1<<j);
				while(a[i]%prime[j]==0) a[i]/=prime[j];
			}
			if(a[i]!=1) vis[i]=1,t[a[i]].push_back(i);
		}
		register int now=0;
		for(register int i=1; i<=n; ++i) {
			if(vis[i]) continue;
			++now;
			memcpy(f[now],f[now-1],sizeof f[now]);
			for(register int S=(~b[i])&maxn,s=S; s; s=(s-1)&S) {
				f[now][s|b[i]]=max(f[now][s|b[i]],f[now-1][s]+1);
			}
			f[now][b[i]]=max(f[now][b[i]],f[now-1][0]+1);
		}
		for(register int i=1; i<=1000; ++i) {
			if(!t[i].size()) continue;
			++now;
			memcpy(f[now],f[now-1],sizeof f[now]);
			for(register int k=0; k<t[i].size(); ++k) {
				register int v=t[i][k];
				for(register int S=(~b[v])&maxn,s=S; s; s=(s-1)&S) {
					f[now][s|b[v]]=max(f[now][s|b[v]],f[now-1][s]+1);
				}
				f[now][b[v]]=max(f[now][b[v]],f[now-1][0]+1);
			}
		}
		register int ans=0;
		for(register int j=0; j<=now; ++j) {
			for(register int i=0; i<=maxn; ++i) {
				ans=max(ans,f[j][i]);
			}
		}
		wr(ans);
		putchar('\n');
	}
	return 0;
}
/*
3
5
6 7 8 9 10
4
699 932 233 466
5
74 52 8 39 37

1
3
5 15 3

1
3
2 6 3
*/
