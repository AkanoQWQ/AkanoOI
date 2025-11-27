#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 77;
const int MAXV = 350;
const int INF = 1e7;
int f[MAXN][MAXN][MAXV],n,a[MAXN],tot;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		tot = max(tot,a[i]+2);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 0;k <= tot;k++){//?tot OK?
				f[i][j][k] = INF;
			}
		}
		f[i][i][a[i]/2] = a[i];
		int val = a[i]/2;
		for(int r2 = i+1;r2 <= n;r2++){
			if(val < a[r2]){
				f[i][r2][a[r2]/2] = min(f[i][r2][a[r2]/2],a[i] + a[r2] - val);//把最后的val用掉 
				break;
			}
			f[i][r2][val/2] = min(f[i][r2][val/2],a[i]);
			val /= 2;
		}
	}
	for(int len = 2;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			const int r = l + len - 1;
			for(int k = 1;k < len;k++){
				const int d = l + k - 1;
				for(int lv = 0;lv <= tot;lv++){
					if(f[l][d][lv] >= INF)continue;//优化很大? 
					for(int rv = 0;lv + rv <= tot;rv++){
						f[l][r][lv+rv] = min(f[l][r][lv+rv],
							f[l][d][lv] + f[d+1][r][rv]
						);
					}
				}
			}
			for(int nowv = 0;nowv <= tot;nowv++){
				int val = nowv;
				for(int r2 = r+1;r2 <= n;r2++){
					if(val < a[r2]){
						f[l][r2][a[r2]/2] = min(f[l][r2][a[r2]/2],f[l][r][nowv] + a[r2] - val);//把最后的val用掉 
						break;
					}
					f[l][r2][val/2] = min(f[l][r2][val/2],f[l][r][nowv]);
					val /= 2;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		int ans = INF;
		for(int j = 0;j <= tot;j++){
			ans = min(ans,f[1][i][j]);
		}
		cout<<ans<<" ";
	}
	return not(Akano loves pure__Elysia);
}

