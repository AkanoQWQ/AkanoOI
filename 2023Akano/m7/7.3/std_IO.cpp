#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 2006;
int n,a[MAXN],s[MAXN],best[MAXN][MAXN],f[MAXN][MAXN],ans;
int main(){
	n = Read();
	for(int i = 1;i <= n;i++){
		a[i] = Read();
		a[i+n] = a[i];
	}
	for(int i = 1;i <= 2*n;i++){
		s[i] = s[i-1] + a[i];
		best[i][i] = i;
	}
	for(int len = 2;len <= n;len++){
		for(int l = 1;l+len-1 <= 2 * n;l++){
			const int r = l + len - 1;
			f[l][r] = INF;
			for(int k = best[l][r-1];k <= best[l+1][r];k++){
				const int cost = f[l][k] + f[k+1][r] + s[r] - s[l-1];
				if(cost < f[l][r]){
					f[l][r] = cost;
					best[l][r] = k;
				}
			}
		}
	}
	ans = INF;
	for(int i = 1;i <= n;i++){
		ans = min(ans,f[i][i+n-1]);
	}
	cout<<ans<<endl;
	
	for(int i = 1;i <= 2 *n;i++)best[i][i] = i;
	for(int len = 2;len <= n;len++){
		for(int l = 1;l+len-1 <= 2 * n;l++){
			const int r = l + len-1;
			f[l][r] = 0;
			for(int k = best[l][r-1];k <= best[l+1][r] && k < r;k++){
				const int cost = f[l][k] + f[k+1][r] + s[r] - s[l-1];
				if(cost > f[l][r]){
					f[l][r] = cost;
					best[l][r] = k;
				}
			}
		}
	}
	ans = 0;
	for(int i = 1;i <= n;i++){
		ans = max(ans,f[i][i+n-1]);
	}
	cout<<ans<<endl;
	return 0;
}
