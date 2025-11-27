#include<bits/stdc++.h>
using namespace std;
int n,tower[106][106],i,j,d[106][106],ans = -9999;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= i;j++){
			cin>>tower[i][j];
		}
	}
	for(i = 1;i <= n;i++){
		for(j = 1;j <= i;j++){
			d[i][j] = max(d[i-1][j],d[i-1][j-1])+tower[i][j];
		}
	}
	for(i = 1;i <= n;i++){
		ans = max(ans,d[n][i]);
	}
	cout<<ans;
	return 0;
}

