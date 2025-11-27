#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;

const int MAXN = 226;
const int MAXR = 140;
int T,n,r;
double f[MAXN][MAXR],_p[MAXN][MAXR],p[MAXN],d[MAXN],ans;
int main(){
	freopen("P3239.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>r;
		for(int i = 1;i <= n;i++){
			cin>>p[i]>>d[i];
			for(int j = 0;j <= r;j++)f[i][j] = 0;
			_p[i][0] = 1;
			for(int j = 1;j <= r;j++)_p[i][j] = _p[i][j-1] * (1-p[i]);
		}
		ans = 0;
		f[0][0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= r;j++){
				f[i][j] += f[i-1][j] * _p[i][r-j];
				if(j > 0)f[i][j] += f[i-1][j-1] * (1-_p[i][r-j+1]);
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= r;j++){
				ans += f[i-1][j] * (1-_p[i][r-j]) * d[i];
			}
		}
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	return 0;
}

