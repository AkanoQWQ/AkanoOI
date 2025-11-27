#include<bits/stdc++.h>
using namespace std;
const int MAXP = 15000066;
const int MAXN = 300006;
const int MAXPR = 1000000;
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
bitset<MAXP> est;
int prime[MAXPR],pnt;
void ES(int nx){
	for(int i = 1;i <= nx;i++)est[i] = 1;
	est[1] = 0;
	for(int i = 2;i <= nx;i++){
		if(est[i]){
			prime[++pnt] = i;
			for(int j = 2;j*i <= nx;j++){
				est[j*i] = 0;
			}
		}
	}
	return ;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
}
int gcd(int aa,int bb){
	if(bb == 0)return aa;
	return gcd(bb,aa%bb);
}
int n,a[MAXN],cntmaxa,z[MAXP],ans = 0,g = -1;
int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		if(g == -1){
			g = a[i];
		}else{
			g = gcd(g,a[i]);
		}
	}
	for(int i = 1;i <= n;i++){
		a[i] /= g;
		if(a[i] > cntmaxa)cntmaxa = a[i];
		z[a[i]]++;
	}
	ES(cntmaxa);
	for(int i = 1;i <= pnt;++i){
		int ck = 0;
		for(int j = 1;prime[i]*j <= cntmaxa;j++){
			ck += z[prime[i]*j];
		}
		if(ck > 0)ans = max(ans,ck);
	}
	if(ans == 0){
		puts("-1");
	}else{
		write(n-ans);
	}
	return 0;
}
