#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
const int MAXM = 2e3 + 6;
int n,m,c[MAXN],val,l,r,a,b,ans = 0x7fffffff;
int cnt[MAXM];
inline void add(int x){
	if(cnt[c[x]] == 0)++val;
	++cnt[c[x]];
	return ;
}
inline void del(int x){
	if(cnt[c[x]] == 1)--val;
	--cnt[c[x]];
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%d",&c[i]);
	l = 1,r = 0;
	while(l <= n && r < n){
		while(val < m && r < n){
			add(++r);
		}
		if(r - l + 1 < ans){
			ans = r - l + 1;
			a = l,b = r;
//			cout<<l<<" "<<r<<" val "<<val<<endl;
		}
		del(l++);
	}
	printf("%d %d",a,b);
	return 0;
}

