#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
const int MAXW = 1e3 + 6;
const int MOD = 998244353;
int n,a[MAXN],b[MAXN];
inline int read(){
	int ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = (ret<<1) + (ret<<3) + (ch^48);
		ch = getchar();
	}
	return ret;
}
void write(int x){
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
namespace CS{
	struct node{
		int fir,sec,thr;
	}num[MAXW];
	int pre_gcd[MAXN][MAXN];
	inline void Select(){
		num[1].fir = num[1].sec = num[1].thr = 1;
		for(int i = 2;i <= 1e3;i++){
			int minn = 1,upp = sqrt(i);
			for(int j = 2;j <= upp;j++){
				if(i % j == 0){
					minn = j;
					break; 
				} 
			}
			int obj = i / minn;
			num[i] = num[obj];
			int minnum = min(num[i].fir,min(num[i].sec,num[i].thr));
			if(minnum == num[i].fir){
				num[i].fir *= minn;
			}else if(minnum == num[i].sec){
				num[i].sec *= minn;
			}else{
				num[i].thr *= minn;
			}
		}
		return ;
	}
	inline void Calc(int MAXV){
		for(int i = 1;i <= MAXV;i++)pre_gcd[i][0] = pre_gcd[0][i] = i;
		for(int i = 1;i <= MAXV;i++){
			for(int j = 1;j <= MAXV;j++){
				const int mn = min(i,j),mx = max(i,j);
				pre_gcd[i][j] = pre_gcd[j][i] = pre_gcd[mn][mx%mn];
			}
		}
		return ;
	}
	inline void solve(){
		Select();
		Calc();
		for(int i = 1;i <= n;i++){
			long long otp = 0,base = 1;
			for(int j = 1;j <= n;j++){
				base *= i;
				base %= MOD;
				otp += base * qgcd(a[i],b[j]);
				otp %= MOD;
			}
			write(otp),putchar('\n');
		}
		return ;
	}
}
namespace BF{
	inline int qgcd(int a,int b){
		int na = __builtin_ctz(a),nb = __builtin_ctz(b),w = na < nb?na:nb;
		b >>= nb;
		while(a){
			a >>= na;
			const int delta = b - a;
			na =  __builtin_ctz(delta);
			if(a < b)b = a;
			a = delta > 0?delta:-delta;
		}
		return b << w;
	}
	inline void solve(){
		for(int i = 1;i <= n;i++){
			long long otp = 0,base = 1;
			for(int j = 1;j <= n;j++){
				base *= i;
				base %= MOD;
				otp += base * qgcd(a[i],b[j]);
				otp %= MOD;
			}
			write(otp),putchar('\n');
		}
		return ;
	}
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)a[i] = read(); 
	for(int i = 1;i <= n;i++)b[i] = read();
	BF::solve();
	return 0;
}

/*

	(r-b)rrr
*/
