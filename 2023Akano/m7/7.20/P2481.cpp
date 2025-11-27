#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 999911659;
const int MAXW = 1018;
const int MAXP = 506;
const int UP = 11;
ll n,p,dp[MAXW][MAXP][UP];
ll dfs(int pos,int sum,int lower){
	sum %= p;
	if(dp[pos][sum][lower] != -1)return dp[pos][sum][lower];
	if(pos == 0)return (sum == 0);
	ll ret = 0;
	for(int i = lower;i <= 9;i++){
		ret += dfs(pos-1,sum * 10 + i,i);
		ret %= MOD;
	}
	dp[pos][sum][lower] = ret;
	return ret;
}
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>p;
	if(n <= 1018){
		cout<<dfs(n,0,1);
	}else{
		if(p == 5){
			cout<<KSM(9,n-1);
		}else if(p == 25){
			cout<<(KSM(9,n-2) * 3) % MOD;
		}
	}
	return 0;
}
