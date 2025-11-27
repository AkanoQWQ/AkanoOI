#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int div2 = 499122177;
const int MAXN = 2e5 + 1018 + 1108;
ll n,arr[MAXN],ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	for(int i = 1;i <= n;i++){
		set<ll> st;
		for(int j = i;j <= n;j++){
			st.insert(arr[j]);
			ll val = 0;
			for(auto v : st){
				if(v <= val)break;
				val = ((val + v) * div2) % MOD; 
			}
			cerr<<i<<" "<<j<<" is "<<val<<endl;
			ans = (ans + val) % MOD; 
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}

