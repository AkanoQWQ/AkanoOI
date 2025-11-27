#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll n,k;
mt19937_64 rng(time(0));
inline ll rd(ll l,ll r){
	return (rng() % (r - l + 1)) + l;
}
inline bool Get(ll l,ll r){
	cout<<l<<" "<<r<<endl;
	string res;
	cin>>res;
	if(res == "Yes"){
		if(l == r)exit(0);
		return true;
	}
	return false;
}
int main(){
	cin>>n>>k;
	ll l = 1,r = n+1;
	while(true){
		l -= k,r += k;
		l = max(l,1ll),r = min(r,n);
		while(l + 4 * k < r){
			const ll mid = (l + r) >> 1;
			if(Get(l,mid)){
				r = mid;
			}else{
				l = mid + 1;
			}
			l -= k,r += k;
			l = max(l,1ll),r = min(r,n);
		}
		const ll now = rd(l,r);
		Get(now,now);
	}
	return not(Akano loves pure__Elysia);
}
