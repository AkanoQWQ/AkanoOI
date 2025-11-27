//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 5e4 + 1018 + 1108;
//const int MAXVAL = 1e5 + 1018 + 1108;
//int n,mxval,ans[MAXN];
//struct Node{
//	int id,h,v;
//}nodes[MAXN];
//using vn = vector<Node>;
//bool operator<(Node na,Node nb){
//	if(na.h != nb.h)return na.h > nb.h;
//	if(na.v != nb.v)return na.v > nb.v;
//	return na.id < nb.id;
//}
//class SegmentTree{
//	private:
//		int val[MAXVAL * 4];
//		bool clear[MAXVAL * 4];
//		inline void PushUp(int p){
//			val[p] = max(val[p*2],val[p*2+1]);
//			return ;
//		}
//		inline void PushDown(int p){
//			if(!clear[p])return ;
//			val[p*2] = val[p*2+1] = 0;
//			clear[p*2] = clear[p*2+1] = true;
//			clear[p] = false;
//			return ;
//		}
//		void Change(int p,int l,int r,int OBJ,int _val){
//			if(l == r){
//				val[p] = max(val[p],_val);
//				return ;
//			}
//			const int mid = (l + r) >> 1;
//			PushDown(p);
//			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
//			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
//			PushUp(p);
//			return ;
//		}
//		int Query(int p,int l,int r,int OBJL,int OBJR){
//			if(OBJL <= l && r <= OBJR){
//				return val[p];
//			}
//			const int mid = (l + r) >> 1;
//			PushDown(p);
//			int ret = 0;
//			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
//			if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
//			return ret;
//		}
//	public:
//		inline void Change(int pos,int _val){
//			Change(1,1,mxval,pos,_val);
//			return ; 
//		}
//		inline int Query(int l,int r){
//			return Query(1,1,mxval,l,r);
//		}
//		inline void Clear(){
//			val[1] = 0;
//			clear[1] = true;
//			return ;
//		}
//}tr;
//vector<int> idx;
//inline void ReadIn(){
//	cin>>n;
//	for(int i = 1;i <= n;i++){
//		cin>>nodes[i].h>>nodes[i].v;
//		nodes[i].id = i;
//		ans[i] = 1;
//		idx.push_back(nodes[i].h),idx.push_back(nodes[i].v);
//	}
//	return ;
//}
//inline void Discretizing(){
//	sort(idx.begin(),idx.end());
//	auto it = unique(idx.begin(),idx.end());
//	idx.erase(it,idx.end());
//	for(int i = 1;i <= n;i++){
//		nodes[i].h = lower_bound(idx.begin(),idx.end(),nodes[i].h) - idx.begin() + 1;
//		nodes[i].v = lower_bound(idx.begin(),idx.end(),nodes[i].v) - idx.begin() + 1;
//	}
//	mxval = lower_bound(idx.begin(),idx.end(),2e9) - idx.begin() + 2;
//	return ;
//}
//vn CDQ(int l,int r){
//	vn ret;
//	if(l == r){
//		ret.push_back(nodes[l]);
//		return ret;
//	}
//	const int mid = (l + r) >> 1;
//	vn ans1 = CDQ(l,mid);
//	vn ans2;
//	for(int i = mid+1;i <= r;i++){
//		ans2.push_back(nodes[i]);
//	}
//	sort(ans2.begin(),ans2.end());
//	merge(ans1.begin(),ans1.end(),ans2.begin(),ans2.end(),back_inserter(ret));
//	auto tail = ans1.begin();
//	tr.Clear();
//	for(auto i : ans2){
//		while(tail != ans1.end() && (*tail).h >= i.h){
//			tr.Change((*tail).v,ans[(*tail).id]);
//			tail++;
//		}
//		ans[i.id] = max(ans[i.id],tr.Query(i.v,mxval)+1);
//	}
//	CDQ(mid+1,r);
//	return ret;
//}
//inline int Solve1(){
//	int ret = 0;
//	CDQ(1,n);
//	for(int i = 1;i <= n;i++){
//		ret = max(ret,ans[i]);
//	}
//	return ret;
//}
//inline void Solve2(){
//	double otp = 0.2;
//	for(int i = 1;i <= n;i++){
//		cout<<otp<<" ";
//	}
//	cout<<endl;
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	ReadIn();
//	Discretizing();
//	cout<<Solve1()<<endl;
//	Solve2();
//	return 0;
//}
