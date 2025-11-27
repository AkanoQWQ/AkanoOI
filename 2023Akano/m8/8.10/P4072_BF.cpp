#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018;
const int MAXM = MAXN;
const int INF = 1e9;
ll len[MAXN],sum[MAXN],dp[MAXM][MAXN],n,m;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P4072.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>len[i];
		sum[i] = sum[i-1] + len[i];
	}
	for(int i = 1;i <= n;i++)dp[0][i] = INF;
	for(int i = 1;i <= m;i++)dp[i][0] = sum[n] * sum[n];
	for(int i = 1;i <= m;i++){
		for(int j = 0;j <= n;j++){
			if(j != 0)dp[i][j] = INF;
			for(int k = 0;k < j;k++){
				const int nowx = sum[j] - sum[k];
				dp[i][j] = min(dp[i][j],dp[i-1][k] + m * nowx * nowx - 2 * sum[n] * nowx);
			}
			cout<<i<<","<<j<<" dp "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
