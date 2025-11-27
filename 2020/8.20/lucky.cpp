#include<bits/stdc++.h>
using namespace std;
int n,i;
int main(){
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	cin>>n;
	while(n > 0){
		if(n%10 == 7){
			cout<<"Yes";
			return 0;
		}
		n /= 10;
	}
	cout<<"No";
	return 0;
}
