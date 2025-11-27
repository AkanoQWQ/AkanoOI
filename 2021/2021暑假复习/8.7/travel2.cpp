#include<bits/stdc++.h>
using namespace std;
int n,m,l,i,j,q,s,t,a,b,c,k;
int rs[36][36];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>l;
	for(i = 0;i < 36;i++){
		for(j = 0;j < 36;j++){
			rs[i][j] = 999999;
		}
	}
	for(i = 0;i < m;i++){
		cin>>a>>b>>c;
		if(c <= l){
			a--,b--;
			rs[a][b] = c;
			rs[b][a] = c;
		}
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			for(k = 0;k < n;k++){
				if(rs[i][k] + rs[k][j] < rs[i][j]){
					rs[i][j] = rs[i][k] + rs[k][j];
					rs[j][i] = rs[i][k] + rs[k][j];
				}
			}
		}
	}
	for(i = 0;i < n;i++){
		rs[i][i] = 0;
	}
/*	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			cout<<rs[i][j]<<" ";
		}
		cout<<endl; 
	}*/
	cin>>q;
	for(i = 0;i < q;i++){
		cin>>s>>t;
		s--,t--;
		c = rs[s][t];
		if(c%l == 0){
			c = c / l;
		}else{
			c = (c/l)+1;
		}
		c--;
		cout<<c<<endl;
	}
	return 0;
}

