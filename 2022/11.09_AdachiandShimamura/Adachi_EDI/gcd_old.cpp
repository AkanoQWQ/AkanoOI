#include<bits/stdc++.h>
using namespace std;
const int MAXP = 15000066;
const int MAXN = 300006;
const int MAXPR = 1000006;
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
int n,a[MAXN],cntmaxa,z[MAXPR],mn[MAXPR],ans = 0x7fffffff;
int bgn[MAXPR],zero[MAXPR];
int main(){
	freopen("gcd.in","r",stdin);
//	freopen("gcd.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		if(a[i] > cntmaxa)cntmaxa = a[i];
	}
	ES(cntmaxa);
	cout<<pnt<<endl;
	for(int i = 1;i <= pnt;++i){
		z[i] = 0x7fffffff;
	}
	for(int i = 1;i <= n;++i){
		int s = a[i];
		for(int j = 1;j <= pnt;++j){
			int prn = 0;
			while(s%prime[j] == 0){
				prn++;
				s /= prime[j];
			}
			if(prn < z[j]){
				if(z[j] != 0x7fffffff){
					bgn[j] = 1;
				}
				mn[j] = 1;
				z[j] = prn;
			}else if(prn == z[j]){
				mn[j]++;
			}else{
				bgn[j] = 1;
			}
			if(s <= 1){
				zero[j+1]++;
				break;
			}
		}
	}
	int sz = 0;
	for(int i = 1;i <= pnt;i++){
		sz += zero[i];
		if(sz > 0){
			if(z[i] == 0){
				mn[i] += sz;
			}else{
				mn[i] = sz;
			}
			z[i] = 0;
		}
	}
	for(int i = 1;i <= pnt;i++){
		if(mn[i] == n || z[i] == 0x7fffffff || bgn[i] == 0)continue;
		ans = min(ans,mn[i]);
	}
	if(ans == 0x7fffffff){
		puts("-1");
	}else{
		write(ans);
	}
	return 0;
}
