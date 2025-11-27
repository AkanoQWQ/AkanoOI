#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int n,m;
struct Node{
	int val;
	priority_queue<int> q;
};
class SegmentTree{
	private:
		Node node[MAXN * 8];
		inline void PushUp(int p){
			node[p].val = max(node[p*2].val,node[p*2+1].val);
			node[p].val = max(node[p].val,node[p].q.top());
			return ;
		}
		void Build(int p,int l,int r){
			node[p].val = -1;
			node[p].q.push(-1);
			if(l == r){
				node[p*2].val = node[p*2+1].val = -1;
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		void Push(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(OBJL <= l && r <= OBJR){
				node[p].q.push(_val);
				node[p].val = max(node[p].val,_val);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)Push(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)Push(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return node[p].val;
			}
			const int mid = (l + r) >> 1;
			int ret = -1;
			ret = max(ret,node[p].q.top());
			if(mid >= OBJL)ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
			if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
			return ret;
		}
		void Delete(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(node[p].val < _val)return ;
			const int mid = (l + r) >> 1;
			if(node[p].q.top() == _val){
				node[p].q.pop();
				if(l <= OBJL-1)Push(1,1,n,l,OBJL-1,_val);
				if(OBJR+1 <= r)Push(1,1,n,OBJR+1,r,_val);
			}else{
				if(mid >= OBJL)Delete(p*2,l,mid,OBJL,OBJR,_val);
				if(mid < OBJR)Delete(p*2+1,mid+1,r,OBJL,OBJR,_val);
			}
			PushUp(p);//if(l != r)?
			return ;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline int Query(int l,int r){
			return Query(1,1,n,l,r);
		}
		inline void Delete(int l,int r){
			int mx = Query(l,r);
			if(mx == -1)return ;
			Delete(1,1,n,l,r,mx);
			return ;
		}
		inline void Push(int l,int r,int v){
			Push(1,1,n,l,r,v);
			return ;
		}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("sorrow.in","r",stdin);
//	freopen("sorrow.out","w",stdout);
	cin>>n>>m;
	tr.Build();
	for(int i = 1;i <= m;i++){
		int opt,l,r,v;
		cin>>opt>>l>>r;
		if(opt == 1){
			cin>>v;
			tr.Push(l,r,v);
		}else if(opt == 2){
			tr.Delete(l,r);
		}else{
			cout<<tr.Query(l,r)<<'\n';
		}
	}
	return 0;
}//bashu 8*shu41
