#include<bits/stdc++.h>
using namespace std;
const int MAXN = 506;
int t,n,a[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		int ans = 1e9;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		for(int i = 1;i < n;i++){
			ans = min(ans,max(0,(a[i+1] - a[i] + 2) / 2));
		}
		cout<<ans<<endl;
	}
	return 0;
}

