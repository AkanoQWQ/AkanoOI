#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200006],c,j,i,ans,cans,kk;
int main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){
			if(a[i] > a[j]){
				c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		} 
	}
	for(i = 0;i < n;i++){
		for(j = n-1;j > i;j--){
			if(a[j] - a[i] <= k){
				cans = j - i;
				if(cans > ans){
					ans = cans;
				}
			}
		} 
	}
	cout<<ans;
	return 0;
}
