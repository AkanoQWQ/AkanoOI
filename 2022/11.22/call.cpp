#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
const int MOD = 998244353;
int n,m;
int a[MAXN];
struct func{
	int opt,p,v; 
}f[MAXN];
int cnt = 0,q;
bool have[5];
vector<int> tc[MAXN];
stack<int> stk;
void calc(int u){
	if(f[u].opt == 1){
		a[f[u].p] += f[u].v;
		if(a[f[u].p] >= MOD)a[f[u].p] -= MOD;
	}else if(f[u].opt == 2){
		for(int i = 1;i <= n;i++){
			a[i] = (1ll * a[i] * f[u].v) % MOD;
		}
	}else{
		const int v = f[u].p;
		if(tc[v].size() == 0)return ;
		for(int i = tc[v].size() - 1;i >= 0;i--){
			stk.push(tc[v][i]);
		}
	}
	return ;
}
namespace subtask_BF{
	void solve(){
		scanf("%d",&q);
		while(q--){
			int inx;
			scanf("%d",&inx);
			stk.push(inx);
			while(!stk.empty()){
				const int u = stk.top();
				stk.pop();
				calc(u);
			}
		}
		return ;
	}
}
void show(){
	for(int i = 1;i <= n;i++){
		printf("%d ",a[i]);
	}
	return ;
}
int main(){
//	freopen("call.in","r",stdin);
//	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;i++){
		scanf("%d",&f[i].opt);
		if(f[i].opt == 1){
			have[1] = 1;
			scanf("%d%d",&f[i].p,&f[i].v);
		}else if(f[i].opt == 2){
			have[2] = 1;
			scanf("%d",&f[i].v);
		}else{
			have[3] = 1;
			int inc,inx;
			scanf("%d",&inc);
			f[i].p = ++cnt;
			for(int i = 1;i <= inc;i++){
				scanf("%d",&inx);
				tc[cnt].push_back(inx);
			}
		}
	}
	subtask_BF::solve();
	show();//output ans
	return 0;
}

