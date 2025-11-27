#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,k;
ll ksm(ll a,ll n,ll p){
	ll ret = 1;
	while(n){
		if(n % 2 == 1){
			ret *= a;
			ret %= p;
		}
		a *= a;
		a %= p;
		n /= 2;
	}
	return ret;
}
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>t>>k;
	while(t--){
		ll y,z,p;
		cin>>y>>z>>p;
		if(k == 1){
			cout<<ksm(y,z,p)<<endl;
		}else if(k == 2){
			if(z == 0){
				cout<<0<<endl;
				continue;
			}
			ll ny = 0;
			bool otp = 0;
			for(ll x = 1;x <= 1e7;x++){
				ny += y;
				if(ny >= p)ny -= p;
				if(ny == z){
					cout<<x<<endl;
					otp = 1;
					break;
				}
			}//Orz, I cannot find x!  这是真心的...... 
			if(otp == 0)cout<<"Orz, I cannot find x!"<<endl;
		}else if(k == 3){
			if(z == 1){
				cout<<0<<endl;
				continue;
			}
			ll ny = 1;
			bool otp = 0;
			for(ll x = 1;x <= 1e7;x++){
				ny *= y;
				ny %= p;
				if(ny == z){
					cout<<x<<endl;
					otp = 1;
					break;
				}
			}//Orz, I cannot find x!  这是真心的...... 
			if(otp == 0)cout<<"Orz, I cannot find x!"<<endl;
		}
	}
	return 0;
}
