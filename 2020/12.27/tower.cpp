#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[106][106],f[106][106];
int main(){
	//freopen("tower.in","r",stdin);
	//freopen("tower.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= i;j++){
			cin>>a[i][j];
		}
	}
	
	for(i = n;i >= 1;i--){
		for(j = 1;j <= i;j++){
			if(i == n){
				f[i][j] = a[i][j];
			}else{
				f[i][j] = max(f[i+1][j+1],f[i+1][j]) + a[i][j];
			}
		}		
	}

	cout<<f[1][1];
	return 0;
}
