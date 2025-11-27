#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const bool OTP = false;
const int MAXN = 5e5 + 1018 + 1108;
const double INF = 1e16;
inline double P(ll inx){
	return inx * inx;
}
int n,m;
struct BaseStation{
	ll x,r,v;
}s[MAXN];
double dp[MAXN],ans = INF;
inline double Cost(int l,int r){
	const double deltaX = s[r].x - s[l].x;
	return deltaX / (2 * sqrt(s[l].r));
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P2497.in","r",stdin);
if(!OTP)		freopen("P2497.ans","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s[i].x>>s[i].r>>s[i].v;
		dp[i] = INF;
	}
	dp[1] = s[1].v;
	for(int i = 2; i <= n; i++){
		for(int j = 1;j < i;j++){
			dp[i] = min(dp[i],dp[j] + Cost(j,i) + s[i].v);
if(OTP)			cout<<"from "<<j<<" "<<dp[i]<<endl;
		}
		if(m - s[i].x <= s[i].r){
			ans = min(ans,dp[i]);
		}
		cout<<i<<" dp "<<dp[i]<<endl;
	}
	cout<<fixed<<setprecision(3)<<ans<<endl;
	return 0;
}
