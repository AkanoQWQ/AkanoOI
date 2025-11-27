#include<bits/stdc++.h>
using namespace std;
int n = 20,ans = 0,md;
int d[22];
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
	cin>>n>>k;
	for(int i = 1;i <= 2000;i++){
		_k[i] = (1ll * _k[i-1] * k) % MOD;
	}
	for(int i = 1;i <= n;i++){
		cout<<i<<":"<<endl;
		ans = 0,md = i;
		dfs(1);
	}
	return 0;
}

