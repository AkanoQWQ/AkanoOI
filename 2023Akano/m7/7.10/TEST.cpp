#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll l,r;
const ll UP = 1e7;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>l>>r){
		cout<<"GCD "<<__gcd(l,r)<<endl;
		bool FD = false; 
		for(ll x = -UP;x <= UP;x++){
			const ll OBJ = 1 - x * l;//y * r;
			if(OBJ % r == 0){
				cout<<x<<" * "<<l<<" + "<<(OBJ / r)<<" * "<<r<<" is "<<1<<endl;
				FD = true;
				break;
			}
		}
		if(!FD){
			cout<<"NOT FOUND"<<endl;
		}
	}
	return 0;
}

