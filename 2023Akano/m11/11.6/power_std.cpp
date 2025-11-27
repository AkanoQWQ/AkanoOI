#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Solve{
	int calc(int n,int m,int i){
		int s=(1+i)*i/2,rr=(m-(i-n));
		int l=(1+n-1)*(n-1)/2+i,r=(i-n+1+i)*n/2;
		int res=max(s-l+(l+1+l+rr)*rr/2,s-r+(r+1+r+rr)*rr/2);
		cerr<<n<<","<<m<<","<<i<<" is "<<s<<","<<l<<","<<r<<","<<rr<<","<<res+1<<endl;
		return res+1;
	}
	int Solve(int n,int m){
		int ans=0;
		
		int l=max(n,m),r=n+m;
		while(r-l+1>=5){
			int len=(r-l+1)/3;
			int lv=calc(n,m,l+len),rv=calc(n,m,r-len);
			if(lv>rv){
				r-=len;
			}
			else{
				l+=len;
			}
		}
		for(int i=l;i<=r;i++)ans=max(ans,calc(n,m,i));
		return ans;
	}
	int T,n,m;
	char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	inline int rd() {
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
		while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
		return x*f;
	}
	
	void main(){
		T=rd();
		T = 2;
		while(T--){
			n=rd(),m=rd();
			
//			int ans=max(Solve(n,m),Solve(m,n);
			int ans=Solve(n,m);
			if(n!=m)ans=max(ans,Solve(m,n));
			cout<<ans<<'\n';
		}
	}
}
signed main(){
	freopen("power/power1.in","r",stdin);
//	freopen("power.out","w",stdout);
	
	Solve::main();
	return 0;
}
