#include<bits/stdc++.h>
using namespace std;
long long x,i,ans;
int main(){
	freopen("coins.in","r",stdin);
	freopen("coins.out","w",stdout);
	cin>>x;
	while(x > 500){
		ans += (x/500)*1000;
		x %= 500;
	}
	while(x > 5){
		ans += (x/5)*5;
		x %= 5;
	}
	cout<<ans; 
	return 0;
}
