#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[106],c;
int main(){
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	cin>>c;
	for(i = 0;i < n-1;i++){
		if(i != c-1){
			cout<<a[i]<<" ";
		}else{
			cout<<a[n-1]<<" "<<a[i]<<" ";
		}
	}
	return 0;
	return 0;
}
