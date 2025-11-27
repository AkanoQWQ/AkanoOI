#include<iostream>
#include<vector>
using namespace std;
const long long N=2e6+5,mod=1e9+7;

template <typename T>inline void read(T &x) {
	x=0;
	long long f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
	return;
}

template <typename T>void write(T x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^'0');
	return;
}

long long n,dep[N],sum[N],inv[N],ans=0;
vector<long long> to[N];

void dfs(long long x){
	for(auto v:to[x]){
		dep[v]=dep[x]+1;
		ans=(ans+sum[dep[v]])%mod;
		dfs(v);
	}
}

signed main() {
	freopen("deconstruct.in","r",stdin);
	freopen("deconstruct.out","w",stdout);
	read(n);
	inv[1]=1;
	sum[1]=1;
	for(long long i=2;i<=n;i++){
		inv[i]=1ll*(mod-(mod/i))*inv[mod%i]%mod,sum[i]=(sum[i-1]+inv[i])%mod;
	}
	dep[1]=0;
	for(long long i=2;i<=n;i++){
		long long fa;
		read(fa);
		to[fa].push_back(i);
	}
	dfs(1);
	write(ans);
	return 0;
}
