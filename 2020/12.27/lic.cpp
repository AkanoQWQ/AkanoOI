#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[19202],k[19202],maxx = -1;
int main(){
	//freopen("lic.in","r",stdin);
	//freopen("lic.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>a[i];
		k[i] = 1;
	}
	
	for(i = n-1;i >= 1;i--){
		for(j = i+1;j <= n;j++){
			if(a[i] < a[j] && k[i] < k[j]+1){
				k[i] = k[j] + 1;
			}
		}
		if(k[i] > maxx){
			maxx = k[i];
		}
	}
	cout<<maxx;
	return 0;
}
