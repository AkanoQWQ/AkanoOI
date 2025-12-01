#include<bits/stdc++.h>
using namespace std;
using ll = long long;
namespace Container{
	template<typename T>
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = len = 0;}
	};
	template<typename T,int SIZE>
	class SegmentTree{
		private:
			SegmentTreeNode<T> node[(SIZE + 4) * 4];
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
		public:
			inline void Build(){
				Build(1,1,SIZE);
				return ;
			}
			inline void Build(T* _arr){
				arr = _arr;
				Build(1,1,SIZE);
				return ;
			}
			inline void Change(int l,int r,int inval){
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
	};
}
const int MAXN = 1e5 + 1018 + 1108;
ll a[MAXN];
int n,m;
Container::SegmentTree<ll,MAXN> tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	tr.Build(a);
	for(int i = 1;i <= m;i++){
		int opt,x,y,k;
		cin>>opt;
		if(opt == 1){
			cin>>x>>y>>k;
			tr.Change(x,y,k);
		}else{
			cin>>x>>y;
			cout<<tr.Query(x,y)<<'\n';
		}
	}
	return 0;
}