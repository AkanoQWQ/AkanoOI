#include<bits/stdc++.h>
using namespace std;
long long a[100006],b[100006],n = 100000;
int main(){
	freopen("BA.out","r",stdin);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	//freopen(".out","w",stdout);
	freopen("BC.out","r",stdin);
	for(int i = 1;i <= n;i++){
		cin>>b[i];
		//cout<<a[i]<<" "<<b[i]<<endl;
		if(a[i] != b[i]){
			cout<<i<<":"<<"read "<<a[i]<<" ,expected"<<b[i]<<endl;
		}
	}
	return 0;
}

