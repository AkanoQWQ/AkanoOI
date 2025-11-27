#include<bits/stdc++.h>
using namespace std;
long long k,ts,num,ck,ans = 9999999,i = 10000000;
int main(){
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	cin>>k;
	while(i > 0){
		num = 0,ck = k;
		ts++;
		ck *= ts;
		while(ck > 0){
			num += ck%10;
			ck /= 10;
		}
		ans = min(ans,num);
		i--;
	}
	cout<<ans;
	return 0;
}

