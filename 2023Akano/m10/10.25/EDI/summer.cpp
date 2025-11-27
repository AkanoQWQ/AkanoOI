#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108;
int n,k,a[MAXN],q;
ll farL[MAXN],farR[MAXN],f[MAXN];
ll F(int x){
	if(f[x] != -2)return f[x];
	if(a[farL[x]] < a[farR[x]]){
		f[x] = F(farL[x]) + 1;
	}else if(a[farL[x]] > a[farR[x]]){
		f[x] = F(farR[x]) + 1;
	}else{
		f[x] = F(farR[x]) + 1;
	}
	return f[x];
}
inline void Solve(){
	a[0] = a[n+1] = INF;
	stack<int> stk;
	for(int i = 1;i <= n;i++){
		while(!stk.empty() && a[stk.top()] < a[i]){
			farR[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		farR[stk.top()] = n + 1;
		stk.pop();
	}
	for(int i = n;i >= 1;i--){
		while(!stk.empty() && a[stk.top()] < a[i]){
			farL[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		farL[stk.top()] = 0;
		stk.pop();
	}
	for(int i = 1;i <= n;i++){
		f[i] = -2;
	}
	f[0] = f[n+1] = -1;
	return ;
}

template<int SIZE,typename T = int>
class SegmentTree{
private:
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = len = 0;}
	};
	SegmentTreeNode node[(SIZE + 4) * 4];
	int OBJL,OBJR,_val;
	T* arr;
	inline void PushUp(int p){
		node[p].val = node[p*2].val + node[p*2+1].val;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].lazy == 0)return ;
		node[p*2].val += node[p*2].len * node[p].lazy;
		node[p*2+1].val += node[p*2+1].len * node[p].lazy;
		node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
		node[p].lazy = 0;
		return ;
	}
	void Build(int p,int l,int r){
		node[p].len = r - l + 1;
		if(l == r){
			if(arr != nullptr){
				node[p].val = arr[l];
			}
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r); 
		PushUp(p);
		return ;
	}
	void ChangeInner(int p,int l,int r){
		if(OBJL <= l && r <= OBJR){
			node[p].val += _val * node[p].len;
			node[p].lazy += _val;
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)ChangeInner(p*2,l,mid);
		if(mid < OBJR)ChangeInner(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	T Query(int p,int l,int r){
		if(OBJL <= l && r <= OBJR){
			return node[p].val;
		}
		const int mid = (l + r) >> 1;
		T ret = 0;
		PushDown(p);
		if(mid >= OBJL)ret = Query(p*2,l,mid);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r);
		return ret;
	}
	class Reference{
	private:
		friend class SegmentTree;
		SegmentTree* source;
		size_t l,r;
		Reference() = default;
		Reference(SegmentTree* _source,int _l,int _r){
			source = _source,l = _l,r = _r;
			return ;
		}
	public:
		operator T(){
			return source->Query(l,r);
		}
		Reference& operator+=(int x){
			source->Change(l,r,x);
			return *this;
		}
		Reference& operator-=(int x){
			source->Change(l,r,-x);
			return *this;
		}
	};
public:
	inline void Build(){
		Build(1,1,SIZE);
		return ;
	}
	inline void Build(T* _arr){
		arr = _arr;
		Build(1,1,SIZE);
		arr = nullptr;
		return ;
	}
	inline void Change(int l,int r,int inval){
		if(l > r)return ;
		OBJL = l,OBJR = r,_val = inval;
		ChangeInner(1,1,SIZE);
		return ;
	}
	inline T Query(int l,int r){
		OBJL = l,OBJR = r;
		return Query(1,1,SIZE);
	}
	SegmentTree(){
		Build();
		return ;
	}
	SegmentTree(T* _arr){
		Build(_arr);
		return ;
	}
	inline Reference operator[](pair<int,int> lr){
		return Reference(this,lr.first,lr.second);
	}
	inline Reference operator()(int l,int r){
		return Reference(this,l,r);
	}
};
SegmentTree<MAXN,ll> vtr;
class ArraySegmentTree{
private:
	int maxa[MAXN];
	inline void PushUp(int p){
		maxa[p] = max(maxa[p*2],maxa[p*2+1]);
		return ;
	}
	void Build(int p,int l,int r){
		if(l == r){
			maxa[p] = a[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	void Change(int p,int l,int r,int OBJ,int _val){
		if(l == r){
			maxa[p] = _val;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
		if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
		PushUp(p);
		return ;
	}
	int QueryPre(int p,int l,int r,int pos){
		if(l == r){
//			if(l == pos)return l - 1;//??什么奇怪特判
			if(maxa[p] < a[pos] || l == pos)return l;
			return r + 1;
		}
		const int mid = (l + r) >> 1;
		if(mid < pos){
			if(maxa[p*2+1] < a[pos]){
				return QueryPre(p*2,l,mid,pos);
			}else{
				int ret = QueryPre(p*2+1,mid+1,r,pos);
				if(ret == mid+1)ret = QueryPre(p*2,l,mid,pos);
				return ret;
			}
		}else{
			return QueryPre(p*2,l,mid,pos);
		}
		return 10181108;
	}
	int QueryNxt(int p,int l,int r,int pos){
		if(l == r){
//			if(l == pos)return l + 1;//??什么奇怪特判
			if(maxa[p] < a[pos] || l == pos)return l;
			return r - 1;
		}
		const int mid = (l + r) >> 1;
		if(mid+1 <= pos){
			return QueryNxt(p*2+1,mid+1,r,pos);
		}else{
			if(maxa[p*2] < a[pos]){
				return QueryNxt(p*2+1,mid+1,r,pos);
			}else{
				int ret = QueryNxt(p*2,l,mid,pos);
				if(ret == mid)ret = QueryNxt(p*2+1,mid+1,r,pos);
				return ret;
			}
		}
		return 10181108;
	}
	int QueryPreEQ(int p,int l,int r,int pos){
		if(l == r){
//			if(l == pos)return l - 1;//??什么奇怪特判
			if(maxa[p] <= a[pos])return l;
			return r + 1;
		}
		const int mid = (l + r) >> 1;
		if(mid < pos){
			if(maxa[p*2+1] <= a[pos]){
				return QueryPreEQ(p*2,l,mid,pos);
			}else{
				int ret = QueryPreEQ(p*2+1,mid+1,r,pos);
				if(ret <= mid+1)ret = QueryPreEQ(p*2,l,mid,pos);
				return ret;
			}
		}else{
			return QueryPreEQ(p*2,l,mid,pos);
		}
		return 10181108;
	}
	int QueryNxtEQ(int p,int l,int r,int pos){
		if(l == r){
//			if(l == pos)return l + 1;//??什么奇怪特判
			if(maxa[p] <= a[pos])return l;
			return r - 1;
		}
		const int mid = (l + r) >> 1;
		if(mid+1 <= pos){
			return QueryNxtEQ(p*2+1,mid+1,r,pos);
		}else{
			if(maxa[p*2] <= a[pos]){
				return QueryNxtEQ(p*2+1,mid+1,r,pos);
			}else{
				int ret = QueryNxtEQ(p*2,l,mid,pos);
				if(ret >= mid)ret = QueryNxtEQ(p*2+1,mid+1,r,pos);
				return ret;
			}
		}
		return 10181108;
	}
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline void Change(int pos,int _val){
		Change(1,1,n,pos,_val);
		return ;
	}
	inline int QueryPre(int pos){
		return QueryPre(1,1,n,pos);
	}
	inline int QueryNxt(int pos){
		return QueryNxt(1,1,n,pos);
	}
	inline int QueryPreEQ(int pos){
		return QueryPreEQ(1,1,n,pos);
	}
	inline int QueryNxtEQ(int pos){
		return QueryNxtEQ(1,1,n,pos);
	}
}atr;
ll ansarr[MAXN + 2],cnts;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("summer/summer2.in","r",stdin);
	freopen("summer.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>a[i];
	Solve();
	for(int i = 1;i <= n;i++)ansarr[i] = F(i);
	atr.Build();
	vtr.Build(ansarr);
	cin>>q;
	while(q--){
		
//		cerr<<endl<<endl<<endl<<endl<<endl;
		
		int x,l,r;
		cin>>x>>l>>r;
//		for(int i = 1;i <= n;i++)cerr<<a[i]<<" ";
//		cerr<<endl;
		if(a[x] < a[x+1]){
//			cerr<<"case1"<<endl;
			int lpos = atr.QueryPre(x);
			if(a[lpos-1] != a[x]){
				vtr[{lpos,x-1}] -= 1;
			}
			
			swap(a[x],a[x+1]);
			atr.Change(x,a[x]),atr.Change(x+1,a[x+1]);
			int rpos = atr.QueryNxt(x+1);
			if(a[rpos+1] != a[x+1]){
				vtr[{x+2,rpos}] += 1;
			}
			
		}else if(a[x] > a[x+1]){
//			cerr<<"case2"<<endl;
			int rpos = atr.QueryNxt(x+1);
			if(a[rpos+1] != a[x+1]){
				vtr[{x+2,rpos}] -= 1;
			}
			
			swap(a[x],a[x+1]);
			atr.Change(x,a[x]),atr.Change(x+1,a[x+1]);
			int lpos = atr.QueryPre(x);
			if(a[lpos-1] != a[x]){
				vtr[{lpos,x-1}] += 1;
			}
		}
		
//		for(int i = 1;i <= n;i++)cerr<<a[i]<<" ";
//		cerr<<endl;
		
		int xL = atr.QueryPreEQ(x),xR = atr.QueryNxtEQ(x);
		int rL = atr.QueryPreEQ(x+1),rR = atr.QueryNxtEQ(x+1);
		if(a[xL] <= a[x])xL--;
		if(a[xR] <= a[x])xR++;
		if(a[rL] <= a[x+1])rL--;
		if(a[rR] <= a[x+1])rR++;
		if(a[x] > a[x+1]){
			if(a[xL] >= a[xR]){
				f[x] = F(xR) + 1;
			}else{
				f[x] = F(xL) + 1;
			}
			if(a[rL] >= a[rR]){
				f[x+1] = F(rR) + 1;
			}else{
				f[x+1] = F(rL) + 1;
			}
		}else if(a[x] < a[x+1]){
			if(a[rL] >= a[rR]){
				f[x+1] = F(rR) + 1;
			}else{
				f[x+1] = F(rL) + 1;
			}
			if(a[xL] >= a[xR]){
				f[x] = F(xR) + 1;
			}else{
				f[x] = F(xL) + 1;
			}
		}
		
		int deltaX = f[x] - vtr[{x,x}],deltaR = f[x+1] - vtr[{x+1,x+1}];
		vtr[{x,x}] += deltaX,vtr[{x+1,x+1}] += deltaR;
		
		
		
		Solve();
//		if(xL != farL[x] || xR != farR[x] || rL != farL[x+1] || rR != farR[x+1]){
//			cerr<<x<<" is "<<xL<<","<<xR<<" and "<<x+1<<" is "<<rL<<","<<rR<<endl;
//			cerr<<x<<" act "<<farL[x]<<","<<farR[x]<<" and "<<x+1<<" act "<<farL[x+1]<<","<<farR[x+1]<<endl;
//		}
		for(int i = 1;i <= n;i++){
			ansarr[i] = F(i);
//			if(vtr[{i,i}] != ansarr[i])cerr<<vtr[{i,i}]<<" compare "<<ansarr[i]<<" in "<<i<<endl;
		}
		
		cout<<vtr[{l,r}] * k + ll(r - l + 1) * (n -1)<<'\n';
		
//		if(++cnts >= 10)return 0;
	}
	return not(Akano loves pure__Elysia);
}
