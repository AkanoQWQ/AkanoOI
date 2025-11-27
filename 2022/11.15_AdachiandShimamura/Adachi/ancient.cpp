#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MOD = 999911659;
const int MAXN = 2006;
const int MEI = MAXN - 6;
int n,g,cnt,sum;
int ksm(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1 == 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int C[MAXN][MAXN];
EXCUTE_ST
	freopen("ancient.in","r",stdin);
	freopen("ancient.out","w",stdout);
	C[1][1] = 1;
	for(int i = 1;i <= MEI;i++)C[i][0] = 1;
	for(int i = 2;i <= MEI;i++){
		for(int j = 1;j <= MEI;j++){
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
		}
	}
	cin>>n>>g;
	for(int i = 1;i <= n;++i){
		if(n%i == 0)sum = (sum + C[n][n/i]) % MOD;
	}
	cout<<ksm(g,sum);
FILE_ED_And_excute

