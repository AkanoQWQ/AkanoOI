#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1006;
int n;
double f[2][MAXN][MAXN],ans;//49.475
int main(){
//	freopen("game.in","r",stdin);
	scanf("%d",&n);
	f[0][0][0] = n;
	for(int i = 0;i <= n;i++){
		const int nw = i & 1;
		const int nxt = (i + 1) & 1;
		const int i_div_two = i / 2;
		for(int j = 0;j <= i;j++){
			for(int k = 0;k <= i_div_two;k++){
				f[nxt][j][k] = 0;
			}
		}
		for(int j = 0;j <= i;j++){
			for(int k = 0;k <= i_div_two;k++){
				//获得r
				f[nxt][j+1][k] += f[nw][j][k] * 0.5;
				//获得l
				if(j > 0){
					f[nxt][j-1][k+1] += f[nw][j][k] * 0.5;
				}else{
					f[nxt][0][k] += f[nw][j][k] * 0.5;
				} 
			}
		}
	}
	const int nn = n & 1;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			ans += f[nn][i][j] * (n - (2 * j));
		}
	}
	printf("%.3Lf",ans / (long double)(n));
	return 0;
}
