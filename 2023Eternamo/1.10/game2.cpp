#include<bits/stdc++.h>
using namespace std;
const int MAXN = 306;
int n;
double f[MAXN][MAXN][MAXN],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	f[0][0][0] = (1<<n);
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				//获得r
				f[i+1][j+1][k] += f[i][j][k] * 0.5;
				//获得l
				if(j > 0){
					f[i+1][j-1][k+1] += f[i][j][k] * 0.5;
				}else{
					f[i+1][0][k] += f[i][j][k] * 0.5;
				} 
			}
		}
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			ans += f[n][i][j] * (n - (2 * j));
		}
	}
	printf("%.3lf",ans / double(1<<n));
	return 0;
}
