#include<bits/stdc++.h>
using namespace std;
long long n,r,k;
int main(){
	freopen("rating.in","r",stdin);
	freopen("rating.out","w",stdout);
	cin>>k>>r;
	if(k >= 10){
		cout<<r;
	}
	if(k < 10){
		cout<<r+100*(10-k);
	}
	return 0;
}
