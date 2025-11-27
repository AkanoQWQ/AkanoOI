#include<bits/stdc++.h>
using namespace std;
inline void read(int& x){//not complete
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return ;
}
void write(int x){//not complete
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n,p;
inline int ksm(int a,int b,int mod){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % mod;
		a = (1ll * a * a) % mod;
		b >>= 1;
	}
	return ret;
}
int main(){
	read(n);
	read(p);
	for(int i = 1;i <= n;i++){
		write(ksm(i,p-2,p)),putchar('\n');
	}
	return 0;
}
