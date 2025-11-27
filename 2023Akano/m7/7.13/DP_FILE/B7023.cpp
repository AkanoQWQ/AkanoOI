#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int MAXN = 1e6 + 6;
int T,n;
class SegmentTree{
	private:
		int mx[MAXN * 4],cnt[MAXN * 4],lazy[MAXN * 4];
		inline void PushUp(int p){
			if(mx[p*2] == mx[p*2+1]){
				mx[p] = mx[p*2],cnt[p] = cnt[p*2] + cnt[p*2+1];
			}else if(mx[p*2] > mx[p*2+1]){
				mx[p] = mx[p*2],cnt[p] = cnt[p*2];
			}else{
				mx[p] = mx[p*2+1],cnt[p] = cnt[p*2+1];
			}
			return ;
		}
		inline void PSD(int p,int delta){
			mx[p] += delta,lazy[p] += delta;
			return ;
		}
		inline void PushDown(int p){
			if(!lazy[p])return ;
			PSD(p*2,lazy[p]),PSD(p*2+1,lazy[p]);
			lazy[p] = 0;
			return ;
		}
		void Build(int p,int l,int r){
			mx[p] = lazy[p] = 0;
			if(l == r){
				cnt[p] = 1;
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,int val){
			if(OBJL <= l && r <= OBJR){
//				cout<<"now "<<l<<" to "<<r<<" mx "<<mx[p]+val<<endl;
				mx[p] += val,lazy[p] += val;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,val);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,val);
			PushUp(p);
			return ;
		}
		long long Query(int p,int l,int r,int OBJL,int OBJR){
//			cout<<l<<" to "<<r<<" mx "<<mx[p]<<" cnt "<<cnt[p]<<endl;
			if(OBJL <= l && r <= OBJR){
				return (mx[p] == 0) ? cnt[p] : 0;
			}
			const int mid = (l + r) >> 1;
			long long ret = 0;
			PushDown(p);
			if(mid >= OBJL)ret = Query(p*2,l,mid,OBJL,OBJR);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int l,int r,int val){
			Change(1,1,n,l,r,val);
			return ;
		}
		inline int Query(int l,int r){
			return Query(1,1,n,l,r);
		}
}tr;
vi edges[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B7023.in","r",stdin);
	freopen("B7023.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans = 1;//(1,1)
		for(int i = 1;i < n;i++){
			int u,v;
			cin>>u>>v;
			if(u < v)swap(u,v);
			edges[u].push_back(v);
		}
		tr.Build();
		for(int r = 2;r <= n;r++){
			//dec 1 ~ r-1
			tr.Change(1,r-1,-1);
			for(auto i : edges[r]){
				tr.Change(1,i,1);
//				cout<<"PUSH "<<1<<" to "<<i<<endl;
			}
			ans += tr.Query(1,r);
//			cout<<"ANS ADD "<<tr.Query(1,r)<<" in "<<r<<endl;
			edges[r].clear();
		}
		cout<<ans<<'\n';
	}
	cout<<flush;
	return 0;
}
