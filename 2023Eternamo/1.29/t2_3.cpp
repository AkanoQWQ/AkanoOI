#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[26],n,x;
int dfs(int pos,int val){
	if(pos == 1)return val % a[1];
	if(val < a[pos])return dfs(pos-1,val);	
	return max(dfs(pos-1,val),dfs(pos-1,val%a[pos]));
}
signed main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cin>>x;
	cout<<dfs(n,x);
	return 0;
}
