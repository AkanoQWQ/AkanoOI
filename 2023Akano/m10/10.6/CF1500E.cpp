#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 4e5 + 1018 + 1108;
//题目本身的信息
int n,q;
//离散化相关
vector<ll> realVal;
int totVal;

//线段树相关
struct Node{
	int tot;//tot表示节点个数,sum表示节点和
	ll sum,pre,suf;
};
class SegmentTree{
private:
	Node node[MAXN * 4];
	inline void PushUp(int p){
		node[p].tot = node[p*2].tot + node[p*2+1].tot;
		node[p].sum = node[p*2].sum + node[p*2+1].sum;
		node[p].pre = node[p*2].pre + node[p*2+1].pre + node[p*2+1].tot * node[p*2].sum;
		node[p].suf = node[p*2].suf + node[p*2+1].suf + node[p*2].tot * node[p*2+1].sum;
		return ;
	}
	void Change(int p,int l,int r,int OBJ,bool _val){
		if(l == r){
			node[p].sum = node[p].pre = node[p].suf = _val * realVal[l];
			node[p].tot = _val;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
		if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
		PushUp(p);
		return ;
	}
	ll GetKth(int p,int l,int r,int k){
		if(l == r)return l;
		const int mid = (l + r) >> 1;
		if(k <= node[p*2].tot){
			return GetKth(p*2,l,mid,k);
		}else{
			return GetKth(p*2+1,mid+1,r,k - node[p*2].tot);
		}
	}
	ll GetPreSum(int p,int l,int r,int k){
		if(l == r){
			return realVal[l];
		}
		const int mid = (l + r) >> 1;
		if(k <= node[p*2].tot){
			return GetPreSum(p*2,l,mid,k);
		}else{
			return node[p*2].sum + GetPreSum(p*2+1,mid+1,r,k - node[p*2].tot);
		}
	}
	ll GetSufSum(int p,int l,int r,int k){
		if(l == r){
			return realVal[l];
		}
		const int mid = (l + r) >> 1;
		if(k <= node[p*2+1].tot){
			return GetSufSum(p*2+1,mid+1,r,k);
		}else{
			return node[p*2+1].sum + GetSufSum(p*2,l,mid,k - node[p*2+1].tot);
		}
	}
	void Get(int p,int l,int r,int OBJL,int OBJR,vector<Node>& vec){
		if(OBJL <= l && r <= OBJR){
			vec.push_back(node[p]);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Get(p*2,l,mid,OBJL,OBJR,vec);
		if(mid < OBJR)Get(p*2+1,mid+1,r,OBJL,OBJR,vec);
		return ;
	}
	ll Query(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			return node[p].sum;
		}
		const int mid = (l + r) >> 1;
		ll ret = 0;
		if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
		return ret;
	}
public:
	inline void Insert(int _val){
		Change(1,1,totVal,_val,true);
		return ;
	}
	inline void Erase(int _val){
		Change(1,1,totVal,_val,false);
		return ;
	}
	inline ll GetKth(int k){
		return GetKth(1,1,totVal,k);
	}
	inline ll GetPreSum(int k){
		return GetPreSum(1,1,totVal,k);
	}
	inline ll GetSufSum(int k){
		return GetSufSum(1,1,totVal,k);
	}
	inline ll QuerySum(int l,int r){
		if(l > r)return 0;
		return Query(1,1,totVal,l,r);
	}
	inline ll QueryPre(int l,int r){
		if(l > r)return 0;
		ll ret = 0,pre = 0;
		vector<Node> vec;
		Get(1,1,totVal,l,r,vec);
		for(auto i : vec){
			ret += i.pre + pre * i.tot;
			pre += i.sum;
		}
		return ret;
	}
	inline ll QuerySuf(int l,int r){
		if(l > r)return 0;
		ll ret = 0,suf = 0;
		vector<Node> vec;
		Get(1,1,totVal,l,r,vec);
		reverse(vec.begin(),vec.end());
		for(auto i : vec){
			ret += i.suf + suf * i.tot;
			suf += i.sum;
		}
		return ret;
	}
	inline int Size(){
		return node[1].tot;
	}
}tr;
inline bool Judge(int x){
	ll val1 = tr.GetPreSum(x+1),val2 = tr.GetSufSum(x);
	return val1 <= val2;
}
inline ll Solve(){
	n = tr.Size();
	if(n == 0)return 0;
	int posL = 0,posR = 0;
	{
		int l = 1,r = n - 1;
		while(l <= r){
			const int mid = (l + r) >> 1;
			if(Judge(mid)){
				posL = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
	}
	{
		int l = 1,r = n - 1;
		while(l <= r){
			const int mid = (l + r) >> 1;
			if(Judge(mid)){
				posR = mid + 1;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
	}
	if(posL <= 0){
		return tr.QuerySuf(1,totVal) - tr.QueryPre(1,totVal);
	}
	ll ret = 0;
	if(posR < n){
		int oppo = n - (posR + 1) + 1;
		ll l = tr.GetKth(posR + 1),r = tr.GetKth(oppo);
		ret += tr.QuerySuf(1,r-1) + (n - posR) * tr.QuerySum(r,totVal);
		ret -= tr.QueryPre(l+1,totVal) + (n - posR) * tr.QuerySum(1,l);
	}
	if(posL > 1){
		int oppo = n - (posL - 1) + 1;
		ll l = tr.GetKth(posL - 1),r = tr.GetKth(oppo);
		ret += tr.QuerySuf(r,totVal);
		ret -= tr.QueryPre(1,l);
	}
	int oppoR = n - posR + 1;
	ret -= tr.QuerySum(1,tr.GetKth(posL));
	ret += tr.QuerySum(tr.GetKth(oppoR),totVal);
	return ret;
}
ll arr[MAXN],opt[MAXN],optX[MAXN];
inline void ReadIn(){
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		realVal.push_back(arr[i]);
	}
	for(int i = 1;i <= q;i++){
		cin>>opt[i]>>optX[i];
		realVal.push_back(optX[i]);
	}
	realVal.push_back(-1e14);//防止有0
	sort(realVal.begin(),realVal.end());
	auto it = unique(realVal.begin(),realVal.end());
	realVal.erase(it,realVal.end());
	totVal = int(realVal.size()) - 1;
	for(int i = 1;i <= n;i++){
		arr[i] = lower_bound(realVal.begin(),realVal.end(),arr[i]) - realVal.begin();
	}
	for(int i = 1;i <= q;i++){
		optX[i] = lower_bound(realVal.begin(),realVal.end(),optX[i]) - realVal.begin();
	}
	for(int i = 1;i <= n;i++){
		tr.Insert(arr[i]);
	}
	return ;
}
inline void MainSolve(){
	cout<<Solve()<<'\n';
	for(int i = 1;i <= q;i++){
		if(opt[i] == 1){
			tr.Insert(optX[i]);
		}else if(opt[i] == 2){
			tr.Erase(optX[i]);
		}
		cout<<Solve()<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	MainSolve();
	return not(Akano loves pure__Elysia);
}
