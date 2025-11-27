#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
int t,n,k,a[MAXN];
template<bool mx>
class SegmentTree{
	private:
		int val[MAXN*4];
		inline void PushUp(int p){
			if(mx){
				val[p] = max(val[p*2],val[p*2+1]);
			}else{
				val[p] = min(val[p*2],val[p*2+1]);
			}
			return ;
		}
		void Build(int p,int l,int r){
			if(mx){
				val[p] = 0;
			}else{
				val[p] = n+1;
			}
			if(l == r){
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int _val){
			if(l == r){
				if(mx){
					val[p] = max(val[p],_val);
				}else{
					val[p] = min(val[p],_val);
				}
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return val[p];
			}
			const int mid = (l + r) >> 1;
			int ret = mx ? 0 : n+1;
			if(mx){
				if(mid >= OBJL)ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
				if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
			}else{
				if(mid >= OBJL)ret = min(ret,Query(p*2,l,mid,OBJL,OBJR));
				if(mid < OBJR)ret = min(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
			}
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,k);
			return ;
		}
		inline void Change(int pos,int _val){
			Change(1,1,k,pos,_val);
			return ;
		}
		inline int Query(int l,int r){
			return Query(1,1,k,l,r); 
		}
};
SegmentTree<true> tr1;
SegmentTree<false> tr2; 
int upans[MAXN],downans[MAXN],lans[MAXN],rans[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		tr1.Build(),tr2.Build();
		for(int i = 1;i <= k;i++){
			upans[i] = lans[i] = n+1;
			downans[i] = rans[i] = 0;
		}
		for(int i = 1;i <= n;i++){
			tr1.Change(a[i],i);
			tr2.Change(a[i],i);
		}
		for(int i = 1;i <= n;i++){
			int up = tr2.Query(a[i],k);
			int down = tr1.Query(a[i],k);
			upans[a[i]] = min(upans[a[i]],up),downans[a[i]] = max(downans[a[i]],down);
			if(down != 0){
				lans[a[i]] = min(lans[a[i]],i);
				rans[a[i]] = max(rans[a[i]],i);
			}
		}
		for(int i = 1;i <= k;i++){
			cout<<max(downans[i] - upans[i] + 1,0) * 2<<' ';
		}
	}
	return 0;
}
