#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using Bigint = __int128;
using ll = long long;
Bigint MOD,TOTMOD;
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
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	cin>>t;
	TOTMOD = 1;
	for(int i = 1;i <= 32;i++)TOTMOD *= 10;
	while(t--){
		cin>>n>>k;
		MOD = 1;
		for(int i = 1;i <= k;i++)MOD *= 10;
		Bigint num = 1;
		for(ll i = 1;i <= n;i++){
			num *= i;
			while(num % 10 == 0){
				num /= 10;
			}
			num %= TOTMOD;
		}
		num %= MOD;
		int res = k - Popcnt(num);
		for(int i = 1;i <= res;i++)cout<<0;
		cout<<num<<endl;
	}
	return not(Akano loves pure__Elysia);
}
