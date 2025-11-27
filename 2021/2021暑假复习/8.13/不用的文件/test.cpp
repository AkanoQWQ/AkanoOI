#include<bits/stdc++.h>
using namespace std;
string a[200006],b[200006];
int n,i;
int main(){
	freopen("test.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	for(i = 0;i < n;i++){
		cin>>b[i];
	}
	for(i = 0;i < n;i++){
		if(a[i] != b[i]){
			cout<<i<<"³ö´í!"<<endl;
			cout<<"expect"<<a[i]<<",but"<<b[i]<<endl; 
		}
	}
	cout<<"end!";
	return 0;
}

