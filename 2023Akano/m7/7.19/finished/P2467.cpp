#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4206;
int dp[2][MAXN],n,mod,ans,now = 1,pre = 0;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>mod;
	dp[now][1] = 1;
	for(int i = 1;i <= n;i++){
		swap(now,pre);
		for(int j = 1;j <= i;j++){
			dp[now][j] = (dp[now][j-1] + dp[pre][i-j+1]) % mod;
		}
	}
	for(int i = 1;i <= n;i++)ans = (ans + dp[now][i]) % mod;
	cout<<(ans*2)%mod<<endl;
	return 0;
}
