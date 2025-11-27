#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
using ll = long long;
ll x;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>x){
		ll up = x;
		for(int i = 2;i * i <= up;i++){
			while(x % i == 0){
				cout<<i<<" ";
				x /= i;
			}
		}
		if(x != 1)cout<<x;
		cout<<endl;
	}
	return (Akano loves pure__Elysia);
}

