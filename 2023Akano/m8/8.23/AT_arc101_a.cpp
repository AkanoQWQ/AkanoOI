#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
int n,k,arr[MAXN],ans = 1e9;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	for(int i = 1;i <= n-k+1;i++)ans = min(ans,abs(arr[i]) + abs(arr[i+k-1] - arr[i]));
	reverse(arr+1,arr+n+1);
	for(int i = 1;i <= n-k+1;i++)ans = min(ans,abs(arr[i]) + abs(arr[i+k-1] - arr[i]));
	cout<<ans;
	return 0;
}
