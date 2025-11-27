#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 19260817;
ll ExGcd(ll a,ll b,ll& x,ll& y){
	if(b == 0){
		x = 1,y = 0;
	}
		return a;
	ll ret = ExGcd(b,a%b,x,y);
	cout<<"in "<<a<<" and "<<b<<" "<<x<<" and "<<y<<endl;
	ll tempx = x;
	x = y;
	y = tempx - (a/b) * y;
	return ret;
}
ll x,y,a,b;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	ll gcd = ExGcd(b,MOD,x,y);
	cout<<gcd<<" ? "<<x<<" "<<y<<endl;
	if(a % gcd != 0){
		cout<<"Angry!"<<endl;
	}else{
		cout<<x * (a / gcd)<<endl;	
	}
	return 0;
}

