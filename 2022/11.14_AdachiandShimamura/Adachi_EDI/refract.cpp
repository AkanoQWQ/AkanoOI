#include<bits/stdc++.h>
#define FILE_ST namespace Mi_Shatas_Lilion{
#define FILE_ED }
#define excute int main(){return Mi_Shatas_Lilion::main();}
using namespace std;
FILE_ST
const int MAXN = 6006;
const int MOD = 1e9 + 7;
int n,dp[MAXN][2],ans;
pair<int,int> p[MAXN];
int main(){
	freopen("refract.in", "r", stdin);
    freopen("refract.out", "w", stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
    	scanf("%d%d",&p[i].first,&p[i].second);
	}
	sort(p+1,p+n+1);
	for(int i = 1;i <= n;i++){
		dp[i][0] = dp[i][1] = 1;
		for(int j = i-1;j >= 1;j--){
			if(p[j].second > p[i].second){
				dp[j][1] += dp[i][0];
				if(dp[j][1] >= MOD)dp[j][1] -= MOD;
			}else{
				dp[i][0] += dp[j][1];
				if(dp[i][0] >= MOD)dp[i][0] -= MOD;
			}
		}
	}
	ans = MOD - n;
	for(int i = 1;i <= n;i++){
		ans = (1ll * ans + dp[i][0] + dp[i][1]) % MOD;
	}
	printf("%d",ans);
	return 0;
}
FILE_ED
excute
