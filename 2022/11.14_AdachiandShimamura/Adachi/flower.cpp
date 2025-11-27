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
using namespace std;
const int MAXN = 1e5 + 6;
bool estas_subtask2 = 1;
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
int n,m,a[MAXN];
namespace subtask1{
	void solve(){
		while(m--){
			int l = read(),r = read(),k = read();
			const int mo = k;
			int ans = 0;
			for(int i = l;i <= r;++i){
				ans = max(ans,a[i] % mo);
			}
			write(ans),putchar('\n');
		}
		return ;
	}
}
namespace subtask2{
	int b[MAXN][302];
	void solve(){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 300;j++){
				b[i][j] = b[i-1][j];
			}
			b[i][a[i]]++;
		}
		while(m--){
			int l = read(),r = read(),k = read();
			int ans = 0;
			for(int i = 1;i <= 300;i++){
				if(b[r][i] - b[l-1][i] <= 0)continue;
				ans = max(ans,i % k);
			}
			write(ans),putchar('\n');
		}
		return ;
	}
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;++i){
		a[i] = read();
		if(a[i] > 300){
			estas_subtask2 = 0;
		}
	}
	if(estas_subtask2 == 1){
		subtask2::solve();
	}else{
		subtask1::solve();
	}
	return 0;
}
