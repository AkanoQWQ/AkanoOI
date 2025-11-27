#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(a%b == 0)return b;
	return gcd(b,a%b);
}
int m,n;
int main(){
	cin>>m>>n;
	cout<<gcd(m,n);
	return 0;
}
