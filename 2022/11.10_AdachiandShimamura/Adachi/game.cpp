#include<bits/stdc++.h>
using namespace std;
int mp[44][44],t,n,m,sum,maxmp,ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		sum = 0,maxmp = 0,ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin>>mp[i][j];
				maxmp = max(maxmp,mp[i][j]);
				sum += mp[i][j];
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				ans += maxmp - mp[i][j];
			}
		}
		if(ans % 2 == 1){
			puts("-1");
		}else{
			ans /= 2;
			cout<<ans<<endl;
		}
		continue;
		/*totopt = (maxmp*n*m) / 2;
		for(int i = 1;i <= n;i++){
			if(i%2 == 1){
				for(int j = 1;j < m;j++){
					maxopt = max(maxopt,mp[i][j]);
					sumopt += mp[i][j];
					if(mp[i][j] < 0){
						goto pts;
					}
					mp[i][j+1] -= mp[i][j];
				}
				if(mp[i][m] < 0){
					goto pts;
				}
				mp[i+1][m] -= mp[i][m];
			}else{
				for(int j = m;j > 1;j--){
					if(mp[i][j] < 0){
						goto pts;
					}
					mp[i][j-1] -= mp[i][j];
				}
				if(mp[i][1] < 0){
					goto pts;
				}
				mp[i+1][1] -= mp[i][1];
			}
		}
		cout<<totopt - sumopt<<endl;*/
	}
	return 0;	
}
