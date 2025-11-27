#include<bits/stdc++.h>
using namespace std;
const int MAXV = 300000;
int n,a[106],cnt[106],ans,vsum;
bool mp[MAXV+6];
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		vsum += a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(mp,0,sizeof(mp));
		mp[0] = 1;
		int ans = 0;
		for(int j = 1;j <= n;j++){
			if(i == j)continue;
			for(int k = vsum-a[j];k >= 0;k--){
				if(mp[k]){
					mp[k+a[j]] = 1;
				}
			}
		}
		for(int j = 1;j <= vsum;j++){
			ans += mp[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
