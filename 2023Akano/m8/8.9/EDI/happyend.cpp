#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
ll P(ll inx){
	return inx * inx;
}
const int MAXN = 1e3 + 1018 + 1108;
ll t,n,h[MAXN],c[MAXN],dp[MAXN][MAXN],mn[MAXN],useless;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("happyend.in","r",stdin);
	freopen("happyend.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++)cin>>h[i];
		for(int i = 1;i <= n;i++)cin>>c[i];
		for(int i = 1;i < n;i++)cin>>useless>>useless;
		mn[n+1] = 0;
		for(int u = n;u >= 1;u--){
			mn[u] = INF;
			for(int st = n;st > u;st--){//Ã¶¾ÙÆðµã 
				dp[u][st] = dp[u+1][st] + P(c[st]) + c[st] * (n-u);
				mn[u] = min(mn[u],dp[u][st]);
			}
			dp[u][u] = mn[u+1] - h[u] + P(c[u]) + c[u] * (n-u);
			mn[u] = min(mn[u],dp[u][u]);
		}
		cout<<mn[1]<<endl;
	}
	return 0;
}

