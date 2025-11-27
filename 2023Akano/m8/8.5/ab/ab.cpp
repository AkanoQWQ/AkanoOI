#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	srand(time(0));
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	a -= ((a+b) & 1);
	cout<<a+b<<endl;
	return 0;
}
