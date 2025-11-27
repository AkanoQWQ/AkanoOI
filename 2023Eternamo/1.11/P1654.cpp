#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int n;
double p[MAXN],f[3][MAXN],g[MAXN];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>p[i];
		f[1][i] = (f[1][i-1] + 1) * p[i];
		f[2][i] = (f[2][i-1] + 2 * f[1][i-1] + 1) * p[i];
		g[i] = g[i-1] * (1-p[i]) /*0*/+ (g[i-1] + 3 * f[2][i-1] + 3 * f[1][i-1] + 1)* p[i];
	}
	printf("%.1lf",g[n]);
	return 0;
}

