#include<bits/stdc++.h>
using namespace std;
int r[3006][3006],i,n,k,j,a[3006],sum;
int dp(int t,int s){
	int c,b;
	if(t <= 0)return 0;
	if(t <= s){
		return dp(t-1,t-1-k);
	}
	c = dp(t-2,t-2-k);
	b = dp(t-1,s) + a[t-1];
	cout<<"dp("<<t<<","<<s<<")"<<","<<t<<" "<<s<<" "<<c<<" "<<b<<endl;
	return max(c,b);
}
int main(){
	freopen("robot.in","r",stdin);
	//freopen("robot.out","w",stdout);
	cin>>n>>k;
	for(i = 1;i <= n;i++)cin>>a[i];
	for(i = 1;i <= n;i++){
		
	}
	return 0;
}

