#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f=-1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
int n,a,o,f,f_o,opt;
int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a = read();
		if(a == 1){
			o++;
		}else{
			f++;
		}
	}
	if(n == 1){
		if(a == 1){
			puts("1");
		}else{
			puts("-1");
		}
		return 0;
	}
	if(o == 0){
		for(int i = 1;i <= n;i++){
			putchar('-'),putchar('1'),putchar(' ');
		}
		return 0;
	}else if(f == 0){
		for(int i = 1;i <= n;i++){
			putchar('1'),putchar(' ');
		}
		return 0;
	}
	if(f >= o){
		f_o = f - o;
		opt = f_o / o;
		f_o -= opt * o;
		while(o--){
			putchar('1'),putchar(' ');
			putchar('-'),putchar('1'),putchar(' ');
			if(f_o > 0){
				f_o--;
				putchar('-'),putchar('1'),putchar(' ');
			}
			for(int i = 1;i <= opt;i++){
				putchar('-'),putchar('1'),putchar(' ');
			}
		}		
	}else{
		f_o = o - f;
		for(int i = 1;i <= f_o;i++){
			putchar('1'),putchar(' ');
		}
		for(int i = 1;i <= f;i++){
			putchar('-'),putchar('1'),putchar(' ');
			putchar('1'),putchar(' ');
		}
	}
	return 0;
}
