#include<bits/stdc++.h>
using namespace std;
double f[1006];
int n,t;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		for(int i = 0;i < n;i++)f[i+1] = f[i] + ((double)n / double(n-i));
		printf("%.2lf\n",f[n]);	
	}
	return 0;
}
