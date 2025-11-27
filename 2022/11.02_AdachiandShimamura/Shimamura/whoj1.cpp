#include<bits/stdc++.h>
using namespace std;
int n,a[2006];
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int nlen = unique(a+1,a+n+1) - a - 1;
	for(int i = 1;i <= nlen;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
