#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
const int MAXN = 2e7 + 6;
const int MAXK = 106;
const int MOD = 998244353;
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
	int l[MAXK][MAXK];
//	int* operator[](int a){
//		return l[a];
//	}
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
__int128 ii = 1;
/*matrix operator*(matrix a,matrix b){
	matrix ret = empty_matrix;
	for(int i = 0;i <= k+2;i++){
		for(int s = 0;s <= k+2;s++){
			for(int j = 0;j <= k+2;j++){
				ret[i][j] = (ret[i][j] + (a[i][s] * b[s][j])) % MOD;
				cout<<i<<","<<j<<"TT"<<a[i][s]<<" _+_ "<<b[s][j]<<" "<<(a[i][s] * b[s][j])<<" "<<ret[i][j]<<endl;
			}
		}
	}
	puts("TESTTEST");
	ret.show();
	return ret;
}*/
inline matrix operator*(matrix a,matrix b) {
	matrix ret = empty_matrix;
	for(int i=0;i<=k+2;++i) {
		for(int kk=0;kk<=k+2;++kk) {
			for(int j=0;j<=k+2;++j) {
				ret.l[i][j]=(ret.l[i][j]+a.l[i][kk]*b.l[kk][j])%MOD;
			}
		}
	}
	return ret;
}
matrix operator^(matrix a,int b){
	matrix ret = matrix_one;
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
void INIT_FOR_OP(){
	OP.l[k+2][k+2] = 1,OP.l[0][k+2] = 1;
	for(int i = 1;i <= k+1;i++){
		OP.l[i-1][i] = 1;
		OP.l[i][0] = s[i-1] * p[i] % MOD;
		cout<<i<<": "<<s[i-1]<<"*"<<p[i]<<endl;
	}
	//op[k+]
	return ;
}
EXCUTE_ST
	k = 3;
	for(int i = 0;i <= k;i++){
		for(int j = 0;j <= k;j++){
			OP.l[i][j] = rand();
		}
	}
	OP.l[2][4] = 234;
	OP.show();
	OP = OP * OP;
	OP.show();
FILE_ED_And_excute
