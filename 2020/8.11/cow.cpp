#include<bits/stdc++.h>
using namespace std;
int i,j,k,ans,ss,cache,cache2,n,m,cows[106][106];
int main(){
	freopen("cow.in","r",stdin);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>cache>>cache2;
		cows[cache][cache2] = 1;
	}
	for(k = 1;j <= n;k++){
		for(i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				cows[i][j] = cows[i][j]||(cows[i][k]&&cows[k][j]);
				cows[j][i] = cows[j][i]||(cows[j][k]&&cows[k][i]);
			}
		}
	}
	cout<<cows[5][1]<<" "<<cows[5][2]<<cows[5][3]<<cows[5][4]<<endl;
	for(i = 1;i <= n;i++){
		cache = 0;
		for(j = 1;j <= n;j++){
			if(cows[i][j]||cows[j][i])cache++;
		}
		cout<<cache<<endl;
		if(cache == (n-1))ans++;
	}
	cout<<"-------------"<<endl<<ans;
	return 0;
}
