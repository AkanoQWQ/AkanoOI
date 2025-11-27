#include<bits/stdc++.h>
using namespace std;
long long a,b,c1,c2,ans;


int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	while(1){
		ans = 0;
		cin>>a>>b;
		if(a == 0&&b == 0)break;
		while(a != 0&&b != 0){
			c1 = a % 10;
			c2 = b % 10;
			a /= 10;
			b /= 10;
			if(c1 + c2 >= 10){
				ans++;
				a+1;
			}
		}
		cout<<ans;
	}
	return 0;
}
