#include<bits/stdc++.h>
using namespace std;
long long a,b,i,j,k,cache,n,m;
int trees[100000000];
int main(){
	freopen("height.in","r",stdin);
	freopen("height.out","w",stdout);
	cin>>n>>m;
	for(i = 0;i < n;i++){
		cin>>cache;
		trees[cache]++;
	}
	for(i = 0;i < m;i++){
		cin>>cache;
		cout<<trees[cache]<<" ";
	}
	return 0;
}
