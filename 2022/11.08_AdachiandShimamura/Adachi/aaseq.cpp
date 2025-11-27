#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100006;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
}
int n,q,a[MAXN];
int main(){
	freopen("aaseq.in","r",stdin);
	freopen("aaseq.out","w",stdout);
	n = read(),q = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	while(q--){
		int l = read(),r = read();
		ll sum = 0;
		for(int i = l;i <= r;i++){
			int mmin = 0x7fffffff;
			for(int j = i;j <= r;j++){
				mmin = min(mmin,a[j]);
				sum += mmin;
			}
		}
		write(sum),putchar('\n');
	}
	return 0;
}
