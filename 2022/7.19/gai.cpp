#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,b,i,f;
	cin>>n;
	for(a=2;a*a<=n;a++){
		if (n%a!=0) continue;
		b=n/a;
		cout<<b;
		return 0;
	}
	//cout<<"test";
	return 0;
}
