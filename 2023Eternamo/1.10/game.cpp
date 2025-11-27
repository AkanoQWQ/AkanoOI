#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
int n,tot;
bool r[MAXN];
void calc(){
	int rem_r = 0;
	tot += n;
	for(int i = 1;i <= n;i++){
		if(r[i] == 0){
			if(rem_r > 0){
				rem_r--;
				tot -= 2;
			}
		}else{
			rem_r++;
		}
	}
	return ;
}
void dfs(int dep){
	if(dep > n){
		calc();
		return ;
	}
	r[dep] = 0;
	dfs(dep + 1);
	r[dep] = 1;
	dfs(dep + 1);
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	dfs(1);
	printf("%.3lf",(double(tot) / double(1<<n)));
	return 0;
}
