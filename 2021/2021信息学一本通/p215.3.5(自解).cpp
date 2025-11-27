#include<bits/stdc++.h>
using namespace std;
int i,j,a[64],k,n; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	a[1] = 9;
	for(i = 2;i <= n;i++){
		k = 1;
		for(j = i-1;j > 0;j--){
			k *= 10;
		}
		a[i] = k + 7 * a[i-1];
	}
	cout<<a[n];
	return 0;
}

