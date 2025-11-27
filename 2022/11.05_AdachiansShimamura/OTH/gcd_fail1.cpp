#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3000006;
const int MOD = 998244353;
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int igcd(__int128 a,__int128 b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
long long a,b,c,d,g,ans = 1,inx,iny;
__int128 x[MAXN],y[MAXN];
void write(__int128 inx){
	if(inx < 0){
		inx = -inx;
		putchar('-');
	}
	if(inx > 9){
		write(inx / 10);
	}
	putchar((inx%10) + '0');
}
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
	for(int i = 2;i <= 1000;i++){
		x[i] = x[i-1] * x[1];
	}
	for(int i = 2;i <= 1000;i++){
		y[i] = y[i-1] * y[1];
	}
 	for(int i = a;i <= b;i++){
		for(int j = c;j <= d;j++){
			cout<<ans<<" "<<(igcd(x[i],y[j]))<<endl;
			ans = (ans * (igcd(x[i],y[j])%MOD))%MOD;
			
		}
	}
	cout<<ans;
	return 0;
}
