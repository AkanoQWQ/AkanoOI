#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll q,a,b;
ll Solve(ll x){
	ll ret = 0;
	ret = ll(sqrt(x)) * 2;
	cout<<"ORG "<<ret<<endl;
	ll m = floor(double(x) / a);
	ll mx = a * m + m - 1;
	if(x <= mx)--ret;
	cout<<a*m<<" to "<<mx<<" in "<<m<<endl;
	m = floor(double(x) / b);
	mx = b * m + m - 1;
	if(x <= mx)--ret;
	cout<<b*m<<" to "<<mx<<endl;
	return ret;	
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>q;
	while(q--){
		cin>>a>>b;
		cout<<Solve(a*b-1)<<endl;
	}
	return 0;
}

