#include<bits/stdc++.h>
using namespace std;
bool road[2006][2006],DOSTH;
int i,j,a,b,ans,n,m,k;
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		road[i][i] = 1;
	}
	for(i = 0;i < m;i++){
		cin>>a>>b;
		road[a][b] = 1;
	}
	DOSTH = 1;
	while(DOSTH){
		DOSTH = 0; 
		for(i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				for(k = 1;k <= n;k++){
					if(road[i][k] == 1 && road[k][j] == 1 && road[i][j] == 0){
						road[i][j] = 1;
						DOSTH = 1;
					//	cout<<i<<"与"<<j<<"通过"<<k<<"建立关系"<<endl;
					}
				}
			}
		}
	}
	
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			//cout<<road[i][j]<<" ";
			if(road[i][j] == 1){
				ans++;
			}
		}
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}

