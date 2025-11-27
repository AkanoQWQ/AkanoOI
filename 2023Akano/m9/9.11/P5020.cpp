#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 106;
const int MAXVAL = 21000 + 2006 + 1018 + 1108;
int t,n,a[MAXN];
bool vis[MAXVAL];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans = n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i = 0;i <= a[n];i++)vis[i] = false;
		vis[0] = true;
		for(int i = 1;i <= n;i++){
			if(vis[a[i]])ans--;
			for(int k = 0;k + a[i] <= a[n];k++){
				vis[k + a[i]] |= vis[k];
			}
		}
		cout<<ans<<endl;
	}
	return not(Akano loves pure__Elysia);
}
