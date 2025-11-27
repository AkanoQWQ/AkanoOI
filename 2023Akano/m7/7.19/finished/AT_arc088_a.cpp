#include<bits/stdc++.h>
using namespace std;
long long a,b,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b;
	while(a <= b){
		++ans;
		a *= 2;
	}
	cout<<ans;
	return 0;
}
