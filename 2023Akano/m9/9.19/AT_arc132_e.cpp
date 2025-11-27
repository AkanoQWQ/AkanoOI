#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int MOD = 998244353;
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll a,ll b){
	return (a * KSM(b,MOD-2)) % MOD;
}
int n,lft[MAXN],point[MAXN],lst = 0;
ll ans,f[MAXN];
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>str;
	str = "." + str + ".";
	f[0] = 1;
	for(int i = 1;i <= n+1;i++){
		f[i] = (f[i-1] * Div(2*i-1,(2*i))) % MOD;
		lft[i] = lft[i-1] + (str[i] == '<');
		point[i] = point[i-1] + (str[i] == '.');
	}
	point[n+1] = point[n]; 
	for(int i = 1;i <= n+1;i++){
		if(str[i] == '.'){
			ll tot = lst + (lft[i] - lft[lst]);
			ans += (((tot * f[point[lst]]) % MOD) * f[point[n] - point[i-1]]) % MOD;
			ans = ((ans % MOD) + MOD) % MOD; 
			lst = i;
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
