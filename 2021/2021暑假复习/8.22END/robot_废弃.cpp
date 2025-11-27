#include<bits/stdc++.h>
using namespace std;
int r[2006][2006],i,n,k,j,a[2006],sum;
int dp(int t,int s){
	int c,b;
	//cout<<"dp("<<t<<","<<s<<")"<<endl;
	if(t <= 0)return 0;
	if(t <= s){
		return dp(t-1,t-1-k);
	}
	/*if(s <= 0){
		cout<<"dp("<<t<<","<<s<<")"<<","<<t<<" "<<s<<" "<<a[t]<<endl;
		return a[t];
	}*/
	c = dp(t-2,t-2-k);
	b = dp(t-1,s) + a[t-1];//469686
	
	
	//cout<<"dp("<<t<<","<<s<<")"<<","<<t<<" "<<s<<" "<<c<<" "<<b<<endl;
	return max(c,b);
}
//1 2 3 4 5 6 
int main(){
	freopen("robot.in","r",stdin);
	//freopen("robot.out","w",stdout);
	cin>>n>>k;
	for(i = 1;i <= n;i++)cin>>a[i];
	cout<<dp(n+1,n+1-k);
	return 0;
}

