#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(long long b = k+1;b <= n;b++){
		ans += (b-k) * (n/b);
		long long up = (n/b) * b + 1;
		if(up > n)continue;
		if(n - up + 1 >= max(k-1,0ll))ans += n - up - max(k-1,0ll) + 1;
	}
	cout<<ans;
	return 0;
}
