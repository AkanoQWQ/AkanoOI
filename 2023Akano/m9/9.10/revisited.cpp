#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int TOT_MAXN = 262144 + 1018 + 1108;
const int INF = 1e9;
int n,arr[TOT_MAXN];
namespace Subtask1{
	const int MAXN = 2006 + 1018; 
	int f[MAXN][MAXN],best[MAXN][MAXN],cnts[MAXN],mxval;
	inline ll Solve(){
		ll ret = 0;
		for(int i = 1;i <= n;i++){
			f[i][i] = arr[i];
			mxval = max(mxval,arr[i]);
			best[i][i] = i;
			best[i][n+1] = n;
		}
		mxval += log2(n) + 1;
		for(int len = 2;len <= n;len++){
			for(int l = n - len + 1;l >= 1;l--){
				const int r = l + len - 1;
				f[l][r] = INF;
				int reall = max(l,best[l][r-1]),realr = min(r-1,best[l+1][r]);
				for(int k = reall;k <= realr;k++){
					if(max(f[l][k],f[k+1][r]) + 1 < f[l][r]){
						best[l][r] = k;
					}
					f[l][r] = min(f[l][r],max(f[l][k],f[k+1][r])+1);
				}
			}
		}
		cerr<<"mx "<<mxval<<endl;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				ret += f[i][j];
				for(int k = 1;k <= f[i][j];k++){
					cnts[k]++;
				}
			}
		}
		for(int i = 1;i <= mxval;i++){
			cerr<<i<<" cnts "<<cnts[i]<<endl;
		}
		return ret;
	}
}
bool IsSubtask2 = true;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	cout<<Subtask1::Solve();
	return not(Akano loves pure__Elysia);
}
