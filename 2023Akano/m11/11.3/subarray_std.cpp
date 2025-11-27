#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Solve{
	typedef long long ll;
	const int N=200010;
	const int INF=1e18;
	int n,m,a[N],sum[N];
	
	struct Ques{
		int k,ans;
	}qs[N];int q;
	
	vector<int>qq[N];
	
	struct Seg{
		int k,b;
		int calc(int x){
			return k*x+b;
		}
	};
	struct Node{
		int ch[2];
		Seg s;
	}tr[N];int tot;
	void Insert(int&p,int l,int r,Seg s){
		if(l>r)return;
		if(!p){
			p=++tot;
			tr[p].s=s;
			return;
		}
		int mid=(l+r)>>1;
		if(tr[p].s.calc(mid)<s.calc(mid)){
			swap(tr[p].s,s);
		}
		if(tr[p].s.k<s.k){
			Insert(tr[p].ch[1],mid+1,r,s);
		}
		else{
			Insert(tr[p].ch[0],l,mid-1,s);
		}
	}
	int Query(int p,int l,int r,int x){
		if(!p)return -INF;
		int res=tr[p].s.calc(x),mid=(l+r)>>1;
		if(x==mid)return res;
		if(x<mid){
			return max(res,Query(tr[p].ch[0],l,mid-1,x));
		}
		return max(res,Query(tr[p].ch[1],mid+1,r,x));
	}
	void clear(){
		for(int i=1;i<=tot;i++){
			tr[i]=tr[0];
		}
		tot=0;
	}
	void main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		int now=0;
		for(int i=1;i<=m;i++){
			int op,x;cin>>op>>x;
			if(op==1){
				++q;
				qs[q].k=now;
				qs[q].ans=now+a[x];
				qq[x].push_back(q);
			}
			else{
				now+=x;
			}
		}
		
		int root=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			Insert(root,-1e7,1e7,{-(i-1),-sum[i-1]});
			
			for(int j:qq[i]){
				if(qs[j].k>=1e7){
					qs[j].ans+=(i-1)*qs[j].k+sum[i-1];
				}
				else if(qs[j].k<=-1e7){
					qs[j].ans+=0;
				}
				else{
					int res=sum[i-1]+(i-1)*qs[j].k+Query(root,-1e7,1e7,qs[j].k);
					qs[j].ans+=res;
				}
			}
		}
		clear();
		root=0;
		for(int i=n;i;i--){
			Insert(root,-1e7,1e7,{i,sum[i]});
			
			for(int j:qq[i]){
				if(qs[j].k>=1e7){
					qs[j].ans+=(n-i)*qs[j].k+sum[n]-sum[i];
				}
				else if(qs[j].k<=-1e7){
					qs[j].ans+=0;
				}
				else{
					int res=Query(root,-1e7,1e7,qs[j].k)-sum[i]-i*qs[j].k;
//					cerr<<"R "<<res<<'\n';
					qs[j].ans+=res;
				}
			}
		}
		
		for(int i=1;i<=q;i++){
			cout<<qs[i].ans<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subarray/subarray4.in","r",stdin);
	freopen("subarray/subarray4.ans","w",stdout);
	
	Solve::main();
	
	return 0;
}


