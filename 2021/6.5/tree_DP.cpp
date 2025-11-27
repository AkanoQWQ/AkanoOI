#include<bits/stdc++.h>
using namespace std;
const int N = 500005,M = 500005 * 2;
int i,j,next[M],first[M],v[M],w[M],t,n,m,p,ans,d[M],x,y,z;
void add(int x,int y,int z){
	next[++t] = first[x];
	first[x] = t;
	v[t] = y;
	w[t] = z;
}
void dfs(int x,int father){
	if(ans < d[x]){
		ans = d[x];
		p = x;
	}
	for(i = first[x];i;i = next[i]){
		int j = v[i];
		if(j == father) continue;
		d[j] = d[x] + w[i];
		dfs(j,x);
	}
}
void find(int x){
	d[x] = 0;
	ans = 0;
	dfs(x,0);
}
int main(){
	//freopen("treedp.in","r",stdin);
	//freopen("treedp.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	find(1);
	find(p);
	cout<<ans;
	return 0;
}

