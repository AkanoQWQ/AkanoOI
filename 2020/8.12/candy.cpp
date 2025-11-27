#include<bits/stdc++.h>
using namespace std;
int n,x,y,i,j,k,ans,cache;
int c[101][2],lu[101][2];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>c[i][0];
		lu[0][0] = c[0][0];
		if(i)lu[i][0] = lu[i-1][0]+c[i][0];
	}
	for(i = 0;i < n;i++){
		cin>>c[i][1];
		lu[0][1] = c[0][1];
		if(i){
			lu[i][1] = lu[i][0]+c[i][1];
			if(lu[i][0]+c[i][1] < lu[i-1][1]+c[i][1]){
				lu[i][1] = lu[i-1][1]+c[i][1];
			}
		}
	}
	for(k = 0;k < 2;k++){
		for(i = 0;i < n;i++){
			for(j = 0;j < 2;j++){
				if(lu[i][k] + lu[k][j] > lu[i][j]){
					if(k < j){
						lu[i][j] = lu[i][k] + lu[k][j] - c[i][k];
					}
					
				}
			}
		}
	}
	cout<<lu[n-1][1];
	return 0;
}
