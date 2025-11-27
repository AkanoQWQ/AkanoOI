#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
const int MAXK = 272;
int n,k,a,b;
struct Matrix{
	ull c[MAXK][MAXK];
	ull* operator[](int _x){
		return c[_x];
	}
	const ull* operator[](int _x)const {
		return c[_x];
	}
	Matrix(){memset(c,0,sizeof(c));}
	Matrix(int val){
		memset(c,0,sizeof(c));
		for(int i = 1;i <= 2*k;i++)c[i][i] = val;
	}
};
Matrix operator*(const Matrix& mtx1,const Matrix& mtx2){
	Matrix ret;
	for(int i = 1;i <= k*2;i++){
		for(int j = 1;j <= k*2;j++){
			if(j <= k){
				for(int kk = 1;kk <= k;kk += 7){
					ret[i][j] += mtx1[i][kk] * mtx2[kk][j];
					ret[i][j] += mtx1[i][kk+1] * mtx2[kk+1][j];
					ret[i][j] += mtx1[i][kk+2] * mtx2[kk+2][j];
					ret[i][j] += mtx1[i][kk+3] * mtx2[kk+3][j];
					ret[i][j] += mtx1[i][kk+4] * mtx2[kk+4][j];
					ret[i][j] += mtx1[i][kk+5] * mtx2[kk+5][j];
					ret[i][j] += mtx1[i][kk+6] * mtx2[kk+6][j];
					ret[i][j] %= MOD;
				}
			}else{
				for(int kk = 1;kk <= 2*k;kk += 7){
					ret[i][j] += mtx1[i][kk] * mtx2[kk][j];
					ret[i][j] += mtx1[i][kk+1] * mtx2[kk+1][j];
					ret[i][j] += mtx1[i][kk+2] * mtx2[kk+2][j];
					ret[i][j] += mtx1[i][kk+3] * mtx2[kk+3][j];
					ret[i][j] += mtx1[i][kk+4] * mtx2[kk+4][j];
					ret[i][j] += mtx1[i][kk+5] * mtx2[kk+5][j];
					ret[i][j] += mtx1[i][kk+6] * mtx2[kk+6][j];
					ret[i][j] %= MOD;
				}
			}
		}
	}
	for(int i = 1;i <= k*2;i++){
		for(int j = 1;j <= k*2;j++){
			ret[i][j] %= MOD;
		}
	}
	return ret;
}
inline int KSM(int a,ll b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline Matrix MTX_KSM(Matrix a,ll b){
	Matrix ret = Matrix(1);
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
ostream& operator<<(ostream& cout,Matrix mtx){
	for(int i = 1;i <= k*2;i++){
		for(int j = 1;j <= k*2;j++){
			cout<<mtx[i][j]<<" ";
		}
		cout<<endl;
	}
	return cout;
}
inline Matrix MakeOpt(){
	Matrix ret;
	for(int i = 1;i <= k;i++){
		if(i-1 >= 1){
			ret[i][i-1] = 1;
			ret[i+k][i-1+k] = 1;
			if(a < i-1 && i-1 < b)ret[i][i-1+k] = 1;
		}
		ret[i][i] = 1;
		ret[i+k][i+k] = 1;
		if(a < i && i < b)ret[i][i+k] = 1;
		if(i+1 <= k){
			ret[i][i+1] = 1;
			ret[i+k][i+1+k] = 1;
			if(a < i+1 && i+1 < b)ret[i][i+1+k] = 1;
		}
	}
	return ret;
}
inline Matrix MakeOpt2(){
	Matrix ret;
	for(int i = 1;i <= k;i++){
		if(i-1 >= 1){
			ret[i][i-1] = 1;
			ret[i+k][i-1+k] = 1;
		}
		ret[i][i] = 1;
		ret[i+k][i+k] = 1;
		if(i+1 <= k){
			ret[i][i+1] = 1;
			ret[i+k][i+1+k] = 1;
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k>>a>>b;
	Matrix def,opt = MakeOpt(),opt2 = MakeOpt2();
	def[1][k/2] = 1;
	opt = MTX_KSM(opt,n-2);
	def = def * opt * opt2;
	cout<<(1ll * def[1][k/2 + k] * KSM(n-2,MOD-2)) % MOD<<endl;
	return 0;
}
