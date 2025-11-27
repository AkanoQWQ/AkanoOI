#include<bits/stdc++.h>
using namespace std;
int i,a,b;
int main(){
	//freopen(".in","r",stdin);
	//freopen("test.out","w",stdout);
	cin>>a>>b;
	while(a > 0){
		cout<<a<<"%"<<b<<"="<<a % b<<endl;
		a /= 10;
	}
	return 0;
}

