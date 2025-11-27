#include<iostream>
#include<algorithm>
#define For(i,j,k) for(long long i=j;i<=k;i++)
#define Rof(i,j,k) for(long long i=j;i>=k;i--)
using namespace std;
const long long N=5e5+10,Mod=1e9+7;
long long fac[N],rfac[N],A[N],B[N],num[N<<1],n,c;

long long Pow(long long x,long long e){
	long long ret=1;
	while(e){
		if(e&1){
			ret=ret*x%Mod;
		}
		x=x*x%Mod;
		e>>=1;
	}
	return ret;
}

long long work(long long a,long long b,long long leftA,long long leftB,long long w){
	long long ans=0;
	For(i,0,a){
		long long s=Pow(Pow(w+1,leftA+a-i)-Pow(w,leftA+a-i)+Mod,b);
		s=s*Pow(w+1,leftB*(a-i))%Mod*Pow(w,(b+leftB)*i)%Mod;
		s=s*rfac[i]%Mod*rfac[a-i]%Mod;
		if(i&1){
			ans=(ans-s+Mod)%Mod;
		}
		else{
			ans=(ans+s)%Mod;
		}
	}
	return ans*fac[a]%Mod;
}

int main(){
	scanf("%lld",&n);
	For(i,1,n){
		scanf("%lld",&A[i]),num[++c]=A[i];
	}
	For(i, 1, n){
		scanf("%lld",&B[i]),num[++c]=B[i];
	}
	fac[0]=1;
	For(i,1,n){
		fac[i] =fac[i-1]*i%Mod;
	}
	rfac[n]=Pow(fac[n],Mod-2);
	Rof(i,n,1){
		rfac[i-1]=rfac[i]*i%Mod;
	}
	sort(A+1,A+n+1,[&](long long &a,long long &b) {
		return (a=0)>(b=0);
	});
	sort(B+1,B+n+1,[&](long long &a,long long &b) {
		return (a=0)>(b=0);
	});
	sort(num+1,num+c+1,[&](long long &a,long long &b) {
		return (a=0)>(b=0);
	});
	c=unique(num+1,num+c+1)-num-1;
	long long leftA=0,leftB=0;
	long long ans=1;
	For(i,1,c){
		long long rightA=leftA,rightB=leftB;
		while(rightA<n&&A[rightA+1]==num[i]){
			++rightA;
		}
		while(rightB<n&&B[rightB+1]==num[i]){
			++rightB;
		}
		ans=ans*work(rightA-leftA,rightB-leftB,leftA,leftB,num[i])%Mod;
		if(ans==0)break;
		leftA=rightA,leftB=rightB;
	}
	printf("%lld\n",ans);
	return 0;
}
