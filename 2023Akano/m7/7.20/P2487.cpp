#include<bits/stdc++.h>
using namespace std;
using pii = pair<long long,double>;
const int MAXN = 5e4 + 1018 + 1108;
const int MAXVAL = 1e5 + 1018 + 1108;
int n,mxval;
pii ans[MAXN];
struct Node{
	int id,h,v;
}nodes[MAXN];
using vn = vector<Node>;
bool operator<(Node na,Node nb){
	if(na.h != nb.h)return na.h > nb.h;
	if(na.v != nb.v)return na.v > nb.v;
	return na.id < nb.id;
}
inline pii Merge(pii pa,pii pb){
	if(pa.first > pb.first){
		return pa;
	}else if(pa.first < pb.first){
		return pb;
	}else{
		return make_pair(pa.first,pa.second + pb.second);
	}
}
class SegmentTree{
	private:
		pii val[MAXVAL * 4];
		bool clear[MAXVAL * 4];
		inline void PushUp(int p){
			val[p] = Merge(val[p*2],val[p*2+1]);
			return ;
		}
		inline void PushDown(int p){
			if(!clear[p])return ;
			val[p*2] = val[p*2+1] = make_pair(0,0);
			clear[p*2] = clear[p*2+1] = true;
			clear[p] = false;
			return ;
		}
		void Change(int p,int l,int r,int OBJ,pii _val){
			if(l == r){
				val[p] = Merge(val[p],_val);
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		pii Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return val[p];
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			pii ret = make_pair(0,0);
			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret = Merge(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
			return ret;
		}
	public:
		inline void Change(int pos,pii _val){
			Change(1,1,mxval,pos,_val);
			return ; 
		}
		inline pii Query(int l,int r){
			return Query(1,1,mxval,l,r);
		}
		inline void Clear(){
			val[1] = make_pair(0,0);
			clear[1] = true;
			return ;
		}
}tr;
vector<int> idx;
inline void ReadIn(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>nodes[i].h>>nodes[i].v;
		nodes[i].id = i;
		ans[i] = make_pair(1,1);
		idx.push_back(nodes[i].h),idx.push_back(nodes[i].v);
	}
	return ;
}
inline void Discretizing(){
	sort(idx.begin(),idx.end());
	auto it = unique(idx.begin(),idx.end());
	idx.erase(it,idx.end());
	for(int i = 1;i <= n;i++){
		nodes[i].h = lower_bound(idx.begin(),idx.end(),nodes[i].h) - idx.begin() + 1;
		nodes[i].v = lower_bound(idx.begin(),idx.end(),nodes[i].v) - idx.begin() + 1;
	}
	mxval = lower_bound(idx.begin(),idx.end(),2e9) - idx.begin();
	return ;
}
vn CDQ(int l,int r){
	vn ret;
	if(l == r){
		ret.push_back(nodes[l]);
		return ret;
	}
	const int mid = (l + r) >> 1;
	vn ans1 = CDQ(l,mid);
	vn ans2;
	for(int i = mid+1;i <= r;i++){
		ans2.push_back(nodes[i]);
	}
	sort(ans2.begin(),ans2.end());
	merge(ans1.begin(),ans1.end(),ans2.begin(),ans2.end(),back_inserter(ret));
	auto tail = ans1.begin();
	tr.Clear();
	for(auto i : ans2){
		while(tail != ans1.end() && (*tail).h >= i.h){
			tr.Change((*tail).v,ans[(*tail).id]);
			tail++;
		}
		auto get = tr.Query(i.v,mxval);
		get.first += 1;
		ans[i.id] = Merge(ans[i.id],get);
	}
	CDQ(mid+1,r);
	return ret;
}
int sv1[MAXN],sv2[MAXN],mans;
double f1[MAXN],f2[MAXN],tot;
inline int Solve1(){
	long long ret = 0,nowans = 0;
	CDQ(1,n);
	for(int i = 1;i <= n;i++){
//		cout<<nodes[i].h<<" "<<nodes[i].v<<endl;
		sv1[i] = ans[i].first;
		f1[i] = ans[i].second;
		ret = max(ret,ans[i].first);
		ans[i] = make_pair(1,1);
	}
	nowans = ret;
//	cout<<"NOWANS "<<nowans<<endl;
	reverse(nodes+1,nodes+n+1);
	for(int i = 1;i <= n;i++){
		nodes[i].h = mxval - nodes[i].h + 1;
		nodes[i].v = mxval - nodes[i].v + 1;
//		cout<<nodes[i].h<<" "<<nodes[i].v<<endl;
	}
	CDQ(1,n);
	for(int i = 1;i <= n;i++){
		sv2[i] = ans[i].first;
		f2[i] = ans[i].second;
		if(sv1[i] == nowans){
			tot += f1[i];
		}
//		cout<<i<<" sv "<<sv1[i]<<" and "<<sv2[i]<< " f "<<f1[i]<<" and "<<f2[i]<<endl;
	}
	mans = nowans;
	return nowans;
}
inline void Solve2(){
	if(tot <= 1e-7){
		cout<<"WWWW"<<endl;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(sv1[i] + sv2[i] - 1 == mans){
			cout<<f1[i] * f2[i] / tot<<" ";
		}else{
			cout<<0<<" ";	
		}
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P2487.in","r",stdin);
	ReadIn();
	Discretizing();
	cout<<Solve1()<<endl;
	Solve2();
	return 0;
}
