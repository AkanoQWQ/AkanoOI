#include<bits/stdc++.h>
using namespace std;
int i,j,ans,cache,a,b,c;
int main(){
	cin>>a>>b>>c;
	ans = a+b+c;
	if(ans >= 270){
		cout<<"A";
		cout<<endl;
		return 0;
	}else if(ans < 270 && ans >= 240){
		cout<<"B";
		cout<<endl;
		return 0;
	}else{
		cout<<"C";
		return 0;
	}
	return 0;
	return 0;
}
