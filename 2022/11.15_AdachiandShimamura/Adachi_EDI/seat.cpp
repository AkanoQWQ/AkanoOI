#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
int n,MOD;
int ksm(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1 == 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int inv(int a,int b){
	return (1ll * a * ksm(b,MOD-2)) % MOD;
}
void solve(int inx){
	if(inx == 1){
		puts("1");
	}else if(inx == 2){
		cout<<inv(1,2)<<" "<<inv(1,2)<<endl;
		cout<<inv(1,2)<<" "<<inv(1,2);
	}else{
		puts("Never gonna give you up");
	}
	return ;
}
EXCUTE_ST
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>MOD;
	solve(n);
FILE_ED_And_excute

