#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
const int MOD = 1e9+7;
int mp[MAXN][MAXN];
int n,m,ans;
void show(){
	for(int i = 1;i <= n+1;i++){
		for(int j = 1;j <= m+1;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return ;
}
void dfs(int x,int y){
	if(x == n+1 && y == 1){
		ans++;
		return ;
	}
	if(y == 1 || (y > mp[x][y-1] && (x == 1 || y > mp[x-1][y-1]))){
		mp[x][y] = y;
		if(y+1 == m+1){
			dfs(x+1,1);
		}else{
			dfs(x,y+1);
		}
	}
	if(y == 1 || (y-1 > mp[x][y-1] && (x == 1 || y-1 > mp[x-1][y-1]))){
		mp[x][y] = y-1;
		if(y+1 == m+1){
			dfs(x+1,1);
		}else{
			dfs(x,y+1);
		}
	}
	return ;
}
int main(){
	freopen("whoo.in","r",stdin);
	freopen("whoo.out","w",stdout);
	cin>>n>>m;
	if(n >= 4 && (n*m >= 1000)){
		cout<<"Never gonna give you up";
		return 0;
	}
	dfs(1,1);
	ans %= MOD;
	cout<<ans;
	return 0;
}

