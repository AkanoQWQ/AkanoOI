#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 300006;
ll INF = 1;
ll dp[MAXN],t[MAXN],s,c[MAXN],n;
int main(){
	freopen("arrangement.in","r",stdin);
	for(int i = 1;i <= 60;i++)INF *= 2;
	cin>>n>>s;
	for(int i = 1;i <= n;i++){
		cin>>t[i]>>c[i];
		t[i] += t[i-1];
		c[i] += c[i-1];
	}
	for(int i = 1;i <= n;i++){
		dp[i] = (t[i] + s) * c[i];
		cout<<"pre"<<i<<":"<<dp[i]<<endl;
		int zy = 0;
		for(int j = 1;j < i;j++){
			dp[i] = min(dp[i],dp[j] + (t[i]+s)*(c[i]-c[j]));
			if(dp[i] == dp[j] + (t[i]+s)*(c[i]-c[j])){
				zy = j;
			}
		}
		cout<<i<<":"<<dp[i]<<" with "<<zy<<endl;
	}
	cout<<dp[n];
	return 0;
}

