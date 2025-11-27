#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using ll = long long;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
inline string ReadS(){
	string ret;
	char ch = getchar();
	while(!isdigit(ch)){
		ch = getchar();
	}
	while(isdigit(ch)){
		ret += ch;
		ch = getchar();
	}
	return ret;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXM = 6;
const int MAXN = 506;
const int MOD = 998244353;
int n,m;
struct Matrix{
	int c[MAXM][MAXM];
	int* operator[](int _x){
		return c[_x];
	}
	Matrix(){memset(c,0,sizeof(c));}
	Matrix(int num){
		memset(c,0,sizeof(c));
		for(int i = 1;i <= m;i++){
			c[i][i] = num;
		}
	}
}opt,_10[MAXN],sum[MAXN][MAXN],ans[MAXN];
Matrix operator*(Matrix mtx1,Matrix mtx2){
	Matrix ret = Matrix();
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= m;k++){
				ret[i][j] = (ret[i][j] + 1ll * mtx1[i][k] * mtx2[k][j]) % MOD;
			}
		}
	}
	return ret;
}
Matrix operator+(Matrix mtx1,Matrix mtx2){
	Matrix ret;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			ret[i][j] = mtx1[i][j] + mtx2[i][j];
			if(ret[i][j] >= MOD)ret[i][j] -= MOD;
		}
	}
	return ret;
}
Matrix operator^(Matrix mtx,int b){
	Matrix ret = Matrix(1);
	while(b){
		if(b & 1)ret = ret * mtx;
		mtx = mtx * mtx;
		b >>= 1;
	}
	return ret;
}
string str;
int main(){
	freopen("P3176.in","r",stdin);
	str = ReadS(),m = Read();
	for (int i = 1;i <= m;i++)opt[i][m] = 1;
	for (int i = 2;i <= m;i++)opt[i][i-1] = 1;
	n = str.length();
	str = "." + str;
	_10[0] = opt;
	for(int i = 1;i <= n;i++)_10[i] = _10[i-1] ^ 10;
	for(int endi = 1;endi <= n;endi++){
		sum[endi+1][endi] = Matrix(1);
		for(int j = endi;j >= 1;j--){
			sum[j][endi] = sum[j+1][endi] * (_10[endi-j] ^ (str[j]-'0'));	
		}
	}
	ans[0] = Matrix(1);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < i;j++){
			ans[i] = ans[i] + (ans[j] * sum[j+1][i]);
		}
	}
	int anst = 0;
	for(int i = 1;i <= m;i++){
		anst = (1ll * anst + ans[n][1][i]) % MOD;
	}
	Write(anst); 
	return 0;
}
