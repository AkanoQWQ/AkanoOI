#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Solve{
	typedef long long ll;
	class IO {
		char ibuf[1 << 16], obuf[1 << 16], *ipl = ibuf, *ipr = ibuf, *op = obuf;
	public:
		~IO() { write(); }
		void read() { if (ipl == ipr) ipr = (ipl = ibuf) + fread(ibuf, 1, 1 << 15, stdin); }
		void write() { fwrite(obuf, 1, op - obuf, stdout), op = obuf; }
		char getchar() { return (read(), ipl != ipr) ? *ipl++ : EOF; }
		void putchar(char c) { *op++ = c; if (op - obuf > (1 << 15)) write(); }
		template <typename V> IO& operator >> (V& v) {
			int s = 1; char c = getchar(); v = 0;
			for (; !isdigit(c); c = getchar()) if (c == '-') s = -s;
			for (; isdigit(c); c = getchar()) v = (v << 1) + (v << 3) + (c ^ 48);
			return v *= s, *this;
		}
		IO& operator << (char c) { return putchar(c), *this; }
		template <typename V> IO& operator << (V v) {
			if (!v) putchar('0'); if(v < 0) putchar('-'), v = -v;
			char stk[100], *top = stk;
			for (; v; v /= 10) *++top = v % 10 + '0';
			while (top != stk) putchar(*top--); return *this;
		}
	}io;
	
	const int N=500010;
	int n,m,T;
	int a[N];
	
	struct SegmentTree{
		struct Node{
			int l,r;
			int sum,mx,x,dlt;
			
			int rv,rp;
			int lv,lp;
		}tr[N<<2];
		void cover(int p,int d){
			tr[p].dlt+=d;
			tr[p].mx+=d;
			tr[p].sum+=(tr[p].r-tr[p].l+1)*d;
			
			if(tr[p].rp){
				tr[p].rv+=(tr[p].rp-tr[p<<1].x)*d;
			}
			if(tr[p].lp){
				tr[p].lv+=(tr[p<<1|1].x-tr[p].lp)*d;
			}
		}
		void pushdown(int p){
			if(tr[p].dlt){
				cover(p<<1,tr[p].dlt);
				cover(p<<1|1,tr[p].dlt);
				tr[p].dlt=0;
			}
		}
		int pos;
		int calcL(int p,int mx,int x){
			//>
			if(mx>=tr[p].mx)return 0;
			if(tr[p].l==tr[p].r)return pos=tr[p].l,(tr[p].l-x)*mx;
			pushdown(p);
			if(mx<tr[p<<1].mx){
				int res=calcL(p<<1,mx,x)+tr[p].rv;
				if(tr[p].rp)pos=tr[p].rp;
				return res;
			}
			else{
				return calcL(p<<1|1,mx,x);
			}
		}
		int calcR(int p,int mx,int x){
			//>=
			if(mx>tr[p].mx)return 0;
			if(tr[p].l==tr[p].r)return pos=tr[p].l,(x-tr[p].l)*mx;
			pushdown(p);
			if(mx<=tr[p<<1|1].mx){
				int res=calcR(p<<1|1,mx,x)+tr[p].lv;
				if(tr[p].lp)pos=tr[p].lp;
				return res;
			}
			else{
				return calcR(p<<1,mx,x);
			}
		}
		void pushup(int p){
			tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
			if(tr[p<<1].mx==tr[p].mx)tr[p].x=tr[p<<1].x;
			else tr[p].x=tr[p<<1|1].x;
			
			tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
			
			pos=0;
			tr[p].rv=calcL(p<<1|1,tr[p<<1].mx,tr[p<<1].x);
			tr[p].rp=pos;
			pos=0;
			tr[p].lv=calcR(p<<1,tr[p<<1|1].mx,tr[p<<1|1].x);
			tr[p].lp=pos;
		}
		void build(int p,int l,int r){
			tr[p].l=l,tr[p].r=r;
			if(l==r){
				tr[p].sum=a[l];
				tr[p].mx=a[l];
				tr[p].x=l;
				return;
			}
			int mid=(l+r)>>1;
			build(p<<1,l,mid),build(p<<1|1,mid+1,r);
			pushup(p);
		}
		void change(int p,int l,int r,int x){
			if(l<=tr[p].l&&tr[p].r<=r){
				cover(p,x);
				return;
			}
			pushdown(p);
			if(l<=tr[p<<1].r)change(p<<1,l,r,x);
			if(r>=tr[p<<1|1].l)change(p<<1|1,l,r,x);
			pushup(p);
		}
		int QL(int p,int l,int r,int&mx,int&x){
			if(l<=tr[p].l&&tr[p].r<=r){
				if(tr[p].mx>mx){
					int res=calcL(p,mx,x);
					mx=tr[p].mx;
					x=tr[p].x;
					return res;
				}
				return 0;
			}
			pushdown(p);
			int res=0;
			if(l<=tr[p<<1].r)res=QL(p<<1,l,r,mx,x);
			if(r>=tr[p<<1|1].l)res+=QL(p<<1|1,l,r,mx,x);
			return res;
		}
		int QR(int p,int l,int r,int&mx,int&x){
			if(l<=tr[p].l&&tr[p].r<=r){
				if(tr[p].mx>=mx){
					int res=calcR(p,mx,x);
					mx=tr[p].mx;
					x=tr[p].x;
					return res;
				}
				return 0;
			}
			pushdown(p);
			int res=0;
			if(r>=tr[p<<1|1].l)res=QR(p<<1|1,l,r,mx,x);
			if(l<=tr[p<<1].r)res+=QR(p<<1,l,r,mx,x);
			return res;
		}
		void Qmx(int p,int l,int r,int&mx,int&x){
			if(l<=tr[p].l&&tr[p].r<=r){
				if(tr[p].mx>mx){
					mx=tr[p].mx;
					x=tr[p].x;
				}
				return;
			}
			pushdown(p);
			if(l<=tr[p<<1].r)Qmx(p<<1,l,r,mx,x);
			if(r>=tr[p<<1|1].l)Qmx(p<<1|1,l,r,mx,x);
		}
		int Qsum(int p,int l,int r){
			if(l<=tr[p].l&&tr[p].r<=r)return tr[p].sum;
			pushdown(p);
			int res=0;
			if(l<=tr[p<<1].r)res=Qsum(p<<1,l,r);
			if(r>=tr[p<<1|1].l)res+=Qsum(p<<1|1,l,r);
			return res;
		}
	}seg;
	void main(){
		int id;cin>>id;
		cin>>n>>m>>T;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		seg.build(1,1,n);
		
		int lst=0;
		while(m--){
			int op,l,r;cin>>op>>l>>r;
			l^=(T*lst),r^=(T*lst);
			if(op==1){
				int x;cin>>x;
				seg.change(1,l,r,x);
			}
			else{
				int mx=-1e10,x=0;
				seg.Qmx(1,l,r,mx,x);
				int Mx=mx,X=x;
				
				int sum=seg.Qsum(1,l,r);
				
				int resL=0;
				if(l<X){
					mx=seg.Qsum(1,l,l),x=l;
					resL=seg.QL(1,l+1,X,mx,x);
				}
				int resR=0;
				if(X<r){
					mx=seg.Qsum(1,r,r),x=r;
					resR=seg.QR(1,X,r-1,mx,x);
				}
				int ans=resL+resR+Mx-sum;
				cout<<ans<<'\n';
				
				lst=ans;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("rprfq.in","r",stdin);
	freopen("rprfq.out","w",stdout);
	
	Solve::main();
	
	return 0;
}
