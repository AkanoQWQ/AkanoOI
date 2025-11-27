#include<bits/stdc++.h>
using namespace std;
string a[200006],b[200006];
int n,i;
int main(){
	freopen("string.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i]>>b[i];
	}
	for(i = 0;i < n;i++){
		if(i == 77){
			cout<<a[i]<<endl<<b[i]<<endl; 
		}
	}
	return 0;
}

