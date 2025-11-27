#include<bits/stdc++.h>
using namespace std;
const __int128 int128one = 1;
const __int128 MOD = 1234;
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
long double b,d;
long long n;
long double yu(long double inx){
	int l = 1,r = 66;
	long double ret = inx;
	while(l <= r){
		int mid = (l + r) / 2;
		long double x = 1;
		for(int i = 1;i <= mid;i++)x *= MOD;
		if(inx < x){
			r = mid-1;
		}else{
			ret = inx - x;
			l = mid+1;
		}
	}
	return ret;
}
int main(){
	int x = 1234*114 + 1024;
	while(x > MOD)x = yu(x);
	cout<<x;
	return 0;
}
