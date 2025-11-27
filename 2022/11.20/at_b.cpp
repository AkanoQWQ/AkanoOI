#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 6;
int n,l,a[MAXN],ans = 1ll * 0x7fffffff / 2 * 0x7fffffff;
signed main(){
	cin>>n>>l;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	a[n+1] = l;
	for(int i = 1;i <= n;i++){
		int mtpos = l - a[i];
		const int ml = lower_bound(a+1,a+n+1,mtpos) - a - 1;
		const int mr = ml + 1;		
		int addcost;
		if(ml == 0){
			addcost = a[mr] - mtpos;
		}else if(mr == n+1){
			addcost = mtpos - a[ml];
		}else{
			addcost = min(mtpos - a[ml],a[mr] - mtpos);
		}
		ans = min(ans,2*addcost);
	}
	ans += 2 * l;
	cout<<ans;
	return 0;
}
