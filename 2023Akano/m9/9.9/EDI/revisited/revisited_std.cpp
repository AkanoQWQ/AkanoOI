#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018; 
const int INF = 1e9;
int n,f[MAXN][MAXN];
ll ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>f[i][i];
	}
	for(int len = 2;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			const int r = l + len - 1;
			f[l][r] = INF;
			for(int k = l;k < r;k++){
				f[l][r] = min(f[l][r],max(f[l][k],f[k+1][r])+1);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			ans += f[i][j];
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
