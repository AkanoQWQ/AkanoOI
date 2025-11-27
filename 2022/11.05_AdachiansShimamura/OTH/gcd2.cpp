#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3000006;
const int MOD = 998244353;
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int a,b,c,d,x,y,g,ans = 1,g_g[MAXN];
int main(){
	freopen("gcd.in","r",stdin);
	//freopen("gcd.out","w",stdout);
	cin>>a>>b>>c>>d>>x>>y;
	g = gcd(x,y);
	g_g[0] = 1;
	for(int i = 1;i <= MAXN-6;i++){
		g_g[i] = (1ll * g_g[i-1] * g) % MOD;
	}
 	for(int i = a;i <= b;i++){
		for(int j = c;j <= d;j++){
			cout<<i<<","<<j<<" is "<<g_g[min(i,j)]<<endl;
			ans *= g_g[min(i,j)];
		}
	}
	cout<<ans;
	return 0;
}

