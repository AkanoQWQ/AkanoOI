#include<bits/stdc++.h>
using namespace std;
const __int128 int128one = 1;
const __int128 MOD = int128one * 7528443412 * 1000000000 + 579576937;
inline __int128 read(){
	__int128 x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void write(__int128 x){
    if(x > 9)write(x/10);
    putchar(x % 10 + '0');
    return ;
}
__int128 b,d,n;
const int llen = 5;
const int calcl = 2;
struct mat{
	__int128 a[llen][llen];
}calc,orgcalc,ans;
mat operator *(mat a,mat b){
	mat c;
	c.a[1][1] = (a.a[1][1] * b.a[1][1]);
	c.a[1][1] = (c.a[1][1] + (a.a[1][2] * b.a[2][1])) % MOD;
	c.a[1][2] = (a.a[1][1] * b.a[1][2]);
	c.a[1][2] = (c.a[1][2] + (a.a[1][2] * b.a[2][2])) % MOD;
	c.a[2][1] = (a.a[2][1] * b.a[1][1]);
	c.a[2][1] = (c.a[2][1] + (a.a[2][2] * b.a[2][1])) % MOD;
	c.a[2][2] = (a.a[2][1] * b.a[1][2]);
	c.a[2][2] = (c.a[2][2] + (a.a[2][2] * b.a[2][2])) % MOD;
	return c;
}
void mpow(__int128 times){
	while(times){
		if(times & 1)ans = ans * calc;
		calc = calc * calc;
		times >>= 1;
	}
	return ;
}
__int128 outans;
int main(){
	freopen("strr.in","r",stdin);
	freopen("strr.out","w",stdout);
	b = read(),d = read(),n = read();
	if(n == 0){
		cout<<1;
		return 0;
	}
	calc.a[1][1] = b;
	calc.a[1][2] = 1;
	calc.a[2][1] = (d-(b*b))/4;
	ans.a[1][1] = b,ans.a[1][2] = 2;
	mpow(n-1);
	outans = ans.a[1][1];
	if(n % 2 == 0 && (b*b != d))outans--;
	if(outans < 0)outans += MOD;
	write(outans);
	return 0;
}
