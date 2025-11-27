#include<bits/stdc++.h>
using namespace std;
int i,j,n,q,k,a,b,c,m,x,y;
int lu[10007][10007];
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>n;
	n--;
	for(i = 0;i <= n+6;i++){
		for(j = 0;j <=n+6;j++){
			lu[i][j] = 200000000;
		}
	}
	for(i = 0;i < n;i++){
		scanf("%d%d%d",&a,&b,&c);
		lu[a][b] = c;
		lu[b][a] = c;
	}
	for(i = 1;i <= n+1;i++){
		for(j = 1;j <= n+1;j++){
			for(m = 1;m <= n+1;m++){
				if(lu[i][m] + lu[m][j] < lu[i][j]){
				lu[i][j] = lu[i][m] + lu[m][j];
				lu[j][i] = lu[i][m] + lu[m][j];
				} 
			}
		}
	}
	cin>>q>>k;
	for(i = 0;i < q;i++){
		scanf("%d%d",&x,&y);
		cout<<lu[x][k] + lu[k][y]<<endl;
	}
	return 0;
}
