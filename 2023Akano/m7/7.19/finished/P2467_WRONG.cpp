#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4206;
int dp[MAXN][MAXN],n,mod,ans;
inline int Solve1(){
	dp[1][1] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			dp[i+1][j+1] = (dp[i+1][j+1] + 1ll * dp[i][j] * j) % mod;
			if(j >= 1){
				dp[i+1][j-1] = (dp[i+1][j-1] + 1ll * dp[i][j] * j) % mod;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		cout<<dp[n][i]<<" ";
	}
	cout<<endl;
	return (dp[n][1] * 2)%mod;
}
inline int Solve2(){
	dp[1][1] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			dp[i+1][j+1] = (dp[i+1][j+1] + 1ll * dp[i][j] * j) % mod;
			if(j >= 1){
				dp[i+1][j-1] = (dp[i+1][j-1] + 1ll * dp[i][j] * j) % mod;
			}
		}
	}
	return dp[n][2]%mod;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>mod;
	if(n % 2 == 1){
		cout<<Solve1()<<endl;
	}else{
		cout<<Solve2()<<endl;
	}
	return 0;
}
