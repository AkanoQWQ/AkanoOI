#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
const int MAXN = 2e5 + 6;
inline ll read(){
	ll x = 0, f = 1;
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
ll p[MAXN][2],n,m;
EXCUTE_ST
	freopen("least.in","r",stdin);
	freopen("least.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		p[i][0] = read();
		p[i][1] = read();
	}
	for(int k = 1;k <= m;k++){
		ll ans = 0;
		for(int st = 1;(st+k-1) <= m;st++){
			bool fd = 1;
			const int ed = st + k - 1;
			for(int i = 1;i <= n;i++){
				if(((p[i][0] < st)||(p[i][0] > ed))&&((p[i][1] < st)||(p[i][1] > ed))){
					fd = 0;
					break;
				}
			}
			ans += fd;
		}
		write(ans),putchar(' ');
	}
FILE_ED_And_excute
