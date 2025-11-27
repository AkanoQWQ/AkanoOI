#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 14;
int n,a[MAXN],livet[MAXN],winner,ans[MAXN],poss;
struct edge{
	int l,r,lst,nxt;
	bool used;
}e[MAXN];
void dfs(int alive){
	if(alive == 1){
		livet[winner] = n - 1;
		for(int i = 1;i <= n;i++){
			ans[i] += livet[i];
		}
		poss++;
		return ;
	}
	int pos = 0;
	while(pos != n){
		pos = e[pos].nxt;
		if(pos == n)break;
		const int LP = e[pos].l,RP = e[pos].r;
		if(a[LP] > a[RP]){
			livet[RP] = n - alive,winner = LP;
		}else{
			livet[LP] = n - alive,winner = RP;
		}
		const int lst_e = e[pos].lst,nxt_e = e[pos].nxt;
		const edge e1 = e[lst_e],e2 = e[nxt_e];
		e[lst_e].nxt = nxt_e,e[nxt_e].lst = lst_e;
		e[lst_e].r = winner,e[nxt_e].l = winner;
		dfs(alive-1);
		e[lst_e] = e1,e[nxt_e] = e2;
	}
	return ;
}
int ksm(int aa,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * aa) % MOD;
		aa = (1ll * aa * aa) % MOD;
		b >>= 1;
	}
	return ret;
}
int divv(int aa,int b){
	return (1ll * aa * ksm(b,MOD-2)) % MOD;
}
int gcd(int aa,int b){
	if(b == 0)return aa;
	return gcd(b,aa % b);
}
int main(){
	//freopen("battle.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	if(n > 12){
		puts("Never gonna give you up");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	e[0].nxt = 1,e[n].lst = n-1;
	for(int i = 1;i < n;i++){
		e[i].l = i,e[i].r = i + 1,e[i].used = 0;
		e[i].nxt = i + 1,e[i].lst = i - 1;
	}
	dfs(n);
	for(int i = 1;i <= n;i++){
		const int g = gcd(ans[i],poss);
//		cout<<i<<":"<<ans[i]<<" "<<poss<<endl;
		ans[i] = divv(ans[i] / g,poss / g);
	}
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
