#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int base = 11;
const int mod = 10181108;
long long MyHash(long long x){
	long long a = base,hashVal = 1;
	while(x){
		if(x & 1)hashVal = (hashVal * a) % mod;
		a = (a * a) % mod;
		x >>= 1;//等价于 x /= 2; 
	}
	return hashVal;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cerr<<__gcd(base,mod)<<endl;
	return not(Akano loves pure__Elysia);
}
//如果实在你实在看不懂这段代码,提示一下这是一个快速幂 
