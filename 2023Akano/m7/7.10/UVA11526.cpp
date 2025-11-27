#include<bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll Solve(ll x){
	ll ret = 0,l = 1,r = 0;
	while(l <= x){
		const ll r = x / (x / l);
		ret += (r - l + 1) * (x / l);
		l = r + 1;
	}
	return ret;
}
ll t,n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<Solve(n)<<endl;
	}
	return 0;
}
