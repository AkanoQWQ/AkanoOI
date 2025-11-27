#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 6;
int n,a[MAXN],m;
class Segement_tree{
	private:
		int val[MAXN*4],lazy[MAXN*4],len[MAXN*4];
		inline bool Check(int OBJL,int OBJR,int l,int r){
			return OBJL <= l && r <= OBJR;
		}
		inline void PushUp(int p){
			val[p] = val[p*2] + val[p*2+1];
			return ;
		}
		inline void PushDown(int p){
			val[p*2] += len[p*2] * lazy[p];
			val[p*2+1] += len[p*2+1] * lazy[p];
			lazy[p*2] += lazy[p],lazy[p*2+1] += lazy[p];
			lazy[p] = 0;
			return ;
		}
		void Build(int p,int l,int r){
			len[p] = (r - l + 1);
			if(l == r){
				val[p] = a[l];
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid);
			Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		void Change(int p,int OBJL,int OBJR,int l,int r,int k){
			if(Check(OBJL,OBJR,l,r)){
				val[p] += len[p] * k;
				lazy[p] += k;
				return ;
			}
			PushDown(p);
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)Change(p*2,OBJL,OBJR,l,mid,k);
			if(mid < OBJR)Change(p*2+1,OBJL,OBJR,mid+1,r,k);
			PushUp(p);
			return ;
		}
		int Query(int p,int OBJL,int OBJR,int l,int r){
			if(Check(OBJL,OBJR,l,r)){
				return val[p];
			}
			PushDown(p);
			int ret = 0;
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)ret = Query(p*2,OBJL,OBJR,l,mid);
			if(mid < OBJR)ret += Query(p*2+1,OBJL,OBJR,mid+1,r);
			return ret;
		}
	public:
		inline void Change(int OBJL,int OBJR,int k){
			Change(1,OBJL,OBJR,1,n,k);
			return ; 
		}
		inline int Query(int OBJL,int OBJR){
			return Query(1,OBJL,OBJR,1,n);
		}
		inline void Build(){
			Build(1,1,n);
			return ; 
		} 
}t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	t.Build();
	while(m--){
		int opt,x,y,k;
		cin>>opt>>x>>y;
		if(opt == 1){
			cin>>k;
			t.Change(x,y,k);
		}else{
			cout<<t.Query(x,y)<<endl;
		}
	}
	return 0;
}
