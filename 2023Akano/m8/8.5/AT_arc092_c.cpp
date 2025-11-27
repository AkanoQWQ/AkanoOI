#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
ll n,a[MAXN],t,pos,mx = -2e9,ans1 = -1e14,ans2 = -1e14;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		bool allf = true;
		mx = -2e9,ans1 = 0,ans2 = 0;
		cin>>n;
		ans1 = ans2 = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			mx = max(mx,a[i]);
			if(a[i] >= 0)allf = false;
		}
		if(allf){
			cout<<mx<<endl;
			continue;
		}
		for(int i = 1;i <= n;i += 2){
			ans1 += max(a[i],0ll);
		}
		for(int i = 2;i <= n;i += 2){
			ans2 += max(a[i],0ll);
		}
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}
