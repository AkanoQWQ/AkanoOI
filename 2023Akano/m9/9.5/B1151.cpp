#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1018;
int n,m,arr[MAXN];
ll f[MAXN][MAXN],suf1[MAXN],suf2[MAXN][MAXN];//用了i个炸弹,最后位置为j右边带来的最大收益
int best[MAXN][MAXN];
inline ll Value(int l,int r){
	return suf2[r][r+1] - suf2[l][r+1];
}
inline ll Solve(){
	ll ret = 0;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	suf1[n+1] = 0;
	for(int i = n;i >= 1;i--){
		suf1[i] = suf1[i+1] + arr[i];
	}
	for(int i = 1;i <= n;i++){
		suf2[0][i] = 0;
		for(int j = 1;j <= i;j++){
			suf2[j][i] = suf2[j-1][i] + arr[j] * suf1[i];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			ret += arr[i] * arr[j];
		}
	}
	for(int i = 1;i <= m;i++){
		best[i][n+1] = n;
		for(int j = n;j >= 1;j--){
			f[i][j] = 0;//清空? 
			for(int k = best[i-1][j];k <= best[i][j+1];k++){
				if(f[i-1][k] + Value(k,j) > f[i][j]){
					best[i][j] = k;
					f[i][j] = f[i-1][k] + Value(k,j);
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0;i <= n;i++)ans = max(ans,f[m][i]);
	return ret - ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n>>m){
		if(n == 0 && m == 0)break;
		cout<<Solve()<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
