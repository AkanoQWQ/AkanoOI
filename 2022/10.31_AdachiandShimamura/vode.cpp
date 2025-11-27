#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 5003;
bool dp[MAXN][MAXN];
bool fd[MAXN][MAXN];
bool team[MAXN];
int n,m,k;
inline int read(){
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
bool find(int pos,int val){
	if(val == 0)return 0;
	if(fd[pos][val])return dp[pos][val];
	fd[pos][val] = 1;
	int nxt = pos + 1;
	if(nxt == n + 1)nxt = 1;
	dp[pos][val] = 0;
	for(int i = val-1;i >= max(val-k,0);--i){
		if(fd[nxt][i]){
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
	freopen("vode.in","r",stdin);
	freopen("vode.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1;i <= n;i++){
		team[i] = getchar() - '0';
		while(team[i] != 0 || team[i] != 1)team[i] = getchar() - '0';
	}
	for(int i = 1;i <= n;i++){
		if(fd[i][m-1]){
			if(dp[i][m-1]){
				putchar(team[i]+'0');
			}else{
				putchar((!team[i])+'0');
			}
		}else{
			if(find(i,m-1)){
				putchar(team[i]+'0');
			}else{
				putchar((!team[i])+'0');
			}
		}
		putchar(' ');
	}
	return 0;
}
