#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
#define ll long long
const int MOD = 1e9 + 7;
inline int read(){
	int x = 0, f = 1;
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
const int MAXN = 3006;
int n,a[MAXN],b[MAXN];
ll ans = 1;
ll ksm(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1 == 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
namespace subtask1{
	int mp[6][6],BFans = 0;
	void calc(){
		for(int i = 1;i <= n;i++){
			bool fda = 0,fdb = 0;
			for(int j = 1;j <= n;j++){
				if(mp[i][j] > a[i] || mp[i][j] > b[j]){
					return ;
				}
				if(mp[i][j] == a[i]){
					fda = 1;
				}
				if(mp[j][i] == b[i]){
					fdb = 1;
				}
			}
			if(fda == 0 || fdb == 0)return ;
		}
		BFans++;
	}
	void dfs(int x,int y){
		if(y > n){
			dfs(x+1,1);
			return ;
		}
		if(x > n){
			calc();
			return ;
		}
		int up_max = min(a[x],b[y]);
		for(int i = 0;i <= up_max;i++){
			mp[x][y] = i;
			dfs(x,y+1);
		}
		return ;
	}
	void solve(){
		dfs(1,1);
		printf("%d",BFans);
	}
}
EXCUTE_ST
	freopen("silhouette.in","r",stdin);
	freopen("silhouette.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	for(int i = 1;i <= n;i++){
		b[i] = read();
	}
	if(n <= 4){
		subtask1::solve();
		return 0;
	}
	for(int i = 1;i <= n;i++){
		ll poss = 1,sel_max = 0;
		for(int j = 1;j <= n;j++){
			if(b[j] < a[i]){
				poss = (poss * (b[j]+1)) % MOD;
			}else{
				sel_max++;
			}
		}
		if(sel_max == 0){
			puts("0");
			return 0;
		}
		poss = (poss * (ksm(a[i]+1,sel_max) - ksm(a[i],sel_max)));
		ans = (ans * poss) % MOD;
	}
	printf("%lld",ans);
FILE_ED_And_excute
