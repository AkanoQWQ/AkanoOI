#include<iostream>
using namespace std;
const int mod=1e9+7,N=3.7e7+5;

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

inline int ADD(int x,int y) {
	if(x+y>=mod) return x+y-mod;
	return x+y;
}

int t,n,a[N],pre[N],la[N],pos[300005],mex=0;
bool vis[300005];

signed main() {
	freopen("clods.in","r",stdin);
	freopen("clods.out","w",stdout);
	re(t);
	while(t--) {
		for(int i=0;i<=n;i++){
			vis[i]=pre[i]=la[i]=0;
		}
		for(int i=0;i<mex;++i){
			pos[i]=0;
		}
		re(n);
		if(n==37000000){
			a[1]=0;
			vis[0]=1;
			int x,y;
			re(x),re(y);
			for(int i=2;i<=n;i++){
				a[i]=((long long)a[i-1]*x+y+i)&262143ll,vis[a[i]]=1;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				re(a[i]),vis[a[i]]=1;
			}
		}
		mex=0;
		while(vis[mex]){
			++mex;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>mex){
				continue;
			}
			pre[i]=pos[a[i]];
			pos[a[i]]=i;
		}
		int p=n;
		for(int i=0;i<mex;i++){
			p=min(p,pos[i]);
		}
		for(int i=n;i>=1;i--){
			p=min(p,i);
			la[i]=p;
			if(a[i]<mex){
				p=min(p,pre[i]);
			}
		}
		pre[0]=1;
		for(int i=1;i<=n;i++){
			if(la[i]){
				pre[i]=pre[la[i]-1];
			}
			else{
				pre[i]=0;
			}
			pre[i]=ADD(pre[i],pre[i-1]);
		}
		wr((pre[n]-pre[n-1]+mod)%mod);
		putchar('\n');
	}
	return 0;
}
