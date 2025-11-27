#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int INF = 0x7fffffff;
int dp[MAXN],h[MAXN],w[MAXN],n;
int sq(int a){
	return a*a;
}
int main(){
	freopen("sample1.in","r",stdin);
	//freopen("D.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>h[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>w[i];
		w[i] += w[i-1];
		cout<<i<<":"<<w[i]<<endl;
	}
	dp[1] = 0;
	cout<<0<<endl;
	for(int i = 2;i <= n;i++){
		dp[i] = INF;
		for(int j = 1;j < i;j++){
			//cout<<j<<" to "<<i<<":"<<dp[j]+sq(h[i]-h[j])<<"+"<<w[i]-w[j-1]<<endl;
			dp[i] = min(dp[i],dp[j]+sq(h[i]-h[j])+w[i]-w[j-1]);
		}
		cout<<dp[i]<<endl;
	}
	cout<<dp[n];
	return 0;
}

