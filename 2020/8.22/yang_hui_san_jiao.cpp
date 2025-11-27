#include<bits/stdc++.h>
using namespace std;
int i,j,n,ji,cache,cache2,sanjiao[1000][1000];
int main(){   
	n = 32;                 
	sanjiao[1][1] = 1;
	for(i = 2;i <= n;i++){
		for(j = 1;j <= i;j++){
			sanjiao[i][j] = sanjiao[i-1][j-1] + sanjiao[i-1][j];
		}
	}
	cin>>ji;
	for(i = 1;i <= ji;i++){
		cin>>cache>>cache2;
		cout<<sanjiao[cache+1][cache2+1]<<endl;
	}
	return 0;
}
