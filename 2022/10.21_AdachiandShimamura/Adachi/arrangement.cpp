#include<bits/stdc++.h>
#define ll int
using namespace std;
const int MAXN = 5006;
const int INF = 0x7fffffff;
ll dp[MAXN][MAXN],t[MAXN],s,c[MAXN],n,ans;
int main(){
	//freopen("P2365_7.in","r",stdin);
	//freopn("arrangement.out","w",stdout);
	ans = INF;
	scanf("%d%d",&n,&s);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&t[i],&c[i]);
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
		for(int k = 2;k <= i;k++){
			for(int j = 1;j < i;j++){
				dp[i][k] = min(1ll * dp[i][k],1ll * dp[j][k-1] + 1ll * (t[i]+k*s)*(c[i]-c[j]));
			}
		}
	}
	for(int i = 1;i <= n;i++){
		ans = min(ans,dp[n][i]);
	}
	printf("%d",ans);
	return 0;
}
