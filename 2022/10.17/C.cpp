#include<bits/stdc++.h>
using namespace std;
int t,a[1006],n;
bool judge(int k){
	int l = 1,r = n;
	for(int i = 1;i <= k;i++){
		while(a[r] > k-i+1){
			r--;
		}
		if(l > r)return 0;
		l++;
		r--;
	}
	return 1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(judge(i)){
				ans = i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
