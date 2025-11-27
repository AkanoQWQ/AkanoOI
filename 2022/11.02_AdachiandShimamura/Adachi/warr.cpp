#include<bits/stdc++.h>
using namespace std;
const int MAXN = 12;
const int MAXPOP = 1<<(MAXN-3) + 2;
int n,m,pop;
int f[MAXPOP][MAXN],w[MAXPOP][MAXN],dp[MAXPOP*2+1][MAXPOP*2+1],ans;
void dfs(int p,int stat,int sze){
	for(int i = 0;i <= sze;i++){
		dp[p][i] = 0;
	}
	if(sze == 1){
		for(int i = 0;i < n - 1;i++){
			if(stat & (1<<i)){//1 war
				dp[p][1] += w[p-pop+1][i+1];
			}else{
				dp[p][0] += f[p-pop+1][i+1];
			}
		}
		return ;
	}
	for(int newstat = 0;newstat <= 1;newstat++){
		dfs(p*2,stat*2+newstat,sze/2);
		dfs(p*2+1,stat*2+newstat,sze/2);
		for(int l = 0;l <= min(sze,m);l++){
			for(int r = 0;r <= min(sze,m);r++){
				dp[p][l+r] = max(dp[p][l+r],dp[p*2][l]+dp[p*2+1][r]);
			}
		}
	}
}
int main(){
	freopen("warr.in","r",stdin);
	freopen("warr.out","w",stdout);
	cin>>n>>m;
	pop = (1 << (n-1));
	for(int i = 1;i <= pop;i++){
		for(int j = 1;j < n;j++){
			cin>>w[i][j];
		}
	}
	for(int i = 1;i <= pop;i++){
		for(int j = 1;j < n;j++){
			cin>>f[i][j];
		}
	}
	dfs(1,0,pop*2-1);
	for(int i = 0;i <= m;i++){
		ans = max(ans,dp[1][i]);
	}
	cout<<ans;
	return 0;
}

