#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 2e5 + 1018 + 1108;
pii arr[MAXN];
int n,ans[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>arr[i].first;
		arr[i].second = i;
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i <= n/2;i++){
		ans[arr[i].second] = arr[n/2+1].first;
	}
	for(int i = n/2+1;i <= n;i++){
		ans[arr[i].second] = arr[n/2].first;
	}
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<endl;
	}
	cout<<endl;
	return 0;
}

