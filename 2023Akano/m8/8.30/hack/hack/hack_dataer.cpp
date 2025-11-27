#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
Rander rd;
int cnt;
inline void Make(){
	++cnt;
	ll mx1 = 1e10,mx2 = 1e9;
	if(cnt <= 8){
		mx1 = 1e5,mx2 = 1e8;
	}
	ll x,maxval,base,mod;
	maxval = ((1ll * rd() * rd()) % mx1) + 1;
	x = ((1ll * rd() * rd()) % maxval) + 1;
	base = rd(1,mx2),mod = rd(1,mx2);
	while(__gcd(base,mod) == 1){
		base = rd(1,mx2),mod = rd(1,mx2);
	}
	cout<<x<<" "<<maxval<<" "<<base<<" "<<mod<<endl;
	return ;
}
inline void Solve(){
	system("Solve.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("hack",1,20,Make,Solve);
	return not(Akano loves pure__Elysia);
}
