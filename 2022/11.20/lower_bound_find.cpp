#include<bits/stdc++.h>
using namespace std;
int a[4] = {0,2,4,6};
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int b = lower_bound(a+1,a+4,7) - a;
	cout<<b<<endl;
	b = lower_bound(a+1,a+4,7) - a;
	cout<<b<<endl;
	b = lower_bound(a+1,a+4,1) - a;
	cout<<b;
	return 0;
}

