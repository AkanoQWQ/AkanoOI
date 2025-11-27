#include<bits/stdc++.h>
#define ll long long
#define int __int128
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=2000005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int V=1e9;

namespace Solve {
	struct Node {
		int l,r;
		__int128 k,b;
	};
	struct Tag1 {
		__int128 mul,add;
		Tag1 operator + (const Tag1 &rhs) const {
			return {mul*rhs.mul,add*rhs.mul+rhs.add};
		}
	};
	struct Tag2 {
		__int128 mv,av,mul,add;
		Tag2 operator + (const Tag2 &rhs) const {
			return {mv+rhs.mv*mul,av+rhs.av+rhs.mv*add,mul*rhs.mul,add*rhs.mul+rhs.add};
		}
	};
	ll a[maxn];
	ll b[maxn];
	int d[maxn];
	__int128 calc(Node v) {
		return v.k*v.r+v.b;
	}
	void _print(__int128 x) {
		if(!x) {
			return ;
		}
		_print(x/10);
		cout<<(ll)(x%10);
	}
	void print(__int128 x) {
		if(!x) {
			cout<<"0";
		} else {
			_print(x);
		}
	}
	namespace Read {
		char buf[(1<<21)+5],*P,*Q;
#define getchar() (P==Q&&(Q=(P=buf)+fread(buf,1,1<<21,stdin),P==Q)?EOF:*P++)
		ll read() {
			ll x=0;
			char ch=getchar();
			while(ch<'0'||ch>'9') {
				ch=getchar();
			}
			while('0'<=ch&&ch<='9') {
				x=10*x+ch-'0';
				ch=getchar();
			}
			return x;
		}
	}
	using namespace Read;
	void main(int tid) {
		ll n=read(),k=read();
		for(int i=2;i<=n;i++) {
			a[i]=read();
		}
		for(int i=1;i<=k;i++) {
			b[i]=read();
		}
		int sum=0;
		for(int i=1;i<=k;i++) {
			sum+=b[i];
			d[i]=sum;
		}
		sum=0;
		int t=n;
		for(int i=k;i>=1;i--) {
			sum+=b[i];
			d[t--]=sum;
		}
		for(int i=k+1;i<=n-k;i++) {
			d[i]=sum;
		}
		
		
		int rev=0;
		Tag1 t1={1,0};
		Tag2 t2={0,0,1,0};
		deque<Node> q;
		q.push_back({0,V,d[1],0});
		
		auto c1=[&](Node &v,int l,int r) {
			v.l=(l-t1.add)/t1.mul;
			v.r=(r-t1.add)/t1.mul;
			if(rev) {
				swap(v.l,v.r);
			}
		};
		auto c2=[&](Node &v,int k,int b) {
			v.k=(k-t2.add)/t2.mul;
			v.b=b-t2.av-t2.mv*v.k;
		};
		auto trans=[&](Node v,bool f=true) {
			v.l=v.l*t1.mul+t1.add;
			v.r=v.r*t1.mul+t1.add;
			if(rev) {
				swap(v.l,v.r);
			}
			if(f) {
				v.b+=v.k*t2.mv+t2.av;
				v.k=v.k*t2.mul+t2.add;
			}
			return v;
		};
		auto back=[&](bool f=true) {
			if(rev) {
				return trans(q.front(),f);
			}
			return trans(q.back(),f);	
		};
		
		for(int i=2;i<=n;i++) {
			if(a[i]>back().r) {
				Node v;
				c1(v,back().r+1,a[i]);
				c2(v,0,calc(back()));
				if(rev) {
					q.push_front(v);
				} else {
					q.push_back(v);
				}
			} else if(a[i]<back().r) {
				while(q.size()&&back().l>a[i]) {
					if(rev) {
						q.pop_front();
					} else {
						q.pop_back();
					}
				}
				Node v=back(false);
				if(rev) {
					q.pop_front();
				} else {
					q.pop_back();
				}
				c1(v,v.l,a[i]);
				if(rev) {
					q.push_front(v);
				} else {
					q.push_back(v);
				}
			}
			
			rev^=1;
			t1=t1+(Tag1){-1,a[i]};
			t2=t2+(Tag2){a[i],0,-1,d[i]};
			
			while(q.size()) {
				Node v=back();
				if(v.k<0) {
					v=back(false);
					if(rev) {
						q.pop_front();
					} else {
						q.pop_back();
					}
					c1(v,v.l,v.l);
					if(rev) {
						q.push_front(v);
					} else {
						q.push_back(v);
					}
					if(q.size()>1&&calc(trans(rev?q[1]:q[q.size()-2]))>=calc(back())) {
						if(rev) {
							q.pop_front();
						} else {
							q.pop_back();
						}
					} else {
						break;
					}
				} else {
					break;
				}
			}
		}
		
		print(calc(back()));
		cout<<"\n";
	}
}

signed main() {
	freopen("var.in","r",stdin);
	freopen("var.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll tid,T=1;
	tid=Solve::read(),T=Solve::read();
	tid = (tid + 10181108 + 1234) * tid * tid * tid;
	for(int t=1;t<=T;t++) {
		Solve::main(t);
	}
#ifndef ONLINE_JUDGE
	cerr<<"Time: "<<clock()<<"ms\n";
#endif
}
