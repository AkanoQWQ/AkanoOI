#include<bits/stdc++.h>
using namespace std;
int n,m,f[206][306],c[206],w[206],i,j;
int main(){
	//freopen("package.in","r",stdin);
	//freopen("package.out","w",stdout);
	cin>>m>>n;
	for(i = 1;i <= n;i++){
		cin>>w[i]>>c[i];
	}
	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++){
			if(j >= w[i]){
				f[i][j] = max(f[i][j-w[i]]+c[i],f[i-1][j]);
			}else{
				f[i][j] = f[i-1][j];
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
