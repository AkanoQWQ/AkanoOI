//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 37000006;
const int MOD = 1e9 + 7;
int TT,n,a[MAXN]; 
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
int ans,tong[MAXN],p[MAXN],mex,cnt,pos,dp[MAXN];
EXCUTE_ST
	freopen("clods.in","r",stdin);
	freopen("clods.out","w",stdout);
	TT = read();
	while(TT--){
		n = read();
		ans = 0;
		if(n == MAXN-6){
			int x = read(),y = read();
			a[1] = 0;
			for(int i = 2;i <= n;i++){
				a[i] = (1ll * a[i-1] * x + y + i) & 262143; 
			}
		}else{
			for(int i = 1;i <= n;i++){
				a[i] = read();
			}
		}
		memset(tong,0,sizeof(tong));
		for(int i = 1;i <= n;i++){
			p[i] = tong[a[i]];
			tong[a[i]] = i;
 		}
		for(int i = 0;i <= n+1;i++){
			if(tong[i] == 0){
				mex = i;
				break;
			}
		}
		pos = n;
		for(int i = 0;i < mex;i++){
			pos = min(pos,tong[i]);
		}
		for(int i = n;i >= 1;i--){
			pos = min(pos,i);
			tong[i] = pos;
			if(a[i] < mex){
				pos = min(pos,p[i]);
			} 
		}
		dp[0] = 1;
		for(int i = 1;i <= n;i++){
			if(tong[i] > 0){
				dp[i] = dp[tong[i]-1];
			}else{
				dp[i] = 0;
			}
			dp[i] += dp[i-1];
			dp[i] %= MOD;
		}
		write((dp[n] - dp[n-1] + MOD)%MOD),putchar('\n');
	}
FILE_ED_And_excute
