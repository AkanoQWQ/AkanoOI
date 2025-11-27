#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10 + 18 + 11 + 8;
int a[MAXN],n,k;
double f[MAXN][MAXN],g[MAXN][MAXN],h[MAXN][MAXN];
int main(){
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		g[i][i] = f[i][i] = 1;
	}
	for(int len = 2;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			const int r = l + len - 1;
			for(int x = l;x <= r-1;x++){
				h[l][r] += f[l][x] * g[x+1][r];
			}
			for(int win = l+1;win <= r;win++){
				double poss = double(a[l]) / double(a[l] + a[win]);
				poss *= h[l][win] * f[win][r] / (r - l);
				f[l][r] += poss;
			}
			for(int win = l;win <= r-1;win++){
				double poss = double(a[r]) / double(a[r] + a[win]);
				poss *= h[win][r] * g[l][win] / (r - l);
				g[l][r] += poss;
			}
		}
	}
	printf("%.17lf",g[1][k] * f[k][n]);
	return 0;
}
