#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 6;
int n,c;
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
	n = read();
	c = read();
	write(200),putchar(' '),write(500),putchar('\n');
	for(int i = 2;i <= n;i++){
		c = read();
		for(int a = max((c/5) - 199,0);a <= 200;a++){
			const int bb = c - 5 * a;
			if(!(bb & 1)){
				write(a),putchar(' '),write(bb/2),putchar('\n');
				goto st;
			}
		}
		st:;
	}
	return 0;
}
