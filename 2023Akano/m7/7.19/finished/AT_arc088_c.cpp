#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 1018 + 1108;
string str;
long long ans,n,dfn[MAXN],dnt1,dnt2,onecnt;
class SegmentTree{
	private:
		int val[MAXN * 8],lazy[MAXN * 8],len[MAXN * 8];
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
			Build(1,1,n+4);
		}
		inline void Change(int l,int r,int _val){
			Change(1,1,n+4,l,r,_val);
			return ;
		}
		inline int Query(int l,int r){
			if(l <= 0 || l > r)return 0;
			return Query(1,1,n+4,l,r);
		}
}tr;
deque<int> q[32];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>str;
	n = str.length();
	str = "." + str;
	dnt1 = 0,dnt2 = n+1;
	for(int i = 1;i <= n;i++){
		q[str[i] - 'a'].push_back(i);
	}
	for(int i = 0;i < 26;i++){
		onecnt += (q[i].size() % 2 == 1);
	}
	if(onecnt >= 2){
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		const int no = str[i] - 'a';
		if(q[no].empty())continue;//have been choosed
		if(q[no].size() == 1){
			dfn[q[no].front()] = (n / 2) + 1;
			q[no].pop_front();
			continue;
		}
		dfn[q[no].front()] = ++dnt1;
		dfn[q[no].back()] = --dnt2;
		q[no].pop_front(),q[no].pop_back();
	}
	tr.Build();
	for(int i = 1;i <= n;i++){
		ans += tr.Query(dfn[i]+1,dfn[i]+1);
		tr.Change(1,dfn[i],1);
	}
	cout<<ans<<endl;
	return 0;
}
