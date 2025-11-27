#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
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
int n,a,o,f,f_o,opt,l[MAXN],tail,lll,l2[MAXN],c[MAXN],anss;
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
	if(n == 1 || o == 0 || f == 0){
		puts("1");
		return 0;
	}
	if(f >= o){
		f_o = f - o;
		opt = f_o / o;
		f_o -= opt * o;
		while(o--){
			l[++tail] = 1;
			l[++tail] = -1;
			if(f_o > 0){
				f_o--;
				l[++tail] = -1; 
			}
			for(int i = 1;i <= opt;i++){
				l[++tail] = -1;
			}
		}		
	}else{
		f_o = o - f;
		for(int i = 1;i <= f_o;i++){
			l[++tail] = 1;
		}
		for(int i = 1;i <= f;i++){
			l[++tail] = -1;
			l[++tail] = 1;
		}
	}
	for(int i = 1;i <= tail;i++){
		l2[i] = max(l2[i-1]+l[i],l[i]);
		lll = max(lll,l2[i]);
	}
	for(int i = 0;i <= (1<<n)-1;i++){
		int onenum = 0;
		int x = i;
		for(int j = 0;j <= n;j++){
			onenum += x&1;
			x >>= 1;
		}
		if(onenum != o)continue;
		for(int j = n-1;j >= 0;j--){
			int sss = (i >> j) & 1;
			c[n-j] = -1;
			if(sss == 1)c[n-j] = 1;
		}
		int ssss = 0;
		memset(l2,0,sizeof(l2));
		for(int i = 1;i <= tail;i++){
			l2[i] = max(l2[i-1]+c[i],c[i]);
			ssss = max(ssss,l2[i]);
		}
		if(ssss == lll)anss++;
	}
	cout<<anss;
	return 0;
}
