//#include<bits/stdc++.h>
//#include<vector>
//using namespace std;
//const int MAXN = 4e5 + 1018 + 1108;
//int n,c,a,cnt;
//struct SegmentTreeNode{
//	int val,lazy,len;
//};
//class SegmentTree{
//	private:
//		SegmentTreeNode node[MAXN * 4];
//		inline void PushUp(int p){
//			node[p].val = node[p*2].val + node[p*2+1].val;
//			return ;
//		}
//		inline void PushDown(int p){
//			if(node[p].lazy == 0)return ;
//			node[p*2].val += node[p].lazy * node[p*2].len;
//			node[p*2].lazy += node[p].lazy;
//			node[p*2+1].val += node[p].lazy * node[p*2+1].len;
//			node[p*2+1].lazy += node[p].lazy;
//			node[p].lazy = 0;
//			return ;
//		}
//		void Build(int p,int l,int r){
//			node[p].len = r - l + 1;
//			if(l == r)return ;
//			const int mid = (l + r) >> 1;
//			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
//			return ;
//		}
//		void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
//			if(OBJL <= l && r <= OBJR){
//				node[p].val += _val * node[p].len;
//				node[p].lazy += _val;
//				return ;
//			}
//			const int mid = (l + r) >> 1;
//			PushDown(p);
//			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
//			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
//			PushUp(p);
//			return ;
//		}
//		int Query(int p,int l,int r,int OBJL,int OBJR){
//			if(OBJL <= l && r <= OBJR){
//				return node[p].val;
//			}
//			const int mid = (l + r) >> 1;
//			PushDown(p);
//			int ret = 0;
//			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
//			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
//			return ret;
//		}
//	public:
//		inline void Build(){
//			Build(1,1,n);
//			return ;
//		}
//		inline void Change(int l,int r,int _val){
//			Change(1,1,n,l,r,_val);
//			return ;
//		}
//		inline int Query(int l,int r){
//			return Query(1,1,n,l,r);
//		}
//}tr;
//struct QueueNode{
//	vector<int> pop;
//}kue[MAXN];
//vector<int> group[MAXN];
//inline int Find(int no,int dis){
//	int l = 0,r = group[no].size(),ans = -1;
//	while(l < r){
//		const int mid = (l + r) >> 1;
//		if(tr.Query(group[no][mid],group[no][mid]) <= dis){
//			r = mid;
//			ans = group[no][mid];
//		}else{
//			l = mid + 1;
//		}
//	}
//	return ans;
//}
//inline void Insert(int no,int dis,int popno){
//	int pos = Find(no,dis);
//	if(pos == -1){
//		pos = ++cnt;
//		group[no].push_back(pos);
//		kue[pos].pop.push_back(popno);
//	}else{
//		int newpos = min(dis - tr.Query(pos,pos),int(kue[pos].pop.size()));
//		kue[pos].pop.insert(kue[pos].pop.end() - newpos,popno);
//	}
//	if(pos > 1)tr.Change(1,pos-1,1);
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
////	freopen("queue/ex_queue3.in","r",stdin);
////	freopen("queue.out","w",stdout);
//	cin>>n;
//	tr.Build();
//	for(int i = 1;i <= n;i++){
//		cin>>c>>a;
//		Insert(c,a,i);
//	}
//	for(int i = 1;i <= cnt;i++){
//		for(auto j : kue[i].pop){
//			cout<<j<<" ";
//		}
//	}
//	cout<<endl;
//	return 0;
//}
