#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int t,n,m,p,stp[MAXN];
int ksm(int a,int b,int mo){
//	cout<<a<<" ^ "<<b<<" eqs ";
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % mo;
		a = (1ll * a * a) % mo; 
		b >>= 1;
	}
	return ret;
}
int inv(int x,int mo){
	return ksm(x,mo-2,mo) % mo;
} 
int C(int n,int m,int mo){
	if(n > m)return 0;
	return 1ll * stp[m] * inv((1ll*stp[n]*stp[m-n])%mo,mo) % mo;
}
void INIT(const int& md){
	stp[0] = 1;
	for(int i = 1;i <= p+2;i++){
		stp[i] = (1ll * stp[i-1] * i) % md;
	}
	return ;
}
int Lucas(int n,int m,int mo){
	if(n > m)return 0;
	if(n <= mo && m <= mo)return C(n,m,mo);
	return Lucas(n/mo,m/mo,mo) * C(n%mo,m%mo,mo);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>p;
		m += n;
		INIT(p);
		cout<<Lucas(n,m,p)%p<<endl;
	}
	return 0;
}

