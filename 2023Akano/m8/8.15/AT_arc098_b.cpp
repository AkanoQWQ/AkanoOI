#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int arr[MAXN],sum,sor;
long long ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 0;i <= arr[0];i++){
		cin>>arr[i];
	}
	int r = 0;
	for(int l = 1;l <= arr[0];l++){
		while(r < arr[0] && ((sum + arr[r+1]) == (sor ^ arr[r+1]))){
			++r;
			sum += arr[r],sor ^= arr[r];
		}
		sum -= arr[l],sor ^= arr[l];
		ans += r - l + 1;
	}
	cout<<ans;
	return 0;
}
