#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using i128 = __int128;
i128 EXGCD(i128 a,i128 b,i128& x,i128& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	i128 gcd = EXGCD(b,a % b,x,y);
	i128 oldX = x;
	x = y;
	y = oldX - (a / b) * y;
	return gcd;
}
inline ll Solve(i128 a,i128 b,i128 mod){//a * x + mod * y = b
	a = (a + mod) % mod;
	b = (b + mod) % mod;
	i128 x,y;
	i128 gcd = EXGCD(a,mod,x,y);
	if(b % gcd != 0)return -1;
	mod /= gcd;
	x *= b / gcd,y *= b / gcd;
	x = ((x % mod) + mod) % mod;
	return x;
}
ll a,b,c,d;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	while(cin>>a>>b>>c>>d){
 		if(a == 0 && b == 0 && c == 0 && d == 0)break;
 		ll res = Solve(c,b-a,1ll<<d);
 		if(res == -1){
 			cout<<"FOREVER"<<endl;
		}else{
			cout<<res<<endl;
		}
	 }
	return not(Akano loves pure__Elysia);
}
