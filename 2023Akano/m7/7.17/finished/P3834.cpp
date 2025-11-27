#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
struct Node{
	int ls,rs,val;
};
int n,q,val[MAXN],idx[MAXN],org[MAXN];
class SegmentTree{
	private:
		Node node[MAXN * (1<<5)];
		int roots[MAXN],tot;
		inline void PushUp(int p){
			node[p].val = node[node[p].ls].val + node[node[p].rs].val;
			return ;
		}
		int Build(int l,int r){
			const int p = ++tot;
			if(l == r)return p;
			const int mid = (l + r) >> 1;
			node[p].ls = Build(l,mid),node[p].rs = Build(mid+1,r);
			return p;
		}
		int Change(int p,int l,int r,int OBJ,int _val){
			const int no = ++tot;
			node[no] = node[p];
			if(l == r){
				node[no].val += _val;
				return no;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)node[no].ls = Change(node[no].ls,l,mid,OBJ,_val);
			if(mid < OBJ)node[no].rs = Change(node[no].rs,mid+1,r,OBJ,_val);
			PushUp(no);
			return no;
		}
		int Query(int p1,int p2,int l,int r,int k){
			if(l == r)return l;
			const int mid = (l + r) >> 1,delta = node[node[p2].ls].val - node[node[p1].ls].val;
			if(k <= delta){
				return Query(node[p1].ls,node[p2].ls,l,mid,k);
			}
			return Query(node[p1].rs,node[p2].rs,mid+1,r,k-delta);
		}
	public:
		inline void Build(){
			roots[0] = Build(1,n);
			return ;
		}
		inline void Change(int val,int history,int version){
			roots[version] = Change(roots[history],1,n,val,1);
			return ;
		}
		inline int Query(int kth,int history,int version){
			return Query(roots[history],roots[version],1,n,kth);
		}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P3834.in","r",stdin);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>val[i];
		idx[i] = val[i];
	}
	sort(idx+1,idx+n+1);
	int len = unique(idx+1,idx+n+1) - idx - 1;
	for(int i = 1;i <= n;i++){
		const int itv = lower_bound(idx+1,idx+len+1,val[i]) - idx;
		org[itv] = val[i];
		val[i] = itv;
		tr.Change(val[i],i-1,i);
	}
	for(int i = 1;i <= q;i++){
		int l,r,w;
		cin>>l>>r>>w;
		cout<<org[tr.Query(w,l-1,r)]<<'\n';
	}
	return 0;
}

