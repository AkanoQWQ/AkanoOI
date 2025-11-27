#include<bits/stdc++.h>
using namespace std;
int t,m,i,j,medt[106],v[106],package[1006][1006];
int main(){
	//freopen("P1050.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t>>m;
	for(i = 1;i <= m;i++){
		cin>>medt[i]>>v[i];
	}
	for(i = 1;i <= m;i++){
		for(j = 1;j <= t;j++){
			if(j >= medt[i]){
				package[i][j] = max(package[i-1][j],package[i-1][j-medt[i]]+v[i]);
			}else{
				package[i][j] = package[i-1][j];
			}
			
		}
	}
	cout<<package[m][t];
	return 0;
}

