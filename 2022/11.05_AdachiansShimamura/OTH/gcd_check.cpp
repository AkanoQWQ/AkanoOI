#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3000006;
const int MOD = 998244353;
long long gcd(long long a,long long b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
long long a,b,c,d,g,ans = 1,inx,iny;
long long x[MAXN],y[MAXN];
int main(){
	freopen("gcd.in","r",stdin);
	//freopen("gcd.out","w",stdout);
	cin>>a>>b>>c>>d>>inx>>iny;
	x[1] = inx,y[1] = iny;
	if(gcd(inx,iny) == 1){
		cout<<1;
		return 0;
	}
	x[0] = 1,y[0] = 1;
	for(int i = 2;i <= 100;i++){
		x[i] = x[i-1] * x[1];
	}
	for(int i = 2;i <= 100;i++){
		y[i] = y[i-1] * y[1];
	}
 	for(int i = a;i <= b;i++){
		for(int j = c;j <= d;j++){
			ans = (ans * (gcd(x[i],y[j])%MOD))%MOD;
		}
	}
	cout<<ans;
	return 0;
}
