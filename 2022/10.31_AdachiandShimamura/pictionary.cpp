#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4002;
inline int iread(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline short read(){
	short x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
short gcd(short a,short b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
short n,m;
int q,cnt,tail;
short d[MAXN][MAXN];
struct pr{
	short l,r,g;
}p[(MAXN*MAXN / 2) + 3];
bool cmp4p(pr a,pr b){
	return a.g < b.g;
}
void write(short x){
    if(x > 9)write(x/10);
    putchar(x % 10 + '0');
    return ;
}
int main(){
	freopen("pictionary.in","r",stdin);
	freopen("pictionary.out","w",stdout);
	n = read(),m = read(),q = iread();
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			p[++cnt].l = i;
			p[cnt].r = j;
			p[cnt].g = gcd(i,j);
		}
	}
	sort(p+1,p+cnt+1,cmp4p);
	tail = cnt;
	for(int i = 1;i <= m;i++){
		const short building = m - i + 1;
		while(p[tail].g > building && tail >= 1)tail--;
		while(p[tail].g == building && tail >= 1){
			int nowl = p[tail].l,nowr = p[tail].r;
			if(d[nowl][nowr] == 0){
				d[nowl][nowr] = i;
				d[nowr][nowl] = i;
			}
			for(int j = 1;j <= n;j++){
				if(d[j][nowl] != 0){
					if(d[j][nowr] == 0){
						d[j][nowr] = i;
						d[nowr][j] = i;
					}
				}
				if(d[j][nowr] != 0){
					if(d[j][nowl] == 0){
						d[j][nowl] = i;
						d[nowl][j] = i;
					}
				}
			}
			tail--;
		}
	}
	while(q--){
		short a = read(),b = read();
		write(d[a][b]);
		putchar('\n');
	}
	return 0;
}
