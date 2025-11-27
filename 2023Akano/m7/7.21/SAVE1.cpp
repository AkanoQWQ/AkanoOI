//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;
//using pii = pair<ll,ll>;
//const ll INF = LLONG_MAX;
//const int MAXN = 4e5 + 1018 + 1108;
//inline ll P(ll inx){
//	return inx * inx;
//}
//inline ll operator-(const pii& pa,const pii& pb){
//	return P(pa.first-pb.first) + P(pa.second-pb.second);
//}
//struct Node{
//	pii val;
//	int l,r;
//	ll mn[3],mx[3];
//	inline void Update(const Node& upd){
//		mn[1] = min(mn[1],upd.mn[1]);
//		mx[1] = max(mx[1],upd.mx[1]);
//		mn[2] = min(mn[2],upd.mn[2]);
//		mx[2] = max(mx[2],upd.mx[2]);
//		return ;
//	}
//	Node(){}
//	Node(pii inp){val = inp,l = r = 0,mn[1] = mx[1] = inp.first,mn[2] = mx[2] = inp.second;}
//};
//inline ll Minposs(const Node& nd,const pii& inp){
//	ll D1 = max(0ll,max(nd.mn[1] - inp.first,inp.first - nd.mx[1]));
//	ll D2 = max(0ll,max(nd.mn[2] - inp.second,inp.second - nd.mx[2]));
//	return P(D1) + P(D2);
//}
//bool Cmp1(pii p1,pii p2){
//	if(p1.first != p2.first)return p1.first < p2.first;
//	return p1.second < p2.second;
//}
//bool Cmp2(pii p1,pii p2){
//	if(p1.second != p2.second)return p1.second < p2.second;
//	return p1.first < p2.first;
//}
//int n;
//pii p[MAXN];
//class KDTree{
//	private:
//		pii* arr;
//		pii OBJ;
//		Node node[MAXN];
//		int tot,root;
//		ll nowans;
//		inline void PushUp(int p){
//			if(node[p].l != 0)node[p].Update(node[node[p].l]);
//			if(node[p].r != 0)node[p].Update(node[node[p].r]);
//			return ;
//		}
//		int Build(int l,int r){
//			const int p = ++tot;
//			const int mid = (l + r) >> 1;
//			ll fc1 = 0,fc2 = 0,s1 = 0,s2 = 0;
//			for(int i = l;i <= r;i++){
//				s1 += arr[i].first;
//				s2 += arr[i].second;
//			}
//			s1 /= (r - l + 1),s2 /= (r - l + 1);
//			for(int i = l;i <= r;i++){
//				fc1 += P(arr[i].first - s1);
//				fc2 += P(arr[i].second - s2);
//			}
//			if(fc1 > fc2){
//				nth_element(arr+l,arr+mid,arr+r,Cmp1);
//			}else{
//				nth_element(arr+l,arr+mid,arr+r,Cmp2);
//			}
//			node[p] = Node(arr[mid]);
//			if(mid-1 >= l)node[p].l = Build(l,mid-1);
//			if(r >= mid+1)node[p].r = Build(mid+1,r);
//			PushUp(p);
//			return p;
//		}
//		ll QueryMn(int p){
//			ll ret = OBJ - node[p].val;
//			if(ret == 0)ret = INF;//itself
//			nowans = min(nowans,ret);
//			if(node[p].l == 0 && node[p].r == 0){
//				return ret;
//			}else if(node[p].l == 0){
//				if(Minposs(node[node[p].r],OBJ) < nowans){
//					ret = min(ret,QueryMn(node[p].r));
//					nowans = min(nowans,ret);
//				}
//			}else if(node[p].r == 0){
//				if(Minposs(node[node[p].l],OBJ) < nowans){
//					ret = min(ret,QueryMn(node[p].l));
//					nowans = min(nowans,ret);
//				}
//			}else{
//				ll valL = Minposs(node[node[p].l],OBJ);
//				ll valR = Minposs(node[node[p].r],OBJ);
//				if(valL > valR){
//					swap(node[p].l,node[p].r);
//					swap(valL,valR);
//				}
//				if(valL < nowans){
//					ret = min(ret,QueryMn(node[p].l));
//					nowans = min(nowans,ret);
//				}
//				if(valR < nowans){
//					ret = min(ret,QueryMn(node[p].r));
//					nowans = min(nowans,ret);
//				}
//			}
//			return ret;
//		}
//	public:
//		inline void Build(pii* _arr){
//			arr = _arr;
//			root = Build(1,n);
//			return ;
//		}
//		inline ll QueryMn(pii inp){
//			OBJ = inp;
//			nowans = INF;
//			return QueryMn(root);
//		}
//}KDT;
//ll mans = LLONG_MAX;
//mt19937 rng(time(0));
//inline ll Read(){
//	ll ret = 0,f = 1;
//	char ch = getchar();
//	while(!isdigit(ch)){
//		if(ch == '-')f = -1;
//		ch = getchar();
//	}
//	while(isdigit(ch)){
//		ret = ret * 10 + ch - '0';
//		ch = getchar();
//	}
//	return ret * f;
//}
//int otp[66];
//inline void Write(ll inx){
//	int len = 0;
//	while(inx){
//		otp[++len] = inx % 10;
//		inx /= 10;
//	}
//	for(int i = len;i >= 1;i--){
//		putchar(otp[i] + '0');
//	}
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	n = Read();
//	for(int i = 1;i <= n;i++){
//		p[i].first = Read();
//		p[i].second = Read();
//	}
//	shuffle(p+1,p+n+1,rng);
//	KDT.Build(p);
//	for(int i = 1;i <= n;i++){
//		mans = min(mans,KDT.QueryMn(p[i]));
//	}
//	Write(mans);
//	return 0;

