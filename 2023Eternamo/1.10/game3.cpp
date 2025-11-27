#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
int n,tot;
int f[333][333][333];
bool r[MAXN];
void calc(){
	int xiaochu = 0;
	int rem_r = 0,rrr = n;
	tot += n;
	for(int i = 1;i <= n;i++){
		if(r[i] == 0){
			if(rem_r > 0){
				rem_r--;
				tot -= 2;
				xiaochu++;
				rrr -= 2;
			}
		}else{
			rem_r++;
		}
	}
//	cout<<n<<","<<rem_r<<","<<xiaochu<<":"<<rrr<<endl;
//	f[n][rem_r][xiaochu]++;
	return ;
}
void calc2(int inn){
	int xiaochu = 0;
	int rem_r = 0,rrr = n;
	for(int i = 1;i <= inn;i++){
		if(r[i] == 0){
			if(rem_r > 0){
				rem_r--;
				xiaochu++;
				rrr -= 2;
			}
		}else{
			rem_r++;
		}
	}
	cout<<inn<<","<<rem_r<<","<<xiaochu<<":"<<rrr<<endl;
	f[inn][rem_r][xiaochu]++;
	return ;
}
void dfs(int dep){
	calc2(dep-1);
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
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				cout<<f[i][j][k]<<" "; 
			}
			cout<<endl;
		}
		cout<<"----------------"<<endl;
	}
	printf("%.3lf",(double(tot) / double(1<<n)));
	return 0;
}
