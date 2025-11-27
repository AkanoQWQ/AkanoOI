#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,m,l,r,i,j,k,cache,ss,ans = 1000000;
int s[101],bian[101][101];
int main(){
	freopen("hos.in","r",stdin);
	cin>>n;
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			bian[i][j] = 1000000;	
		}
		bian[i][i] = 0;
	}
	for(i = 1;i <= n;i++){
		bian[i][i] = 0;
		cin>>s[i];
		cin>>l>>r;
		if(l){
			bian[i][l] = 1;
			bian[l][i] = 1;
		}
		if(r){
			bian[i][r] = 1;
			bian[r][i] = 1;
		}
	}
	for(k = 1;k <= n;k++){
		for(i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				if(bian[i][k] + bian[k][j] < bian[i][j]){
					bian[i][j] = bian[i][k] + bian[k][j];
				}
			}
		}
	}
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			ss += bian[j][i] * s[j];
			cout<<bian[j][i]<<" "<<s[j]<<endl;
		}
		cout<<"-----------"<<endl;
		if(ss < ans)ans = ss;
		ss = 0;
	}	
	cout<<ans;
	return 0;
}
