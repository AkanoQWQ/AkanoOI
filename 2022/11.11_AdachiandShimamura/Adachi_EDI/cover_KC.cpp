#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return ;
}
int qpow(int x,int up){
	int result=1;
	for(;up;up>>=1){
		if(up&1) result=(long long)result*x%mod;
		x=(long long)x*x%mod;
	}
	return result;
}
struct point{
	int h;
	int l;
}a[2005][2005];
int n,m,ans=0;
char mmap[2005][2005],c,_[2006];
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n=read();
	m=read();	
	_[0] = 1;
	for(int i = 1;i <= 2001;++i){
		_[i] = (_[i-1] * 2) % mod;
	}
	for(int i=1;i<=n;i++){
		c=getchar();
		while(c!='#'&&c!='.') c=getchar();
		mmap[i][1]=c;
		for(int j=2;j<=m;j++){
			mmap[i][j]=getchar();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j].h==0){
				bool flag1=0;
				int pos1=m;
				for(int k=j;k<=m;++k){
					if(mmap[i][k]=='#'){
						flag1=1;
						pos1=k;
						break;
					}
				}
				if(flag1==1){
					a[i][j].h=pos1-j;
				}
				else{
					a[i][j].h=pos1-j+1;
				}
				if(flag1==1){
					for(int k=j;k<pos1;k++){
						a[i][k].h=a[i][j].h;
					}
				}
				else{
					for(int k=j;k<=pos1;k++){
						a[i][k].h=a[i][j].h;
					}
				}
			}
			if(a[i][j].l==0){
				bool flag2=0;
				int pos2=n;
				for(int k=i;k<=n;k++){
					if(mmap[k][j]=='#'){
						flag2=1;
						pos2=k;
						break;
					}
				}
				if(flag2==1){
					a[i][j].l=pos2-i;
				}
				else{
					a[i][j].l=pos2-i+1;
				}
				if(flag2==1){
					for(int k=i;k<pos2;k++){
						a[k][j].l=a[i][j].l;
					}
				}
				else{
					for(int k=i;k<=pos2;k++){
						a[k][j].l=a[i][j].l;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j].h+a[i][j].l!=0){
				int tt=a[i][j].h+a[i][j].l-1;
				ans=(ans+(long long)(_[tt]-1)*qpow(_[tt],mod-2))%mod;
			}
		}
	}
	write(ans);
	return 0;
}

