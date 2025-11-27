#include<bits/stdc++.h>
using namespace std;
int a[207],t,n,maxdep;
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
void dfs(int pos,int g,int choosenum){
	maxdep = max(maxdep,choosenum);
	if(pos >= n+1)return ;
	if(gcd(g,a[pos]) == 1){
		dfs(pos+1,g*a[pos],choosenum+1);
	}
	dfs(pos+1,g,choosenum);
	return ;
}
int main(){
	freopen("multiply.in","r",stdin);
	freopen("multiply.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxdep = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		dfs(1,1,0);
		cout<<maxdep<<endl;
	}
	return 0;
}

