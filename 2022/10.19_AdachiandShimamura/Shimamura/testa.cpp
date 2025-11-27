#include<bits/stdc++.h>
using namespace std;
unsigned long long a = 1;
int main(){
	for(long long i = 1;i <= 63;i++)a *= 2;
	a += (a-1);
	cout<<a;
	printf("\n%lld",a);
	return 0;
}

