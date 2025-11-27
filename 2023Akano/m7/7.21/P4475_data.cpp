#include<bits/stdc++.h>
#include "DP_FILE/comp.h"
using namespace std;
Rander rd = Rander(1,1e9);
Rander rd2 = Rander(1,1e5); 
Rander f = Rander(0,1);
inline int rnd1(){
	int ret = rd();
	return ret;
}
inline int rnd2(){
	int ret = rd2();
	if(f())ret = -ret;
	return ret;
}
inline void OTP(){
	cout<<rnd2()<<" "<<rnd2()<<" "<<rnd1()<<endl;
}
int n = 5e4,m = 5e4;
int main(){
	freopen("P4475.in","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n+m;i++)OTP();
	return 0;
}

