#include<bits/stdc++.h>
using namespace std;
int i,j,ans,cache,n,m,k,s,l,r,ji;
long long mrs[1000006];
int mr[20061108];
int main(){
	//freopen("mrs.in","r",stdin);
	cin>>n>>m;
	for(i = 0;i < n;i++){
		cin>>mrs[i];
		mr[mrs[i]]++;
	}
	n--;
	for(i = 0;i < m;i++){
		cin>>k;
		cout<<mr[k]<<" ";
	}
	return 0;
}
