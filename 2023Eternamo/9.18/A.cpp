#include<bits/stdc++.h>
using namespace std;
int t,n,k,x;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>x;
		if(n < k || x < k-1){
			cout<<-1<<endl;
			continue;
		} 
		int ans = 0;
		ans += (k - 1) * k / 2;
		n -= k;
		if(x == k){
			ans += n * (k-1); 
		}else{
			ans += n * x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
