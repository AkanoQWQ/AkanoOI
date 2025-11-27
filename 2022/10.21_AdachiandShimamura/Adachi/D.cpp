#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100006;
ll INF = 1;
ll dp[MAXN],h[MAXN],w[MAXN],n;
ll sq(ll a){
	return a*a;
}
void dfs(int pos,ll v){
	dp[pos] = v;
	if(v > dp[n])return ;
	for(int i = 1;i <= n;i++){
		if(i == pos)continue;
		const ll val = sq(h[pos]-h[i]) + w[max(i,pos)-1] - w[min(i,pos)] + v;
		if(val < dp[i] && val < dp[n]){
			dfs(i,val);
		}
	}
	return ;
}
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	for(int i = 1;i <= 56;i++)INF *= 2;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>h[i];
		dp[i] = INF;
	}
	for(int i = 1;i <= n;i++){
		cin>>w[i];
		w[i] += w[i-1];
	}
	dfs(1,0);
	cout<<dp[n];
	return 0;
}
