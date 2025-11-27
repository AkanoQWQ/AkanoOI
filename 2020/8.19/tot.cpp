#include<bits/stdc++.h>
using namespace std;
int a,b,c,zong;
int main(){
	freopen("tot.in","r",stdin);
	freopen("tot.out","w",stdout);
	cin>>a>>b>>c;
	zong = a+b+c;
	if(zong >= 270){
		cout<<"A";
	}else if(zong >= 240){
		cout<<"B";
	}else if(zong < 240){
		cout<<"C";
	}
	return 0;
}
