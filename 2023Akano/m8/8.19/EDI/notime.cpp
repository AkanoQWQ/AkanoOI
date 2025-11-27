#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
bool mx = true;
int nowval;
int n,q,arr[MAXN],ans[MAXN];
int smallerpre[MAXN],smallersuf[MAXN];
int samepre[MAXN],samesuf[MAXN];
int biggerpre[MAXN],biggersuf[MAXN];
class SegmentTree{
	private:
		int val[MAXN * 4];
		inline void PushUp(int p){
			if(mx){
				val[p] = max(val[p*2],val[p*2+1]);
			}else{
				val[p] = min(val[p*2],val[p*2+1]);
			}
			return ;
		}
		void Build(int p,int l,int r){
			val[p] = nowval;
			if(l == r)return ;
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
			int ret = nowval;
			if(mid >= OBJL){
				if(mx){
					ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
				}else{
					ret = min(ret,Query(p*2,l,mid,OBJL,OBJR));
				}
			}
			if(mid < OBJR){
				if(mx){
					ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
				}else{
					ret = min(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
				}
			}
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int pos,int _val){
			Change(1,1,n,pos,_val);
			return ;
		}
		inline int Query(int l,int r){
			if(l > r)return nowval;
			return Query(1,1,n,l,r);
		}
}tr;
struct Query{
	int l,r,blk,id;
}ask[MAXN];
bool Cmp(Query q1,Query q2){
	if(q1.blk != q2.blk)return q1.blk < q2.blk;
	if(q1.blk & 1){
		return q1.r < q2.r;
	}else{
		return q1.r > q2.r;
	}
}
inline void Solve(){
	int l = 1,r = 0,nowans = 0;
	for(int i = 1;i <= q;i++){
		while(l > ask[i].l){//-l
			l--;
			int nxt = samesuf[l];
			if(l <= nxt && nxt <= r && smallersuf[l] > nxt){
				
			}else{
				nowans++;
			}
		}
		while(r < ask[i].r){//+r
			r++;
			int nxt = samepre[r];
			if(l <= nxt && nxt <= r && smallerpre[r] < nxt){
				
			}else{
				nowans++;
			}
		}
		while(l < ask[i].l){//l+
			int lst = samesuf[l];
			if(l <= lst && lst <= r && smallerpre[lst] < l){
				
			}else{
				nowans--;
			}
			l++;
		}
		while(r > ask[i].r){//r-
			int lst = samepre[r];
			if(l <= lst && lst <= r && smallersuf[lst] > r){
				
			}else{
				nowans--;
			}
			r--;
		}
		ans[ask[i].id] = nowans;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("notime.in","r",stdin);
	freopen("notime.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	nowval = 0,mx = true;
	tr.Build();
	for(int i = 1;i <= n;i++){
		smallerpre[i] = tr.Query(1,arr[i]-1);
		samepre[i] = tr.Query(arr[i],arr[i]);
		biggerpre[i] = tr.Query(arr[i]+1,n);
		tr.Change(arr[i],i);
	}
	nowval = n+1,mx = false;
	tr.Build();
	for(int i = n;i >= 1;i--){
		smallersuf[i] = tr.Query(1,arr[i]-1);
		samesuf[i] = tr.Query(arr[i],arr[i]);
		biggersuf[i] = tr.Query(arr[i]+1,n);
		tr.Change(arr[i],i);
	}
	int blen = sqrt(n);
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i,ask[i].blk = (ask[i].l-1) / blen + 1;
	}
	sort(ask+1,ask+q+1,Cmp);
	Solve();
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
