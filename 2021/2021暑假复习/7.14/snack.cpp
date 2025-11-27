#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long gcd(long long x,long long y){
	if(x%y == 0)return y;
	return gcd(y,x%y);
}
int main(){
	freopen("snack.in","r",stdin);
	freopen("snack.out","w",stdout);
	cin>>a>>b;
	cout<<a*b/gcd(a,b);
	return 0;
}

