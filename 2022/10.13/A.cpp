#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(a+b == c){
			cout<<"YES"<<endl;
			continue;
		}else if(a+c == b){
			cout<<"YES"<<endl;
			continue;
		}else if(b+c == a){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}

