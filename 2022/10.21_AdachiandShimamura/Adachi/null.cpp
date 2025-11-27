#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2006;
ll INF = 1;
ll dp[MAXN][MAXN],n,m,x[MAXN];
ll sq(ll a){
	return a*a;
}
ll Solve2(){
	ll ret = INF;
	for(int i = 1;i <= n;i++){
		ret = min(ret,sq(x[i]+1) + sq(x[n] - x[i] + 1));
	}
	return ret;
}
int main(){
	freopen("null.in","r",stdin);
	freopen("null.out","w",stdout);
	for(int i = 1;i <= 56;i++)INF *= 2;
	cin>>n>>m;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			dp[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;i++){
		cin>>x[i];
		x[i] += x[i-1];
		dp[i][1] = sq(x[i] + 1);
	}
	if(m == 2){
		cout<<Solve2();
		return 0;
	}
	for(int j = 2;j <= m;j++){
		for(int i = 2;i <= n;i++){
			for(int k = 1;k < i;k++){
				dp[i][j] = min(dp[i][j],dp[k][j-1] + sq(x[i] - x[k] + 1));
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}

