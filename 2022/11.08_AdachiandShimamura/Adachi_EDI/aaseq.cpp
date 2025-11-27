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
int n,q,a[MAXN],l[MAXN],r[MAXN];
int main(){
	//freopen("aaseq.in","r",stdin);
	//freopen("aaseq.out","w",stdout);
	n = read(),q = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	for(int i = 1;i <= n;i++){
		for(int j = i-1;j >= 1;j--){
			if(a[j]<a[i])break;
			l[i]++;
		}
		for(int j = i+1;j <= n;j++){
			if(a[j]<a[i])break;
			r[i]++;
		}
	}
	while(q--){
		int lll = read(),rr = read();
		ll sum = 0;
		for(int i = lll;i <= rr;i++){
			//sum += (min(l[i],i-lll)+1)*(min(r[i],rr-i)+1);
			sum += (l[i]+1)*(r[i]+1);
		}
		write(sum),putchar('\n');
	}
	return 0;
}
