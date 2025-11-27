#include<bits/stdc++.h>
using namespace std;
int n,a[302006],i,tail = 0,nums[302006],objective = -1;
long long ans,cnt;
int main(){
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i = 0;i < n;i++){
		if(a[i] != objective){
			nums[tail]++;
			objective = a[i];
			tail++;
		}else{
			nums[tail]++;
		}
	}
	for(i = 0;i < tail;i++){
		cnt += (nums[i] * nums[i]-1)/2;
	}
	ans = (n * (n-1)/2) - cnt;
	cout<<ans;
	return 0;
}//n = 300000时真的不会炸吗?! 

