#include<bits/stdc++.h>
using namespace std;
template <typename T>inline void re(T &x) {
	x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
	return;
}
template <typename T>void wr(T x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10^'0');
	return;
}
#define int long long
const long mod=1e9+7;
const int N=2e6+5;
int n;
int dep[N];
int inv[N];
int sum[N];
int ans=0;
vector<int>to[N];
void dfs(int x) {
	for(auto v:to[x]) {
		dep[v]=dep[x]+1;
		ans=(ans+sum[dep[v]])%mod;
		dfs(v);
	}
}
signed main() {
	freopen("deconstruct.in","r",stdin);
	freopen("deconstruct.out","w",stdout);
	re(n);
	inv[1]=1;
	sum[1]=1;
	for(int i=2;i<=n;++i) inv[i]=1ll*(mod-(mod/i))*inv[mod%i]%mod,sum[i]=(sum[i-1]+inv[i])%mod;
	dep[1]=0;
	for(int i=2;i<=n;++i) {
		int fa;re(fa);
		to[fa].push_back(i);
	}
	dfs(1);
	wr(ans);
	return 0;
}
