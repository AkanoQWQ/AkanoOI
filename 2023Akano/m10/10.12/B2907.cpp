#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ushort = unsigned short;
using ushortp = ushort*;
using cushortp = const ushort*;
struct Matrix{
	ushort c[3][3];
	ushortp operator[](int x){
		return c[x];
	}
	cushortp operator[](int x)const{
		return c[x];
	}
	Matrix(){
		memset(c,0,sizeof(c));
		return ;
	}
};
Matrix operator*(Matrix mtx1,Matrix mtx2){
	Matrix mtx;
	int PlzPutItInRegisterQWQ;
	for(int i = 1;i <= 2;i++){
		for(int k = 1;k <= 2;k++){
			PlzPutItInRegisterQWQ = mtx1[i][k];
			for(int j = 1;j <= 2;j++){
				mtx[i][j] += PlzPutItInRegisterQWQ * mtx2[k][j];
			}
		}
	}
	return mtx;
}
Matrix stat,opt;
inline Matrix KSM(Matrix a,int b){
	Matrix ret;
	ret[1][1] = ret[2][2] = 1;
	while(b){
		if(b & 1)ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	opt[1][2] = opt[2][1] = opt[2][2] = stat[1][2] = 1;
	cin>>n;
	stat = stat * KSM(opt,n);
	cout<<stat[1][1] % 32768<<endl;
	return not(Akano loves pure__Elysia);
}
