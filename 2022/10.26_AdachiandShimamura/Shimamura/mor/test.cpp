#include<bits/stdc++.h>
using namespace std;
unsigned long long t,x,s,cj;
int main(){
	cin>>t;
	while(t--){
		cin>>x>>s;
		cj = 2;
		if(x >= 3)cj++;
		if(x >= 5)cj++;
		if(s >= 10000000)cj++;
		if(s >= 20000000)cj++;
		if(s >= 40000000)cj++;
		if(s >= 60000000)cj++;
		cout<<cj<<endl;
	}
    return 0;
}

