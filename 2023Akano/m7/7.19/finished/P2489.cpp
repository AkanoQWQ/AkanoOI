#include<bits/stdc++.h>
using namespace std;
const int MAXN = 33;
const int MAXSTAT = 250;
const int MAXH = 7;
int n,m,k,h,maxs;
double dp[MAXN][MAXN][MAXSTAT][MAXH];
char mp[MAXN][MAXN];
inline int SlowPow(int x,int y){
	int ret = 1;
	while(y--)ret *= x;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>h;
	maxs = 1<<k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
		}
	}
	
	return 0;
}

