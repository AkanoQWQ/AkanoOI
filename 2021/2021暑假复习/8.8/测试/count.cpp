#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e,z[28964],i,j;
bool comp(int a,int b){
	return a>b;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a>>b>>c>>d>>e;
		z[i] = a + b + c + d + e;
	}
	sort(z,z+n,comp);
	for(i = 0;i < n;i++){
		cout<<z[i]<<" ";
	}
	return 0;
}

