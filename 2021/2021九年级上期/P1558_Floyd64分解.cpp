#include<bits/stdc++.h>
using namespace std;
const int MN = 1005;
int Floyd[MN][MN],i,j,n,m,p,x,y,k,ans;
bool USED[MN];
int main(){
	//freopen("P1558.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(i = 0;i < m;i++){
		cin>>p>>x>>y;
		if(p == 0){
			Floyd[x][y] = 1;
			Floyd[y][x] = 1;
		}else{
			Floyd[x][y] = -1;
			Floyd[y][x] = -1;
		}
	}
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			for(k = 1;k <= n;k++){
				if(Floyd[i][k] == -1 && Floyd[k][j] == -1){
					Floyd[i][j] = 1;
				}
				if(Floyd[i][k] == 1 && Floyd[k][j] == 1){
					Floyd[i][j] = 1;
				}
			}
		}	
	}
	/*for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			cout<<Floyd[i][j]<<" ";
		}
		cout<<endl; 
	}*/
	for(i = 1;i <= n;i++){
		if(USED[i] == 0){
			USED[i] == 1;
			for(j = 1;j <= n;j++){
				if(Floyd[i][j] == 1)USED[j] = 1;
			}
		ans++;
		}
	}
	cout<<ans;
	return 0;
}

