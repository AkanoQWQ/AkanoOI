#include<bits/stdc++.h>
using namespace std;
const int MAXV = 300000;
int n,a[106],cnt[106],ans,vsum;
int mp[MAXV+6],mp2[MAXV+6];
int main(){
	freopen("coin.in","r",stdin);
	//freopen("coin.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		vsum += a[i];
	}
	memset(mp,0,sizeof(mp));
	mp[0] = 1;
	for(int j = 1;j <= n;j++){
		for(int k = vsum-a[j];k >= 0;k--){
			if(mp[k]){
				mp[k+a[j]]++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		memcpy(mp2,mp,sizeof(mp2));
		int ans = 0;
		for(int k = vsum-a[i];k >= 0;k--){
			if(mp2[k]){
				mp2[k+a[i]]--;
			}
		}
		for(int j = 1;j <= vsum;j++){
			cout<<mp2[j]<<" ";
			ans += (mp2[j] > 0);
		}
		cout<<endl;
		cout<<a[i]<<":"<<ans<<endl;
	}
	return 0;
}
