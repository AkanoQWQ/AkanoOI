#include<bits/stdc++.h>
using namespace std;
const int MAXN = 306;
int t,n;
char mp[MAXN][MAXN];
inline void Solve(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>mp[i][j];
		}
		mp[i][n+1] = mp[i][n+2] = '.';
	}
	for(int j = 1;j <= n;j++){
		mp[n+1][j] = mp[n+2][j] = '.';
	}
	int cnt[3] = {0,0,0};
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cnt[(i+j)%3] += (mp[i][j] == 'X');
		}
	}
	const int mn = min(cnt[0],min(cnt[1],cnt[2]));
	int change = 0;
	for(int i = 0;i < 3;i++)if(cnt[i] == mn)change = i;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if((i + j) % 3 == change && mp[i][j] == 'X'){
				mp[i][j] = 'O';
			}
			cout<<mp[i][j];
		}
		cout<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		Solve();
	}
	return 0;
}
