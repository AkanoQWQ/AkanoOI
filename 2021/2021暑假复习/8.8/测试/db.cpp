#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[198964],b[198964],k,kk,ans[198964],tail;//4000 4000
bool fl[10006][10006];
int main(){
	freopen("db.in","r",stdin);
	freopen("db.out","w",stdout);
	memset(fl,0,sizeof(fl));
	cin>>n>>m;
	for(i = 0;i < m;i++){
		cin>>a[i]>>b[i];
	}
	for(k = m;k > 0;k--){
		fl[a[k]][b[k]] = 1;
		fl[b[k]][a[k]] = 1;
		for(i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				for(kk = 1;kk <= n;kk++){
					if(fl[i][kk] == 1 && fl[kk][j] == 1){
						fl[i][j] = 1;
					}
				}
			}
		}
		
		for(i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				if(i == j)fl[i][j]=0;
				if(fl[i][j] == 0&&i != j)ans[tail]++;
			}
		}
		ans[tail] /= 2;
		tail++;
	}
	for(i = tail-1;i >= 0;i--){
		cout<<ans[i]<<endl;
	}
	return 0;
}

