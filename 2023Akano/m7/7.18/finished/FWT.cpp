#include<bits/stdc++.h>
using namespace std;
const int MAXV = (1<<17) + 1018;
const int MOD = 998244353;
int n,inv2;
inline int KSM(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline void MD(int& num){
	num %= MOD;
	num = (1ll * num + MOD) % MOD;
	return ;
}
inline void MUL(int* f1,int* f2,int* ans,int len){
	for(int i = 1;i <= (1<<len);i++){
		ans[i] = (1ll * f1[i] * f2[i]) % MOD;
	}
	return ;
}
inline void FWT_OR(int* f,int len,int pos){
	if(len == 0)return ;
	FWT_OR(f,len-1,pos),FWT_OR(f,len-1,pos+(1<<(len-1)));
	for(int i = pos+(1<<(len-1));i < pos+(1<<len);i++){
		f[i] += f[i-(1<<(len-1))];
		MD(f[i]);
	}
	return ;
}
inline void IFWT_OR(int* f,int len,int pos){
	if(len == 0)return ;
	IFWT_OR(f,len-1,pos),IFWT_OR(f,len-1,pos+(1<<(len-1)));
	for(int i = pos+(1<<(len-1));i < pos+(1<<len);i++){
		f[i] -= f[i-(1<<(len-1))];
		MD(f[i]);
	}
	return ;
}
inline void GetOR(int* f1,int* f2,int* otp,int len){
	for(int i = 1;i <= (1<<len);i++)otp[i] = 0;
	FWT_OR(f1,len,1),FWT_OR(f2,len,1),MUL(f1,f2,otp,len);
	IFWT_OR(otp,len,1);
	for(int i = 1;i <= (1<<len);i++){
		cout<<otp[i]<<" ";
	}
	cout<<'\n';
	IFWT_OR(f1,len,1),IFWT_OR(f2,len,1);
	return ;
}
inline void FWT_AND(int* f,int len,int pos){
	if(len == 0)return ;
	FWT_AND(f,len-1,pos),FWT_AND(f,len-1,pos+(1<<(len-1)));
	for(int i = pos+(1<<(len-1));i < pos+(1<<len);i++){
		f[i-(1<<(len-1))] += f[i];
		MD(f[i-(1<<(len-1))]);
	}
	return ;
}
inline void IFWT_AND(int* f,int len,int pos){
	if(len == 0)return ;
	IFWT_AND(f,len-1,pos),IFWT_AND(f,len-1,pos+(1<<(len-1)));
	for(int i = pos+(1<<(len-1));i < pos+(1<<len);i++){
		f[i-(1<<(len-1))] -= f[i];
		MD(f[i-(1<<(len-1))]);
	}
	return ;
}
inline void GetAND(int* f1,int* f2,int* otp,int len){
	for(int i = 1;i <= (1<<len);i++)otp[i] = 0;
	FWT_AND(f1,len,1),FWT_AND(f2,len,1),MUL(f1,f2,otp,len);
	IFWT_AND(otp,len,1);
	for(int i = 1;i <= (1<<len);i++){
		cout<<otp[i]<<" ";
	}
	cout<<'\n';
	IFWT_AND(f1,len,1),IFWT_AND(f2,len,1);
	return ;
}
int k[MAXV];
inline void FWT_XOR(int* f,int len,int pos){
	if(len == 0)return ;
	FWT_XOR(f,len-1,pos),FWT_XOR(f,len-1,pos+(1<<(len-1)));
	for(int i = pos;i < pos+(1<<len);i++){
		k[i] = f[i];
	}
	for(int i = pos;i < pos+(1<<(len-1));i++){
		f[i] = k[i] + k[i + (1<<(len-1))];
		MD(f[i]);
		f[i + (1<<(len-1))] = k[i + (1<<(len-1))] - k[i];
		MD(f[i + (1<<(len-1))]);
	}
	return ;
}
inline void IFWT_XOR(int* f,int len,int pos){
	if(len == 0)return ;
	IFWT_XOR(f,len-1,pos),IFWT_XOR(f,len-1,pos+(1<<(len-1)));
	for(int i = pos;i < pos+(1<<len);i++){
		k[i] = f[i];
	}
	for(int i = pos;i < pos+(1<<(len-1));i++){
		f[i] = (1ll * inv2 * k[i] - 1ll * inv2 * k[i + (1<<(len-1))]) % MOD;
		MD(f[i]);
		f[i + (1<<(len-1))] = (1ll * inv2 * k[i] + 1ll * inv2 * k[i + (1<<(len-1))]) % MOD;
		MD(f[i + (1<<(len-1))]);
	}
	return ;
}
inline void GetXOR(int* f1,int* f2,int* otp,int len){
	for(int i = 1;i <= (1<<len);i++)otp[i] = 0;
	FWT_XOR(f1,len,1),FWT_XOR(f2,len,1),MUL(f1,f2,otp,len);
	IFWT_XOR(otp,len,1);
	for(int i = (1<<len);i >= 1;i--){
		cout<<otp[i]<<" ";
	}
	cout<<'\n';
	IFWT_XOR(f1,len,1),IFWT_XOR(f2,len,1);
	return ;
}
int a[MAXV],b[MAXV],c[MAXV];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("FWT.in","r",stdin);
	cin>>n;
	inv2 = KSM(2,MOD-2);
	for(int i = 1;i <= (1<<n);i++){
		cin>>a[i];
	}
	for(int i = 1;i <= (1<<n);i++){
		cin>>b[i];
	}
	GetOR(a,b,c,n);
	GetAND(a,b,c,n);
	GetXOR(a,b,c,n);
	return 0;
}
