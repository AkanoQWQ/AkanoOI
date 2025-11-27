#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	cin>>n;
	n %= 1000;
	n = 1000 - n;
	if(n == 1000)n = 0;
	cout<<n;
	return 0;
}
