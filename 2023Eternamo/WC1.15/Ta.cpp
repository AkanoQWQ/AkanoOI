#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m;
inline ll read(){
	ll ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int main(){
	t = read();
	while(t--){
		ll ret = 0;
		n = read(),m = read();
		if(n > 64){
			puts("No");
			continue;
		}
		if((1ull<<(n-1))-1 > m){
			puts("No");
			continue;
		}
		puts("Yes");
		ret = 1;
		putchar('1'),putchar(' ');
		for(int i = 0;i < n-1;i++){
			ret += (1ull<<i);
			write(ret),putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
