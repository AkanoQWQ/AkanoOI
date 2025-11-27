#include<bits/stdc++.h>
using namespace std;
int n,k,pos = 1,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	while(pos < n){
		pos = pos + k - 1;
		ans++;
	}
	cout<<ans;
	return 0;
}
