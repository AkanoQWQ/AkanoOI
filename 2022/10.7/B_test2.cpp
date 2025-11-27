#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,pls = 1,mx = 1;
int main(){//1 +3 4 +5 9 +7 16 + 9
//1 4 9 16 25
	//x = 1 + (x*(4+2x));
	while(ans < 100){
		int pre = ans;
		ans += 1;
		cout<<ans<<endl;
		ans += pls;
		cout<<ans<<endl;
		ans += pls;
		cout<<ans<<endl;
		pls++;
	}
	return 0;
}

