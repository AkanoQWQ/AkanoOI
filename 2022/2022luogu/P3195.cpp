#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 50006;
int n,l,l2,c[MAXN],s[MAXN],dp[MAXN];
int sq(int a){
	return a*a;
}
queue<int> ks;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&l2);
	l = l2+1;
	for(int i = 1;i <= n;i++){
		scanf("%d",c[i]);
		s[i] = s[i-1] + c[i];
	}
	for(int i = 1;i <= n;i++){
		int k = 2 * (sn[i] - l);
		if(!ks.empty){//特判尾部 
			if(ks.top() > k)ks.pop();
		}
		while(ks.size() > 1 && )
	}
	return 0;
}//  								   M
//dp[i] = dp[j] + (s[i] - s[j] + (i  - 1 - l2) - j)^2
//s[i]+i = sn[i]  -----------------------------------
//s[j]+j = sn[j]
//l = l2+1;//我们将与j有关的信息表示为y的形式,把同时与ij有关的信息表示为kx
//(sn[i] - sn[j] - l)^2
//sn[i]^2 - 2*sn[i]*sn[j] - sn[i]*l +sn[j]^2 + sn[j]*l - sn[i]*l + sn[j] * l + l^2
//sn[i]^2 - 2*sn[i]*sn[j] - 2*sn[i]*l +sn[j]^2 + 2*sn[j]*l + l^2  (---)
//dp[i] = Min(sn[i]^2 - 2*sn[i]*sn[j] - 2*sn[i]*l +sn[j]^2 + 2*sn[j]*l + l^2 + dp[j])
//dp[i] - l^2 - sn[i]^2 + 2*sn[i]*l= Min(- 2*sn[i]*sn[j] +sn[j]^2 + 2*sn[j]*l + dp[j])
//dp[i] - l^2 - sn[i]^2 + 2*sn[i]*l= Min(2*sn[j] *-sn[i] +sn[j]^2 + 2*sn[j]*l + dp[j])
//dp[i] - l^2 - sn[i]^2 + 2*sn[i]*l= Min(2*sn[j] * (l-sn[i]) +sn[j]^2 + dp[j])
//dp[i] - (sn[i] - l)^2 = Min(sn[j] * 2*(l-sn[i]) + sn[j]^2 + dp[j])
//b = dp[i] - (sn[i] - l)^2   (y-kx=+b)
//y = sn[j]^2 + dp[j]
//x = sn[j]
//k = 2 * (sn[i] - l)
