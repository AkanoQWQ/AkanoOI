#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5003;
int dp[MAXN][MAXN];
bitset<MAXN> team;
int n,m,k;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
bool find(int pos,int val){
	if(val == 0)return 0;
	if(dp[pos][val] != -1)return dp[pos][val];
	int nxt = pos + 1;
	if(nxt == n + 1)nxt = 1;
	dp[pos][val] = 0;
	for(int i = val-1;i >= max(val-k,0);i--){
		if(dp[nxt][i] != -1){
			if(dp[nxt][i] == (team[nxt] == team[pos])){
				dp[pos][val] = 1;
				break;
			}
		}else{
			if(find(nxt,i) == (team[nxt] == team[pos])){
				dp[pos][val] = 1;
				break;
			}
		}
 	}
	return dp[pos][val];
}
int main(){
	n = read(),m = read(),k = read();
	memset(dp,-1,sizeof(dp));
	for(int i = 1;i <= n;i++)dp[i][0] = 0;
	for(int i = 1;i <= n;i++){
		team[i] = read();
	}
	find(1,m-1);
	for(int i = 1;i <= n;i++){
		//find(i,m-1);
		if(dp[i][m-1]){
			putchar(team[i]+'0');
		}else{
			putchar(!team[i]+'0');
		}
		putchar(' ');
	}
	return 0;
}
