#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> e[500005];
struct MIT{
	int tr[500005];
	int lowbit(int x){
		return x&-x;
	}
	void add(int x, int y){
		while(x<=500000){
			tr[x]+=y;
			x+=lowbit(x);
		}
	}
	int ask(int x){
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x); 
		}
		return res;
	}
}T1, T2;
int w[500005], id[500005];
int dfn[500005], dfncnt;
int dep[500005], siz[500005], a[500005], b[500005], c[500005];
void dfs1(int x, int ff){
	dep[x]=dep[ff]+1;
	dfn[x]=++dfncnt;
	siz[x]=1;
	a[x]=T1.ask(w[x]-1);
	c[x]=T1.ask(w[x])-a[x];
	T1.add(w[x], 1);
	for(auto y:e[x]){
		if(y==ff) continue;
		dfs1(y, x);
		siz[x]+=siz[y];
	}
	T1.add(w[x], -1);
}
ll ans[500005];
int main(){
	freopen("tree/tree2.in","r",stdin);
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &w[i]);
	}
	for(int i=1; i<n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1, 0);
	for(int i=1; i<=n; ++i){
		id[i]=i;
		dep[i]--;
	}
	sort(id+1, id+n+1, [](int x, int y){return w[x]>w[y];});
	for(int i=1, j=1; i<=n; ++i){
		int p=id[i];		
		while(w[id[j]]>w[id[i]]){
			T2.add(dfn[id[j]], 1);
			++j;
		}
		b[p]=T2.ask(dfn[p]+siz[p]-1)-T2.ask(dfn[p]-1);
	}
	sort(id+1, id+n+1, [](int x, int y){return dep[x]-a[x]-b[x]-c[x]<dep[y]-a[y]-b[y]-c[y];});
	for(int i = 1;i <= n;i++){
		cerr<<i<<" dir "<<id[i]<<" a "<<a[id[i]]<<" b "<<b[id[i]]<<" c "<<c[id[i]]<<endl;
	}
	for(int i=1; i<=n; ++i){
		ans[n]+=b[i];
	}
	for(int i=1; i<=n; ++i){
		ans[n-i]=ans[n-i+1]+dep[id[i]]-a[id[i]]-b[id[i]]-c[id[i]]+i-1;
	}
	for(int i=0; i<=n; ++i){
		printf("%lld\n", ans[i]);
	}
	return 0;
}
