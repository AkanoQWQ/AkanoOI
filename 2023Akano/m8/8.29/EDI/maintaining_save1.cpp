//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//using ll = long long;
//const int MAXN = 5e5 + 1018 + 1108;
//int n,q,arr[MAXN];
//int temp[3];
//inline void Shift(int nowarr[],int delta){
//	for(int i = 0;i < 3;i++){
//		temp[(i+delta)%3] = nowarr[i];
//	}
//	for(int i = 0;i < 3;i++){
//		nowarr[i] = temp[i];
//	}
//	return ;
//}
//struct Node{
//	int val[3],lazy;
//};
//class SegmentTree{
//	private:
//		Node node[MAXN * 4];
//		inline void PushUp(int p){
//			node[p].val[0] = node[p*2].val[0] + node[p*2+1].val[0];
//			node[p].val[1] = node[p*2].val[1] + node[p*2+1].val[1];
//			node[p].val[2] = node[p*2].val[2] + node[p*2+1].val[2];
//			return ;
//		}
//		inline void PushDown(int p){
//			if(!node[p].lazy)return ;
//			Shift(node[p*2].val,node[p].lazy);
//			Shift(node[p*2+1].val,node[p].lazy);
//			node[p*2].lazy = (node[p*2].lazy + node[p].lazy) % 3;
//			node[p*2+1].lazy = (node[p*2+1].lazy + node[p].lazy) % 3;
//			node[p].lazy = 0;
//			return ;
//		}
//		void Build(int p,int l,int r){
//			if(l == r){
//				node[p].val[arr[l]]++;
//				return ;
//			}
//			const int mid = (l + r) >> 1;
//			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
//			PushUp(p);
//			return ; 
//		}
//		void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
//			if(OBJL <= l && r <= OBJR){
//				Shift(node[p].val,_val);
//				node[p].lazy = (node[p].lazy + _val) % 3;
//				return ;
//			}
//			const int mid = (l + r) >> 1;
//			PushDown(p);
//			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
//			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
//			PushUp(p);
//			return ;
//		}
//		int Query(int p,int l,int r,int OBJL,int OBJR,int _val){
//			if(OBJL <= l && r <= OBJR){
//				return node[p].val[_val];
//			}
//			const int mid = (l + r) >> 1;
//			PushDown(p);
//			int ret = 0;
//			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR,_val);
//			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR,_val);
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
//		inline int Query(int l,int r,int _val){
//			return Query(1,1,n,l,r,_val);
//		}
//}tr;
//ll ans = 0;
//inline int Find(int inL,int inR,int num,int OBJ){
//	int l = inL,r = inR+1;
//	while(l < r){
//		const int mid = (l + r) >> 1;
//		if(tr.Query(inL,mid,num) >= OBJ){
//			r = mid;
//		}else{
//			l = mid + 1;
//		}
//	}
//	return r;
//}
//inline void BF(){
//	ans = 0;
//	for(int i = 1;i <= n;i++){
//		int pos1 = Find(i,n,0,1),pos2 = Find(i,n,1,1),pos3 = Find(i,n,2,1);
//		int pos = max(pos1,max(pos2,pos3));
//		ans += n+1-pos;
//	}
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("maintaining.in","r",stdin);
//	freopen("maintaining.out","w",stdout);
//	cin>>n>>q;
//	for(int i = 1;i <= n;i++){
//		cin>>arr[i];
//	}
//	tr.Build();
//	BF();
//	cout<<ans<<'\n';
//	for(int i = 1;i <= q;i++){
//		int l,r;
//		cin>>l>>r;
//		tr.Change(l,r,1);
//		BF();
//		cout<<ans<<'\n';
//	}
//	return not(Akano loves pure__Elysia);
//}
