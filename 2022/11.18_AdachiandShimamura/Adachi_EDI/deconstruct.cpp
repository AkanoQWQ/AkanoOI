#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 2e6 + 6;
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
struct Edge{
	int nxt,to;
}e[MAXN];
int head[MAXN],ent;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int dep[MAXN];
void dfs(int u){
	for(int i = head[u];i;i = e[i].nxt){
		dep[e[i].to] = dep[u] + 1;
		dfs(e[i].to);
	}
	return ;
}
int ksm(int a,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * a) % MOD;
		a = (1ll * a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
int n,ks[MAXN],ans;
EXCUTE_ST
	freopen("deconstruct.in","r",stdin);
	freopen("deconstruct.out","w",stdout);
	n = read();
	for(int i = 2;i <= n;i++){
		const int x = read();
		AddEdge(x,i);
	}
	for(int i = 1;i <= n;i++){
		ks[i] = (ks[i-1] + ksm(i,MOD-2)) % MOD;	
	}
	dfs(1);
	for(int i = 2;i <= n;i++){
		ans = (ans + ks[dep[i]]) % MOD;
	}
	cout<<ans;
FILE_ED_And_excute
