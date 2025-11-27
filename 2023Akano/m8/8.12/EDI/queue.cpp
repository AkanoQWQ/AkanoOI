#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 1018 + 1108;
const int SIZE = MAXN;
int n,c,a,cnt;
struct FHQNode{
	int val,key,l,r,sz;
}node[SIZE];
int tot;
class FHQ_Treap{
	private:
		int root;
		inline void PushUp(int p){
			node[p].sz = node[node[p].l].sz + node[node[p].r].sz + 1;
			return ;
		}
		void Split(int p,int k,int& x,int& y){//Split by rank
			if(!p){
				x = y = 0;
				return ;
			}
			if(node[node[p].l].sz+1 <= k){
				x = p;
				Split(node[p].r,k - (node[node[p].l].sz+1),node[p].r,y);
			}else{
				y = p;
				Split(node[p].l,k,x,node[p].l);
			}
			PushUp(p);
			return ;
		}
		int Merge(int x,int y){
			if(x == 0 || y == 0)return x + y;
			if(node[x].val < node[y].val){
				node[y].l = Merge(x,node[y].l);
				PushUp(y);
				return y;
			}else{
				node[x].r = Merge(node[x].r,y);
				PushUp(x);
				return x;
			}
			return 10181108;
		}
		void dfs(int p,vector<int>& vec){
			if(!p)return ;
			dfs(node[p].l,vec);
			vec.push_back(node[p].key);
			dfs(node[p].r,vec);
			return ;
		}
	public:
		inline void Insert(int _key,int kth){
			if(root == 0){
				root = ++tot;
				node[tot].key = _key,node[tot].val = rand(),node[tot].sz = 1;
			}else{
				++tot;
				node[tot].key = _key,node[tot].val = rand(),node[tot].sz = 1;
				int r1,r2;
				Split(root,kth,r1,r2);
				r1 = Merge(r1,tot);
				root = Merge(r1,r2);
			}
			return ;
		}
		inline int Size(){
			return node[root].sz;
		}
		inline vector<int> Output(){
			vector<int> ret;
			dfs(root,ret);
			return ret;
		}
};
struct SegmentTreeNode{
	int val,lazy,len;
};
class SegmentTree{
	private:
		SegmentTreeNode node[MAXN * 4];
		inline void PushUp(int p){
			node[p].val = node[p*2].val + node[p*2+1].val;
			return ;
		}
		inline void PushDown(int p){
			if(node[p].lazy == 0)return ;
			node[p*2].val += node[p].lazy * node[p*2].len;
			node[p*2].lazy += node[p].lazy;
			node[p*2+1].val += node[p].lazy * node[p*2+1].len;
			node[p*2+1].lazy += node[p].lazy;
			node[p].lazy = 0;
			return ;
		}
		void Build(int p,int l,int r){
			node[p].len = r - l + 1;
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(OBJL <= l && r <= OBJR){
				node[p].val += _val * node[p].len;
				node[p].lazy += _val;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return node[p].val;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			int ret = 0;
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int l,int r,int _val){
			Change(1,1,n,l,r,_val);
			return ;
		}
		inline int Query(int l,int r){
			return Query(1,1,n,l,r);
		}
}tr;
FHQ_Treap kueue[MAXN];
vector<int> group[MAXN];
inline int Find(int no,int dis){
	int l = 0,r = group[no].size(),ans = -1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(tr.Query(group[no][mid],group[no][mid]) <= dis){
			r = mid;
			ans = group[no][mid];
		}else{
			l = mid + 1;
		}
	}
	return ans;
}
inline void Insert(int no,int dis,int popno){
	int pos = Find(no,dis);
	if(pos == -1){
		pos = ++cnt;
		group[no].push_back(pos);
		kueue[pos].Insert(popno,0);
	}else{
		int newpos = max(kueue[pos].Size() - (dis - tr.Query(pos,pos)),0);
		kueue[pos].Insert(popno,newpos);
	}
	if(pos > 1)tr.Change(1,pos-1,1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	cin>>n;
	tr.Build();
	for(int i = 1;i <= n;i++){
		cin>>c>>a;
		Insert(c,a,i);
	}
	for(int i = 1;i <= cnt;i++){
		vector<int> pop = kueue[i].Output();
		for(auto j : pop){
			cout<<j<<" ";
		}
	}
	cout<<endl;
	return 0;
}
//Finished
