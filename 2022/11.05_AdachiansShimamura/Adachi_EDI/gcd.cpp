#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXP = 1e7;
const int MAXPR = 670000;
const int MOD = 998244353;
int cnt,pr[MAXPR];
bitset<MAXP> est;
void sel(int n){
	for(int i = 1;i <= n;i++){
		est[i] = 1;
	}
	est[1] = 0;
	for(int i = 2;i <= n;i++){
		if(est[i]){
			pr[++cnt] = i;
			for(int j = 1;i+(j*i) <= n;j++){
				est[i+(j*i)] = 0;
			}
		}
	}
}
int a,b,c,d,x,y,com[MAXPR],comnt;
long long ans = 1;
struct node{
	int a[MAXPR];
}na,nb;
int gcd(int aa,int bb){
	if(bb == 0)return aa;
	return gcd(bb,aa%bb);
}
ll ksm(ll aa,ll n){
	ll ret = 1;
	while(n){
		if(n % 2 == 1)ret = (ret * aa) % MOD;
		aa = (aa * aa) % MOD;
		n /= 2;
	}
	return ret;
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>a>>b>>c>>d>>x>>y;
	if(gcd(x,y) == 1){
		cout<<1;
		return 0;
	}
	sel(min(MAXP-4,int(max(sqrt(x+2),sqrt(y+2)))));
	for(int i = 1;i <= cnt;i++){
		while(x % pr[i] == 0){
			x /= pr[i];
			na.a[i]++;
		}
		if(!x)break;
	}
	for(int i = 1;i <= cnt;i++){
		while(y % pr[i] == 0){
			y /= pr[i];
			nb.a[i]++;
		}
		if(!y)break;
	}
	for(int i = 1;i <= cnt;i++){
		if(na.a[i] && nb.a[i]){
			com[++comnt] = i;
		}
	}
	for(int i = a;i <= b;i++){
		for(int j = c;j <= d;j++){
			for(int k = 1;k <= comnt;k++){
				const int p = com[k];
				ans = (ans * ksm(pr[p],min(na.a[p]*i,nb.a[p]*j))) % MOD;
			}
		}
	}
	cout<<ans;
	return 0;
}
