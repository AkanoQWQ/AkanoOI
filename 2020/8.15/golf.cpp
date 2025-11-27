#include<bits/stdc++.h>
using namespace std;
int k,i,j,a,b; 
int main(){
	freopen("golf.in","r",stdin);
	freopen("golf.out","w",stdout);
	cin>>k;
	cin>>a>>b;
	for(i = a;i <= b;i++){
		if(!(i%k)){
		cout<<"OK";
		return 0; 
		}
	}
	cout<<"NG";
	return 0;
}
