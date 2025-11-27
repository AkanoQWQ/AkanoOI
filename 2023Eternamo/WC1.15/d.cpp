#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 3;
int n,k,dp[MAXN],a[MAXN];
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
void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(),k = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= k;j++){
			if(j+1 <= k){
				dp[i+1][j+1] = 
			}
		}
	}
	return 0;
}

