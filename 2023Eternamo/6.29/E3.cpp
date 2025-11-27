#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1526;
const int MOD = 1e9 + 7;
ll s[2][MAXN][MAXN],n,k,pos[MAXN],b,now = 0,lst = 1,ans,cnt;
bool bs[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>bs[i];cnt += bs[i];
	}
	if(cnt > n / 2){
		for(int i = 1;i <= n;i++){
			bs[i] = !bs[i];
		}
	}
	for(int i = 1;i <= n;i++){
		if(bs[i])pos[++b] = i;
	}
	for(int i = 0;i <= n;i++)s[0][0][i] = 1;
	for(int i = 1;i <= b;i++){
		swap(now,lst);
		for(int j = 0;j <= k;j++){
			s[now][j][0];
			for(int x = 1;x <= n;x++){
				const int use_step = j - abs(x-pos[i]);
				if(use_step < 0){
					s[now][j][x] = s[now][j][x-1];
					continue;
				}
				s[now][j][x] = s[now][j][x-1] + s[lst][use_step][x-1];
				while(s[now][j][x] >= MOD)s[now][j][x] -= MOD;
			}
		}
	}
	for(int j = 0;k - 2 * j >= 0;j++){
		ans += s[now][k-2*j][n];
		while(ans >= MOD)ans -= MOD;
	}
	cout<<ans<<endl;
	return 0;
}

