#include<bits/stdc++.h>
using namespace std;
priority_queue <int> num;
int i,j,n,cache,snum[5006],bnum[5006],inin,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>cache;
		num.push(cache);
	}
	if(n%2){
		for(i = 0;i < n/2;i++){
			bnum[i] = num.top();
			num.pop();
		}
		inin = num.top();
		for(i = 0;i < n/2;i++){
			snum[i] = num.top();
			num.pop();
		}
		for(i = 0;i < n/2;i++){
			cache = bnum[i]+snum[n/2-i];
			if(cache > ans)ans = cache;
		}
		if(inin > ans)ans = inin;
	}else{
		for(i = 0;i < n/2;i++){
			bnum[i] = num.top();
			num.pop();
		}
		for(i = 0;i < n/2;i++){
			snum[i] = num.top();
			cout<<snum[i]<<" ";
			num.pop();
		}
		for(i = 0;i < n/2;i++){
			cache = bnum[i]+snum[n/2-1];
			//cout<<bnum[i]<<" "<<snum[n/2-i]<<endl;
			if(cache > ans){
				ans = cache;
			}
		}
	}
	cout<<ans;
	return 0;
}
