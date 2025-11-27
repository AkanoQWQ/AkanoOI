#include<bits/stdc++.h>
using namespace std;
int cache,mmax = -1,mmin = 1000000,n,i;
int main(){
	freopen("maxspan.in","r",stdin);
	freopen("maxspan.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cache;
		if(cache < mmin){
			mmin = cache;
		}
		if(cache > mmax){
			mmax = cache;
		}
	}
	cout<<mmax-mmin;
	return 0;
}
