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
__int128 b,d;
long long n;
long double yu(long double inx){
	int l = 1,r = 66;
	long double ret = inx;
	while(l <= r){
		int mid = (l + r) / 2;
		long double x = 1;
		for(int i = 1;i <= mid;i++)x *= MOD;
		if(inx <= x){
			r = mid-1;
		}else{
			ret = inx - x;
			l = mid+1;
		}
	}
	return ret;
}
long double yu2(long double inx){
	__int128 l = 1,r = MOD;
	long double ret = inx;
	while(l <= r){
		__int128 mid = (l + r) / 2;
		long double x = mid * MOD;
		if(inx <= x){
			r = mid-1;
		}else{
			ret = inx - x;
			l = mid+1;
		}
	}
	return ret;
}
long long ksm(){
	__int128 ret = 1;
	while(n){
		if(n % 2 == 1)ret = ret * b;
		b = b * b;
		cout<<"newb";
		//write(b),putchar('\n');
		cout<<(long double)(b)<<endl;
		ret %= MOD;
		b %= MOD;
		//write(ret);
		cout<<(long double)(ret);
		cout<<" "<<(long double)(b)<<endl;
		n >>= 1;
	}
	return ret;
}
int main(){
	freopen("strr.in","r",stdin);
	//freopen("strr.out","w",stdout);
	b = read(),d = read();
	b = (b+sqrt((long long)d)) / 2;
	write(b),putchar('\n');
	cin>>n;
	cout<<(long long)(floor(ksm()));
	return 0;
}
