#include<bits/stdc++.h>
using namespace std;
long long r[3006][3006],i,n,k,j,a[3006],sum;
int dp(int t,int s){
	int c,b;
	if(t <= 0)return 0;
	if(t <= s){
		return dp(t-1,t-1-k);
	}
	if(t-2-k >= 0){
		if(r[t-2][t-2-k] == 0 && t-2-k >= 0){
			c = dp(t-2,t-2-k);
			r[t-2][t-2-k] = c;
		}else{
			c = r[t-2][t-2-k];
		}
	}else{
		c = dp(t-2,t-2-k);
	}

	if(t-1 > 0){
		if(r[t-1][s] == 0 && t-1 > 0){
			b = dp(t-1,s) + a[t-1];
			r[t-1][s] = b;
		}else{
			b = r[t-1][s];
		}
	}else{
		b = dp(t-1,s) + a[t-1];
	}
	return max(c,b);
}
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	cin>>n>>k;
	for(i = 1;i <= n;i++)cin>>a[i];
	cout<<dp(n+1,n+1-k);
	return 0;
}

