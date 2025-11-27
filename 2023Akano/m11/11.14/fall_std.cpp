#include<bits/stdc++.h>
using namespace std;

namespace Solve{
	typedef long long ll;
	
	const int N=500010<<1;
	
	int n,a[N],b[N];
	int head[N],ver[N<<1],ne[N<<1],idx=2;
	void add(int x,int y){
		ver[idx]=y,ne[idx]=head[x],head[x]=idx++;
	}
	int lis[N],sz;
	void lisan(){
		for(int i=1;i<=n;i++)lis[++sz]=a[i],lis[++sz]=b[i];
		sort(lis+1,lis+1+sz);
		sz=unique(lis+1,lis+1+sz)-lis-1;
		for(int i=1;i<=n;i++){
			a[i]=lower_bound(lis+1,lis+1+sz,a[i])-lis;
			b[i]=lower_bound(lis+1,lis+1+sz,b[i])-lis;
		}
	}
	
	int fa[N],siz[N];
	int get(int x){
		return fa[x]?(fa[x]=get(fa[x])):x;
	}
	int sum;
	int calc(int x){
		return siz[x]>>1;
	}
	void merge(int x,int y){
		x=get(x),y=get(y);
		if(x==y)return;
		sum-=calc(x)+calc(y);
		fa[x]=y;
		siz[y]+=siz[x];
		sum+=calc(y);
	}
	
	vector<pair<int,int>>mt;
	int vis[N],ind;
	bool dfs(int x,int fe){
		vis[x]=++ind;
		vector<int>e;
		for(int i=head[x];i;i=ne[i])
			if((i^1)!=fe){
				if(!vis[ver[i]]){
					if(dfs(ver[i],i)){
						e.push_back(i>>1);
					}
				}
				else if(vis[ver[i]]<=vis[x]){
					e.push_back(i>>1);
				}
			}
		bool o=1;
		if((e.size()&1)&&fe){
			o=0;
			e.push_back(fe>>1);
		}
		for(int i=0;i+1<(int)e.size();i+=2){
			mt.push_back({e[i],e[i+1]});
		}
		return o;
	}
	void main(){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
		lisan();
		int lastans = 0;
		for(int i=1;i<=n;i++){
			if(a[i] == 498439 && b[i] == 684896){
				cerr<<"wtf"<<endl;
			}
			add(a[i],b[i]);
			if(a[i]!=b[i])add(b[i],a[i]);
			else idx++;
			merge(a[i],b[i]);
			sum-=calc(get(a[i]));
			siz[get(a[i])]++;
			sum+=calc(get(a[i]));
			cout<<sum<<' ';
		}
		cout<<'\n';
		return ;
		for(int i=1;i<=sz;i++)
			if(!vis[i]){
				dfs(i,0);
			}
		for(auto pr:mt){
			cout<<pr.first<<' '<<pr.second<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("fall/fall3.in","r",stdin);
	freopen("fall.out","w",stdout);
	freopen("fallerr.ans","w",stderr);
	Solve::main();
	
	return 0;
}
