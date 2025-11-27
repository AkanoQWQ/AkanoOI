#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],p[30],i,j,package[36][30006];
int main(){
	//freopen("P1057.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cin>>v[i]>>p[i];
	}
	for(i = 1;i <= m;i++){
		for(j = 1;j <= n;j++){
			if(j >= v[i]){
				package[i][j] = max(package[i-1][j],package[i-1][j-v[i]] + v[i]*p[i]);
			}else{
				package[i][j] = package[i-1][j];
			}
			
		}
	}
	cout<<package[m][n];
	return 0;
}

