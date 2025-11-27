#include<bits/stdc++.h>
using namespace std;
using pii = pair<double,double>;
const int INF = 1e9;
const int MAXN = 2e5 + 1018 + 1108;
istream& operator>>(istream& cin,pii& inp){
	cin>>inp.first>>inp.second;
	return cin;
}
ostream& operator<<(ostream& cout,pii otp){
	cout<<"("<<otp.first<<","<<otp.second<<")";
	return cout;
}
inline double P(double inx){
	return inx * inx;
}
double operator-(const pii& pa,const pii& pb){
	return sqrt(P(pa.first-pb.first) + P(pa.second-pb.second));
}
struct Node{
	pii val;
	int l,r;
	double mn[3],mx[3];
	inline void Update(const Node& upd){
		for(int D = 1;D <= 2;D++){
			mn[D] = min(mn[D],upd.mn[D]);
			mx[D] = max(mx[D],upd.mx[D]);
		}
		return ;
	}
	Node(){val = {0,0},l = r = 0,mn[1] = mn[2] = 1e9,mx[1] = mx[2] = 0;}
	Node(pii inp){val = inp,l = r = 0,mn[1] = mx[1] = inp.first,mn[2] = mx[2] = inp.second;}
};
inline double Minposs(const Node& nd,const pii& inp){
	double D1 = max(0.0,max(nd.mn[1] - inp.first,inp.first - nd.mx[1]));
	double D2 = max(0.0,max(nd.mn[2] - inp.second,inp.second - nd.mx[2]));
	return sqrt(P(D1) + P(D2));
}
int n;
pii p[MAXN];
bool Cmp1(pii p1,pii p2){
	if(p1.first != p2.first)return p1.first < p2.first;
	return p1.second < p2.second;
}
bool Cmp2(pii p1,pii p2){
	if(p1.second != p2.second)return p1.second < p2.second;
	return p1.first < p2.first;
}
class KDTree{
	private:
		pii* arr;
		Node node[MAXN * 2];//?
		int tot,root;
		double nowans;
		inline void PushUp(int p){
			if(node[p].l != 0)node[p].Update(node[node[p].l]);
			if(node[p].r != 0)node[p].Update(node[node[p].r]);
			return ;
		}
		int Build(int l,int r){
			const int p = ++tot;
			const int mid = (l + r) >> 1;
			long long fc1 = 0,fc2 = 0,s1 = 0,s2 = 0;
			for(int i = l;i <= r;i++){
				s1 += arr[i].first;
				s2 += arr[i].second;
			}
			s1 /= (r - l + 1),s2 /= (r - l + 1);
			for(int i = l;i <= r;i++){
				fc1 += P(arr[i].first - s1);
				fc2 += P(arr[i].second - s2);
			}
			if(fc1 > fc2){
				nth_element(arr+l,arr+mid,arr+r,Cmp1);
			}else{
				nth_element(arr+l,arr+mid,arr+r,Cmp2);
			}
			node[p] = Node(arr[mid]);			
			if(mid-1 >= l)node[p].l = Build(l,mid-1);
			if(r >= mid+1)node[p].r = Build(mid+1,r);
			PushUp(p);
			return p;
		}
		double QueryMn(int p,pii& OBJ){
			double ret = OBJ - node[p].val;
			if(ret <= 1e-7)ret = INF;//itself
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
				double valL = Minposs(node[node[p].l],OBJ);
				double valR = Minposs(node[node[p].r],OBJ);
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
	public:
		inline void Build(pii* _arr){
			arr = _arr;
			root = Build(1,n);
			return ;
		}
		inline double QueryMn(pii inp){
			nowans = INF;
			return QueryMn(root,inp);
		}
}KDT;
double mans = INF;
mt19937 rng(time(0));
set<pii> st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>p[i];
		if(st.find(p[i]) != st.end()){
			cout<<"0.0000"<<endl;
			return 0;
		}
		st.insert(p[i]);
	}
	shuffle(p+1,p+n+1,rng);
	KDT.Build(p);
	for(int i = 1;i <= n;i++){
		mans = min(mans,KDT.QueryMn(p[i]));
	}
	cout<<fixed<<setprecision(4)<<mans<<endl;
	return 0;
}
