#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXV = 300000;
int n,a[106],ans,vsum;
int mp[MAXV+6],mp2[MAXV+6];
signed main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		vsum += a[i];
	}
	mp[0] = 1;
	for(int j = 1;j <= n;j++){
		for(int k = vsum-a[j];k >= 0;k--){
			if(mp[k]){
				mp[k+a[j]] += mp[k];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		memcpy(mp2,mp,sizeof(mp));
		for(int k = 0;k <= vsum-a[i];k++){
			if(mp2[k]){
				mp2[k+a[i]] -= mp2[k];
			}
		}
		int ans = 0;
		for(int j = 1;j <= vsum;j++){
			ans += (mp2[j] != 0);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
