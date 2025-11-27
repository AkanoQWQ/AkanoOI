#include<bits/stdc++.h>
using namespace std;
int numsite[5][5],pd[5][5],i,j,n = 3,c,a = 0;
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			cin>>numsite[i][j];
		}
	}
	cin>>n;
	while(n--){
		cin>>c;
		for(i = 0;i < 3;i++){
			for(j = 0;j < 3;j++){
				if(numsite[i][j] == c){
					pd[i][j] = 1;
				}
			}
		}
	}
	if(pd[0][0] == 1 &&pd[0][1] == 1 &&pd[0][2] == 1){
		a = 1;
	}else if(pd[1][0] == 1 &&pd[1][1] == 1 &&pd[1][2] == 1){
		a = 1;
	}else if(pd[2][0] == 1 &&pd[2][1] == 1 &&pd[2][2] == 1){
		a = 1;
	}else if(pd[0][0] == 1 &&pd[1][0] == 1 &&pd[2][0] == 1){
		a = 1;
	}else if(pd[0][1] == 1 &&pd[1][1] == 1 &&pd[2][1] == 1){
		a = 1;
	}else if(pd[0][2] == 1 &&pd[1][2] == 1 &&pd[2][2] == 1){
		a = 1;
	}else if(pd[0][0] == 1 &&pd[1][1] == 1 &&pd[2][2] == 1){
		a = 1;
	}else if(pd[0][2] == 1 &&pd[1][1] == 1 &&pd[2][0] == 1){
		a = 1;
	}
	if(a == 1){
		cout<<"Yes"<<endl;
		return 0;
	}else{
		cout<<"No";
	}
	return 0;
}

