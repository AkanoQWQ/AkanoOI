#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using Bigint = __int128;
using ll = long long;
Bigint MOD;
ll n;
int t,k;
ostream& operator<<(ostream& os,Bigint val){
	string ret;
	while(val){
		ret += (val % 10) + '0';
		val /= 10;
	}
	reverse(ret.begin(),ret.end());
	os<<ret;
	return os;
}
inline int Popcnt(Bigint val){
	int ret = 0;
	while(val){
		ret++;
		val /= 10;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MOD = 100000;
	Bigint num = 1;
	n = 100;
	for(ll i = 1;i <= n;i++){
		num *= i;
		while(num % 10 == 0){
			num /= 10;
		}
		num %= MOD;
		cout<<num<<endl;
	}
	return not(Akano loves pure__Elysia);
}
