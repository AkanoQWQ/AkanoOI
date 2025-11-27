#include<bits/stdc++.h>
using namespace std;
const int MAXN = 206;
int n,t,dp[MAXN],ans;
string str[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>t;
	for(int i = 1;i <= n;i++){
		cin>>str[i];
	}
	for(int i = 1;i <= t;i++){
		bool OK = true;
		for(int j = 1;j <= n;j++){
			if(str[j][i-1] == 'x')OK = false;
		}
		if(OK)dp[i] = dp[i-1] + 1;
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

