#include<bits/stdc++.h>
using namespace std;
const int MAXN = 262144;
struct tr{
	int l,r,m;
}t[MAXN*2+6];
int ans;
bool solveable = 1;
int tt,n,a[MAXN+6];//3 4    5 6
void build(int p,int l,int r){
	t[p].l = l,t[p].r = r;
	if(l == r){
		t[p].m = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].m = min(t[p*2].m,t[p*2+1].m);
	return ;
}
void solve(int p){
	if(!solveable)return ;
	if(t[p].l == t[p].r)return ;
	if(abs(t[p*2].m-t[p*2+1].m) != t[p*2].r - t[p*2].l + 1){
		//cout<<abs(t[p*2].m-t[p*2+1].m)<<" compare "<<t[p*2].r - t[p*2].l + 1<<endl;
		solveable = 0;
		return ;
	}
	if(t[p*2].m > t[p*2+1].m){
		ans++;
	}
	solve(p*2);
	solve(p*2+1);
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		solveable = 1;
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		build(1,1,n);
		solve(1);
		if(solveable){
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}

