#include<bits/stdc++.h>
using namespace std;
const int MAXN = 11;
int n,m,a[MAXN];
void calc(){
	bool suc = 1;
	int nowx = -1;
	for(int i = 1;i <= n;i++){
		const int cxor = a[i] xor a[i-1];
	}
}
void dfs(int dep){
	if(dep > n){
		calc();
		return ;
	}
	for(int j = a[i-1]+1;j <= m;j++){
		a[dep] = j;
		dfs(dep + 1);
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		
	}	
	return 0;
}
