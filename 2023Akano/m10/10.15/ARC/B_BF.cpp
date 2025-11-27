#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll a,b,v = 1,val = 1,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	for(ll i = 1;i <= b;i++){
		v *= a;
	}
	for(ll i = 1;i*i <= v;i++){
		if(v % i == 0){
			if(i*i == v){
				val *= i;
			}else{
				val *= v;
			}
		}
	}
	while(val % a == 0){
		val /= a;
		ans++;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
