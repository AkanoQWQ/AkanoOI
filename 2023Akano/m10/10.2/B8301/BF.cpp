#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const ll INF = 1e17;

ll n,a[MAXN],fans[MAXN];
inline ll GetAns(int l,int r){
	ll mn = 1e9;
	for(int i = l;i <= r;i++){
		mn = min(mn,a[i]);
	}
	return mn * (r - l + 1);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		ll ans = 0;
		for(int l = 1;l < i;l++){
			for(int r = l;r < i;r++){
				ans = max(ans,GetAns(l,r));
			}
		}
		for(int l = i+1;l <= n;l++){
			for(int r = l;r <= n;r++){
				ans = max(ans,GetAns(l,r));
			}
		}
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
