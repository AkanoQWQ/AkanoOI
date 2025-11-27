#include<bits/stdc++.h>
using namespace std;
long long n,t,c,ct,ans = 200611080514;
int main(){
	freopen("routes.in","r",stdin);
	freopen("routes.out","w",stdout);
	cin>>n>>t;
	while(n--){
		cin>>c>>ct;
		if(ct > t)continue;
		ans = min(ans,c);
	}
	if(ans == 200611080514){
		cout<<"TLE";
		return 0;
	}else{
		cout<<ans;
	}
	
	return 0;
}

