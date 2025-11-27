#include<bits/stdc++.h>
using namespace std;
int maxm[4000][4000],a[100006],n,k,ans = 1,i,j,mmax,mmin,ii;
int main(){
	freopen("maxm.in","r",stdin);
	freopen("maxm.out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			mmax = -1,mmin = 999999999;
			for(ii = i;ii < j;ii++){
				mmax = max(mmax,a[ii]);
				mmin = min(mmin,a[ii]);
			}
			maxm[i][j] = mmax - mmin;
		}
	}
	for(i = n;i > 0;i--){
		if(i < ans){
			break;
		}
		for(j = 0;(i+j) < n;j++){
			if(maxm[j][j+i] <= k){
				ans = max(ans,i);
			}
		}
	}
	cout<<ans;
	return 0;
}

