#include<bits/stdc++.h>
using namespace std;
int n,k,l;
int road[3300][3300],railway[3300][3300],i,j,a,b,ans;
int main(){
	freopen("connec.in","r",stdin);
	freopen("connec.out","w",stdout);
	cin>>n>>k>>l;
	for(i = 1;i <= k;i++){
		cin>>a>>b;
		road[a][b] = 1;
		road[b][a] = 1;
	}
	for(i = 1;i <= l;i++){
		cin>>a>>b;
		railway[a][b] = 1;
		railway[b][a] = 1;
	}
	for(i = 0;i <= n;i++){
		road[i][i] = 1;
		railway[i][i] = 1;
	}
	for(i = 0;i <= n;i++){// 
		for(j = 0;j <= n;j++){
			for(k = 0;k <= n;k++){
				if(road[i][k] > 0 && road[k][j] > 0){
					road[i][j] = 1;
				}
				if(railway[i][k] > 0 && railway[k][j] > 0){
					railway[i][j] = 1;
				}
			}
		}
	}
	for(i = 1;i <= n;i++){
		ans = 0;
		for(j = 1;j <= n;j++){
			if(road[i][j] > 0 && railway[i][j] > 0){
				ans++;
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
