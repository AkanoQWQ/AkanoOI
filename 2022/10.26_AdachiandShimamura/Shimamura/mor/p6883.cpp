#include<bits/stdc++.h>
using namespace std;
const int MAXN = 26;
int n,k,v[MAXN][MAXN],dp[(1<<20) + 6];
int main(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>v[i][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 1;i < (1<<n);i++){
		for(int j = 0;j < n;j++){
			if((i & (1<<j)) == 0)continue;
			for(int k = 0;k < n;k++){
				if(k != j && (i & (1<<)))
			}
		}
	}
    return 0;
}

