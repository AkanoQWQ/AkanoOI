#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll GCD(ll a,ll b){
	if(b == 0)return a;
	return GCD(b,a % b);
}
inline ll LCM(ll a,ll b){
	return a / GCD(a,b) * b;
}
ll n,a0,a1,b0,b1;
inline bool Judge(ll x){
	return (GCD(x,a0) == a1) && (LCM(x,b0) == b1);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a0>>a1>>b0>>b1;
		int ans = 0;
		for(int dnum = 1;dnum * dnum <= b1;dnum++){
			if(b1 % dnum == 0){
				if(Judge(dnum))ans++;
				if(dnum * dnum != b1 && Judge(b1 / dnum))ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
