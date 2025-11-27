#include<iostream>
#include<cstring>
using namespace std;
const int mod=998244353,N=2e7+5,K=105;

template <typename T>inline void re(T &x){
	x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	x*=f;
	return;
}

template <typename T>void wr(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10^'0');
	return;
}

inline int qpow(int x,int y){
	int ret=1;
	while(y) {
		if(y&1){
			ret=1ll*ret*x%mod;
		}
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

struct Matrix{
	int a[105][105];
	int n,m;
	inline void clear(){
		memset(a,0,sizeof(a));
	}
	inline void one(int x){
		n=m=x;
		clear();
		for(int i=0;i<n;i++){
			a[i][i]=1;
		}
		return;
	}
}A;

inline Matrix operator*(Matrix a,Matrix b) {
	Matrix ret;
	ret.n=a.n;
	ret.m=b.m;
	ret.clear();
	for(int i=0;i<a.n;++i) {
		for(int k=0;k<a.m;++k) {
			for(int j=0;j<b.m;++j) {
				ret.a[i][j]=(ret.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%mod;
			}
		}
	}
	return ret;
}

int n,k,dp[N],p[K],mul[K];

inline Matrix qpow(Matrix x,int y) {
	Matrix ret;
	ret.one(k+1);
	while(y) {
		if(y&1){
			ret=ret*x;
		}
		x=x*x;
		y>>=1;
	}
	return ret;
}

signed main() {
	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	re(n),re(k);
	for(int i=0;i<k;i++){
		int a,b;
		re(a),re(b);
		p[i]=1ll*a*qpow(b,mod-2)%mod;
	}
	p[k]=1;
	mul[0]=1+mod-p[0];
	mul[0]%=mod;
	for(int i=1;i<=k;i++){
		mul[i]=1ll*mul[i-1]*(1+mod-p[i])%mod;
		p[i]=1ll*mul[i-1]*p[i]%mod;
	}
	A.n=A.m=k+2;
	for(int i=0;i<A.m-1;++i){
		A.a[0][i]=p[i];
	}
	for(int i=1;i<A.n-1;++i){
		A.a[i][i-1]=1;
	}
	A.a[0][k+1]=1;
	A.a[k+1][k+1]=1;
	Matrix ans=qpow(A,n);
	wr((ans.a[0][0]+ans.a[0][k+1]-1)%mod);
	return 0;
}
