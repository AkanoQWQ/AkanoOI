#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1e5 + 6;
const int INF = INT_MAX;
istream& operator>>(istream& cin,pii& inp){
	cin>>inp.first>>inp.second;
	return cin;
}
ostream& operator<<(ostream& cout,pii otp){
	cout<<"("<<otp.first<<","<<otp.second<<")";
	return cout;
}
int operator-(const pii& pa,const pii& pb){
	return abs(pa.first-pb.first) + abs(pa.second-pb.second);
}
struct Node{
	pii val;
	int l,r;
	int mn[3],mx[3];
	inline void Update(const Node& upd){
		for(int D = 1;D <= 2;D++){
			mn[D] = min(mn[D],upd.mn[D]);
			mx[D] = max(mx[D],upd.mx[D]);
		}
		return ;
	}
	Node(){val = {0,0},l = r = 0,mn[1] = mn[2] = mx[1] = mx[2] = 0;}
	Node(pii inp){val = inp,l = r = 0,mn[1] = mx[1] = inp.first,mn[2] = mx[2] = inp.second;}
};
inline int Minposs(const Node& nd,const pii& inp){
	int D1 = max(0,max(nd.mn[1] - inp.first,inp.first - nd.mx[1]));
	int D2 = max(0,max(nd.mn[2] - inp.second,inp.second - nd.mx[2]));
	return D1 + D2;
}
inline int Maxposs(const Node& nd,const pii& inp){
	int D1 = max(0,max(inp.first - nd.mn[1],nd.mx[1] - inp.first));
	int D2 = max(0,max(inp.second - nd.mn[2],nd.mx[2] - inp.second));
	return D1 + D2;
}
int n,ans = INF;
bool Cmp1(pii p1,pii p2){
	if(p1.first != p2.first)return p1.first < p2.first;
	return p1.second < p2.second;
}
bool Cmp2(pii p1,pii p2){
	if(p1.second != p2.second)return p1.second < p2.second;
	return p1.first < p2.first;
}
bool (*cmps[2])(pii,pii) = {Cmp1,Cmp2};
class KDTree{
	private:
		pii* arr;
		Node node[MAXN * 2];
		int tot,root;
		int nowans;
		inline void PushUp(int p){
			if(node[p].l != 0)node[p].Update(node[node[p].l]);
			if(node[p].r != 0)node[p].Update(node[node[p].r]);
			return ;
		}
		int Build(int l,int r,bool W){
			const int p = ++tot;
			const int mid = (l + r) >> 1;
			nth_element(arr+l,arr+mid,arr+r,cmps[W]);//cmp by first
			node[p] = Node(arr[mid]);
			if(mid-1 >= l)node[p].l = Build(l,mid-1,!W);
			if(r >= mid+1)node[p].r = Build(mid+1,r,!W);
			PushUp(p);
			return p;
		}
		int QueryMn(int p,pii& OBJ){
			int ret = OBJ - node[p].val;
			if(ret == 0)ret = INF;
			nowans = min(nowans,ret);
			if(node[p].l == 0 && node[p].r == 0){
				return ret;
			}else if(node[p].l == 0){
				if(Minposs(node[node[p].r],OBJ) < nowans){
					ret = min(ret,QueryMn(node[p].r,OBJ));
					nowans = min(nowans,ret);
				}
			}else if(node[p].r == 0){
				if(Minposs(node[node[p].l],OBJ) < nowans){
					ret = min(ret,QueryMn(node[p].l,OBJ));
					nowans = min(nowans,ret);
				}
			}else{
				int valL = Minposs(node[node[p].l],OBJ);
				int valR = Minposs(node[node[p].r],OBJ);
				if(valL > valR){
					swap(node[p].l,node[p].r);
					swap(valL,valR);
				}
				if(valL < nowans){
					ret = min(ret,QueryMn(node[p].l,OBJ));
					nowans = min(nowans,ret);
				}
				if(valR < nowans){
					ret = min(ret,QueryMn(node[p].r,OBJ));
					nowans = min(nowans,ret);
				}
			}
			return ret;
		}
		int QueryMx(int p,pii& OBJ){
			int ret = OBJ - node[p].val;
			nowans = max(nowans,ret);
			if(node[p].l == 0 && node[p].r == 0){
				return ret;
			}else if(node[p].l == 0){
				if(Maxposs(node[node[p].r],OBJ) > nowans){
					ret = max(ret,QueryMx(node[p].r,OBJ));
					nowans = max(nowans,ret);
				}
			}else if(node[p].r == 0){
				if(Maxposs(node[node[p].l],OBJ) > nowans){
					ret = max(ret,QueryMx(node[p].l,OBJ));
					nowans = max(nowans,ret);
				}
			}else{
				int valL = Maxposs(node[node[p].l],OBJ);
				int valR = Maxposs(node[node[p].r],OBJ);
				if(valL > valR){
					swap(node[p].l,node[p].r);
					swap(valL,valR);
				}
				if(valL > nowans){
					ret = max(ret,QueryMx(node[p].l,OBJ));
					nowans = max(nowans,ret);
				}
				if(valR > nowans){
					ret = max(ret,QueryMx(node[p].r,OBJ));
					nowans = max(nowans,ret);
				}
			}
			return ret;
		}
	public:
		inline void Build(pii* _arr){
			arr = _arr;
			root = Build(1,n,true);
			return ;
		}
		inline int Query(pii inp){
			int _mx = 0,_mn = INF;
			nowans = 0;
			_mx = QueryMx(root,inp);
			nowans = INF;
			_mn = QueryMn(root,inp);
			return _mx - _mn;
		}
}KDT;
pii p[MAXN];
mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>p[i];
	shuffle(p+1,p+n+1,rng);
	shuffle(p+1,p+n+1,rng);
	KDT.Build(p);
	for(int i = 1;i <= n;i++){
		ans = min(ans,KDT.Query(p[i]));
	}
	cout<<ans<<endl;
	return 0;
}
