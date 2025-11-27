#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=401;
const int logn=21;
const int inf=0x3f3f3f3f3f3f3f3f;

namespace Solve {
	struct Node {
		int a,b,c,v;
	} a[maxn];
	int n;
	int f[maxn][maxn][maxn];
	int g[maxn][maxn];
	int sb[maxn];
	int sc[maxn];
	void clear() {
		
	}
	void ckmax(int &x,int y) {
		x=max(x,y);
	}
	void main(int tid) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i].a>>a[i].b>>a[i].c>>a[i].v;
		}
		sort(a+1,a+n+1,[&](Node a,Node b) {
			return a.v==b.v?a.a<b.a:a.v<b.v;
		});
		for(int i=1;i<=n;i++) {
			sb[i]=sb[i-1]+a[i].b;
			sc[i]=sc[i-1]+a[i].c;
		}
		memset(f,-0x3f,sizeof(f));
		f[0][0][0]=0;
		for(int l=1;l<=n;l++) {
			int r=l;
			while(r<=n&&a[l].v==a[r].v) {
				r++;
			}
			r--;
			cerr<<l<<" to "<<r<<endl;
			for(int i=l-1;i<=r;i++) {
				memset(g[i],-0x3f,sizeof(g[i]));
			}
			g[l-1][0]=0;
			for(int i=l;i<=r;i++) {
				for(int j=0;j<=n;j++) {
					ckmax(g[i][j],g[i-1][j]+a[i].b);
					ckmax(g[i][j+1],g[i-1][j]+a[i].c);
				}
			}
			int s=r-l+1;
			cerr<<"now "<<l<<" to "<<r<<endl;
			for(int p=0;p<=n;p++) {//选了p个大的
				for(int q=0;q<=n;q++) {//后面最多选q个大的
					if(f[l-1][p][q]>=0)cerr<<l-1<<","<<p<<","<<q<<" is "<<f[l-1][p][q]<<endl;
					if(f[l-1][p][q]<0) {
						continue;
					}
					if(p+s-1>=a[r].a){
						ckmax(//泉部选大的
							f[r][p][max(q-s,0ll)],
							f[l-1][p][q]+sb[r]-sb[l-1]
						);
						for(int i=r-1;i>=l;i--) {
							for(int c=0;c<=i-l;c++) { 
								int real=c+1;
								ckmax(
									f[r][p+real][max(max(q-(s-real),a[i].a-s+1),0ll)],
									f[l-1][p][q]+ sb[r]-sb[i] + a[i].c+g[i-1][c] 
								);

							}
						}
					}
					ckmax(
						f[r][p+s][max(q,a[r].a-s+1)],
						f[l-1][p][q]+sc[r]-sc[l-1]
					);
					
					for(int i=r-1;i>=l;i--) {
						if(p+s-1>=a[i].a) {
							for(int c=0;c<=s;c++) {
								int real=r-i+c;	
								if(p == 1 && q == 4 && i == l && c == 1){
									cerr<<"got "<<real<<endl;
								}
								ckmax(
									f[r][p+real][max({q-(s-real),a[r].a-s+1,0ll})],
									f[l-1][p][q]+sc[r]-sc[i]+g[i][c]
								);
								if(f[l-1][p][q]+sc[r]-sc[i]+g[i][c] == f[34][17][17]){
									cerr<<p<<","<<q<<","<<i<<","<<c<<endl;
									cerr<<f[l-1][p][q]<<" + "<<sc[r]-sc[i]<<" + "<<g[i][c]<<endl;
									cerr<<"here"<<endl;
								}
							}
							break;
						}
					}
				}
			}
			l=r;
		}
		int ans=-inf;
		for(int i=0;i<=n;i++) {
			ckmax(ans,f[n][i][0]);
		}
		if(ans<0) {
			cout<<"explode\n";
		} else {
			cout<<ans<<"\n";
		}
	}
	void init() {
		
	}
}

signed main() {
	freopen("fly/ex_fly5.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int id,T=1;
	cin>>id>>T;
	T = 1;
	Solve::init();
	for(int t=1;t<=T;t++) {
		Solve::main(t);
		Solve::clear();
	}
}
