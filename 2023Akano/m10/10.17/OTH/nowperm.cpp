#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018 + 1108;
const int INF = 1e8;
bool vis[MAXN][MAXN];
int f[MAXN][MAXN],n,q,a[MAXN],logval2[MAXN * 2];
int F(int x,int y){
	if(vis[x][y]){
		f[x][y] = -INF;
		return -INF;
	}
	if(x == y)return 1;
	if(f[x][y] != -1)return f[x][y];
	vis[x][y] = true;
	f[x][y] = F(x + y - abs(x-y),abs(x-y)) + 1;
	vis[x][y] = false;
	return f[x][y];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("perm/perm1.in","r",stdin);
//	freopen("perm/perm2.out","w",stdout);
	memset(f,-1,sizeof(f));
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 0;i <= 2*n;i++){
		logval2[i] = -INF;
	}
	logval2[1] = 0;
	for(int i = 2;i <= 2*n;i++){
		if(i % 2 == 0)logval2[i] = logval2[i / 2] + 1;
	}
	cin>>q;
	while(q--){
		long long ans = 0;
		int l,r;
		cin>>l>>r;
		for(int i = l;i <= r;i++){
			for(int j = i+1;j <= r;j++){
				int sum = (a[i] + a[j]) / __gcd(a[i],a[j]);
				if(logval2[sum] >= 0){
					cerr<<i<<" and "<<j<<"!"<<endl;
					ans += logval2[sum];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
