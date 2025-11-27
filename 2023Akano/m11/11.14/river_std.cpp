#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Solve{
	typedef long long ll;
	
	const int N=300010;
	
	int n,a[N];
	int head[N],ver[N<<1],ne[N<<1],idx=2;
	void add(int x,int y){
		ver[idx]=y,ne[idx]=head[x],head[x]=idx++;
	}
	int dfn[N],siz[N],ind,ff[N];
	void dfs(int x,int fa){
		ff[x]=fa,dfn[x]=++ind,siz[x]=1;
		for(int i=head[x];i;i=ne[i])
			if(ver[i]!=fa){
				dfs(ver[i],x);
				siz[x]+=siz[ver[i]];
			}
	}
	
	struct BIT{
		int c[N];
		void change(int x,int y){
			for(;x<=n;x+=x&-x)c[x]+=y;
		}
		int query(int x){
			int r=0;
			for(;x;x-=x&-x)r+=c[x];
			return r;
		}
	}bson,bfa;
	int vson;
	
	void US(int x,int k){
		bson.change(dfn[x],k*siz[x]*a[x]);
	}
	void Ufa(int x,int k){
		for(int i=head[x];i;i=ne[i]){
			int y=ver[i];
			int v=k*(-siz[x]+n-siz[y])*a[x];
			bfa.change(dfn[y],v);
			bfa.change(dfn[y]+siz[y],-v);
		}
	}
	
	void print(__int128 x){
		if(x>=10)print(x/10);
		cout<<(int)(x%10);
	}
	void printerr(__int128 x){
		if(x>=10)print(x/10);
		cerr<<(int)(x%10);
	}
	void main(){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++){
			int x;cin>>x;
			add(x,i);
		}
		dfs(1,0);
		vector<int>od;
		for(int i=1;i<=n;i++)od.push_back(i);
		sort(od.begin(),od.end(),[&](int i,int j){
			return a[i]>a[j];
		});
		for(int i=1;i<=n;i++){
			US(i,1),Ufa(i,1);
		}
		
		__int128 ans=0;
		for(int i:od){
			US(i,-1),Ufa(i,-1);
			
			__int128 res=0;
			for(int j=head[i];j;j=ne[j]){
				int x=ver[j],v;
				v=bson.query(dfn[x]+siz[x]-1)-bson.query(dfn[x]-1);
				res+=(__int128)v*(n-siz[ver[j]]);
				cerr<<x<<" upto "<<i<<" give "<<v*(n-siz[ver[j]])<<endl;
			}
			if(ff[i]){
				int v;
				v=bson.query(dfn[i]-1)+(bson.query(n)-bson.query(dfn[i]+siz[i]-1));
				v+=bfa.query(dfn[i]);
				res+=(__int128)v*siz[i];
			}
			cerr<<i<<" is ";
			printerr(res);
			cerr<<endl;
			ans+=res;
		}
		
		print(ans);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("river/river1.in","r",stdin);
	freopen("river.out","w",stdout);
	
	Solve::main();
	
	return 0;
}
