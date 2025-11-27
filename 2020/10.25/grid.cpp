#include<bits/stdc++.h>
using namespace std;
int a[3][3],b[3][3],i,j,n,c,k;
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			cin>>a[i][j];
		} 
	}
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>c;
		for(j = 0;j < 3;j++){
			for(k = 0;k < 3;k++){
				if(a[j][k] == c){
					b[j][k] = 1;
				}
			}
		}
	}
	if(b[0][0]&&b[1][0]&&b[2][0]){
		cout<<"Yes";
		return 0; 
	}
	if(b[0][1]&&b[1][1]&&b[2][1]){
		cout<<"Yes";
		return 0; 
	}
	if(b[0][2]&&b[1][2]&&b[2][2]){
		cout<<"Yes";
		return 0; 
	}
	
	if(b[0][0]&&b[0][1]&&b[0][2]){
		cout<<"Yes";
		return 0; 
	}
	if(b[1][0]&&b[1][1]&&b[1][2]){
		cout<<"Yes";
		return 0; 
	}
	if(b[2][0]&&b[2][1]&&b[2][2]){
		cout<<"Yes";
		return 0; 
	}
	if(b[0][0]&&b[1][1]&&b[2][2]){
		cout<<"Yes";
		return 0; 
	}
	if(b[0][2]&&b[1][1]&&b[2][0]){
		cout<<"Yes";
		return 0; 
	}
	cout<<"No";
	return 0;
}
