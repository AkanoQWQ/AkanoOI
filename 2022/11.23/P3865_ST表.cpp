#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int n,m,st[MAXN][22],lg2[MAXN];
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
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		st[i][0] = read();
	}
	lg2[1] = 0;
	lg2[2] = 1;
	for(int i = 3;i <= n;i++){
		lg2[i] = lg2[i/2] + 1;
	}
	for(int i = 1;i <= 20;i++){
		for(int j = 1;j <= n;j++){
			const int obj = j + (1<<(i-1));
			if(obj <= n){
				st[j][i] = max(st[j][i-1],st[obj][i-1]);
			}
		}
	}
	while(m--){
		int l = read(),r = read();
		int k = lg2[r - l + 1];
		printf("%d\n",max(st[l][k],st[r-(1<<k)+1][k]));
	}
	return 0;
}
