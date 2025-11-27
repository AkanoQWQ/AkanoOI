#include<bits/stdc++.h>
using namespace std;
string s;
int i,a,b;
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>s;
	for(i = 0;i < 3;i++){
		if(s[i] == 'A'){
		  	a = 1;
		} 
		if(s[i] == 'B'){
			b = 1;
		} 
	}
	if(a && b){
		cout<<"Yes";
		return 0;
	}else{
		cout<<"No";
	}
	return 0;
}
