#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	freopen("ice.in","r",stdin);
	freopen("ice.out","w",stdout);
	cin>>a>>b;
	c = a + b;
	if(c >= 15 && b >= 8){
		cout<<1;
		return 0;
	}else if(c >= 10 && b >= 3){
		cout<<2;
		return 0;
	}else if(c >= 3){
		cout<<3;
		return 0;
	}else{
		cout<<4;
		return 0;
	}
	return 0;
}

