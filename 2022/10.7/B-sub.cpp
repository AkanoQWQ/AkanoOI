#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,l,r,ans;
ll sq(ll a){
	return a*a;
}
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&l,&r);
		ll lef = (long long)(sqrt(l));
		if(lef * lef < l)lef++;
		ll rig = (long long)(sqrt(r));
		ans = (rig-lef) * 3+1;
		if(lef*lef-1 >= l)ans++;
		if(lef*lef-lef >= l)ans++;
		if(sq(rig+1)-1 <= r)ans++;
		if(sq(rig+1)-rig-1 <= r)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
