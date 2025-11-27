#include<bits/stdc++.h>
using namespace std;
long long mmin = 100000,mmax,n,i,cache,c2,ans;


int main(){
	freopen("share.in","r",stdin);
	freopen("share.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cache;
		if(cache < c2){
			ans += c2 - mmin;
			mmin = cache;
		}
		if(cache < mmin)mmin = cache;
		c2 = cache;
	}
	ans += cache - mmin;
	cout<<ans;
	
	return 0;
}
