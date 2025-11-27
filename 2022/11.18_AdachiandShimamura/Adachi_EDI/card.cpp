#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
const int MAXN = 2e7 + 6;
const int MAXK = 106;
const ll MOD = 998244353;
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
void wwrite(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		wwrite(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
ll n,k,ans;
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
ll ksm(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
ll p[MAXN],a[MAXN],s[MAXN];
struct matrix{
	ll l[MAXK][MAXK];
	ll* operator[](int a){
		return l[a];
	}
	void show(){
		for(int i = 0;i <= k+2;i++){
			for(int j = 0;j <= k+2;j++){
				cout<<l[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return ;
	}
	void display(){
		for(int i = 0;i <= k+2;i++){
			for(int j = 0;j <= k+2;j++){
				if(l[i][j] != 0){
					cout<<i<<" 对 "<<j<<" 有影响,为"<<l[i][j]<<endl;
				}
			}
		}
	}
}empty_matrix,mtx,OP,AFTOP,matrix_one;
matrix operator*(matrix a,matrix b){
	matrix ret = empty_matrix;
	for(int i = 0;i <= k+2;i++){
		for(int s = 0;s <= k+2;s++){
			for(int j = 0;j <= k+2;j++){
				ret.l[i][j] = (ret.l[i][j] + (a.l[i][s] * b.l[s][j])) % MOD;
		//		cout<<i<<","<<j<<"TT"<<a[i][s]<<" _+_ "<<b[s][j]<<" "<<(a[i][s] * b[s][j])<<" "<<ret[i][j]<<endl;
			}
		}
	}
	return ret;
}
matrix operator^(matrix a,ll b){
	matrix ret = matrix_one;
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
void INIT_FOR_OP(){
	/*OP.l[k+2][k+2] = 1,OP.l[0][k+2] = 1;
	for(int i = 1;i <= k+1;i++){
		OP.l[i-1][i] = 1;
		OP.l[i][0] = s[i-1] * p[i] % MOD;
		cout<<i<<": "<<s[i-1]<<"*"<<p[i]<<endl;
	}*/
	OP.l[k+2][k+2] = 1,OP.l[k+2][0] = 1;
	for(int i = 1;i <= k+1;i++){
		OP.l[i][i-1] = 1;
		OP.l[0][i] = s[i-1] * p[i] % MOD;
		cout<<i<<": "<<s[i-1]<<"*"<<p[i]<<endl;
	}
	return ;
}
EXCUTE_ST
	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1;i <= k;i++){
		ll up = read(),down = read();
		const ll g = gcd(up,down);
		up /= g;
		down /= g;
		p[i] = up * ksm(down,MOD-2) % MOD;
	}
	for(int i = 0;i <= k+2;i++){
		matrix_one.l[i][i] = 1;
	}
	if(k == 0){
		printf("%lld",n%MOD);
		return 0;
	}
	p[0] = 1,p[k+1] = 1,a[0] = 1,a[1] = p[1],s[0] = 1;
	for(int i = 1;i <= k;i++){
		s[i] = (s[i-1] * (MOD-p[i]+1)) % MOD;
	}
	INIT_FOR_OP();
	OP.display();
	OP.show();
	AFTOP = OP^n;
	AFTOP.show();
	matrix AF2 = OP^(n-1);
	AF2.show();
	cout<<"matrix ans "<<AFTOP.l[0][k+2]+AFTOP.l[0][0]<<endl;
	return 0;
	for(int i = 2;i <= n;i++){
		for(int x = 1;x <= min(1ll*i,k+1);x++){
			a[i] = (a[i] + (a[i-x] * s[x-1] % MOD) * (p[x]))%MOD;
		}
	}
	for(int i = 1;i <= n;i++){
		ans = (ans + a[i]) % MOD;
	}
	printf("%lld",ans);
FILE_ED_And_excute
