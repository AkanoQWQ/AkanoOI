#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXS = (1<<7) + 14;
const int MOD = 1e9 + 7;
int maxs = 1<<7,lst;
struct Matrix{
	ll c[MAXS][MAXS];
	ll* operator[](int x){
		return c[x];
	}
	const ll* operator[](int x)const {
		return c[x];
	}
	Matrix(){memset(c,0,sizeof(c));}
	Matrix(int x){
		memset(c,0,sizeof(c));
		for(int i = 0;i <= maxs;i++){
			c[i][i] = 1;
		}
		return ;
	}
};
Matrix operator*(const Matrix& mtx1,const Matrix& mtx2){
	Matrix ret;
	for(int i = 0;i <= maxs;i++){
		for(int j = 0;j <= maxs;j++){
			for(int k = 0;k <= maxs;k++){
				ret[i][j] += mtx1[i][k] * mtx2[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}
ostream& operator<<(ostream& cout,Matrix mtx){
	int otpLR = 0,otpUD = 0;
	for(int i = 0;i <= maxs;i++){
		int lst = -1;
		for(int j = 0;j <= maxs;j++){
			if(mtx[i][j] != 0)lst = j;
		}
		if(lst == -1)break;
		otpUD = i,otpLR = max(otpLR,lst);
	}
	for(int i = 0;i <= otpUD;i++){
		for(int j = 0;j <= otpLR;j++){
			cout<<mtx[i][j]<<" ";
		}
		cout<<endl;
	}
	return cout;
}
inline string Bit(int x,int len){
	string ret;
	for(int i = 1;i <= len;i++){
		ret += '0' + (x & 1);
		x >>= 1;
	}
	return ret;
}
inline Matrix GetOpt(int h){
	Matrix ret;
	int dp[8][2];
	int nows = (1<<h) - 1;
	for(int s1 = 0;s1 <= nows;s1++){//根据题解,0上色,1没上色 
		for(int s2 = 0;s2 <= nows;s2++){
			memset(dp,0,sizeof(dp));
			dp[0][1] = 1;
			for(int i = 1;i <= h;i++){
				dp[i][0] += dp[i-1][0] + dp[i-1][1];
				if(((s1 & (1<<(i-1))) || (s2 & (1<<(i-1)))) == 0){
					dp[i][1] += dp[i-1][0];
				}else{
					dp[i][1] += dp[i-1][0] + dp[i-1][1];
				}
			}
			ret[s1][s2] = dp[h][1];
		}
	}
	return ret;
}
inline Matrix KSM(Matrix a,int b){
	Matrix ret = Matrix(1);
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1; 
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("CF498E.in","r",stdin);
	Matrix f;
	f[0][0] = 1;
	for(int i = 1;i <= 7;i++){
		int w;
		cin>>w;
		if(w == 0)continue;
		lst = i;
		Matrix opt = GetOpt(i);
		f = f * KSM(opt,w);
	}
	cout<<f[0][0];
	return not(Akano loves pure__Elysia);
}
