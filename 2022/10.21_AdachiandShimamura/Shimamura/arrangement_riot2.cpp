#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 3006;
ll INF = 1,ans = 0;
ll dp[MAXN][MAXN],t[MAXN],s,c[MAXN],n;
int main(){
	freopen("arrangement.in","r",stdin);
	for(int i = 1;i <= 50;i++)INF *= 2;
	ans = INF;
	cin>>n>>s;
	for(int i = 1;i <= n;i++){
		cin>>t[i]>>c[i];
		t[i] += t[i-1];
		c[i] += c[i-1];
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			dp[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;i++){
		dp[i][1] = (t[i] + s) * c[i];
		for(int k = 1;k <= n;k++){
			for(int j = 1;j < i;j++){
				dp[i][k] = min(dp[i][k],dp[j][k-1] + (t[i]+k*s)*(c[i]-c[j]));
			}
		}
	}
	for(int i = 1;i <= n;i++){
		ans = min(ans,dp[n][i]);
	}
	cout<<ans;
	return 0;
}
