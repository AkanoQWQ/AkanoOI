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
long double b,d,ans = 1,rans,rb;
long double n;
int main(){
	freopen("strr.in","r",stdin);
	freopen("strr.out","w",stdout);
	cin>>b>>d>>n;
	b = (b+sqrt(d)) / 2;
	for(int i = 1;i <= n;i++){
		ans = (ans * b);
		rans = ans;
		__int128 l = 1,r = MOD;
		while(l <= r){
			__int128 mid = (l+r) / 2;
			if(ans < mid*MOD){
				r = mid - 1;
			}else{
				l = mid + 1;
				rans = ans - mid * MOD;
			}
		}
		ans = rans;
	}
	cout<<((long long)(floor(ans))%mod);
	return 0;
}
