#include<bits/stdc++.h>
using namespace std;//remember long long  
namespace stb{//常用数据库 
	void mycin(int b[],int n){
		for(int i = 0;i < n;i++){
			scanf("%d",&b[i]);
		}
		return ; 
	}
	void mycout(int b[],int n){
		for(int i = 0;i < n;i++){
			cout<<b[i];
		}
		return ; 
	}
}
int a[1006][1006],i,j,sum[1006][1006],n,m,r,c;
int main(){
	freopen("matrix.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>r>>c;
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			cin>>a[i][j];
			if(i==0&&j==0){
				sum[0][0] = a[0][0];
			}
			if(i == 0&&j>0){
				sum[0][j] = sum[0][j-1]+a[0][j];
			}
			if(i != 0&&j == 0){
				sum[i][j] = sum[i-1][j] + a[i][j];
			}
			if(i>0 && j>0){
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
			}
		}
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
