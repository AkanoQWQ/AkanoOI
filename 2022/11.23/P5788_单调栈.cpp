#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 6;
int n,a[MAXN],b[MAXN];
int stk[MAXN],tp;
inline int read(){
	int ret = 0,f = 1;
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		while(tp > 0){
			if(a[stk[tp]] < a[i]){
				b[stk[tp]] = i;
				--tp;
			}else{
				break;
			}
		}
		stk[++tp] = i;
	}
	for(int i = 1;i <= n;i++){
		write(b[i]),putchar(' ');
	}
	return 0;
}
