#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,ans = 0,md;
int d[22],_k[2006],k;
vector<int> a[22];
bool u[22];
void calc(){
	int ret = 0;
	for(int i = 1;i <= md;i++){
		ret += d[i];
	}
	a[md].push_back(ret);
	return ;
}
void dfs(int dep){
	if(dep >= md+1){
		calc();
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(u[i])continue;
		u[i] = 1;
		d[dep] = i;
		dfs(dep+1);
		u[i] = 0;
	}
	return ;
}
int main(){
	freopen("resent.in","r",stdin);
	freopen("resent.out","w",stdout);
	cin>>n>>k;
	if(n > 20)return 0;
	_k[0] = 1;
	for(int i = 1;i <= 2000;i++){
		_k[i] = (1ll * _k[i-1] * k) % MOD;
	}
	for(int i = 1;i <= n;i++){
		md = i,ans = 0;
		dfs(1);
		for(int j = 0;j < a[i].size();j++){
			ans = (1ll * ans + _k[a[i][j]])%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
