#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
const int MAXLGN = 25;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
int n,m,lgn;
int st[MAXN][MAXLGN];
int lg[MAXN];
int main(){
	//freopen("P3865_4.in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(),m = read();
	lg[1] = 0,lg[2] = 1;
	for(int i = 3;i < MAXN;i++){
		lg[i] = lg[i/2] + 1;
	}
	lgn = lg[n];
	for(int i = 1;i <= n;i++){
		st[i][0] = read();
	}
	for(int i = 1;i <= lgn;i++){
		for(int j = 1;j <= n && (j+(1<<(i-1)) <= n);j++){
			st[j][i] = max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	while(m--){
		int l = read(),r = read();
		const int k = lg[r-l+1];
		printf("%d\n",max(st[l][k],st[r-(1<<k)+1][k]));
	}
	return 0;
}

