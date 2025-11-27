#include<bits/stdc++.h>
using namespace std;
int a[300],dp,n,MA;
bool mp[3000006];
void dfs(int dep,int cnt){
	mp[cnt] = 1;
	if(dep > n)return ;
	dfs(dep+1,cnt);
	if(dep != dp)dfs(dep+1,cnt+a[dep]);
	return ;
}
int main(){
	freopen("coin.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+n+1);
	dp = -1;
	dfs(1,0);
	for(int i = 1;i <= 300006;i++){
		MA += mp[i];
	}
	cout<<"MA:"<<MA<<endl; 
	for(int i = 1;i <= n;i++){
		memset(mp,0,sizeof(mp));
		int ans = 0;
		dp = i;
		dfs(1,0);
		for(int j = 1;j <= 300006;j++){
			ans += mp[j];
		}
		cout<<a[i]<<":"<<ans<<" "<<MA-ans<<endl; 
	}
	return 0;
}

