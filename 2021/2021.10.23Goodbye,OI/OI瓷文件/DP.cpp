#include<bits/stdc++.h>
using namespace std;
int dp[10006],i,n = 100;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	dp[0] = 0,dp[1] = 1;
	i = 2;//0 1 1 3 5 11 21 43 85 171 341
	while(i <= n){
		dp[i] = dp[i-2]*2 + dp[i-1],i++;
	}
	for(i = 0;i <= n;i++)cout<<dp[i]<<" ";
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			for(k = 0;k < n;k++){
				makedin(p[i],p[j],k);
			}
		}
	}
	for(i=1;i<=3300;i++)a[i*i]=1;
	for(i=ceil[n/2];i<=n;i++){
	if(a[n*n-i*i]==1)total++;
	}
	return 0;
}

