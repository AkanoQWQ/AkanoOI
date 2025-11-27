#include<bits/stdc++.h>
using namespace std;
const __int128 int128one = 1;
const __int128 MOD = int128one * 7528443412 * 1000000000 + 579576937;
const long long mod = 7528443412 * 1000000000 + 579576937;
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
long double b,d,rret,rb;
long long n;
long double ksm(){
	long double ret = 1;
	while(n){
		if(n % 2 == 1)ret *= b;
		b *= b;
		rret = ret;
		__int128 l = 1,r = MOD;
		while(l <= r){
			__int128 mid = (l+r) / 2;
			if(ret < mid*MOD){
				r = mid - 1;
			}else{
				l = mid + 1;
				rret = ret - mid * MOD;
			}
		}
		ret = rret;
		rb = b;
		l = 1,r = MOD;
		while(l <= r){
			__int128 mid = (l+r) / 2;
			if(b < mid*MOD){
				r = mid - 1;
			}else{
				l = mid + 1;
				rb = b - mid * MOD;
			}
		}
		b = rb;
		n /= 2;
		cout<<ret<<" "<<b<<endl;
	}
	return ret;
}
int main(){
	freopen("strr.in","r",stdin);
	//freopen("strr.out","w",stdout);
	cin>>b>>d>>n;
	b = (b+sqrt(d)) / 2;
	cout<<(long long)(ksm());
	return 0;
}
