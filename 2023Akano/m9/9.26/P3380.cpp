//FHQ_Treap 模板
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 6;
const int INF = 2147483647;
struct Node{
	int val,key,l,r,tot,sz;
	Node(int inv,int ink){
		val = inv;
		key = ink;
		tot = sz = 1;
		l = r = 0;
	}
	Node(){
		val = key = l = r = tot = sz = 0;
	}
};
Node node[MAXN];
class Treap{
private:
	int cnt,root;
	inline int& L(int p){
		return node[p].l;
	}
	inline int& R(int p){
		return node[p].r;
	}
	inline void PushUp(int p){
		node[p].sz = node[L(p)].sz + node[R(p)].sz + node[p].tot;
		return ;
	}
	void Split(int p,int k,int& x,int& y){
		if(p == 0){
			x = y = 0;
			return ;
		}
		if(node[p].val <= k){//归入X 
			x = p;//把p挂到x上
			Split(R(p),k,R(p),y); 
		}else{
			y = p;
			Split(L(p),k,x,L(p));
		}
		PushUp(p);
		return ;
	}
	int Merge(int x,int y){//一定有 val_x <= val_y 
		if(x == 0 || y == 0)return x + y;
		if(node[x].key <= node[y].key){//x在下面 
			L(y) = Merge(x,L(y));//尝试把x合并到y的左子树 
			PushUp(y);
			return y;//return x/y 表示了到底是把x还是y接在上一层的(Ly或者Rx上) 
		}else{//y在下面 
			R(x) = Merge(R(x),y);//尝试把y合并到x的右子树
			PushUp(x);
			return x;
		}
		return 10181108;
	}
	int GetVal(int p,int k){
		if(k == node[L(p)].sz + 1)return node[p].val;
		if(k < node[L(p)].sz + 1)return GetVal(L(p),k);
		return GetVal(R(p),k - node[L(p)].sz - 1);
	}
public:
	inline void Insert(int val){
		int x = 0,y = 0;
		Split(root,val,x,y);
		node[++cnt] = Node(val,rand());
		root = Merge(Merge(x,cnt),y);
		return ;
	}
	inline void Delete(int val){
		int x = 0,y = 0,r1 = 0,r2 = 0;
		Split(root,val,x,y);
		Split(x,val-1,r1,r2);//r2
		r2 = Merge(L(r2),R(r2));
		root = Merge(Merge(r1,r2),y);
		return ;
	}
	inline int GetRank(int val){
		int x = 0,y = 0;
		Split(root,val-1,x,y);
		int ans = node[x].sz + 1;
		Merge(x,y);
		return ans;
	}
	inline int GetVal(int k){
		return GetVal(root,k);
	}
	inline int GetPre(int k){
		int x = 0,y = 0;
		Split(root,k-1,x,y);
		int ret = GetVal(x,node[x].sz);
		root = Merge(x,y); 
		return ret;
	}
	inline int GetNext(int k){
		int x = 0,y = 0;
		Split(root,k,x,y);
		int ret = GetVal(y,1);
		root = Merge(x,y); 
		return ret;
	}
	inline void Init(){
		node[1] = Node(INF,rand());
		node[2] = Node(-INF,rand());
		L(1) = 2;
		root = 1,cnt = 2;
		return ;
	}
};
int arr[MAXN],n,q;
class SegmentTree{
private:
	Treap treap[MAXN * 4];
	void Build(int p,int l,int r){
		treap[p].Init();
		for(int i = l;i <= r;i++){
			treap[p].Insert(arr[i]);
		}
		if(l == r)return ;
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		return ;
	}
	void Change(int p,int l,int r,int OBJL,int OBJR,int oldVal,int newVal){
		treap[p].Delete(oldVal);
		cerr<<l<<" to "<<r<<" del "<<oldVal<<" add "<<newVal<<endl;
		treap[p].Insert(newVal);
		if(OBJL <= l && r <= OBJR){
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,oldVal,newVal);
		if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,oldVal,newVal);
		return ;
	}
	inline int GetRank(int p,int l,int r,int OBJL,int OBJR,int val){
		if(OBJL <= l && r <= OBJR){
			return treap[p].GetRank(val);
		}
		const int mid = (l + r) >> 1;
		int ret = 1;
		if(mid >= OBJL)ret += GetRank(p*2,l,mid,OBJL,OBJR,val) - 1;
		if(mid < OBJR)ret += GetRank(p*2+1,mid+1,r,OBJL,OBJR,val) - 1;
		return ret;
	}
	inline int GetPre(int p,int l,int r,int OBJL,int OBJR,int val){
		if(OBJL <= l && r <= OBJR){
			return treap[p].GetPre(val);
		}
		const int mid = (l + r) >> 1;
		int ret = -INF;
		if(mid >= OBJL)ret = max(ret,GetPre(p*2,l,mid,OBJL,OBJR,val));
		if(mid < OBJR)ret = max(ret,GetPre(p*2+1,mid+1,r,OBJL,OBJR,val));
		return ret;
	}
	inline int GetNext(int p,int l,int r,int OBJL,int OBJR,int val){
		if(OBJL <= l && r <= OBJR){
			return treap[p].GetNext(val);
		}
		const int mid = (l + r) >> 1;
		int ret = -INF;
		if(mid >= OBJL)ret = max(ret,GetNext(p*2,l,mid,OBJL,OBJR,val));
		if(mid < OBJR)ret = max(ret,GetNext(p*2+1,mid+1,r,OBJL,OBJR,val));
		return ret;
	}
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline void Change(int l,int r,int oldVar,int newVar){
		Change(1,1,n,l,r,oldVar,newVar);
		return ;
	}
	inline int GetRank(int l,int r,int val){
		return GetRank(1,1,n,l,r,val);
	}
	inline int GetPre(int l,int r,int val){
		return GetPre(1,1,n,l,r,val);
	}
	inline int GetNext(int l,int r,int val){
		return GetNext(1,1,n,l,r,val);
	}
}tr;

int main(){
	srand(time(0));
	freopen("P3380.in","r",stdin);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	tr.Build();
	for(int t = 1;t <= q;t++){
		int opt,pos,l,r,k;
		cin>>opt;
		if(opt == 1){
			cin>>l>>r>>k;
			cout<<tr.GetRank(l,r,k)<<'\n';
		}else if(opt == 2){
			cin>>l>>r>>k;
			cout<<"UNSOLVED"<<endl;
		}else if(opt == 3){
			cin>>pos>>k;
			tr.Change(pos,pos,arr[pos],k);
			arr[pos] = k;
		}else if(opt == 4){
			cin>>l>>r>>k;
			cout<<tr.GetPre(l,r,k)<<'\n';
		}else if(opt == 5){
			cin>>l>>r>>k;
			cout<<tr.GetNext(l,r,k)<<'\n';
		}
	}
	return 0;
}
