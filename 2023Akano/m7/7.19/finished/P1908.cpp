#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
int n;
long long ans,c[MAXN];
vector<long long> vec;
class SegmentTree{
	private:
		int val[MAXN * 4],lazy[MAXN * 4],len[MAXN * 4];
		inline void PushUp(int p){
			val[p] = val[p*2] + val[p*2+1];
			return ;
		}
		inline void PushDown(int p){
			if(!lazy[p])return ;
			val[p*2] += len[p*2] * lazy[p];
			val[p*2+1] += len[p*2+1] * lazy[p];
			lazy[p*2] += lazy[p],lazy[p*2+1] += lazy[p];
			lazy[p] = 0;
			return ;
		}
		void Build(int p,int l,int r){
			len[p] = r - l + 1;
			if(l == r){
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,int _val){
			if(OBJL <= l && r <= OBJR){
				val[p] += _val * len[p],lazy[p] += _val;
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
				return val[p];
			}
			int mid = (l + r) >> 1,ret = 0;
			PushDown(p);
			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
		}
		inline void Change(int l,int r,int _val){
			Change(1,1,n,l,r,_val);
			return ;
		}
		inline int Query(int l,int r){
			if(l <= 0 || l > r)return 0;
			return Query(1,1,n,l,r);
		}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>c[i];
		vec.push_back(c[i]);
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	tr.Build();
	for(int i = 1;i <= n;i++){
		const int val = lower_bound(vec.begin(),vec.end(),c[i]) - vec.begin() + 1;
		ans += tr.Query(val+1,val+1);
		tr.Change(1,val,1);
	}
	cout<<ans;
	return 0;
}

