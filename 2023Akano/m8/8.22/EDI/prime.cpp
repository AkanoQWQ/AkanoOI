#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXVAL = 1e8 + 1018 + 1108;
const int REALV = 5e7;//上界是多少?!!! 
const int MAXN = 2e5 + 1018 + 1108;
namespace Prime{
	bitset<MAXVAL> notp;
	inline void Pre(int mx){
		notp[0] = 1,notp[1] = 1;
		for(int i = 2;i <= mx;i++){
			if(notp[i] == 0){
				for(int j = 2;1ll * i * j <= mx;j++){
					notp[i*j] = true;
				}
			}
		}
		return ;
	}
	inline bool ISP(ll x){
		if(x <= 1)return false;
		if(x <= REALV)return !notp[x];
		for(int i = 2;1ll*i*i <= x;i++){
			if(x % i == 0)return false;
		}
		return true;
	}
}
int n,q;
ll a[MAXN],b[MAXN];
struct Query{
	ll opt,l,r,x,y;
}ask[MAXN];
namespace Subtask1{
	struct Node{
		mutable int l,r;
		mutable ll a,b;
		Node(int _l,int _r,ll _a,ll _b){
			l = _l,r = _r,a = _a,b = _b;
		}
	};
	bool operator<(Node na,Node nb){
		if(na.r != nb.r)return na.r < nb.r;
		if(na.l != nb.l)return na.l < nb.l;
		return na.a < nb.a;
	}
	class ChotollyTree{
		private:
			set<Node> st;
			using itor = set<Node>::iterator;
			inline itor Split(int x){
				itor it = st.lower_bound(Node(0,x,-10000,0));
				if(it == st.end())return it;
				if(x == (*it).l)return it;
				Node nowl = *it,nowr = *it;
				nowl.r = x-1,nowr.l = x;
				st.erase(it);
				st.insert(nowl);
				itor ret = st.insert(nowr).first;
				return ret;
			}
		public:
			inline void Insert(int no,ll a,ll b){
				st.insert(Node(no,no,a,b));
				return ;
			}
			inline void Assign(int l,int r,ll a,ll b){
				itor noder = Split(r+1),nodel = Split(l);
				Node now = Node(l,r,a,b);
				st.erase(nodel,noder);//左闭右开 
				st.insert(now);
				return ;
			}
			inline void Update(int l,int r,ll a,ll b){
				itor noder = Split(r+1),nodel = Split(l);
				for(itor it = nodel;it != noder;it++){
					ll orga = (*it).a,orgb = (*it).b;
					(*it).a = orga * a - orgb * b;
					(*it).b = orga * b + a * orgb; 
				}
				return ;
			}
			inline ll Query(int l,int r){
				itor noder = Split(r+1),nodel = Split(l);
				ll ret = 0;
				for(itor it = nodel;it != noder;it++){
					if((*it).b == 0 && Prime::ISP((*it).a)){
						ret += (*it).r - (*it).l + 1;
					}
				}
				return ret;
			}
	}tr; 
	inline void Solve(){
		for(int i = 1;i <= n;i++){
			tr.Insert(i,a[i],b[i]);
		}	
		for(int i = 1;i <= q;i++){
			if(ask[i].opt == 1){
				tr.Assign(ask[i].l,ask[i].r,ask[i].x,ask[i].y);
			}else if(ask[i].opt == 2){
				tr.Update(ask[i].l,ask[i].r,ask[i].x,ask[i].y);
			}else if(ask[i].opt == 3){
				cout<<tr.Query(ask[i].l,ask[i].r)<<'\n';
			}
		}
		return ;
	}
}
namespace Subtask2{
	struct Complex{
		ll a,b,cnt;
		Complex(){a = b = cnt = 0;}
		Complex(ll _a,ll _b,ll _cnt){
			a = _a,b = _b,cnt = _cnt;	
		}
	};
	Complex operator*(Complex c1,Complex c2){
		if(c1.cnt + c2.cnt > 2)return Complex(0,0,3);//防溢出 
		Complex ret;
		ret.a = c1.a * c2.a - c1.b * c2.b;
		ret.b = c1.a * c2.b + c2.a * c1.b;
		ret.cnt = c1.cnt + c2.cnt;
		return ret;
	}
	Complex arr[MAXN],opt[4];
	struct Node{
		Complex cpx;
		ll ans[4],tag,tot;
	};
	class SegmentTree{
		private:
			Node node[MAXN * 4];
			inline void PushUp(int p){
				for(int i = 0;i < 4;i++){
					node[p].ans[i] = node[p*2].ans[i] + node[p*2+1].ans[i];
				}
				node[p].tot = node[p*2].tot + node[p*2+1].tot;
				return ;
			}
			inline void PushDown(int p){
				if(!node[p].tag)return ;
				ll temp[4];
				for(int son = p*2;son <= p*2+1;son++){
					for(int i = 0;i < 4;i++){
						temp[(i + node[p].tag) % 4] = node[son].ans[i];
					}
					for(int i = 0;i < 4;i++){
						node[son].ans[i] = temp[i];
					}
					node[son].tag = (node[son].tag + node[p].tag) % 4;
				}
				node[p].tag = 0;
				return ;
			}
			inline void Update(int p){
				Complex ret = node[p].cpx * opt[node[p].tag % 4];
				for(int i = 0;i < 4;i++)node[p].ans[i] = 0;
				if(ret.a == 0 && !Prime::notp[abs(ret.b)]){
					node[p].ans[ret.b > 0 ? 1 : 3] = 1;
				}
				if(ret.b == 0 && !Prime::notp[abs(ret.a)]){
					node[p].ans[ret.a > 0 ? 0 : 2] = 1;
				}
				return ;
			}
			void Build(int p,int l,int r){
				if(l == r){
					if(arr[l].a == 0 && arr[l].b == 0){
						node[p].tot = 0;
					}else{
						node[p].tot = 1;
						if(arr[l].a == 0 && abs(arr[l].b) == 1){
							node[p].cpx = Complex(1,0,0);
							node[p].tag = (arr[l].b > 0) ? 1 : 3;
							node[p].tot = 0;
						}else if(arr[l].b == 0 && abs(arr[l].a) == 1){
							node[p].cpx = Complex(1,0,0);
							node[p].tag = (arr[l].a > 0) ? 0 : 2;
						}else{
							node[p].cpx = arr[l];
							node[p].cpx.cnt = 1;//WHY????
							node[p].tag = 0;
						}
					}
					Update(p);
					return ;
				}
				const int mid = (l + r) >> 1;
				Build(p*2,l,mid),Build(p*2+1,mid+1,r);
				PushUp(p);
				return ;
			}
			void Rotate(int p,int l,int r,int OBJL,int OBJR,int d){
				if(OBJL <= l && r <= OBJR){
					node[p].tag = (node[p].tag + d) % 4;
					ll temp[4];
					for(int i = 0;i < 4;i++){
						temp[(i + d) % 4] = node[p].ans[i];
					}
					for(int i = 0;i < 4;i++){
						node[p].ans[i] = temp[i];
					}
					return ;//OK?
				}
				PushDown(p);
				const int mid = (l + r) >> 1;
				if(mid >= OBJL)Rotate(p*2,l,mid,OBJL,OBJR,d);
				if(mid < OBJR)Rotate(p*2+1,mid+1,r,OBJL,OBJR,d);
				PushUp(p);
				return ;
			}
			void Change(int p,int l,int r,int OBJL,int OBJR,Complex _cpx){
				if(!node[p].tot)return ;
				if(l == r){
					node[p].cpx = node[p].cpx * _cpx;
					node[p].tot = (node[p].cpx.cnt <= 2);
					Update(p);
					return ;//OK?
				}
				PushDown(p);
				const int mid = (l + r) >> 1;
				if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_cpx);
				if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_cpx);
				PushUp(p);
				return ;
			}
			void Set(int p,int l,int r,int OBJL,int OBJR,Complex _cpx){
				if(l == r){
					node[p].cpx = _cpx;
					node[p].tot = 1;
					node[p].tag = 0;
					Update(p);
					return ;
				}
				PushDown(p);
				const int mid = (l + r) >> 1;
				if(mid >= OBJL)Set(p*2,l,mid,OBJL,OBJR,_cpx);
				if(mid < OBJR)Set(p*2+1,mid+1,r,OBJL,OBJR,_cpx);
				PushUp(p);
				return ;
			}
			ll Query(int p,int l,int r,int OBJL,int OBJR){
				if(OBJL <= l && r <= OBJR){
					return node[p].ans[0];
				}
				PushDown(p);
				const int mid = (l + r) >> 1;
				ll ret = 0;
				if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
				if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
				return ret;
			}
		public:
			inline void Build(){
				Build(1,1,n);
				return ;
			}
			inline void Rotate(int l,int r,int d){
				Rotate(1,1,n,l,r,d);
				return ;
			}
			inline void Change(int l,int r,Complex _cpx){
				Change(1,1,n,l,r,_cpx);
				return ;
			}
			inline void Set(int l,int r,Complex _cpx){
				Set(1,1,n,l,r,_cpx);
				return ;
			}
			inline ll Query(int l,int r){
				return Query(1,1,n,l,r);
			}
	}tr;
	inline void Solve(){
		opt[0] = Complex(1,0,0),opt[1] = Complex(0,1,0);
		opt[2] = Complex(-1,0,0),opt[3] = Complex(0,-1,0);
		for(int i = 1;i <= n;i++){
			arr[i].a = a[i],arr[i].b = b[i];
		}
		tr.Build();
		for(int i = 1;i <= q;i++){
			if(ask[i].opt == 1){
				tr.Set(ask[i].l,ask[i].r,Complex(ask[i].x,ask[i].y,1));//1 OK?
			}else if(ask[i].opt == 2){
				Complex nowcpx;
				if(ask[i].x == 0 && ask[i].y == 0){
					nowcpx = Complex(ask[i].x,ask[i].y,3);
					tr.Change(ask[i].l,ask[i].r,nowcpx);
				}else if(ask[i].x == 0 && abs(ask[i].y) == 1){
					tr.Rotate(ask[i].l,ask[i].r,(ask[i].y > 0) ? 1 : 3);
				}else if(ask[i].y == 0 && abs(ask[i].x) == 1){
					tr.Rotate(ask[i].l,ask[i].r,(ask[i].x > 0) ? 0 : 2);
				}else{
					nowcpx = Complex(ask[i].x,ask[i].y,1);
					tr.Change(ask[i].l,ask[i].r,nowcpx);
				}
			}else{
				cout<<tr.Query(ask[i].l,ask[i].r)<<'\n';
			}
		}
		return ;
	}
}
int cnt = 0;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	Prime::Pre(REALV);
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}	
	for(int i = 1;i <= q;i++){
		cin>>ask[i].opt;
		if(ask[i].opt == 1){
			cin>>ask[i].l>>ask[i].r>>ask[i].x>>ask[i].y;
			cnt++;
		}else if(ask[i].opt == 2){
			cin>>ask[i].l>>ask[i].r>>ask[i].x>>ask[i].y;
		}else if(ask[i].opt == 3){
			cin>>ask[i].l>>ask[i].r;
		}
	}
	if(cnt >= 1){
		Subtask1::Solve();
	}else{
		Subtask2::Solve();
	}
	return 0;
}
