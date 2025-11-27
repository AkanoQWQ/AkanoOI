#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
int t,n,a[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		int maxR = -1e9,ans = -1e9;
		int maxMid = -1e9;
		for(int i = n;i >= 1;i--){
			ans = max(ans,a[i] + i + maxMid);
			maxMid = max(maxMid,a[i] + maxR);
			maxR = max(maxR,a[i] - i);
		}
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
