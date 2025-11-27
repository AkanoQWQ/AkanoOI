#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
int n,m,k;
bool team[MAXN];
bool dp[MAXN][MAXN];
int s[MAXN][MAXN];
int main(){
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++){
		cin>>team[i];
	}
	for(int i = 1;i <= m;i++){
		for(int pos = 1;pos <= n;pos++){
			int nxt = pos + 1;
			if(nxt == n + 1)nxt = 1;
			int l = max(1,i - k);
			if(team[pos] == team[nxt]){
				dp[pos][i] = s[nxt][i-1] - s[nxt][l-1];
			}else{
				if(s[nxt][i-1] - s[nxt][l-1] == i-l){
					dp[pos][i] = 0;
				}else{
					dp[pos][i] = 1;
				}
			}
			s[pos][i] = s[pos][i-1] + dp[pos][i];
		}
	}
	for(int i = 1;i <= n;i++){
		if(dp[i][m]){
			putchar(team[i]+'0');
		}else{
			putchar((!team[i])+'0');
		}
		putchar(' ');
	}
	return 0;
}
